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


void adicionarProdutoCarrinho(Carrinho *c, Produto *produtos, int codigo, int qtd) {
    if (!c) return;

    Produto *p = buscarProduto(produtos, codigo);
    if (!p) {
        printf("Produto não encontrado.\n");
        return;
    }

    
    if (p->quantidade < qtd) {
        printf("Quantidade insuficiente no estoque\n");
        return;
    }

    ItemCarrinho *novo = malloc(sizeof(ItemCarrinho));
    if (!novo) return;

    novo->codigo = codigo;
    novo->quantidade = qtd;
    novo->prox = c->itens;
    c->itens = novo;

    p->quantidade -= qtd;

    printf("Produto adicionado.\n");
}

void removerProdutoCarrinho(Carrinho *c, Produto *produtos, int codigo) {
    if (!c || !c->itens) return;

    ItemCarrinho *ant = NULL;
    ItemCarrinho *atual = c->itens;

    while (atual && atual->codigo != codigo) {
        ant = atual;
        atual = atual->prox;
    }

    if (!atual) {
        printf("Produto não encontrado no carrinho.\n");
        return;
    }

    Produto *p = buscarProduto(produtos, codigo);
    if (p) {
        p->quantidade += atual->quantidade;
    }

    if (ant)
        ant->prox = atual->prox;
    else
        c->itens = atual->prox;

    free(atual);
    printf("Produto removido do carrinho.\n");
}