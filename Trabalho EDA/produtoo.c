#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

Produto* cadastrarProduto(Produto *lista) {
   Produto *novo = malloc(sizeof(Produto));
   if (!novo) return lista;
    
   printf("Codigo: ");
   scanf("%d", &novo->codigo);
    
   printf("Nome: ");
   scanf(" %[^\n]", novo->nome);
    
   printf("Preco: ");
   scanf("%f", &novo->preco);
    
   printf("Quantidade: ");
   scanf("%d", &novo->quantidade);
    
   novo->prox = lista;
   return novo;
}

void listarProdutos(Produto *lista) {
   while (lista) {
       printf("Codigo: %d | %s | R$: %.2f | Estoque: %d\n",
              lista->codigo, lista->nome, lista->preco, lista->quantidade);
       lista = lista->prox;
   }
    
}

Produto* buscarProduto(Produto *lista, int codigo) {
   while (lista) {
       if (lista->codigo == codigo)
           return lista;
       lista = lista->prox;
   }
   return NULL;
}

Produto* editarProduto(Produto *lista, int codigo) {
   Produto *p = buscarProduto(lista, codigo);
   if (!p) return lista;
   printf("Novo nome: ");
   scanf(" %[^\n]", p->nome);
    
   printf("Novo preco: ");
   scanf("%f", &p->preco);
    
   printf("Nova quantidade: ");
   scanf("%d", &p->quantidade);
    
   return lista;
}

Produto* removerProduto(Produto *lista, int codigo) {
   Produto *ant = NULL;
   Produto *atual = lista;
   while (atual && atual->codigo != codigo) {
       ant = atual;
       atual = atual->prox;
   }
   if (!atual) {
       printf("Produto nao encontrado\n");
       return lista;
   }
   printf("Produto removido: %s (Codigo %d)\n", atual->nome, atual->codigo);
   if (ant)
       ant->prox = atual->prox;
   else
       lista = atual->prox;
   free(atual);
   return lista;
    
}

