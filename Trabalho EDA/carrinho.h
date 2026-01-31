#ifndef CARRINHO_H
#define CARRINHO_H

#include "struct_trabalho.h"

Carrinho* buscarCarrinho(Carrinho *lista, char *cpf);
Carrinho* criarCarrinho(Carrinho *lista, char *cpf);

   void adicionarProdutoCarrinho(Carrinho *c, Produto *produtos, int codigo, int qtd);
void removerProdutoCarrinho(Carrinho *c, Produto *produtos, int codigo);
   void listarCarrinho(Carrinho *c, Produto *produtos);



#endif