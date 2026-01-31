#include <string.h>

Cliente* buscarCliente(Cliente *lista, char cpf[]) {
    Cliente *atual = lista;

    while (atual != NULL) {
        if (strcmp(atual->cpf, cpf) == 0) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}
