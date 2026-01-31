void listarClientes(Cliente *lista) {
    Cliente *atual = lista;

    if (atual == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    while (atual != NULL) {
        printf("\nCPF: %s\n", atual->cpf);
        printf("Nome: %s\n", atual->nome);
        printf("Email: %s\n", atual->email);
        printf("Telefone: %s\n", atual->telefone);
        printf("Nascimento: %s\n", atual->nascimento);

        atual = atual->prox;
    }
}
