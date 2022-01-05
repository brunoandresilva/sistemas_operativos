#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]){

    int pfd[2];
    pipe(pfd);

    //pfd[0] //saida do pipe
    //pfd[1] //entrada do pipe

    if(fork() == 0){
        close(pfd[0]);  //filho nao vai ler, fecha saida

        sleep(5);

        write(pfd[1], "a", 1);
        write(pfd[1], "b", 1);
        printf("escrevi tudo!\n");

        sleep(5);
        printf("vou terminar\n");
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