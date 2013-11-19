#include "../core/headers/routes.h"

int routes(struct mg_event *event) {
	if (event->type == MG_REQUEST_BEGIN) {
	    if (!strcmp(event->request_info->uri, "/hello")) {
	    	hello(event);
	    }
	    else {
			char *msg = "Error 404";
			char content[strlen(msg)+1];
	    	int content_length = snprintf(content, sizeof(content),msg);

			mg_printf(event->conn,
	        "HTTP/1.1 200 OK\r\n"
	        "Content-Type: text/html; charset=utf-8\r\n"
	        "Content-Length: %d\r\n"        // Always set Content-Length
	        "\r\n"
	        "%s",
	        content_length, content);
		}
	}
	return 0;
}