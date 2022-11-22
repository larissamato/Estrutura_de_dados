#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

//Definição do tipo Fila
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

//Definição do Nó Descritor da Fila
struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    
	printf("\n");
  	printf("%-4s %-4s %-10s %-4s %-4s %-4s\n", "#", "MAT", 
	  "NOME", "N1", "N2", "N3");
  	printf("------------------------------------\n");   
	
	int i=0;
	while(no != NULL){
        printf("%-4d %04d %-10s %-4.1f %-4.1f %-4.1f \n", ++i, 
		no->dados.matricula, no->dados.nome, no->dados.n1, 
		no->dados.n2, no->dados.n3);
        no = no->prox;
    }
}

//Questão 3 
void remove_reprovados(Fila* fi){
    if (fi == NULL)
        return;

    float media;
    Elem * no = fi->inicio;
    Elem * aux = fi->inicio;
    
    while(no != NULL){
        media = (no->dados.n1 + no->dados.n2 + no->dados.n3) / 3;
        if (media < 7 && no == fi->inicio){       
            fi->inicio = fi->inicio->prox;
            aux = NULL;
            fi->qtd--;
            aux = no;
            no = no->prox;
        }
        if (media < 7 && no == fi->final){
            fi->final = aux;
            aux->prox = NULL;
            printf("%d %d", &fi->final, &aux);
            fi->qtd--;
            no = NULL;
        }
        if (media < 7) {
            aux-> prox = no->prox;
            no = NULL;
            no = aux->prox;
            aux = no;
            no= no->prox;
        }

        else { 
            aux = no;
            no = no->prox;
        }
    }
}

void intercala_Fila (Fila *l1, Fila *l2, Fila *l3){
    if (l1==NULL || l2 == NULL || l3 == NULL)
        return;
    if (Fila_vazia(l1) || Fila_vazia(l2)){
            if (!Fila_vazia(l1))
                l3->inicio = l1->inicio;
                l3->final = l1->final;
                l3->qtd = l1->qtd;
            if (!Fila_vazia(l2))
                l3->inicio = l2->inicio;
                l3->final = l2->final;
                l3->qtd = l2->qtd;
        return;
    }
    
    l3->inicio = l1->inicio;
    l3->final = l1->final;
    l3->qtd = l1->qtd+l2->qtd;
    Elem *no = l3->inicio;
    while (no!= NULL) {
        if (no-> prox == NULL){
            no->prox = l2->inicio;
            l3->final = l2->final;
            return;
        }
        no = no->prox;
    }
}

void reverso_Fila (Fila *l1){
    if(l1 == NULL)
        return;
    Fila * reverso = cria_Fila();
    Elem * rev = reverso->inicio;
    Elem *no = l1->inicio;
    Elem *aux = l1->inicio;
    while (no !=NULL){
        reverso->inicio = no;
        if (rev == l1->inicio)
            rev->prox =NULL;
        else {
            rev->prox = aux;
        }
        aux = no;
        no = no->prox;
        printf("\nFILA REVERSA\n");
        imprime_Fila(reverso);

    }
}
