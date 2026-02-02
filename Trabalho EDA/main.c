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
    printf("Opcao ");
}

void menuCarrinho() {
    printf("\n=-=-=-=- MENU CARRINHO =-=-=-=\n");
    printf("1 - Adicionar produto\n");
    printf("2 - Remover produto\n");
    printf("3 - Listar carrinho\n");
    printf("Opcao: ");
}
int main() {
    Cliente *clientes = NULL;
    Produto *produtos = NULL;
    Carrinho *carrinhos = NULL;

    int op, sub, codigo, qtd;
    char cpf[15];
    do {
        menuPrincipal();
        scanf("%d", &op);

        switch (op) {

        case 1:
            menuClientes();
            scanf("%d", &sub);

            if (sub == 1)
                cadastrarCliente(&clientes);
            else if (sub == 2)
                listarClientes(clientes);
            else if (sub == 3)
                editarCliente(clientes);
            else if (sub == 4)
                removerCliente(&clientes);
            break;

        case 2:
            menuProdutos();
            scanf("%d", &sub);

            if (sub == 1)
                produtos = cadastrarProduto(produtos);
            else if (sub == 2)
                listarProdutos(produtos);
            else if (sub == 3) {
                printf("Codigo do produto: ");
                scanf("%d", &codigo);
                produtos = editarProduto(produtos, codigo);
            }
            else if (sub == 4) {
                printf("Codigo do produto: ");
                scanf("%d", &codigo);
                produtos = removerProduto(produtos, codigo);
            }
            break;

        case 3:
            printf("CPF do cliente: ");
            scanf("%s", cpf);

            Carrinho *c = buscarCarrinho(carrinhos, cpf);
            if (!c)
                carrinhos = criarCarrinho(carrinhos, cpf);

            c = buscarCarrinho(carrinhos, cpf);

            menuCarrinho();
            scanf("%d", &sub);

            if (sub == 1) {
                printf("Codigo do produto: ");
                scanf("%d", &codigo);
                printf("Quantidade: ");
                scanf("%d", &qtd);
                adicionarProdutoCarrinho(c, produtos, codigo, qtd);
            }
            else if (sub == 2) {
                printf("Codigo do produto: ");
                scanf("%d", &codigo);
                removerProdutoCarrinho(c, produtos, codigo);
            }
            else if (sub == 3)
                listarCarrinho(c, produtos);
            break;
        }
    } while (op != 0);
    printf("\nPrograma encerrado.\n");
    return 0;
}