#include <stdio.h>
#include <stdlib.h>
#define TAM 10

struct no{
    int dado;
    struct no *prox;
};

struct no *vet[TAM];

int preenche(){
    int i;
    for(i=0;i<TAM;i++){
        vet[i]=NULL;
    }
}

int espalha(int chave){
    return chave%TAM;
}

void insere(int chave){
    struct no *aux;
    int pos;
    aux = (struct no*)malloc(sizeof(struct no));
    aux->dado = chave;
    aux->prox = NULL;
    pos = espalha(chave);
    aux -> prox = vet[pos];
    vet[pos] = aux;
}

void busca(int chave){
    struct no *aux;
    int pos = espalha(chave);
    aux = vet[pos];
    while(aux->prox != NULL){
        if(aux -> dado == chave){
            printf("O valor %d foi encontrado!\n", chave);
            return;
        }
        aux = aux -> prox;
    }
    printf("O valor %d nao foi encontrado!\n", chave);
    return;
}

void imprime(){
    struct no *aux;
    int pos = 0;
    printf("\nItens: \n");
    for(pos = 0; pos<TAM;pos++){
        printf("%d - ",pos);
        for(aux = vet[pos] ; aux != NULL; aux = aux -> prox){
            printf("%d " ,aux->dado);
        }
        printf("\n");
    }
}

int main(){
    preenche();
    insere(60);
    insere(10);
    insere(61);
    insere(70);
    insere(2);
    insere(43);
    busca(11);
    busca(60);
    busca(70);
    imprime();
}
