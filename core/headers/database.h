
struct core_db_conf{
	char *host;
	char *user;
	char *password;
	char *database;
};

struct core_db_conf get_db_conf();