
#define _POSIX_C_SOURCE 200809L

/**********************************************
* Filename: send_signal.c
* Description: Send a random integer using SIGUSR1
* Author: Nick G
* Date: 11/3/26
***********************************************/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {

    // Check for receiver PID
    if (argc < 2) {
        printf("Usage: ./send_signal <PID>\n");
        return 1;
    }

    // Get receiver PID from command line
    int receiverPID = atoi(argv[1]);

    if (receiverPID <= 0) {
        printf("Invalid PID\n");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 0 and 99
    int random_value = rand() % 100;

    // Store random number in signal value
    union sigval value;
    value.sival_int = random_value;

    printf("Sending integer: %d\n", random_value);

    // Send SIGUSR1 to receiver
    if (sigqueue(receiverPID, SIGUSR1, value) == -1) {
        perror("sigqueue");
        return 1;
    }

    return 0;
}
