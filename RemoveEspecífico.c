// NOVA FUNÇÃO: Remove a primeira ocorrência de um elemento com o valor 'v'
// Retorna 1 se o elemento foi removido, 0 caso contrário.
int removeElemento(Lista *pList, int v) {
    dado *ant = NULL; // Ponteiro para o nó anterior
    dado *p = pList->prim; // Ponteiro para o nó atual (começa no primeiro)

    // 1. Percorre a lista buscando o elemento 'v'
    while (p != NULL && p->info != v) {
        ant = p; // 'ant' avança
        p = p->prox; // 'p' avança
    }

    // 2. Se 'p' for NULL, o elemento não foi encontrado
    if (p == NULL) {
        printf("Elemento %d nao encontrado na lista.\n", v);
        return 0; // Falha na remoção
    }

    // 3. Se 'ant' for NULL, o elemento a ser removido é o primeiro da lista
    if (ant == NULL) {
        pList->prim = p->prox; // O novo primeiro é o segundo elemento
    } 
    // 4. Se 'ant' não for NULL, o elemento está no meio ou no fim
    else {
        ant->prox = p->prox; // O anterior aponta para o próximo do nó a ser removido
    }

    // 5. Libera a memória do nó removido
    printf("Elemento %d removido com sucesso.\n", p->info);
    free(p);

    return 1; // Sucesso na remoção
}
