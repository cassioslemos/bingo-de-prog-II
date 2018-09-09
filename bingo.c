#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta (int *aposta, int n){
    printf("\nInforme os numeros da sua aposta:\n");
    for(int i=0; i < n; i++){
        while (scanf("%d", &aposta[i]) && (aposta[i] < 0 || aposta[i] > 100)){
            printf("Numero invalido!\n\nDigite novamente: ");
        }
    }
}


void sorteia_valores (int *sorteio, int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
       sorteio[i] = rand() %101;
    }
}

int* compara_aposta (int *aposta, int *sorteio, int *qtdacertos, int na, int ns){
    int *numerosacertados_inicio, *numerosacertados;
    numerosacertados_inicio = malloc(sizeof(int));
    if(numerosacertados_inicio==NULL){
        printf("Memoria indisponivel!");
        exit(1);
    }
    numerosacertados = numerosacertados_inicio;
    for(int i=0; i < na; i++){
        for(int i2=0; i2 < ns; i2++){
            if(sorteio[i2]==aposta[i]){
                *qtdacertos=*qtdacertos+1;
                *numerosacertados=aposta[i];
                numerosacertados_inicio = realloc(numerosacertados_inicio,(*qtdacertos+1)*sizeof(int));
                numerosacertados=numerosacertados_inicio+*qtdacertos;
            }
        }
    }
    return numerosacertados_inicio;
}

int main()
{
    int na, ns=20, *aposta, *sorteio, *qtdacertos,*numerosacertados, *numerosacertados_inicio;
    qtdacertos = malloc(sizeof(int));
    if(qtdacertos==NULL){
        printf("Memoria indisponivel!");
        exit(1);
    }
    *qtdacertos=0;
    printf("Informe quantos numeros voce deseja apostar (De 1 a 20): ");
    while (scanf("%d", &na) && (na < 1 || na > 20)){
        printf("Quantidade invalida!\nDigite novamente: ");
    }
    aposta = calloc(na,sizeof(int));
    if(aposta==NULL){
        printf("Memoria indisponivel!");
        exit(1);
    }
    sorteio = calloc(ns, sizeof(int));
    if(sorteio==NULL){
        printf("Memoria indisponivel!");
        exit(1);
    }
    ler_aposta(aposta,na);
    sorteia_valores(sorteio,ns);
    numerosacertados_inicio=compara_aposta(aposta,sorteio,qtdacertos,na,ns);
    numerosacertados = numerosacertados_inicio;
    if (*qtdacertos==0){
        printf("\nNenhum acerto!");
    }
    else{
        printf("\nVoce teve %d acertos\n\nVoce acertou os numeros:\n", *qtdacertos);
        for(int i=0; i < *qtdacertos; i++){
            printf("%d\n",*numerosacertados);
            numerosacertados++;
        }
    }
    return 0;
}
