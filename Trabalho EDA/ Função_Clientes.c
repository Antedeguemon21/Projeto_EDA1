#include<stdio.h>
#include<stdlib.h>

typedef struct Cliente {
    char cpf[15];
    char nome[100];
    char email[100];
    char telefone[20];
    char nascimento[11];
    struct Cliente *prox;
} Cliente;
