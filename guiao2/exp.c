#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int status;
    int i = 0;

    printf("Antes %d %d\n", getpid(), getppid());

    int pai = getpid();
    int p = fork();

    if(p != 0){
        printf("Pai - Depois %d %d %d\n", getpid(), getppid(), p);
        sleep(60);
        int morto = wait(&status);

        if(WIFEXITED(status)){
            printf("O filho %d terminou com o resultado %d\n", morto, WEXITSTATUS(status));
        }

        printf("Pai - terminei!\n");
    }
    else{
        printf("Filho - Depois %d %d %d\n", getpid(), getppid(), p);
        sleep(10);
        printf("Filho - terminei!\n");

        _exit(123); //so pdemos passar 1 byte! -128 -> 127
    }

    
}