//INCOMPLETO - falta os wait()
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


int main(int argc, char* argv[]){
    int i;

    for(i = 0; i < 10; i++){
        if(fork() != 0){
            //pai i

            printf("Sou o pai %d %d %d\n", i, getpid(), getppid());

            wait(NULL); //executam sequancialmente
            sleep(1);

            printf("Terminei tarefa %d\n", i);

            //wait(NULL); executam sequancialmente
            
            _exit(0);
        }
    }
    //pai
    printf("Sou o ultimo descendente\n");
    printf("Terminei!\n");
}