/*  - Thauan de Souza Tavares da Silva
    - GRR20171591
*/
/*PARA MELHOR ENTENDIMENTO LER ARQUIVO "LEIA-ME"*/
/*TRABALHO 2 para identificação de erros e correção metodo utilizado: Paridade*/

#include <stdio.h>
#include <stdlib.h>

#include "funcoes.h"


int main(){
    unsigned int tamanho;
    unsigned int linhas;
    char **mensagem;
    int *pariMenEnvLinha;
    int *pariMenEnvColuna;

    int *pariMenRecLinha;
    int *pariMenRecColuna;


    //int *pariMensagemRecebida;
    
    printf("\nDigite a quantidade de linhas (linha>=2)\n");
    scanf("%d",&linhas);

    printf("\nDigite o tamanho da mensagem\n");
    scanf("%d",&tamanho);
    
    mensagem=(char**) malloc((linhas)*sizeof(char *));
    for (int i = 0; i < linhas ; i++){
        mensagem[i]=(char*) malloc((linhas)*sizeof(char ));

    }

    for ( int i = 0; i < linhas; i++){
        printf("\n %dº linha da mensagem sem espaço entre os bits Ex:111 \n\n",i+1);
        
        /*for (int j = 0; j < tamanho; j++){
            scanf("%c",&mensagem[i][j]);
        }*/
        //printf("\n");
        fscanf(stdin,"%s",mensagem[i]);

    }
    

    printf("\n Mensagem Digitada\n\n");
    
    for ( int i = 0; i < linhas; i++){
        for (int j = 0; j < tamanho; j++){
           printf("%c ",mensagem[i][j]);
        }
        printf("\n");
    }

    pariMenEnvLinha=(int*) malloc((linhas)*sizeof(int ));//i fixo varia o j para achar a paridade
    pariMenEnvColuna=(int*) malloc((tamanho)*sizeof(int ));//j fixo varia o i para achar a paridade
    
    pariMenRecLinha =(int*) malloc((linhas)*sizeof(int ));//i fixo varia o j para achar a paridade
    pariMenRecColuna=(int*) malloc((tamanho)*sizeof(int ));//j fixo varia o i para achar a paridade

    /*CALCULA A PARIDADE DA MENSAGEM*/
    for ( int i = 0; i < linhas; i++){
        pariMenEnvLinha[i]=paridadeLinha(mensagem,i,tamanho);
    }
    
    for ( int i = 0; i < tamanho; i++){
        pariMenEnvColuna[i]=paridadeColuna(mensagem,i,linhas);
    }

   /*printf("\nCOLUNA\n");
    
    for ( int i = 0; i < tamanho; i++){
        printf(" %d",pariMenEnvColuna[i]);
    }
        printf("\n");
    printf("\nLINHA\n");
    for ( int i = 0; i < linhas; i++){
        printf(" %d",pariMenEnvLinha[i]);
    }

        printf("\n");*/

    

    gerandoInterferencia(mensagem,tamanho,linhas);//simula uma interferencia alterando o valor 
    
    printf("\n Mensagem que chegou\n\n");

    for ( int i = 0; i < linhas; i++){
        for (int j = 0; j < tamanho; j++){
           printf("%c ",mensagem[i][j]);
        }
        printf("\n");
    }


    for ( int i = 0; i < linhas; i++){
        pariMenRecLinha[i]=paridadeLinha(mensagem,i,tamanho);
    }
    
    for ( int i = 0; i < tamanho; i++){
        pariMenRecColuna[i]=paridadeColuna(mensagem,i,linhas);
    }

    /*printf("\nREC COLUNA\n");


    for ( int i = 0; i < tamanho; i++){
        printf(" %d",pariMenRecColuna[i]);
    }
        printf("\n");
    printf("\nREC LINHA\n");
    for ( int i = 0; i < linhas; i++){
        printf(" %d",pariMenRecLinha[i]);
    }
        printf("\n");*/

    int linhaOk=-1;
    int colunaOk=-1;

    for (int i = 0; i < linhas; i++){
        if(pariMenEnvLinha[i] != pariMenRecLinha[i]){
            linhaOk=i;
        }
    }
    for (int i = 0; i < tamanho; i++){
        //printf("ParimenEnvColuna[%d]=%d\n ParimenRECColuna[%d]=%d\n",i,pariMenEnvColuna[i],i,pariMenRecColuna[i]);
        if(pariMenEnvColuna[i] != pariMenRecColuna[i]){
           // printf("\nENTREEEI\n");
            colunaOk=i;
        }
    }
   
    printf("\n Verificando Integridade\n\n");

    if((linhaOk != -1) && (colunaOk)!=-1){
        printf("\n Erro detectado na mensagem!\n");
        printf("\n Erro identificado na posição linha = %d coluna= %d\n",linhaOk,colunaOk);
        printf("\n Corrigindo Erro\n");
        
        if(mensagem[linhaOk][colunaOk]=='1'){
            mensagem[linhaOk][colunaOk]='0';
            linhaOk=-1;
            colunaOk=-1;
         }else{
            mensagem[linhaOk][colunaOk]=='1';
            linhaOk=-1;
            colunaOk=-1;
        }
    }else{
        printf("\n Mensagem sem Erro!\n\n");

    }

    
    if((linhaOk == -1) && (colunaOk)==-1){
        printf("\n Mensagem Recebida com Sucesso!!!\n\n");
        for ( int i = 0; i < linhas; i++){
            for (int j = 0; j < tamanho; j++){
               printf("%c ",mensagem[i][j]);
            }
        printf("\n");
        }
    }
    
    
    
}