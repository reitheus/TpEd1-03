#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "percurso.h"
#include "posicao.h"
#include "arvore.h"

typedef struct {
    char **mapa;
    char op;
    int tamL;
    int tamC;
    int v;
}Labirinto;

Labirinto* alocaLab(int, int );

void desalocaLab(Labirinto** );
int verificavazio(Labirinto* );
Labirinto* lelabirinto(char );



void printLab(Labirinto* );

void posMause(Labirinto*, Posicao* );

int achaSaidaArvore(Labirinto* pLab, Posicao *saida, Posicao *mause, Percurso *pTra, int i,Posicao *inicio, int achou, No **node);

Labirinto* imprimepercursoNolabirinto(Labirinto* ,Percurso* , Posicao*);

#endif//labirinto.h
