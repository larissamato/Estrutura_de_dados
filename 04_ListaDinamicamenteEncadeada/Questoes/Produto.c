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
  	printf("********************************************************\n"); 
	
	
	while(no != NULL){
        printf("%-10d %-10d %-9s %-10.1f %-4d \n",no, 
		no->dados.codigo, no->dados.nome, no->dados.preco, 
		no->dados.qtde);
        no = no->prox;
    }
	printf("********************************************************\n"); 
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

//QUESTÃO 2
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

//QUESTÃO 3 
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

// QUESTÃO 4
void concatena(Lista* li_1, Lista* li_2, Lista* li_3) {
	if (lista_vazia(li_1) || lista_vazia(li_2) ) {
		if (!lista_vazia(li_1)) 
			*li_3 = *li_1;			 
				
		if (!lista_vazia(li_2))
			*li_3 = *li_2;				 
				
		return;
	}
	int tam_l1 = tamanho_lista(li_1);

	Elem* q = *li_2;
	*li_3 = *li_1;	
	Elem* p = endereco_elemento(li_3, tam_l1);	
	 p->prox = q;	
}

//QUESTÃO 5 
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

//QUESTÃO 6
int troca(Lista* li, int pos1, int pos2){
	if (lista_vazia(li) || pos1 < 1 || pos1 > tamanho_lista(li) || pos2 < 1 || pos2 > tamanho_lista(li))
		return 0;

	Elem* p1 = endereco_elemento(li, pos1);
	Elem* p2 = endereco_elemento(li, pos2);
	Elem* ant1= endereco_ant_elemento(li,pos1);
	Elem* ant2= endereco_ant_elemento(li, pos2);

	//Verifica se não há trocas
	if (pos1==pos2){
		return 0;
	}
	//Verifica começo e final da lista 
	else if (p1->dados.codigo==1 && p2->prox ==NULL){
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
		if(ant1==p2){
			ant2->prox=p1;
			p1->prox=p2;
			p2->prox=NULL;
		}else{
			p1->prox=p2->prox;
			ant2->prox=p1;
			ant1->prox=p2;
			p2->prox = NULL;
		}
	}
	//pos2 estiver no final da lista
	else if (p2->prox == NULL && p1->dados.codigo!=1){
		if (ant2==p1){
			ant1->prox=p2;
			p2->prox=p1;
			p1->prox=NULL;
			
		}else{
			p2->prox=p1->prox;
			ant1->prox=p2;
			ant2->prox=p1;
			p1->prox = NULL;
		}
	}
	//verifica se pos1 está no topo da lista
	else if (p1->dados.codigo==1 && p2->prox != NULL){
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
	
	return 1;

}

//QUESTÃO 7
void divide(Lista* li, Lista* li2, int par){
	if (lista_vazia(li) || par < 1 || par > tamanho_lista(li)) {
		return;
	}
	Elem* l1 = endereco_elemento(li, par);
	Elem* l2 = endereco_elemento(li, par+1);
	l1->prox=NULL;
	*li2= l2;

}

//QUESTÃO 8
void troca_dados(Lista* li, int i, int j){
	if (lista_vazia(li) || i < 1 || i > tamanho_lista(li) || j < 1 || j > tamanho_lista(li))
		return;

	Lista* controle = cria_lista();
    struct produto contr = {1,"bala",0.50,200};
    insere_lista_final(controle,contr); 

	Elem* p1 = endereco_elemento(li, i);
	Elem* p2 = endereco_elemento(li, j);
	Elem* p3 = endereco_elemento(controle,1);

	p3->dados=p2->dados;
	p2->dados= p1->dados;
	p1->dados = p3->dados;

	libera_lista(controle);
}

/*//QUESTÃO 9
int troca_elemento(Lista* li, int elem1, int elem2){
	if (lista_vazia(li) || elem1 < 1 || elem1 > tamanho_lista(li) || elem2 < 1 || elem2 > tamanho_lista(li))
		return 0;

	Elem* p1 = endereco_elemento(li, elem1);
	Elem* p2 = endereco_elemento(li, elem2);
	Elem* ant1= endereco_ant_elemento(li,elem1);
	Elem* ant2= endereco_ant_elemento(li, elem2);

	//Verifica se não há trocas
	if (elem1==elem2){
		return 0;
	}
	//Verifica começo e final da lista 
	else if (p1->dados.codigo==1 && p2->prox ==NULL){
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
		if(ant1==p2){
			ant2->prox=p1;
			p1->prox=p2;
			p2->prox=NULL;
		}else{
			p1->prox=p2->prox;
			ant2->prox=p1;
			ant1->prox=p2;
			p2->prox = NULL;
		}
	}
	//pos2 estiver no final da lista
	else if (p2->prox == NULL && p1->dados.codigo!=1){
		if (ant2==p1){
			ant1->prox=p2;
			p2->prox=p1;
			p1->prox=NULL;
			
		}else{
			p2->prox=p1->prox;
			ant1->prox=p2;
			ant2->prox=p1;
			p1->prox = NULL;
		}
	}
	//verifica se pos1 está no topo da lista
	else if (p1->dados.codigo==1 && p2->prox != NULL){
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
	else if (elem1 < elem2 && p2->prox != NULL){
		p1->prox = p2->prox;
		ant1->prox=p2;
		p2->prox = p1;
	}
	//Troca normal
	else if ( elem1 > elem2 && p2->prox != NULL){
		p2->prox=p1->prox;
		ant2->prox=p1;
		p1->prox = p2;
	}
	
	return 1;

}
*/
//Questão 10 
int insere_lista_ordenada(Lista* li, struct produto pro){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = pro;
    if((*li) == NULL){
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.codigo < pro.codigo){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}





