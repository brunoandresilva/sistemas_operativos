#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000


int readchar(int fd){
    char c[1];
    if(read(fd, c, 1) != 0)
        return c;
    else    
        return -1;
}

ssize_t readln(int fd, char *line, size_t size){
    //TODO

    char c = readchar(fd);

    while(c != '\n'){
        printf("%c", c);
    }
}

int main(int argc, char* argv[]){
    char line[100];
    int fd = open("exemplo.txt", O_RDONLY); 

    readln(fd, line, 100);
    return 0;
}