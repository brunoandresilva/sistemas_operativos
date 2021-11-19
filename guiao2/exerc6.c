#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX 1000
#define N 10


int main(int argc, char* argv) {

        int i;

        int j;

        int array[N][MAX];

        for(i=0; i<N; i++){
                for(j=0;j<MAX;j++){
                        array[i][j]=0;
                }
        }

        array[2][345]=123;
        array[5][345]=123;

        int pids[N];

        for(i=0; i<N ; i++){

                pids[i]=fork();
                if(pids[i]==0){
                        int r;

                        for(j=0;j<MAX;j++)
                                if (array[i][j] == 123){
                                        r = 1;
                                        break;
                                }
                        _exit(r);
                }

 }

        printf("Sou o pai\n");
        int r = 0;
        for(i=0; i<N; i++){
                int status, pid;
                waitpid(pids[i], &status, 0);
                if (WIFEXITED(status) && WEXITSTATUS(status)){
                        r = 1;
                        printf("linha %d\n", i);
                }
        }

        printf( "Resultado: %d\n", r);

}