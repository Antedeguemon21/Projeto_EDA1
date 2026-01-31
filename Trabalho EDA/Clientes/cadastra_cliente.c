#include <stdio.h>
#include <stdlib.h>

void cadastrarCliente(Cliente **lista) {
    Cliente *novo = (Cliente*) malloc(sizeof(Cliente));

    printf("CPF: ");
    scanf("%s", novo->cpf);


    if (buscarCliente(*lista, novo->cpf) != NULL) {
        printf("Cliente já cadastrado!\n");
        free(novo);
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", novo->nome);

    printf("Email: ");
    scanf("%s", novo->email);

    printf("Telefone: ");
    scanf("%s", novo->telefone);

    printf("Nascimento: ");
    scanf("%s", novo->nascimento);


    novo->prox = *lista;
    *lista = novo;

    printf("Cliente cadastrado com sucesso!\n");
}
