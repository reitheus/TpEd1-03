#include <stdio.h>
#include "labirinto.h"
#include "percurso.h"
#include "posicao.h"
#include "arvore.h"

int main(){

    //inicio do Programa
    // alocação e atribuição para as variaveis principais e de controle
    char opcao=' ';
    int valida=1;
    int achou = 0;
    Percurso *pTra;
    
    Posicao *inicio = alocaPos();//aloca o inicio
    Posicao *saida = alocaPos();//aloca a posição para saida
    Posicao *mause = alocaPos();//aloca uma posição para o rato
    Labirinto *pLab;
    No *arvore;
    
    //leitura do terminal
    pLab = lelabirinto(opcao);
    printf("\n"); 
    
    //atualização das posições e execução do programa
    posMause(pLab, mause);
    updatePos(inicio, valueY(mause), valueX(mause));  
    updatePos( saida, pLab->tamL - 2, pLab->tamC - 2);
    pTra = alocaPer(pLab->v);
    
    arvoreInicia(&arvore);
    arvoreInsere(&arvore, *mause);
    valida = achaSaidaArvore(pLab, saida, mause, pTra,0, inicio, achou, &arvore);
    arvorePesquisaMenor(&arvore, pTra, 0, saida);
    arvorePesquisaMaior(&arvore, pTra, 0, saida);
    
    //impressão da saida
    if(valida == 1){

        pLab = imprimepercursoNolabirinto(pLab,pTra, mause);
        
    }else if(valida != 1){
        
        printf("EPIC FAIL\n");
    }
    
    //desalocação da memoria
    arvoreLibera(&arvore);
    desalocaPos(&inicio);
    desalocaPos(&mause); 
    desalocaPos(&saida);
    desalocaPer(&pTra);
    desalocaLab(&pLab);
    
    //fim do Programa
    return 0;
}
