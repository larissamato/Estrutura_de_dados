#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDin.h"

int testaReverso(char* cadeia) {
	
	int tam = strlen(cadeia);
	
	if ( (tam == 0) || ((tam%2) != 0)  )
		return 0;
	
	
    struct caractere item;
   
    Pilha* pi = cria_Pilha(); 	   
	
	for(int i=0; i<tam; i++) {
		item.c = cadeia[i];
		insere_Pilha(pi, item);		
	}
	
	Pilha* aux = cria_Pilha(); 
	
	int metade = tam / 2;
	for(int i=0; i<metade; i++) {		
		consulta_topo_Pilha(pi, &item);
		remove_Pilha(pi);
		insere_Pilha(aux, item);		
	}

	struct caractere item2;
	while(!Pilha_vazia(pi)) {
		
		consulta_topo_Pilha(pi, &item);
		remove_Pilha(pi);
		
		consulta_topo_Pilha(aux, &item2);
		remove_Pilha(aux);
		
		if (item.c != item2.c)
			break;				
	}
	
	int retorno = 0;
	if ( (Pilha_vazia(pi)) && (item.c == item2.c) ) {
		retorno = 1;
	}

	libera_Pilha(pi);	
	libera_Pilha(aux);
	
	return retorno;
	
}

int main(){
    
	char x[30];
	strcpy(x, "ABCD"); 
    char y[30];
    strcpy(y, "DCBA");
    char cadeia[30];
    strcpy(cadeia, strcat(x,y));
    printf("%s\n", cadeia);

	if (testaReverso(cadeia))
		printf("Tudo certo!");
	else
		printf("III Perdeu!");
	
    printf("\n\n\n");
     
    system("pause");
    return 0;
}

