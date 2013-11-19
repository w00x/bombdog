#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../libs/mongoose.h"

char *concat(char *foo, char *bar) {
        char *tmp;

        tmp = (char *)malloc(strlen(foo)+strlen(bar)+1);
        *tmp = *"";

        strcat(tmp,foo);
        strcat(tmp,bar);
        
        return tmp;
}

void echo_content(struct mg_event *event, char *type, char *pre_content) {
	char content[strlen(pre_content)+1];
    int content_length = snprintf(content, sizeof(content),pre_content);

    mg_printf(event->conn,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: %d\r\n"        // Always set Content-Length
        "\r\n"
        "%s",
        type,content_length, content);
}