bombdog: main.c core/core.c core/libs/mongoose.c config/routes.c config/database.c controllers/*.c core/libs/mysql_wrapper.c core/libs/utils.c
	gcc main.c core/core.c core/libs/mongoose.c config/routes.c controllers/*.c core/libs/mysql_wrapper.c core/libs/utils.c config/database.c -o bombdog -ldl -lpthread `mysql_config --libs` -ljson
