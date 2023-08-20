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
}No;

int arvoreInicia(No **pRaiz);

int arvoreInsere(No **ppRaiz, Posicao pos);

int arvoreLibera(No **node);

int arvorePesquisaMenor(No **ppRaiz, Percurso *pTra, int i, Posicao *saida);

int arvorePesquisaMaior(No **node, Percurso *pTra, int i, Posicao *saida);


#endif//arvore.h
