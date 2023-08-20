#include <stdio.h>
#include <stdlib.h>

#include "percurso.h"
#include "posicao.h"


//Função de alocação do percurso
Percurso* alocaPer(int x){

    Percurso* newper = (Percurso*)malloc(sizeof(Percurso));
    newper->tamTrajeto = x;
    newper->mCaminho = (Posicao*) malloc (newper->tamTrajeto * sizeof(Posicao));
    newper->maiorCaminho = (Posicao*) malloc (newper->tamTrajeto * sizeof(Posicao));
    newper->trajetos = (Posicao*) malloc (newper->tamTrajeto * sizeof(Posicao));
    newper->mcom = x;
    newper->tamMaior = -100;
    return newper;
}

//Função de atualização do trajeto, com a atribuição de posx e posy a um ponto do vetor de posição.
void updateTra(Percurso *newper, int i, int posy, int posx){
    
    newper->trajetos[i].x = posx;
    newper->trajetos[i].y = posy;
    
}

//Função de desalocação de percurso
void desalocaPer(Percurso** pTra){
    
    free((*pTra)->trajetos);
    free((*pTra)->mCaminho);
    free(*pTra);
}
