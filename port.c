/* port.c */
#include <stdlib.h>
#include <signal.h>
#include <syslog.h>
#include "worker.h"

void signalHandler(int signal) {
	syslog(LOG_INFO, "Received signal: %d\n", signal);
	printf("Received signal: %d\n", signal);

    // Handle the signal here
    // You can perform cleanup or take appropriate action based on the signal received
    // exit(EXIT_SUCCESS);
}

// Driver code
int main()
{
	openlog("ipe-backend", LOG_CONS, LOG_LOCAL0);
    // Open a connection to the system logger
    // openlog("myprogram", LOG_PID, LOG_USER);

    // Send log messages
    // syslog(LOG_INFO, "This is an informational message");
    // syslog(LOG_WARNING, "This is a warning message");
    // syslog(LOG_ERR, "This is an error message");

	// Register the signal handler for SIGTERM
    if (signal(SIGTERM, signalHandler) == SIG_ERR) {
        syslog(LOG_INFO, "Error registering signal handler");
        exit(EXIT_FAILURE);
    }

	signal(SIGINT, signalHandler);
	signal(SIGILL, signalHandler);
	signal(SIGABRT, signalHandler);
	signal(SIGFPE, signalHandler);
	signal(SIGSEGV, signalHandler);
	signal(SIGTERM, signalHandler);

	worker();

    // Close the connection to the system logger
    closelog();
	return 0;
}
