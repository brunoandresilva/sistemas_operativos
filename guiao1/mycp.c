#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000


int main(int argc, char* argv[]){
    char buffer[MAX];
    int n;

    if(argc != 3){
        printf("./mycp origem destino\n");
        exit(0);
    }

    int origem = open(argv[1], O_RDONLY); //parecido com fopen(..., 'r')
    if(origem < 0){
        perror(argv[1]);
        exit(1);
    }

    int destino = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0640); //parecido com fopen(..., 'w)
    if(destino < 0){
        perror(argv[2]);
        exit(1);
    }
    

    while((n = read(origem, buffer, MAX)) != 0){
        write(destino, buffer, n);
    }

    close(origem);
    close(destino);
    return 0;
}