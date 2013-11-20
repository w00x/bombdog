#include "../core/headers/database.h"
#include <stdio.h>

struct core_db_conf get_db_conf() {
	struct core_db_conf DB_CONF;

	DB_CONF.host = "localhost";
	DB_CONF.user = "root";
	DB_CONF.password = "08041984";
	DB_CONF.database = "tengotinta_dev";

	return DB_CONF;
}
