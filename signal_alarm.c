/**********************************************
* Filename: signal_alarm.c
* Description: Demonstrate signal and alarm handling
* Author: Nick G
* Date: 11/3/26
***********************************************/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void alarm_handler() {
    printf("Alarm signal received!\n");
    exit(1);
}
int main() {

     //send out alarm signal to the process after 5 seconds
    signal(SIGALRM, alarm_handler);

    printf("Setting an alarm for 5 seconds...\n");
    // Set an alarm for 5 seconds
    alarm(5);

   for (int i = 0; i < 10; i++) {
        printf("Sleeping for %d seconds...\n", i + 1);
        sleep(1);
    }
   


    return 0;
}