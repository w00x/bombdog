#include "mysql_wrapper.h"

MYSQL_RES *db_query(char *sql) {
	MYSQL *con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        return NULL;
    } 

    struct core_db_conf DB_CONF = get_db_conf();
    
    if (mysql_real_connect(con, DB_CONF.host, DB_CONF.user, DB_CONF.password, DB_CONF.database, 0, NULL, 0) == NULL) 
    {
        //finish_with_error(con);
        return NULL;
    } 

    if (mysql_query(con, sql)) 
    {
        //finish_with_error(con);
        return NULL;
    }

    MYSQL_RES *result = mysql_store_result(con);
    mysql_close(con);
    return result;
}

char *mysql_json(MYSQL_RES *result) {
    if (result == NULL) 
    {
        return NULL;
    }

char *content = "";
    MYSQL_FIELD *fields;
    fields = mysql_fetch_fields(result);

	char *table_name = fields->org_table;

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    json_object * jobj = json_object_new_object();
    json_object *jarray = json_object_new_array();
    

    while ((row = mysql_fetch_row(result))) 
    { 
        
json_object * item_arr = json_object_new_object();
        int i = 0;
        for(i = 0; i < num_fields; i++) {
		json_object *jstring;
            if(row[i] != NULL) {
		jstring = json_object_new_string(row[i]);
		}
		else {
		jstring = json_object_new_string("");
		}
            
            json_object_object_add(item_arr,fields[i].name, jstring);
        }        

         json_object_array_add(jarray,item_arr);
    }

    json_object_object_add(jobj,table_name, jarray);

    return (char *)json_object_to_json_string(jobj);
}
