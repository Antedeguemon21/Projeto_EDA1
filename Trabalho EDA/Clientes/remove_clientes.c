void removerCliente(Cliente **lista) {
    char cpf[15];
    printf("CPF do cliente a remover: ");
    scanf("%s", cpf);

    Cliente *atual = *lista;
    Cliente *anterior = NULL;

    while (atual != NULL && strcmp(atual->cpf, cpf) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Cliente não encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *lista = atual->prox;  // remove o primeiro
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Cliente removido com sucesso!\n");
}
