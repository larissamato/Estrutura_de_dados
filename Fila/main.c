#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

void intercala(Fila* fi_1, Fila* fi_2, Fila* fi_3) {
		
	if ( (Fila_vazia(fi_1)) && (Fila_vazia(fi_2)) ) {
		return;
	}
	
	struct aluno al;
	
	while  ( (!Fila_vazia(fi_1)) && (!Fila_vazia(fi_2)) ) {			
		consulta_Fila(fi_1, &al);
		remove_Fila(fi_1);
		insere_Fila(fi_3, al);						
		
		consulta_Fila(fi_2, &al);
		remove_Fila(fi_2);
		insere_Fila(fi_3, al);				
	}
	
	while(!Fila_vazia(fi_1)) {
		consulta_Fila(fi_1, &al);
		remove_Fila(fi_1);
		insere_Fila(fi_3, al);
	}
	
	while(!Fila_vazia(fi_2)) {
		consulta_Fila(fi_2, &al);
		remove_Fila(fi_2);
		insere_Fila(fi_3, al);
	}

}

void fila_aprovados(Fila* fi_1, Fila* fi_2) {
	
	if (Fila_vazia(fi_1))  {
		return;
	}
	
	struct aluno al;
	
	Fila* fi_aux = cria_Fila();
	// Inserindo os aprovados
	while(!Fila_vazia(fi_1)) {
		consulta_Fila(fi_1, &al);
		remove_Fila(fi_1);
		insere_Fila(fi_aux, al);
		
		if (al.n1 >= 6) {		
			insere_Fila(fi_2, al);
		}	
	}
	
	//Reconstruindo fila original
	while(!Fila_vazia(fi_aux)) {
		consulta_Fila(fi_aux, &al);
		remove_Fila(fi_aux);
		insere_Fila(fi_1, al);
	}	
	
}


int main(){
    struct aluno al,a[4] = {{2,"A",8,0,0},
                         {4,"B",1,0,0},
                         {1,"C",4,0,0},
                         {3,"D",9,0,0}};
                         
	struct aluno b[7] = {{2,"Z",2,0,0},
                         {4,"Y",3,0,0},
                         {1,"K",7,0,0},
                         {3,"W",5,0,0},
						 {3,"U",9,0,0},
						 {3,"I",8,0,0},
						 {3,"O",1,0,0}};
                         
    
	Fila* fi = cria_Fila();
    int i;
    for(i=0; i < 4; i++){
        insere_Fila(fi,a[i]);        
    }
    imprime_Fila(fi); 
    
    Fila* fi_2 = cria_Fila();   
    for(i=0; i < 7; i++){
        insere_Fila(fi_2,b[i]);        
    }
    imprime_Fila(fi_2);
	
	printf("\n--------------\n");   
	
	Fila* fi_3 = cria_Fila();
	intercala(fi, fi_2, fi_3);
	
	imprime_Fila(fi);
	imprime_Fila(fi_2);
	imprime_Fila(fi_3);
	
	////////////////////////
	
	Fila* fi_4 = cria_Fila();
	fila_aprovados(fi_3, fi_4);
	imprime_Fila(fi_4);
	
	printf("\n*****************\n");
	imprime_Fila(fi_3);
    
    libera_Fila(fi);
    system("pause");
    return 0;
}


