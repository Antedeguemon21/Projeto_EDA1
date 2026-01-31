void editarCliente(Cliente *lista) {
    char cpf[15];
    printf("CPF do cliente a editar: ");
    scanf("%s", cpf);

    Cliente *c = buscarCliente(lista, cpf);

    if (c == NULL) {
        printf("Cliente não encontrado.\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", c->nome);

    printf("Novo email: ");
    scanf("%s", c->email);

    printf("Novo telefone: ");
    scanf("%s", c->telefone);

    printf("Nova data de nascimento: ");
    scanf("%s", c->nascimento);

    printf("Dados atualizados!\n");
}
