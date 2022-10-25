#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"
int main(){
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
	Lista* li4 =NULL;
    li4 = cria_lista();
	Lista* li5 =NULL;
    li5 = cria_lista();
	Lista* li6 =NULL;
    li6 = cria_lista();
	
	for(int i=0; i<4;i++)
		insere_lista_final(li,p[i]);

    for(int i=0; i<4;i++)
		insere_lista_final(li2,p2[i]);

	for(int i=0; i<4;i++)
		insere_lista_final(li4,p2[i]);
	
	for(int i=0; i<4;i++)
		insere_lista_final(li6,p[i]);

    //Questão 2
	printf("\n----------------------- QUESTÃO 2 -----------------------------\n");
    printf ("-> TAMANHO DA LISTA: %d", tamanho_lista(li));
	printf("\n---------------------------------------------------------------\n\n");

    //Questão 3
	printf("\n----------------------- QUESTÃO 3 -----------------------------\n"); 
    Lista endereco = endereco_elemento(li, 3);	  
	if (endereco != NULL) 
		printf("-> ENDEREÇO: %d\n", endereco); 
	else
		printf("Nao foi possivel retornar o endereco"); 

	Lista ant = endereco_ant_elemento(li, 3);	  
	if (ant != NULL) 
		printf("-> ENDEREÇO ANTERIOR: %d", ant); 
	else
		printf("Nao foi possivel retornar o endereco");
	printf("\n---------------------------------------------------------------\n\n");

    //Questão 4
	printf("\n----------------------- QUESTÃO 4 -----------------------------\n");
    concatena(li,li2,li3);
    imprime_lista(li3);
	printf("\n---------------------------------------------------------------\n\n");

	//Questão 5
	printf("\n----------------------- QUESTÃO 5 -----------------------------\n");
	float n = menorPreco(li);
	printf ("-> MENOR PREÇO: %.2f", n);
	printf("\n---------------------------------------------------------------\n\n");

	//Questão 6
	printf("\n----------------------- QUESTÃO 6 -----------------------------\n");
	int tro = troca(li2, 1,4);
	if (tro ==0){
	printf("\nNÃO FOI POSSÍVEL REALIZAR TROCA!\n");
	}else{
		printf("TROCA REALIZADA!\n");
		imprime_lista(li2);
	}
	printf("\n---------------------------------------------------------------\n\n");


	//Questão 7
	printf("\n----------------------- QUESTÃO 7 -----------------------------\n");
	divide(li4,li5, 2); 
	imprime_lista(li4);
	imprime_lista(li5);
	printf("\n---------------------------------------------------------------\n\n");

	//Questão 8
	printf("\n----------------------- QUESTÃO 8 -----------------------------\n");
	troca_dados(li6,2,4);
	imprime_lista(li6);
	printf("\n---------------------------------------------------------------\n\n");

	/*//Questão 9 - OBS não entendi a dferença do 9 para o 6, então deixei o mesmo código
	printf("\n----------------------- QUESTÃO 9 -----------------------------\n");
	int elem = troca_elemento(li2, 2,2);
	if (elem==0){
	printf("\nNÃO FOI POSSÍVEL REALIZAR TROCA!\n");
	}else{
		printf("\n\n\t\t\tTROCA REALIZADA!\n");
		imprime_lista(li2);
	}
	printf("\n---------------------------------------------------------------\n\n");
	*/

	//Questão 10
	printf("\n----------------------- QUESTÃO 10 -----------------------------\n");
	Lista* ordenada = cria_lista();
    struct produto pro1= {1,"arroz",21.99,200};
	struct produto pro2= {2,"arroz",21.99,200};
	struct produto pro3= {3,"arroz",21.99,200};
    insere_lista_ordenada(ordenada,pro1); 
	insere_lista_ordenada(ordenada,pro3);
	insere_lista_ordenada(ordenada,pro2);  
	imprime_lista(ordenada);
	printf("\n---------------------------------------------------------------\n\n");

	libera_lista(li);
	libera_lista(li2);
	libera_lista(li3);
	libera_lista(li4);
	libera_lista(li5);
	libera_lista(li6);
}
//g++ *.c -o a.out.run


