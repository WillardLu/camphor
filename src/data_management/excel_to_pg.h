// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef CAMPHOR_SRC_DATA_MANAGEMENT_EXCEL_TO_PG_H
#define CAMPHOR_SRC_DATA_MANAGEMENT_EXCEL_TO_PG_H

#include <pqxx/include/libpq-fe.h>
#include <mountain_town/string/basic.h>
#include <xlsxio/xlsxio_read.h>

#include <iostream>
#include <vector>

using std::string;
using std::vector;

string GetFields(PGconn* conn, string db_table, string ignored_fields,
                 vector<string>& field_name, vector<string>& field_type);
string ExcelToPG(PGconn* conn, string db_table, string ignored_fields,
                 string special_fields, string special_value, string xlsx_file,
                 string sheet_name, size_t head_rows, size_t tail_rows);

#endif  // CAMPHOR_SRC_DATA_MANAGEMENT_EXCEL_TO_PG_H