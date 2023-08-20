#ifndef PERCURSO_H
#define PERCURSO_H

#include "posicao.h"

typedef struct {
    Posicao *trajetos;
    Posicao *mCaminho;
    Posicao *maiorCaminho;
    int mcom;
    int tamMaior;
    int tamTrajeto;
}Percurso;

Percurso* alocaPer(int );
void desalocaPer(Percurso** );
void updateTra(Percurso* , int, int, int);

#endif//percurso.h
