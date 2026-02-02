#include <stdio.h>
#include "Clientees.h"
#include "produto.h"
#include "carrinho.h"

void menuPrincipal() {
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("      SISTEMA DE VENDAS      \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("1 - Gerenciar Clientes\n");
    printf("2 - Gerenciar Produtos\n");
    printf("3 - Modo Compra\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}

void menuClientes() {
    printf("\n-=-=-=- MENU CLIENTES =-=-=-=-=\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Editar\n");
    printf("4 - Remover\n");
    printf("Opcao: ");
}

void menuProdutos() {
    printf("\n-=-=-= MENU PRODUTOS =-=-=\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Editar\n");
    printf("4 - Remover\n");
    printf("Opcao: ");
}

void menuCarrinho() {
    printf("\n=-=-=-=- MENU CARRINHO =-=-=-=\n");
    printf("1 - Adicionar produto\n");
    printf("2 - Remover produto\n");
    printf("3 - Listar carrinho\n");
    printf("Opcao: ");
}

int main () {
    
}