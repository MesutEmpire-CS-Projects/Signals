#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "signal.h"

int main (){
    //Create a child process by forking
    pid_t pid = fork();

    // if pid == 0 then the child process execute the script
    if(pid == 0 ){
        printf("Starting the shell Script");
        // Executed the shell script command ./NYONGA.sh
        system("./NYONGA.sh");
    }

    // The parent process delays for 10 secs
    sleep(10);
    // Terminates the child process
    kill(pid,SIGTERM);
    printf("Closed the shell Script");

    return 0;
}