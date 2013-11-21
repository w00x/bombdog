#include "core.h"

static int event_handler(struct mg_event *event) {

  if (event->type == MG_REQUEST_BEGIN) {
    routes(event);
    return 1;
  }

  // We do not handle any other event
  return 0;
}

int start_bd() {
	struct mg_context *ctx;

	// List of options. Last element must be NULL.
	const char *options[] = {"listening_ports", "8050","num_threads","1000", NULL};

	// Start the web server.
	ctx = mg_start(options, &event_handler, NULL);

	// Wait until user hits "enter". Server is running in separate thread.
	// Navigating to http://localhost:8080 will invoke begin_request_handler().
	getchar();

	// Stop the server.
	mg_stop(ctx);

	return 0;
}
