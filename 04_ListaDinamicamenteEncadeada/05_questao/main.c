#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"
int main(){

	struct produto p[4] = {
	{1,"seda",0.50,4},
	{2,"panela",50.00,7},
	{3,"camisa",5.00,90},
	{4,"camisa",0.01,90}
	};

	Lista* li = NULL;
	li = cria_lista();
	
	for(int i=0; i<4;i++)
		insere_lista_final(li,p[i]);

	imprime_lista(li);

	//Questão 5
	float n = menorPreco(li);
	printf ("-> Preço %.2f\n", n);
}


//g++ *.c -o a.out.run


