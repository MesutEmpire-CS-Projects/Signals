
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "signal.h"

// This is signal handler for SIGUSR1
void sigUser1_handler(int num){
    printf("Here is my 1st  user defined signal\n");

}
// This is signal handler for SIGUSR2
void sigUser2_handler(int num){
    printf("Here is my 2nd  user defined signal\n");

}
int main()
{
    //Register signal handler for SIGUSR1 and SIGUSR2
signal(SIGUSR1,sigUser1_handler);
signal(SIGUSR2,sigUser2_handler);

    printf("Waiting for signal!!\n");

    // Create a child process
    int child_id = fork();

    //Infinite Loop
    for(int i ; ; i++){
        // If this process is the child and i==5, raise SIGUSR1
        if ( i == 5 && child_id == 0){
            // Child process send SIGUSR1 to the parent
            kill(getppid(), SIGUSR1);
        }
       // If i==10, send SIGUSR2 to the parent process
        else if ( i == 10){
            // Parent raises SIGUSR2
            raise(SIGUSR2);
        }
        sleep(1);
    }

    return 0;

}