#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"
 

struct elemento {
	struct produto dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
	Lista* li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL)
		*li = NULL;
	return li;
}

void libera_lista(Lista* li){
	if (li != NULL){
		Elem* no;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free(li);
	}
}

int insere_lista_final(Lista* li, struct produto p){
	if(li == NULL)
		return 0;
	Elem *no;
	no=(Elem*) malloc(sizeof(Elem));
	if(no == NULL)
		return 0;
	no->dados = p;
	no->prox = NULL;
	//lista vazia
	if((*li) == NULL){
		*li = no;
	//lista não vazia	
	}else {
		Elem *aux;
		aux = *li;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = no;
	}
	return 1;
}

//Questão 5 
float menorPreco(Lista* li){
	if (li==NULL)
		return 0;

	if (*li == NULL)
		return 0;

	Elem* no = *li;
	float menor = 2.0;

	while(no!=NULL){
		if(no->dados.preco < menor)
		menor = no->dados.preco;
		 no = no->prox;
	}
	return menor;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;    
	int i=0;
	printf("\n");
  	printf("CÓDIGO  #  NOME  #  PREÇO  #  QUANTIDADE \n");
  	printf("------------------------------------\n");   
	
	
	while(no != NULL){
        printf("%-10d %-9s %-10.1f %-4d \n", 
		no->dados.codigo, no->dados.nome, no->dados.preco, 
		no->dados.qtde);
        no = no->prox;
    }
    printf("------------------------------------\n\n");
}