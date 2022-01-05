//EXERCICIO 3

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int wordcount(char* fn){
    //???
    int pfd[2];
    pipe(pfd);

    //pfd[0] //saida do pipe
    //pfd[1] //entrada do pipe

    if(fork() == 0){
        close(pfd[0]);  //filho nao vai ler, fecha saida

        dup2(pfd[1], 1);  //redir STDOUT -> entrada do pipe
        close(pfd[1]);

        int fd = open(fn, O_RDONLY);
        dup2(fd, 0);    //redir STDIN -> ficheiro a contar
        close(fd);

        execlp("wc", "wc", "-w", NULL);
        
        _exit(1);
    }

    else{
        close(pfd[1]);  //pai nao vai escrever, fecha entrada -> IMPORTANTE!!
        char c;
        int n = 0;

        printf("estou a ler do pipe...\n");

        while(read(pfd[0], &c, 1) > 0 && c >= '0' && c <= '9')
            n = n*10+c-'0';

        close(pfd[0]);
        return n;
    }
}

int main(int argc, char* argv[]){
    int n = wordcount("exp.c");
    printf("Numero de palavras: %d", n);
}