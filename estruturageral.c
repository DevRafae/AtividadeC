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
// Função para remover o último elemento da lista e retornar seu valor
int removeFim(Lista *pList) {
    if (estaVazia(pList)) {
        printf("Erro: a lista esta vazia. Nao ha o que remover.\n");
        return -1;
    }

    dado *p = pList->prim;
    int valor;

    // Caso 1: A lista tem apenas um elemento
    if (p->prox == NULL) {
        valor = p->info;
        free(p);
        pList->prim = NULL;
        return valor;
    }

    // Caso 2: A lista tem mais de um elemento
    dado *ant = NULL;
    while (p->prox != NULL) {
        ant = p;
        p = p->prox;
    }

    // 'p' é o último nó, 'ant' é o penúltimo
    valor = p->info;
    ant->prox = NULL; // O penúltimo agora é o último
    free(p);
    return valor;
}

// Função para remover a primeira ocorrência de um 'valor' específico
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
int main() {
    int valor;

    Lista lista;
    criaLista(&lista);

    insereIni(&lista, 12); //aqui e consigo colocar os valores na lista então se eu coloco o 12 ele vai ser o novo priemiro da lista
    insereIni(&lista, 2);//quando eu coloco o 2, ele vai ser o novo primeiro
    insereFim(&lista, 20);
    insereFim(&lista, 30);
        printf("Lista original: ");
    mostraLista(&lista); // Deve imprimir: 10  20  30
    printf("\n\n");

    // Removendo o primeiro elemento
    valor = removeIni(&lista);
    printf("Valor removido do inicio: %d\n", valor);
    printf("Lista apos a primeira remocao: ");
    mostraLista(&lista); // Deve imprimir: 20  30
    printf("\n\n");

    // Removendo o novo primeiro elemento
    valor = removeIni(&lista);
    printf("Valor removido do inicio: %d\n", valor);
    printf("Lista apos a segunda remocao: ");
    mostraLista(&lista); // Deve imprimir: 30
    printf("\n\n");

    // Liberando o que sobrou da lista
    liberaLista(&lista);
    printf("Memoria liberada.\n");

    return 0;
}
