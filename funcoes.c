#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gerandoInterferencia(char **mensagem, unsigned int tamC, int tamI){
    int interferencia;
    int alteraPosI;
    int alteraPosJ;
    
    //for (int i = 0; i < tam; i++){
    //    printf("%c \n",mensagem[i]);
    //}
    srand( (unsigned)time(NULL) );
    interferencia = 1 + ( rand() % 10 );   //gera valores entre 1 e 10
    //printf("\n chance = %d\n",interferencia);
    if(interferencia<=5){ //50% de chance de gerar interferencia
        //pega uma posição aleatoria do vetor e muda o valor
        alteraPosI =  ( rand() % tamI );
        alteraPosJ =  ( rand() % tamC );

        //printf("\n altera posição i = %d e j = %d\n",alteraPosI,alteraPosJ);
        
        if (mensagem[alteraPosI][alteraPosJ]=='1'){
            mensagem[alteraPosI][alteraPosJ]='0';
        }else{
            mensagem[alteraPosI][alteraPosJ]='1';

        }
    }
    
    /* for (int i = 0; i < tam; i++){
        printf("%c \n",mensagem[i]);
    }*/

}
int ehPar(int aux){
    if((aux % 2)==0){
        return 0;
    }else{
        return 1;
    }
}

int paridadeLinha(char **mensagem, int linha,unsigned int tam){
    int aux=0;
    int pari;   
    //fprintf (stderr, "teste %d %d\n", linha, tam);
    for (int i = 0; i < tam; i++){
      //  fprintf(stderr,"teste\n");
        if(mensagem[linha][i]=='1'){
            aux++;
        }
    }
    pari=ehPar(aux);
    return pari;
}

int paridadeColuna(char** mensagem, int coluna,unsigned int tam){
    int aux=0;
    int pari;
    for (int i = 0; i < tam; i++){        
        if(mensagem[i][coluna]=='1'){
            aux++;
        }
    }
    pari=ehPar(aux);
    return pari;
}