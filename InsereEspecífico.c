// NOVA FUNÇÃO: Insere um elemento na posição 'pos' (considerando 0 como o primeiro)
int inserePosicao(Lista *pList, int v, int pos) {
    // 1. Cria o novo nó (o novo vagão)
    dado *novo = (dado*) malloc(sizeof(dado));
    // ... (verifica alocação)

    // 2. Caso especial: Inserção na primeira posição (pos == 0)
    if (pos == 0) {
        novo->prox = pList->prim; // O novo vagão aponta para o que era o primeiro
        pList->prim = novo;       // A locomotiva aponta para o novo vagão
        return 1;
    }

    // 3. Percorre a lista até a posição anterior à desejada
    dado *p = pList->prim;
    int i = 0;
    // O loop para quando 'p' for o nó ANTERIOR à posição de inserção (i == pos - 1)
    while (p != NULL && i < pos - 1) {
        p = p->prox;
        i++;
    }

    // 4. Verifica se a posição é válida (se 'p' não chegou ao fim antes da hora)
    if (p == NULL) {
        printf("Erro: Posicao %d invalida (fora dos limites da lista).\n", pos);
        free(novo); 
        return 0;
    }

    // 5. Realiza a inserção (o reengate)
    novo->prox = p->prox; // O novo vagão aponta para o vagão que estava na posição 'pos'
    p->prox = novo;       // O vagão anterior ('p') aponta para o novo vagão

    return 1;
}
