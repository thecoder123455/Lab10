/**********************************************
* Filename: signal_sigaction.c
* Description: Demonstrate use of sigaction

* Author: Nick G
* Date: 11/3/26
***********************************************/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void sigaction_handler(int signum, siginfo_t *info, void *context) {
    (void)context; // Unused parameter
    (void)signum; // Unused parameter
    printf("Signal received from PID: %ld\n", (long)info->si_pid);
    exit(1);
}

int main(){

    int pid = fork();
    if (pid == 0) {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &sigaction_handler;
    sigaction(SIGUSR1, &sa, NULL);

    while(1) {
    printf("Sleeping\n");
    sleep(1);
    }
} else {
    sleep(5);
    kill(pid, SIGUSR1);
    sleep(3);
    wait(NULL);


}
return 0;
}