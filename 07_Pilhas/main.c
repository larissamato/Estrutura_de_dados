#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
#include <cstring>
/*
//Questão 2
int copiaPilha(Pilha* pi_1, Pilha* pi_2) {
	
	if (Pilha_vazia(pi_1))
		return 0;
		
	Pilha* aux = cria_Pilha();	
	
	struct aluno al;
	while(!Pilha_vazia(pi_1)) {
		consulta_topo_Pilha(pi_1, &al);
		remove_Pilha(pi_1);
		insere_Pilha(aux, al);
	}
	
	while(!Pilha_vazia(aux)) {
		consulta_topo_Pilha(aux, &al);
		remove_Pilha(aux);
		insere_Pilha(pi_1, al);
		insere_Pilha(pi_2, al);
	}
	
	libera_Pilha(aux);	
	return 1;
}

//Questão 3

//Questão 4
int verificaParentizacao(char* cadeia) {
	
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
*/
//Questão 5 
int verificaReverso(char* cadeia) {
	
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
   /* struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    
	Pilha* pi = cria_Pilha();
    
    int i;
    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);

    imprime_Pilha(pi);
*/



    char cadeia[30];
	strcpy(cadeia, "RENANNANER"); 
	
	if (verificaReverso(cadeia))
		printf("OKKKKKKKKKKKKKKKK");
	else
		printf("ERROOOOOOOOOOOO");
	
    printf("\n\n\n");/*
//-------------------------------------------------------------    
    char cadeia[30];
	strcpy(cadeia, "{{()}[()]}"); 
	
	if (testa_cadeia(cadeia))
		printf("OKKKKKKKKKKKKKKKK");
	else
		printf("ERROOOOOOOOOOOO");
//-----------------------------------------------------------------
struct caractere item;
   
    Pilha* pi = cria_Pilha();
    
    for(int i=65; i<72; i++) {
    	item.c = i;
    	insere_Pilha(pi, item);
	}
    
	imprime_Pilha(pi);
    altera_topo(pi, 7);
    imprime_Pilha(pi);
    //---------------------------------------------------------------		
	
	
    libera_Pilha(pi);
*/

    printf("\n\n\n");


    system("pause");
    return 0;
}

