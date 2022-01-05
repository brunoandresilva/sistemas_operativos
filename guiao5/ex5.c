//EXERCICIO 5 -> INACABADO

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int pfd[2];
    pipe(pfd);

    if(fork() == 0){
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);
        execlp("grep", "grep", "-v", "ˆ#", "/etc/passwd", NULL);
        _exit(1);
    }

    else if(fork() == 0){
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);
        execlp("cut", "cut", "-f7", "-d:", NULL);
        _exit(1);
    }

    else if(fork() == 0){
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);
        execlp("uniq", "uniq", NULL);
        _exit(1);
    }

    else if(fork() == 0){
        close(pfd[1]);
        dup2(pfd[0], 0);
        close(pfd[0]);
        execlp("wc", "wc", "-l", NULL);
        _exit(1);
    }

    else{
        close(pfd[0]);
        close(pfd[1]);

        wait(NULL);
        wait(NULL);
        wait(NULL);
        wait(NULL);
    }
}