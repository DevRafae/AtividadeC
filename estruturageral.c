#include <stdio.h>
#include <stdlib.h>

// cria a estrutura que se chama dado
typedef struct dado{
    int info; // esse é o valor que quero guardar
    struct  dado* prox; //o prox aponta pro proximo elemento
} dado; //cad dado vai se um nó da lista

// Aqui temos um ponteiro que sempre vai apontar para o primeiro valor da lista 
typedef struct ListaSimplesEnc { //
 dado *prim;
} Lista;

//Cria a lista onde prim é o primeiro valor que vai no começo da lista (pList) e este valor é NULL 
void criaLista (Lista * pList){
    pList -> prim = NULL;
}

//isso cria um novo dado  e coloca ele na frente da lista plist q ta apontando pro novo dado
void insereIni (Lista *pList, int v){
dado *novo;
novo = ( dado*) malloc (sizeof (dado)); //Cria um espaço na memória com o tamanho do dado
novo -> info = v; //defino que o "info" recebe o valor de "novo" que é o valor que colocamos agora
novo -> prox = pList -> prim; // prox elemento vai ser o novo pList que vai ser o valor do novo no primeiro
pList -> prim = novo;// pList vai ser o valor q o  primeiro vai receber que tem o valor do novo
}

//isso cria uma função para verificar se a lista ta vazia
int estaVazia(Lista *pList){
return (pList->prim == NULL); //se não tiver nenhum dado na lista (ela for NULL) ele vai reportar
}

// isso cria um novo dado no fim da lista
void insereFim (Lista *pList, int v){
dado *novo, *p;
novo = (dado*) malloc (sizeof (dado));
novo -> info = v;
novo -> prox = NULL;
 if(estaVazia(pList)){
     pList -> prim = novo;}
     else{
         p = pList -> prim;
         while (p -> prox != NULL){
             p = p -> prox;}
             p -> prox = novo;}
}

// Função para liberar toda a memória alocada pela lista
void liberaLista(Lista *pList) {
    dado *p;      // Ponteiro para percorrer a lista (o "operário 1")
    dado *temp;   // Ponteiro temporário para guardar o próximo nó (o "operário 2")

    p = pList->prim; // Começamos pelo primeiro vagão

    while (p != NULL) { // Enquanto ainda houver vagões para liberar...
        // 1. O operário 'temp' anota onde está o próximo vagão
        temp = p->prox; 
        
        // 2. O operário 'p' libera a memória do vagão atual
        printf("Liberando no com valor: %d\n", p->info); // Mensagem para vermos funcionando
        free(p);
        
        // 3. O operário 'p' se move para o próximo vagão que 'temp' guardou
        p = temp;
    }

    // 4. Ao final, avisamos a "locomotiva" que o trem não existe mais
    pList->prim = NULL; 
}
//Isso mostra a lista passando por cada info que tem ela, mas se tiver vaizia só imprime o "esta vazia)"
void mostraLista (Lista *pList){
dado *p;
for (p = pList -> prim; p != NULL; p = p->prox) { //A lista começa a ser analizada no ponteio p e enquanto esse ponteiro não for null eu vou mostrando o lacor até chegar no proximo 
printf("%d\t", p->info);
}
}

// Função para remover o primeiro elemento da lista e retornar seu valor
int removeIni(Lista *pList) {
    // Passo 1: Verificar se a lista não está vazia
    if (estaVazia(pList)) {
        printf("Erro: a lista esta vazia. Nao ha o que remover.\n");
        return -1; // Retorna um valor de erro (poderia ser outra estratégia)
    }

    dado *p;  // Ponteiro para guardar o endereço do nó a ser removido
    int valorRemovido; // Variável para guardar a informação do nó

    // Passo 2: 'p' aponta para o primeiro nó, que será removido
    p = pList->prim;
    valorRemovido = p->info; // Guarda o valor antes de perder o nó

    // Passo 3: A locomotiva ('prim') agora aponta para o segundo nó
    pList->prim = p->prox;

    // Passo 4: Libera a memória do antigo primeiro nó
    free(p);

    // Passo 5: Retorna o valor que estava no nó removido
    return valorRemovido;
}
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


// Função para remover a primeira ocorrência de um 'valor' específico (EXISTENTE NO CÓDIGO ORIGINAL, MANTIDO)
// Retorna 1 se removeu, 0 se não encontrou ou a lista estava vazia
int removeElemento(Lista *pList, int valor) {
    if (estaVazia(pList)) {
        printf("Erro: a lista esta vazia.\n");
        return 0;
    }

    dado *p = pList->prim;
    dado *ant = NULL;

    // Procura o elemento
    while (p != NULL && p->info != valor) {
        ant = p;
        p = p->prox;
    }

    // Se 'p' é NULL, o elemento não foi encontrado
    if (p == NULL) {
        printf("Elemento %d nao encontrado.\n", valor);
        return 0;
    }

    // Se 'ant' é NULL, o elemento a ser removido é o primeiro
    if (ant == NULL) {
        pList->prim = p->prox;
    } else {
        // Remove o nó 'p' ligando o anterior ao próximo
        ant->prox = p->prox;
    }

    free(p);
    printf("Elemento %d removido com sucesso.\n", valor);
    return 1;
}

// NOVA FUNÇÃO: Insere um elemento na posição 'pos' (considerando 0 como o primeiro)
int inserePosicao(Lista *pList, int v, int pos) {
    // 1. Cria o novo nó (o novo vagão)
    dado *novo = (dado*) malloc(sizeof(dado));
    if (novo == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return 0;
    }
    novo->info = v;

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
    // Se p é NULL, significa que a lista acabou antes de chegar na posição anterior (pos - 1)
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


int main() {
    int valor;

    Lista lista;
    criaLista(&lista);

    printf("--- Testando inserePosicao() ---\n");
    
    // Inserção em lista vazia (pos 0)
    inserePosicao(&lista, 10, 0); // Lista: 10
    printf("Lista apos 10 na pos 0: ");
    mostraLista(&lista); 
    printf("\n");

    // Inserção no início (pos 0)
    inserePosicao(&lista, 5, 0); // Lista: 5 -> 10
    printf("Lista apos 5 na pos 0: ");
    mostraLista(&lista); 
    printf("\n");

    // Inserção no meio (pos 1)
    inserePosicao(&lista, 15, 1); // Lista: 5 -> 15 -> 10
    printf("Lista apos 15 na pos 1: ");
    mostraLista(&lista); 
    printf("\n");
    
    // Inserção no fim (pos 3, pois a lista tem 3 elementos)
    inserePosicao(&lista, 20, 3); // Lista: 5 -> 15 -> 10 -> 20
    printf("Lista apos 20 na pos 3: ");
    mostraLista(&lista); 
    printf("\n");
    
    // Inserção no meio (pos 2)
    inserePosicao(&lista, 12, 2); // Lista: 5 -> 15 -> 12 -> 10 -> 20
    printf("Lista apos 12 na pos 2: ");
    mostraLista(&lista); 
    printf("\n");
    
    // Inserção em posição inválida
    inserePosicao(&lista, 99, 10); // Deve dar erro
    printf("\n");
    
    printf("Lista final do teste de inserePosicao: ");
    mostraLista(&lista); 
    printf("\n\n");
    
    // Libera a lista para os próximos testes
    liberaLista(&lista);
    printf("\n");


    // --- Testes Anteriores (Mantidos para integridade) ---

    criaLista(&lista);
    insereIni(&lista, 12); 
    insereIni(&lista, 2);
    insereFim(&lista, 20);
    insereFim(&lista, 30);
    insereFim(&lista, 40); 
    
    // A lista deve ser: 2 -> 12 -> 20 -> 30 -> 40
    printf("--- Testando removeFim() ---\n");

    // 1. Remove o último (40)
    valor = removeFim(&lista);
    printf("Valor removido do fim (esperado 40): %d\n", valor);
    printf("Lista apos primeira remocao do fim: ");
    mostraLista(&lista); 
    printf("\n\n");

    // 2. Remove o novo último (30)
    valor = removeFim(&lista);
    printf("Valor removido do fim (esperado 30): %d\n", valor);
    printf("Lista apos segunda remocao do fim: ");
    mostraLista(&lista); 
    printf("\n\n");
    
    // 3. Remove o primeiro (2) e o último (20) para testar o caso de um único elemento
    valor = removeIni(&lista); // Remove 2
    valor = removeFim(&lista); // Remove 20
    valor = removeFim(&lista); // Remove 12
    printf("Lista apos remocoes extras: ");
    mostraLista(&lista); // Deve imprimir: (vazia)
    printf("\n\n");

    // 4. Teste de lista vazia
    valor = removeFim(&lista);
    printf("Valor removido de lista vazia (esperado -1): %d\n", valor);
    printf("\n");


    // TESTE DA FUNÇÃO removeIni() (mantido do seu código original)
    printf("--- Testando removeIni() (original) ---\n");
    criaLista(&lista); // Recria a lista
    insereIni(&lista, 100);
    insereIni(&lista, 200);
    printf("Lista para removeIni: ");
    mostraLista(&lista); // Deve imprimir: 200 100
    printf("\n");

    valor = removeIni(&lista);
    printf("Valor removido do inicio: %d\n", valor);
    printf("Lista apos a remocao: ");
    mostraLista(&lista); // Deve imprimir: 100
    printf("\n\n");


    // Liberando o que sobrou da lista
    liberaLista(&lista);
    printf("Memoria liberada.\n");

    return 0;
}
