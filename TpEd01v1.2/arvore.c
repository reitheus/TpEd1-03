#include <stdio.h>
#include <stdlib.h>
#include "percurso.h"
#include "posicao.h"
#include "arvore.h"

//node == nó

// typedef struct no{
//     Posicao pos;
//     struct no* pai;
//     struct no* direita;
//     struct no* esquerda;
//     struct no* cima;
//     struct no* baixo;
// }No;


int arvoreInicia(No **pRaiz ){
    *pRaiz = NULL;
    // pRaiz->pai = NULL;
    // pRaiz->direita = NULL;
    // pRaiz->esquerda = NULL;
    // pRaiz->cima = NULL;
    // pRaiz->baixo = NULL;

    return 1;
}

//Libera toda a arvore recursivamente
int arvoreLibera(No **node){



    if( *node == NULL){
        return 1;

    }


    No *aux1;
    No *aux2;
    No *aux3;
    No *aux4;

    aux1 = (*node)->direita;
    aux2 = (*node)->esquerda;
    aux3 = (*node)->cima;
    aux4 = (*node)->baixo;

    free(*node);

    arvoreLibera(&aux1);
    arvoreLibera(&aux2);
    arvoreLibera(&aux3);
    arvoreLibera(&aux4);

    return 1;
}

No* alocaVetor(int x){
    No *vet = (No*)malloc(x * sizeof(No));

    return vet;
}

int liberaVetor(No **vet){
    free(*vet);
    return 1;

}

int insereVetor(No *nodeInsert, No *node){
    
    if(nodeInsert->primo == NULL){
        nodeInsert->primo = node;
        return 1;
    }else{
        insereVetor(nodeInsert->primo, node);
    }
    
    return 1;

}

int organizaEmNiveis(No *vet, No *node, int nivel){
    
    if(node == NULL){
        return 1;
    }

    insereVetor(&vet[nivel], node);

    organizaEmNiveis(vet, node->cima, nivel + 1);
    organizaEmNiveis(vet, node->baixo, nivel + 1);
    organizaEmNiveis(vet, node->direita, nivel + 1);
    organizaEmNiveis(vet, node->esquerda, nivel + 1);



    return 1;
}

No* NoCria(Posicao pos){

    No *pAux = (No*)malloc(sizeof(No));
    pAux->pos = pos;
    pAux->pai = NULL;
    pAux->direita = NULL;
    pAux->baixo = NULL;
    pAux->esquerda = NULL;
    pAux->cima = NULL;
    pAux->primo = NULL;

    return pAux;

}


int arvoreInsere(No **ppRaiz, Posicao pos){
    if(*ppRaiz == NULL){
        *ppRaiz = NoCria(pos);
        return 1;

    }

    return 0;
}


int arvorePesquisaMenor(No **node, Percurso *pTra, int i, Posicao *saida){


    if( *node == NULL){
        return 1;
    }

    //inicia a posição do mause na raiz da arvore.
    Posicao mause;
    mause.x = (*node)->pos.x;
    mause.y = (*node)->pos.y;

    updateTra(pTra,i ,mause.x, mause.y);

    if (mause.y == valueY(saida) && mause.x == valueX(saida)){

        if(i < pTra->mcom){
            pTra->mcom = i;
            for(int j=0;j < pTra->mcom;j++){
            	
                pTra->mCaminho[j] = pTra->trajetos[j];
            	
            }
            
        }
        return 1;//se o rato acha a saida retorna 1
    }

    arvorePesquisaMenor(&((*node)->direita), pTra, i + 1, saida);

    arvorePesquisaMenor(&((*node)->cima), pTra, i + 1, saida);

    arvorePesquisaMenor(&((*node)->baixo), pTra, i + 1, saida);

    arvorePesquisaMenor(&((*node)->esquerda), pTra, i + 1, saida);
    
    return 1;

}



int arvorePesquisaMaior(No **node, Percurso *pTra, int i, Posicao *saida){

    
    if( *node == NULL){
        
        return 1;

    }



    //inicia a posição do mause na raiz da arvore.
    Posicao mause;
    mause.x = (*node)->pos.x;
    mause.y = (*node)->pos.y;

    updateTra(pTra,i ,mause.x, mause.y);

    if (mause.y == valueY(saida) && mause.x == valueX(saida)){
        
        if(i > pTra->tamMaior){
            
            pTra->tamMaior = i+1;
            for(int j=0;j < pTra->tamMaior;j++){
            	
                pTra->maiorCaminho[j] = pTra->trajetos[j];
            	
            }
            
        }
        return 1;//se o rato acha a saida retorna 1
    }




    arvorePesquisaMaior(&((*node)->direita), pTra, i + 1, saida);

    arvorePesquisaMaior(&((*node)->cima), pTra, i + 1, saida);

    arvorePesquisaMaior(&((*node)->baixo), pTra, i + 1, saida);

    arvorePesquisaMaior(&((*node)->esquerda), pTra, i + 1, saida);

    return 1;

}


int alturaArvore(No *node){

    int iCima, iDireita, iEsquerda, iBaixo;

    if( node == NULL){
        
        return 0;

    }

    iDireita = alturaArvore(node->direita);

    iCima = alturaArvore(node->cima);

    iBaixo = alturaArvore(node->baixo);

    iEsquerda = alturaArvore(node->esquerda);

    if(iDireita > iCima && iDireita > iBaixo && iDireita > iEsquerda){

        return iDireita + 1;

    }else if(iCima > iDireita && iCima > iBaixo && iCima > iEsquerda){

        return iCima + 1;

    }else if(iBaixo > iDireita && iBaixo > iCima && iBaixo > iEsquerda){
        return iBaixo + 1;

    }else{
        return iEsquerda + 1;

    }
    
    return 0;

}


int printEmNivel(No *vet, int x){
    No *aux;
    for(int i = 0; i < x; i++){
        printf("\nNivel %i:\n", i + 1);
        aux = vet[i].primo;
        while(aux != NULL){
            printf("(%i, %i) ", aux->pos.y, aux->pos.x - 1);
            aux = aux->primo;
        }

    }
    return 1;
}