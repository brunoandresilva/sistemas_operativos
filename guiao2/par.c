#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


int main(int argc, char* argv[]){
    int i;

    for(i = 0; i < 10; i++){
        if(fork() == 0){
            //filho i

            printf("Sou o filho %d\n", i);

            sleep(5);

            printf("Terminei tarefa %d\n", i);

            _exit(0);
        }
    }
    //pai
    printf("Sou o pai\n");
    

    for(i = 0; i < 10; i++){
        wait(NULL);
    }
    printf("Terminei!\n");
}