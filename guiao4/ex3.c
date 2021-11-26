#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

    int f;

    f = open("erros.txt", O_WRONLY | O_CREAT | O_APPEND, 0600);
    dup2(f, 2); close(f);

    f = open("/etc/passwd", O_RDONLY);
    if(f == -1){perror("passwd");}
    dup2(f, 0); close(f);

    f = open("saida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);
    dup2(f, 1); close(f);

    if(!fork){
        execlp("wc", "wc", NULL);
    }
    
}