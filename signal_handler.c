
/**
* @file signal_handler.c
* @brief Sets a signal handler for SIGINT, the handler prints a message and then
quits
*/
/**
* Modified by: Nick G
*
* Brief summary of modifications:\
* Switched the signal from SIGINT to SIGKILL, which is a non-catchable signal. This means that the program will terminate immediately when it receives the signal, without executing the signal handler.
*/
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
* @brief Signal handler for SIGINT - prints a message and exits
*/
void handle_signal() {
printf("\nReceived a signal (Ctrl+C)\n");
//With no exit(1) the program continues to run even after the signal is recived 
exit(1);
}

int main() {
// Register for the signal

//With SIGKILL the program will not be able to catch the signal and will terminate immediately
signal(SIGINT, handle_signal);



// Wait until a signal is received
int count = 0;
while(1) {
printf("Sleeping\n");
sleep(1);
count++;
if (count == 10) {
printf("Exiting after 10 seconds\n");
kill(getpid(), SIGKILL);
}   
}
}
