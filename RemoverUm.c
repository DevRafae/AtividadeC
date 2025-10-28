//função principal
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
