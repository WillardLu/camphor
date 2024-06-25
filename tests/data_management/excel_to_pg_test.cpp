// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include <gtest/gtest.h>

#include <data_management/excel_to_pg.h>
#include <toml/toml.hpp>

using std::cout;
using std::endl;

TEST(EXCEL_TO_PG_Tests, GetFields) {
  // 读取数据库配置文件并连接
  auto data = toml::parse("tests/data_management/testdata/database.toml");
  const auto pg_info = toml::find(data, "postgresql");
  string conn_info = "host=" + toml::find<std::string>(pg_info, "host") + " ";
  conn_info += "port=" + toml::find<std::string>(pg_info, "port") + " ";
  conn_info += "user=" + toml::find<std::string>(pg_info, "user") + " ";
  conn_info += "password=" + toml::find<std::string>(pg_info, "password") + " ";
  conn_info += "dbname=" + toml::find<std::string>(pg_info, "database");
  PGconn* conn = PQconnectdb(conn_info.data());
  EXPECT_EQ(PQstatus(conn), CONNECTION_OK);
  if (PQstatus(conn) == CONNECTION_BAD) {
    fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
    PQfinish(conn);
    return;
  }
  vector<string> field_name;
  vector<string> field_type;
  string ignore_fields = "'id0', 'statement_date'";
  string err = GetFields(conn, "list_of_hospitalization", ignore_fields,
                         field_name, field_type);
  PQfinish(conn);
  // 普通测试
  EXPECT_EQ(err, "");
  EXPECT_EQ(field_name[0], "department");
}

TEST(EXCEL_TO_PG_Tests, ExcelToPG) {
  // 1、读取数据库配置文件并连接
  auto data = toml::parse("tests/data_management/testdata/database.toml");
  const auto pg_info = toml::find(data, "postgresql");
  string conn_info = "host=" + toml::find<std::string>(pg_info, "host") + " ";
  conn_info += "port=" + toml::find<std::string>(pg_info, "port") + " ";
  conn_info += "user=" + toml::find<std::string>(pg_info, "user") + " ";
  conn_info += "password=" + toml::find<std::string>(pg_info, "password") + " ";
  conn_info += "dbname=" + toml::find<std::string>(pg_info, "database");
  PGconn* conn = PQconnectdb(conn_info.data());
  EXPECT_EQ(PQstatus(conn), CONNECTION_OK);
  if (PQstatus(conn) == CONNECTION_BAD) {
    fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
    PQfinish(conn);
    return;
  }
  // 2、读取Excel文件并导入到数据库
  string xlsx = "tests/data_management/testdata/3月住院.xlsx";
  string db_table = "list_of_hospitalization";
  string ignore_fields = "'id0', 'statement_date'";
  string err = ExcelToPG(conn, db_table, ignore_fields, "statement_date, ",
                         "2024.3, ", xlsx, "Page1", 1, 1);
  EXPECT_EQ(err, "");

  xlsx = "tests/data_management/testdata/3月门诊.xlsx";
  db_table = "list_of_outpatient_service";
  ignore_fields = "'id0', 'statement_date'";
  err = ExcelToPG(conn, db_table, ignore_fields, "statement_date, ", "2024.3, ",
                  xlsx, "Page1", 1, 1);
  EXPECT_EQ(err, "");

  xlsx = "tests/data_management/testdata/3月检治项目.xlsx";
  db_table = "list_of_examination_and_treatment";
  ignore_fields = "'id0', 'statement_date'";
  err = ExcelToPG(conn, db_table, ignore_fields, "statement_date, ", "2024.3, ",
                  xlsx, "Page1", 1, 1);
  EXPECT_EQ(err, "");

  // ASSERT开头的语句失败后会跳出，不会执行后续代码，所以要在此之前做好收尾工作。
  // EXPECT开头的语句失败后会继续执行后续代码，所以要在此之前做好收尾工作。
  PQfinish(conn);
}