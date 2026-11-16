
/**
* @file signal_segfault.c
* @brief Program that dereferences a null pointer causing a segmentation fault
*/
/**
* Modified by: Nick G
*
* Brief summary of modifications:
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void segfault_handler() {
    printf("Segmentation fault received!\n");
    exit(1);

}



int main () {
    // Register the signal handler
    signal(SIGSEGV, segfault_handler);
   

    // Declare a null pointer
        int *ptr = NULL;

        // Dereference the null pointer to cause a segmentation fault
        printf("Dereferencing null pointer...\n");
        printf("Value: %d\n", *ptr);
   
// Return to exit the program
return 0;
}
