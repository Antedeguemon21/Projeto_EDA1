    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "carrinho.h"

    Carrinho* criarCarrinho(Carrinho *lista, char cpf[]) {
        Carrinho *novo = malloc(sizeof(Carrinho));
        strcpy(novo->cpf_cliente, cpf);
        novo->itens = NULL;
        novo->prox = lista;
        return novo; }


    Carrinho* buscarCarrinho(Carrinho *lista, char cpf[]) {
        while (lista) {
            if (strcmp(lista->cpf_cliente, cpf) == 0)
                return lista;
            lista = lista->prox;
        }
        return NULL;
    }


    void adicionarProdutoCarrinho(Carrinho *c, Produto *produtos, int codigo, int qtd) {
        if (!c) return;

        Produto *p = buscarProduto(produtos, codigo);
        if (!p) {
            printf("Produto não encontrado\n");
            return;
        }

        
        if (p->quantidade < qtd) {
            printf("Quantidade insuficiente no estoque\n");
            return;
        }

        ItemCarrinho *novo = malloc(sizeof(ItemCarrinho));
        if (!novo) return;

        novo->codigoProduto = codigo;
        novo->quantidade = qtd;
        novo->prox = c->itens;
        c->itens = novo;

        p->quantidade -= qtd;

        printf("Produto adicionado\n");
    }

    void removerProdutoCarrinho(Carrinho *c, Produto *produtos, int codigo) {
        if (!c || !c->itens) return;

        ItemCarrinho *ant = NULL;
        ItemCarrinho *atual = c->itens;

        while (atual && atual->codigoProduto != codigo) {
            ant = atual;
            atual = atual->prox;
        }

        if (!atual) {
            printf("Produto não encontrado no carrinho\n");
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
        printf("Produto removido do carrinho\n");
    }

    void listarCarrinho(Carrinho *c, Produto *produtos) {
    if (!c || !c->itens) {
        printf("Carrinho vazio.\n");
        return;
    }

    ItemCarrinho *it = c->itens;
    int totalItens = 0;
    float valorTotal = 0;

    printf("Carrinho do cliente CPF %s:\n", c->cpf_cliente);

    while (it) {
        Produto *p = buscarProduto(produtos, it->codigoProduto);
        if (p) {
            printf("Codigo: %d | Nome  %s | Quantidade  %d | Subtotal  %.2f\n",
                   p->codigo, p->nome, it->quantidade, p->preco * it->quantidade);

            totalItens += it->quantidade;
            valorTotal += p->preco * it->quantidade;
        }
        it = it->prox;
    }

    printf("Total de itens  %d\n", totalItens);
    printf("Valor total da compra  %.2f\n", valorTotal);
}
