#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDin.h"

void Reverso(char* cadeia) {
	
	int tam = strlen(cadeia);
	
	if ( (tam == 0) || ((tam%2) != 0)  )
		return;
	
    struct caractere item;
    char cadeiainversa[30];
    Pilha* pi = cria_Pilha(); 	   
	
	for(int i=0; i<tam; i++) {
		item.c = cadeia[i];
		insere_Pilha(pi, item);		
	}
	for(int i=0; i<tam; i++) {
		consulta_topo_Pilha(pi, &item);
		remove_Pilha(pi);
        cadeiainversa[i]= item.c;
	}
    strcpy(cadeia,cadeiainversa);

	libera_Pilha(pi);	
}

int main(){
    
    char cadeia[30];
    strcpy(cadeia, "INSTITUTO FEDERAL DE GOIAS");

	Reverso(cadeia);
	printf("%s", cadeia);
    printf("\n\n\n");
     
    system("pause");
    return 0;
}

