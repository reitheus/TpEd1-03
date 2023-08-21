#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "percurso.h"
#include "posicao.h"
#include "arvore.h"

#define TAM 51

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

Labirinto* lelabirintoInterface(const char str[TAM]);

Labirinto* lelabirinto(char );



void printLab(Labirinto* );

void posMause(Labirinto*, Posicao* );

int achaSaida(Labirinto*, Posicao* , Posicao* , Percurso* ,int ,Posicao* , int );

int achaSaidaArvore(Labirinto* pLab, Posicao *saida, Posicao *mause, Percurso *pTra, int i,Posicao *inicio, int achou, No **node);


Labirinto* imprimepercursoNolabirinto(Labirinto *plab,Percurso *pTra, Posicao *mause, No *vet, int altura);

#endif // LABIRINTO_H
