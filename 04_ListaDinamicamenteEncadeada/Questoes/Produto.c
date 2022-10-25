#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"
 
// ------------------------- Base -------------------------------
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

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
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

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;    
	int i=0;
	printf("\n");
  	printf("ENDEREÇO # CÓDIGO  #  NOME  #  PREÇO  #  QUANTIDADE \n");
  	printf("------------------------------------\n");   
	
	
	while(no != NULL){
        printf("%-10d %-10d %-9s %-10.1f %-4d \n",no, 
		no->dados.codigo, no->dados.nome, no->dados.preco, 
		no->dados.qtde);
        no = no->prox;
    }
    printf("------------------------------------\n\n");
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.codigo != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//não encontrado
        return 0;

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

//-------------------------- Exercícios ---------------------

//Questão 2
int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

//Questão 3 
Lista endereco_elemento(Lista* li, int pos) {
	
	if (lista_vazia(li) || pos < 1 || pos > tamanho_lista(li))
		return NULL;
	
	int i = 1;
	
	Elem* no = *li;
	while(i < pos) {
		no = no->prox;
		i++;
	}
		
	return no;
		
}

Lista endereco_ant_elemento(Lista* li, int pos) {
	
	if (lista_vazia(li) || pos < 1 || pos > tamanho_lista(li))
		return NULL;
	
    Elem *no = *li;
    while(no != NULL && no->dados.codigo < pos-1){
        no = no->prox;
    }

	return no;
		
}

// Questão 4
void concatena(Lista* li_1, Lista* li_2, Lista* li_3) {
	
	if (lista_vazia(li_1) || lista_vazia(li_2) ) {
	
		if (!lista_vazia(li_1)) 
			*li_3 = *li_1;			 
				
		if (!lista_vazia(li_2))
			*li_3 = *li_2;				 
				
		return;
	}
	
	int tam_l1 = tamanho_lista(li_1);
	Elem* p = endereco_elemento(li_1, tam_l1);
	Elem* q = *li_2;
	
	*li_3 = *li_1;		
	 p->prox = q;
	
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

//Questão 6
/*Escreva uma função que receba a posição de dois elementos de uma lista e os troque de lugar. A
função deve retornar se a operação foi possível ou não.*/
int troca(Lista* li, int pos1, int pos2){
	if (lista_vazia(li) || pos1 < 1 || pos1 > tamanho_lista(li) || pos2 < 1 || pos2 > tamanho_lista(li))
		return 0;

	Elem* p1 = endereco_elemento(li, pos1);
	Elem* p2 = endereco_elemento(li, pos2);
	Elem* ant1= endereco_ant_elemento(li,pos1);
	Elem* ant2= endereco_ant_elemento(li, pos2);

	Elem* no = *li;

	//Verifica começo e final da lista 
	if (p1->dados.codigo==1 && p2->prox ==NULL){
		*li = p2;
		p2->prox=p1->prox;
		ant2->prox=p1;
		p1->prox=NULL;
	}
	//Verifica começo e final da lista 
	else if (p2->dados.codigo==1 && p1->prox ==NULL){
		*li = p1;
		p1->prox=p2->prox;
		ant1->prox=p2;
		p2->prox=NULL;
	}
	//pos1 está no final da lista
	else if (p1->prox == NULL && p2->dados.codigo!=1){
		p1->prox=p2->prox;
		ant2->prox=p1;
		ant1->prox=p2;
		p2->prox = NULL;
	}

	//pos2 estiver no final da lista
	else if (p2->prox == NULL && p1->dados.codigo!=1){
		p2->prox=p1->prox;
		ant2->prox=p1;
		ant1->prox=p2;
		p1->prox = NULL;
	}

	//verifica se pos1 está no topo da lista
	 if (p1->dados.codigo==1 && p2->prox != NULL){
		if (p2->dados.codigo==2){
			*li=p2;
			p1->prox=p2->prox;
			p2->prox=p1;
			
		}else{
		*li=p2;
		p1->prox=p2->prox;
		ant2->prox=p1;
		p2->prox=ant2;
		}
	}

	//verifica se pos2 está no topo da lista 
	else if (p2->dados.codigo==1 && p1->prox != NULL){
		if (p1->dados.codigo==2){
			*li=p1;
			p2->prox=p1->prox;
			p1->prox=p2;

		}else{
			*li=p1;
			p2->prox=p1->prox;
			ant1->prox=p2;
			p1->prox=ant1;
		}
		
	}

    //Troca normal
	else if (pos1 < pos2 && p2->prox != NULL){

		p1->prox = p2->prox;
		ant1->prox=p2;
		p2->prox = p1;
	}

	//Troca normal
	else if ( pos1 > pos2 && p2->prox != NULL){

		p2->prox=p1->prox;
		ant2->prox=p1;
		p1->prox = p2;
	}

	else {
		return 0;
	}

	return 1;

}





