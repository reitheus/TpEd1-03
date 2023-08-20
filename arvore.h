#ifndef ARVORE_H
#define ARVORE_H

#include "posicao.h"


typedef struct no{
    Posicao item;
    No *baixo;
    No *direita;
    No *cima;
    No *esquerda;
}No;

typedef No* Arvore;

void iniciaArvore(No**);



#endif//TAD Arvore.h