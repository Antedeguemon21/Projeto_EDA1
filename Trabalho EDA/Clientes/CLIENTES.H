#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct Cliente {
    char cpf[15];
    char nome[100];
    char email[100];
    char telefone[20];
    char nascimento[11];
    struct Cliente *prox;
} Cliente;


// Protótipos das funções
Cliente* buscarCliente(Cliente *lista, char cpf[]);
void cadastrarCliente(Cliente **lista);
void editarCliente(Cliente *lista);
void listarClientes(Cliente *lista);
void removerCliente(Cliente **lista);

#endif
