int main() {
    Cliente *listaClientes = NULL;

    cadastrarCliente(&listaClientes);
    cadastrarCliente(&listaClientes);
    listarClientes(listaClientes);

    removerCliente(&listaClientes);
    listarClientes(listaClientes);

    return 0;
}
// Apenas para testes. Excluir depois
