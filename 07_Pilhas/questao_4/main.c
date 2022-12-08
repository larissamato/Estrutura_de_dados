#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDin.h"

/*
Correto: ( ( ( ) ) )
*/

int testa_cadeia(char* cadeia) {
	
	int tam = strlen(cadeia);
	
	if ( (tam == 0) || ((tam%2) != 0)  )
		return 0;
		
    struct caractere item;
   
    Pilha* pi = cria_Pilha(); 	   
	
	for(int i=0; i<tam; i++) {
		
		if ( (cadeia[i] == '(') || (cadeia[i] == '[') || (cadeia[i] == '{') ) {
			item.c = cadeia[i];
			insere_Pilha(pi, item);
		} else {
			consulta_topo_Pilha(pi, &item);
			
			if ( (cadeia[i] == ')' && item.c == '(') ||  (cadeia[i] == ']' && item.c == '[') || (cadeia[i] == '}' && item.c == '{')) {
				remove_Pilha(pi);
			}
			else {
				break;
			}
		
		}	
			
	}
	
	int retorno = 0;
	if (Pilha_vazia(pi)) 
		retorno = 1;
	
	libera_Pilha(pi);	
		
	return retorno;
	
}

int main(){
    
	char cadeia[30];
	strcpy(cadeia, "{{()}[()]}"); 
	
	if (testa_cadeia(cadeia))
		printf("Parentização correta");
	else
		printf("Parentização incorreta");
		
	
	
    printf("\n\n\n");
        
    system("pause");
    return 0;
}

