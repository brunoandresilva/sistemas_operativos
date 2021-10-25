#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000


int main(int argc, char* argv[]){
    char buffer[MAX];
    int n;

    int origem = 0; //stdin

    int destino = 1; //stdout
    
    while((n = read(origem, buffer, MAX)) != 0){
        write(destino, buffer, n);
    }

    return 0;
}