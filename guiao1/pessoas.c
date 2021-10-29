#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char* ficheiro = "pessoas.dat";

struct pessoa{
    char nome[100];
    int idade;
};



int mostrar(){
    struct pessoa nova;
    int n;

    int fd = open(ficheiro, O_RDONLY);
    if (fd < 0)
        return -1;

    while((n = read(fd, &nova, sizeof(nova))) > 0){
        printf("Nome: %s, Idade: %d\n", nova.nome, nova.idade);
    }
    close(fd);
    return 0;
}

int inserir(char* nome, int idade){
    struct pessoa nova;
    strcpy(nova.nome, nome);
    nova.idade = idade;


    int fd = open(ficheiro, O_WRONLY|O_CREAT|O_APPEND, 0600);
    if(fd < -1)
        return -1;
    
    write(fd, &nova, sizeof(nova));
    close(fd);

    //abrir ficheiro
    //escrever para ficheiro
    //fechar ficheiro
}

int atualizar(char* nome, int idade){

}