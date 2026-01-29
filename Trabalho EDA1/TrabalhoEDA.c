#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    char cpf[15];
    char nome[100];
    char email[100];
    char telefone[20];
    char nascimento[11];
    struct Cliente *prox;
} Cliente;

typedef struct Produto {
    int codigo;
    char nome[100];
    float preco;
    int quantidade;
    struct Produto *prox;
} Produto;

typedef struct ItemCarrinho {
    int codigoProduto;
    int quantidade;
    struct ItemCarrinho *prox;
} ItemCarrinho;

typedef struct Carrinho {
    char cpf_cliente[15];
    ItemCarrinho *itens;
    struct Carrinho *prox;
} Carrinho;