#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]){

    int random[3][10];
    int i, o;

    srand(time(NULL));
    for(o = 0; o < 3; o++)
        for(i = 0; i < 10; i++)
            random[o][i] = rand() % 100;
    

    for(o = 0; o < 3; o++){
        for(i = 0; i < 10; i++)
            printf("%d ", random[o][i]);
        printf("\n");
    }

    return 0;
}