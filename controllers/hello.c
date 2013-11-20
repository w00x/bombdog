#include "hello.h"
#include <stdlib.h>
#include <json/json.h>

int hello(struct mg_event *event) {
    MYSQL_RES *result;
    result = db_query("select * from cuenta");

    if (result == NULL) 
    {
        return -1;
    }

    char *json_str = mysql_json(result);
printf("%s",json_str);
    echo_content(event,"application/json",json_str);

	return 0;
}
