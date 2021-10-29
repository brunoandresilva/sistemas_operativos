#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000


char buffer[1000];

int readchar(int fd){
    char c[1];
    if(read(fd, c, 1) != 0)
        return c[0];
    else    
        return -1;
}

ssize_t readln(int fd, char *line, size_t size){
    int i = 0;

    char c = readchar(fd);

    while(c > 0 && c != '\n' && i < size){
        line[i] = c;
        i++;
        c = readchar(fd);
    }
    line[i] = 0;
    return i;
}

int main(int argc, char* argv[]){
    char line[100];
    int fd = open("destino.txt", O_RDONLY); 
    while(readln(fd, line, 200) > 0){
        printf("%s\n", line);
    }
    return 0;
}