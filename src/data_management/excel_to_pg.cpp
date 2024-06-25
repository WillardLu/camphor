// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include "excel_to_pg.h"

/// @brief 获取数据表字段名与字段类型
/// @param conn 数据库连接句柄
/// @param db_table 数据库表
/// @param ignored_fields 忽略的字段
/// @param field_name 字段名
/// @param field_type 字段类型
/// @return 错误信息
string GetFields(PGconn* conn, string db_table, string ignored_fields,
                 vector<string>& field_name, vector<string>& field_type) {
  if (ignored_fields != "") {
    ignored_fields = " and column_name not in (" + ignored_fields + ") ";
  }
  string sql =
      "SELECT column_name, data_type FROM information_schema.columns WHERE "
      "table_name='" +
      db_table + "'" + ignored_fields + " order by ordinal_position;";
  PGresult* res = PQexec(conn, sql.data());
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    PQclear(res);
    return "Error executing query: " + string(PQerrorMessage(conn)) + "\n";
  }
  int rows = PQntuples(res);
  for (int i = 0; i < rows; i++) {
    field_name.push_back(PQgetvalue(res, i, 0));
    field_type.push_back(PQgetvalue(res, i, 1));
  }
  PQclear(res);
  return "";
}

/// @brief Excel文件数据导入PostgreSQL数据库
/// @param conn 数据库连接句柄
/// @param db_table 数据库表
/// @param ignored_fields 忽略的字段
/// @param special_fields 特殊字段
/// @param special_value 对应特殊字段的值
/// @param xlsx_file xlsx文件
/// @param sheet 工作表
////@param head_rows 表头要忽略掉的行数
////@param tail_rows 表尾要忽略掉的行数
/// @return 错误信息
/// @note 这里只处理xlsx格式的文件。
///       特殊字段用于合成插入语句时另外添加的有特殊作用字段，并且后面必须有逗号。
///       特殊字段的值要与特殊字段对应，并且后面也必须有逗号。
string ExcelToPG(PGconn* conn, string db_table, string ignored_fields,
                 string special_fields, string special_value, string xlsx_file,
                 string sheet_name, size_t head_rows, size_t tail_rows) {
  // 1、获取数据表字段信息
  vector<string> field_name;
  vector<string> field_type;
  string err =
      GetFields(conn, db_table, ignored_fields, field_name, field_type);
  if (err != "") return err;
  // 2、根据字段内容合成插入语句的前面部分
  string sql = "INSERT INTO " + db_table + " (" + special_fields;
  for (size_t i = 0; i < field_name.size(); i++) {
    sql += field_name[i];
    sql += i == field_name.size() - 1 ? ") VALUES " : ", ";
  }
  // 3、读取xlsx文件内容
  xlsxioreader xlsx_data;
  if ((xlsx_data = xlsxioread_open(xlsx_file.data())) == NULL) {
    return "Error opening file: " + xlsx_file + ".\n";
  }
  char* value;
  xlsxioreadersheet sheet;
  // 计算表的行数
  size_t sheet_rows = 0;
  if ((sheet = xlsxioread_sheet_open(xlsx_data, sheet_name.data(),
                                     XLSXIOREAD_SKIP_EMPTY_ROWS)) != NULL) {
    while (xlsxioread_sheet_next_row(sheet)) sheet_rows++;
    xlsxioread_sheet_close(sheet);
  } else {
    xlsxioread_close(xlsx_data);
    return "Error opening sheet: " + sheet_name + "\n";
  }
  // 读取内容
  size_t i = 0;
  size_t j = 0;
  string str1 = "";
  if ((sheet = xlsxioread_sheet_open(xlsx_data, sheet_name.data(),
                                     XLSXIOREAD_SKIP_EMPTY_ROWS)) != NULL) {
    while (xlsxioread_sheet_next_row(sheet)) {
      i++;
      // 路过表头与表尾
      if (i <= head_rows) continue;
      if (i > sheet_rows - tail_rows) break;
      sql += "(" + special_value;
      j = 0;
      while ((value = xlsxioread_sheet_next_cell(sheet)) != NULL) {
        str1 = value;
        if (field_type[j] == "character varying" || field_type[j] == "text" ||
            field_type[j] == "character" || field_type[j] == "varchar" ||
            field_type[j] == "date" ||
            field_type[j] == "timestamp without time zone" ||
            field_type[j] == "timestamp with time zone") {
          sql += "'" + str1 + "', ";
        } else {
          sql += str1 + ", ";
        }
        xlsxioread_free(value);
        j++;
      }
      sql = RTrim(sql, ", ") + "), ";
    }
    sql = RTrim(sql, ", ") + ";";
    xlsxioread_sheet_close(sheet);
  }
  //  clean up
  xlsxioread_close(xlsx_data);
  // 4、执行插入语句
  PGresult* res = PQexec(conn, sql.data());
  if (PQresultStatus(res) != PGRES_COMMAND_OK) {
    return PQerrorMessage(conn);
  }
  PQclear(res);
  return "";
}