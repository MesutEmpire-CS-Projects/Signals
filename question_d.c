
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"


int main(){

    //Create the first child process
    int pid1 = fork();

    //Declare variables
    int num;
    int child_status_1;
    int child_status_2;

    // If pid1==0 then it is the child process from the first fork()
    if (pid1==0){
        printf("The Child Process has started \n");
        num=1;
    }
    else{
        // THis is the Parent Process
        printf("The Parent Process has started \n");
        //The parent waits for the first child
        wait(&child_status_1);
       if (child_status_1 >= 0 ){
           printf("The child process has  terminated\n");
       }
       // Parent set num to 6
        num=6;;
    }

    for (int i=num;i<num+5;i++){
        printf("%d \n",i);
    }

    // This is executed by the Parent Process
   if(pid1 !=0){
       // Create a second fork
       int pid2 = fork();

       // If pid2==0 then it is the child process from the second fork()
       if(pid2 == 0){
           printf("The Child Process has started \n");
           num=11;
       }
       else{
           // This is the Parent Process
           printf("The Parent Process has started \n");
           // Parent waits for the second child to terminate
           waitpid(pid2,&child_status_2,0);
           if (child_status_2 >= 0 ){
               printf("The child process has  terminated \n");
           }
           // Parent sets num to 16
           num=16;;
       }

       // For loop for printing the numbers
       for (int i=num;i<num+5;i++){
           printf("%d \n",i);
       }
   }


    return 0;
}