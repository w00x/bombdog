//#include <my_globals.h>
#include <stdio.h>
#include <mysql/mysql.h>
#include <json/json.h>
#include "../headers/database.h"

MYSQL_RES *db_query(char *sql);
char *mysql_json(MYSQL_RES *result);
