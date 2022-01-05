#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]){

    int pfd[2];
    pipe(pfd);

    //pfd[0] //saida do pipe
    //pfd[1] //entrada do pipe

    if(fork() == 0){
        close(pfd[0]);  //filho nao vai ler, fecha saida

        dup2(pfd[1], 1);  //redir STDOUT -> entrada do pipe
        close(pfd[1]);

        execlp("ls", "ls", NULL);
        _exit(1);
    }

    else{
        close(pfd[1]);  //pai nao vai escrever, fecha entrada -> IMPORTANTE!!
        char c;

        printf("estou a ler do pipe...\n");

        while(read(pfd[0], &c, 1) > 0)
            printf("recebi %c\n", c);

        close(pfd[0]);
        close(pfd[1]);
    }
    

    
}