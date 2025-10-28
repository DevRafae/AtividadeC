// NOVA FUNÇÃO: Remove o último elemento da lista e retorna seu valor
int removeFim(Lista *pList) {
    // 1. Verifica se a lista está vazia
    if (estaVazia(pList)) {
        printf("Erro: a lista esta vazia. Nao ha o que remover do fim.\n");
        return -1;
    }

    dado *p = pList->prim; // Ponteiro para o nó atual (começa no primeiro)
    dado *ant = NULL;      // Ponteiro para o nó anterior (começa nulo)
    int valorRemovido;

    // 2. Caso especial: A lista tem apenas um elemento
    if (p->prox == NULL) {
        valorRemovido = p->info;
        free(p);
        pList->prim = NULL; // A lista fica vazia
        return valorRemovido;
    }

    // 3. Percorre a lista para encontrar o último nó (p) e o penúltimo nó (ant)
    while (p->prox != NULL) {
        ant = p; // 'ant' sempre guarda o nó anterior a 'p'
        p = p->prox; // 'p' avança para o próximo nó
    }

    // Ao sair do loop:
    // 'p' é o último nó a ser removido.
    // 'ant' é o penúltimo nó (o novo último).

    // 4. Salva o valor do nó a ser removido
    valorRemovido = p->info;

    // 5. O penúltimo nó aponta para NULL (torna-se o novo fim da lista)
    ant->prox = NULL;

    // 6. Libera a memória do último nó
    free(p);

    // 7. Retorna o valor removido
    return valorRemovido;
}
