#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pessoas.h"


int main(int argc, char*argv[]){
    if(argc == 4 && strcmp(argv[1], "-i") == 0){
        //inserir
        char* nome = argv[2];
        int idade = atoi(argv[3]);
        inserir(nome, idade);
    }
    else if(argc == 4 && strcmp(argv[1], "-u") == 0){
        //atualizar
        char* nome = argv[2];
        int idade = atoi(argv[3]);
        atualizar(nome, idade);
    }
    else if(argc == 1){
        mostrar();
    }
    else
        printf("pessoas [-u|-i] nome idade\n");
}