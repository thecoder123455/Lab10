
#define _POSIX_C_SOURCE 200809L

/**********************************************
* Filename: recv_signal.c
* Description: Receive an integer using SIGUSR1
* Author: Nick G
* Date: 11/3/26
***********************************************/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void sigaction_handler(int signum, siginfo_t *info, void *context) {
    (void)context; // Unused parameter
    (void)signum; // Unused parameter
    printf("\nSignal received!\n");
    printf("Received integer: %d\n", info->si_value.sival_int);
}
void sigint_handler(int signum) {
    (void)signum; // Unused parameter
    printf("\nSIGINT received. Exiting gracefully.\n");
    exit(0);
}



int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &sigaction_handler;
    sigaction(SIGUSR1, &sa, NULL);

    signal(SIGINT, sigint_handler);


    printf("Receiver PID: %d\n", getpid());

    while(1) {
        pause();
    }

    return 0;
}
