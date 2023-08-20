#include <stdio.h>
#include <stdlib.h>

#include "posicao.h"

//Função de alocaçãod de Posição
Posicao* alocaPos(){
    Posicao* newpos = (Posicao*)malloc(sizeof(Posicao));
    return newpos;
}

//Função de desalocação de Posição
void desalocaPos(Posicao** ppos){
    free(*ppos);
}

//Função de atribuição para x e y de posicao    
void updatePos(Posicao* posicao, int y, int x){
    
    posicao->y = y;
    posicao->x = x;
}

//Função pega uma posição e retorna o seu valor x
int valueX(Posicao* posicao){

    return posicao->x;
}

//Função pega uma posição e retorna o seu valor y
int valueY(Posicao* posicao){

    return posicao->y;
}
