#ifndef PRODUTO_H
#define PRODUTO_H
#include "structs_trabalho.h"

Produto* cadastrarProduto(Produto *lista);
void listarProdutos(Produto *lista);
Produto* buscarProduto(Produto *lista, int codigo);
Produto* editarProduto(Produto *lista, int codigo);
Produto* removerProduto(Produto *lista, int codigo);

#endif
