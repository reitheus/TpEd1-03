#ifndef ARVORE_H
#define ARVORE_H

#include "percurso.h"
#include "posicao.h"

typedef struct no{
    Posicao pos;
    struct no* pai;
    struct no* direita;
    struct no* esquerda;
    struct no* cima;
    struct no* baixo;
    struct no* primo;
}No;
//node == nó
int arvoreInicia(No **pRaiz);

int arvoreInsere(No **ppRaiz, Posicao pos);

int arvoreLibera(No **node);

No* alocaVetor(int x);

int liberaVetor(No **vet);


int organizaEmNiveis(No *vet, No *node, int nivel);


int arvorePesquisaMenor(No **ppRaiz, Percurso *pTra, int i, Posicao *saida);

int arvorePesquisaMaior(No **node, Percurso *pTra, int i, Posicao *saida);

int alturaArvore(No *node);


int printEmNivel(No *vet, int x);


#endif // LABIRINTO_H
