#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
#include <cstring>

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

int main(){
   struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    
	Pilha* pi = cria_Pilha();
    Pilha* pi_2 = cria_Pilha();

    int i;
    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);

    imprime_Pilha(pi);
    copiaPilha(pi, pi_2);
    imprime_Pilha(pi_2);
 
    libera_Pilha(pi);
    libera_Pilha(pi_2);
    system("pause");
    return 0;
}

