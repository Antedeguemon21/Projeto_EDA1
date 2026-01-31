#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carrinho.h"

Carrinho* criarCarrinho(Carrinho *lista, char cpf[]) {
      Carrinho *novo = malloc(sizeof(Carrinho));
     strcpy(novo->cpf, cpf);
     novo->itens = NULL;
    novo->prox = lista;
    return novo; }


Carrinho* buscarCarrinho(Carrinho *lista, char cpf[]) {
    while (lista) {
        if (strcmp(lista->cpf, cpf) == 0)
            return lista;
        lista = lista->prox;
    }
    return NULL;
}