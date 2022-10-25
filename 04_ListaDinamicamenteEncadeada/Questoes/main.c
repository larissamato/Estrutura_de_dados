#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"
int main(){
    // Base
	struct produto p[4] = {
	{1,"bala",0.50,200},
	{2,"panela",50.00,7},
	{3,"camisa",5.00,90},
	{4,"lasanha",0.01,90}
	};

    struct produto p2[4] = {
	{1,"arroz",21.99,200},
	{2,"manteiga",19.90,7},
	{3,"leite ",4.99,90},
	{4,"água  ",1.50,90}
	};

	Lista* li = NULL;
	li = cria_lista();
    Lista* li2 = NULL;
	li2 = cria_lista();
	Lista* li3 =NULL;
    li3 = cria_lista();

	for(int i=0; i<4;i++)
		insere_lista_final(li,p[i]);

    for(int i=0; i<4;i++)
		insere_lista_final(li2,p2[i]);

	//imprime_lista(li);
    //imprime_lista(li2);
    //imprime_lista(li3);

    //Questão 2
    //printf ("\n-> TAMANHO DA LISTA: %d\n", tamanho_lista(li));

    //Questão 3 
    /*Lista endereco = endereco_elemento(li, 3);	  
	if (endereco != NULL) 
		printf("-> ENDEREÇO: %d\n", endereco); 
	else
		printf("Nao foi possivel retornar o endereco"); 

	Lista ant = endereco_ant_elemento(li, 3);	  
	if (ant != NULL) 
		printf("-> ENDEREÇO ANTERIOR: %d\n", ant); 
	else
		printf("Nao foi possivel retornar o endereco");*/ 
/*
    //Questão 4
    concatena(li,li2,li3);
    imprime_lista(li3);

	//Questão 5
	float n = menorPreco(li);
	printf ("-> MENOR PREÇO: %.2f\n", n);

	//Questão 6
	int tro = troca(li, 1, 3);
	if (tro==0)
		printf("Operação mal sucedida!\n");
	if (tro==1)
		printf("Operação bem sucedida!\n");
*/
	int tro = troca(li, 4,4);
	if (tro ==0){
	printf("\nNÃO FOI POSSÍVEL REALIZAR TROCA!\n");
	}else{
		printf("\n\n\t\t\tTROCA REALIZADA!\n");
		imprime_lista(li);
	}






	libera_lista(li);
	libera_lista(li2);
	libera_lista(li3);

}


//g++ *.c -o a.out.run


