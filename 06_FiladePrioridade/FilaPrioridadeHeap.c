#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaPrioridadeHeap.h" //inclui os Prot�tipos

struct fila_prioridade{
    int qtd;
    struct paciente dados[MAX];
};

FilaPrio* cria_FilaPrio(){
    FilaPrio *fp;
    fp = (FilaPrio*) malloc(sizeof(struct fila_prioridade));
    if(fp != NULL)
        fp->qtd = 0;
    return fp;
}

void libera_FilaPrio(FilaPrio* fp){
    free(fp);
}

int consulta_FilaPrio(FilaPrio* fp, char* nome){
    if(fp == NULL || fp->qtd == 0)
        return 0;
    strcpy(nome,fp->dados[0].nome);
    return 1;
}

void promoverElemento(FilaPrio* fp, int filho){
    int pai;
    struct paciente temp;
    pai = (filho - 1) / 2;
    while((filho > 0) && (fp->dados[pai].prio <= fp->dados[filho].prio)){
        temp = fp->dados[filho];
        fp->dados[filho] = fp->dados[pai];
        fp->dados[pai] = temp;

        filho = pai;
        pai = (pai - 1) / 2;
    }
}

int insere_FilaPrio(FilaPrio* fp, char *nome, int prioridade){
    if(fp == NULL)
        return 0;
    if(fp->qtd == MAX)//fila cheia
        return 0;
    /* insere na primeira posi��o livre */
    strcpy(fp->dados[fp->qtd].nome,nome);
    fp->dados[fp->qtd].prio = prioridade;
    /* desloca elemento para posi��o correta */
    promoverElemento(fp,fp->qtd);
    /* incrementa n�mero de elementos no heap */
    fp->qtd++;
    return 1;
}

void rebaixarElemento(FilaPrio* fp, int pai){
    struct paciente temp;
    int filho = 2 * pai + 1;
    while(filho < fp->qtd){

        if(filho < fp->qtd-1) /* verifica se tem 2 filhos */
            if(fp->dados[filho].prio < fp->dados[filho+1].prio)
                filho++; /*filho aponta para filho menor */

        if(fp->dados[pai].prio >= fp->dados[filho].prio)
            break; /* encontrou lugar */

        temp = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho];
        fp->dados[filho] = temp;

        pai = filho;
        filho = 2 * pai + 1;
    }
}

int remove_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return 0;
    if(fp->qtd == 0)
        return 0;

    fp->qtd--;
    fp->dados[0] = fp->dados[fp->qtd];
    rebaixarElemento(fp,0);
    return 1;
}

int tamanho_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return -1;
    else
        return fp->qtd;
}

int estaCheia_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return -1;
    return (fp->qtd == MAX);
}

int estaVazia_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return -1;
    return (fp->qtd == 0);
}

void imprime_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return;
    int i;
    
	printf("\n");
  	printf("%-4s %-12s %-12s\n", "#", "PRIORIDADE", 
	  "NOME");
  	printf("------------------------------------\n");   
	for(i=0; i < fp->qtd ; i++){
        printf("%-4d %-12d %-12s \n", (i+1), 
		fp->dados[i].prio,fp->dados[i].nome);
    }
}
//-------------------------------------------------------------------------

void promoverElementoMin(FilaPrio* fp, int filho){
    int pai;
    struct paciente temp;
    pai = (filho - 1) / 2;
    while((filho > 0) && (fp->dados[pai].prio >= fp->dados[filho].prio)){
        temp = fp->dados[filho];
        fp->dados[filho] = fp->dados[pai];
        fp->dados[pai] = temp;

        filho = pai;
        pai = (pai - 1) / 2;
    }
}

int insere_FilaPrioMin(FilaPrio* fp, char *nome, int prioridade){
    if(fp == NULL)
        return 0;
    if(fp->qtd == MAX)//fila cheia
        return 0;
    strcpy(fp->dados[fp->qtd].nome,nome);
    fp->dados[fp->qtd].prio = prioridade;
    promoverElementoMin(fp,fp->qtd);
    fp->qtd++;
    return 1;
}

void rebaixarElementoMin(FilaPrio* fp, int pai){
    struct paciente temp;
    int filho = 2 * pai + 1;
    while(filho < fp->qtd){

        if(filho < fp->qtd-1) /* verifica se tem 2 filhos */
            if(fp->dados[filho].prio > fp->dados[filho-1].prio)
                filho++; /*filho aponta para filho menor */

        if(fp->dados[pai].prio <= fp->dados[filho].prio)
            break; /* encontrou lugar */

        temp = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho];
        fp->dados[filho] = temp;

        pai = filho;
        filho = 2 * pai + 1;
    }
}

int remove_FilaPrioMin(FilaPrio* fp){
    if(fp == NULL)
        return 0;
    if(fp->qtd == 0)
        return 0;

    fp->qtd--;
    fp->dados[0] = fp->dados[fp->qtd];
    rebaixarElementoMin(fp,0);
    return 1;
}
