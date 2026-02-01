#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Cliente* buscarCliente(Cliente *lista, char cpf[]) {
    Cliente *atual = lista;

    while (atual != NULL) {
        if (strcmp(atual->cpf, cpf) == 0) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}


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


void editarCliente(Cliente *lista) {
    char cpf[15];
    printf("CPF do cliente a editar: ");
    scanf("%s", cpf);

    Cliente *c = buscarCliente(lista, cpf);

    if (c == NULL) {
        printf("Cliente não encontrado.\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", c->nome);

    printf("Novo email: ");
    scanf("%s", c->email);

    printf("Novo telefone: ");
    scanf("%s", c->telefone);

    printf("Nova data de nascimento: ");
    scanf("%s", c->nascimento);

    printf("Dados atualizados!\n");
}

void listarClientes(Cliente *lista) {
    Cliente *atual = lista;

    if (atual == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    while (atual != NULL) {
        printf("\nCPF: %s\n", atual->cpf);
        printf("Nome: %s\n", atual->nome);
        printf("Email: %s\n", atual->email);
        printf("Telefone: %s\n", atual->telefone);
        printf("Nascimento: %s\n", atual->nascimento);

        atual = atual->prox;
    }
}

void removerCliente(Cliente **lista) {
    char cpf[15];
    printf("CPF do cliente a remover: ");
    scanf("%s", cpf);

    Cliente *atual = *lista;
    Cliente *anterior = NULL;

    while (atual != NULL && strcmp(atual->cpf, cpf) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Cliente não encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Cliente removido com sucesso!\n");
}
