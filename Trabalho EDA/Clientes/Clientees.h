#ifndef CLIENTE_H
#define CLIENTE_H
#include "struct_Clientes.h"


Cliente* buscarCliente(Cliente *lista, char cpf[]);
void cadastrarCliente(Cliente **lista);
void editarCliente(Cliente *lista);
void listarClientes(Cliente *lista);
void removerCliente(Cliente **lista);

#endif
