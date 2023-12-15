
#include "stdio.h"
#include "unistd.h"

int main()
{
    // Create a copy of the calling function
    int id = fork();

    // If id == 0  then it is the child process then print a message from the child
    // with its pid
    if(id == 0 ){
        printf("This is the child process : %d \n",getpid());
    }
    else if (id > 0 ){
        // if the id >0 then this is the Parent process
        printf("This is the Parent Process: %d and child process : %d\n",getpid(),id);
    }
    else {
        // Otherwise print the error message
        perror("Error : Failed to fork ");
    }

    //This is printed by all the processes
    printf("All Processes \n");
}