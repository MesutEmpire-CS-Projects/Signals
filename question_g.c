
#include "stdio.h"
#include "unistd.h"
#include "signal.h"

// Signal handler for SIGALRM
void sigAlarm_handler(int num)
{
    printf("The alarm has gone off!!\n");

    // Delete the file
    int response = remove("./JUJU.txt");
    printf("%d\n",response);

    // If the deletion is successful then print successfully deleted
    if ( response == 0)
    {
        printf("JUJU file is deleted successfully\n");
    }
    else
    {
        // If an error occurs , print an error message
        perror("Error: JUJU file unable to be deleted\n");
    }
}

int main()
{
    // Declare the file pointer
    FILE *fptr;

    // Create the file
    fptr = fopen("./JUJU.txt", "w");
    //If failed to create file then print the error message
    if(fptr == NULL){
        perror("Error: Failed to create JUJU file");
        return 1;
    }
    printf("File Created \n");

    // Register the signal handler for SIGALRM
    signal(SIGALRM, sigAlarm_handler);

    //Set alarm to trigger the SIGALRM after 5 sec
    alarm(5);

    // Close file
    fclose(fptr);

    // Delays the execution of the program by 10 seconds
    sleep(10);
}