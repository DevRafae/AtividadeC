int main() {
    Lista lista;
    criaLista(&lista);

    insereIni(&lista, 12); //aqui e consigo colocar os valores na lista então se eu coloco o 12 ele vai ser o novo priemiro da lista
    insereIni(&lista, 2);//quando eu coloco o 2, ele vai ser o novo primeiro
    insereFim(&lista, 20);
    insereFim(&lista, 30);
        mostraLista(&lista);//isso imprime
    
    printf("Lista antes de liberar:\n");
    mostraLista(&lista);
    printf("\n\n");

    //aqui vamos limpar o vagão
    printf("Iniciando processo de liberacao...\n");
    liberaLista(&lista);
    printf("Processo de liberacao concluido.\n\n");

    // Vamos verificar se a lista está realmente vazia agora
    if (estaVazia(&lista)) {
        printf("A lista esta vazia agora, como esperado.\n");
    } else {
        printf("Algo deu errado, a lista ainda contem elementos.\n");
    }


    if (estaVazia(&lista))
        printf("Lista vazia\n");
    else
        printf("Lista com elementos\n");

    return 0;}
