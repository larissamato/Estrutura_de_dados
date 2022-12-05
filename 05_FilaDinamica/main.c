#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

//Questão 1 
/*
a) Sua estrutura de dados se baseia em que o primeiro item inserido será o primeiro removido
b) São utilizadas em situações do mundo real, como por exemplo fila de impressora
*/

//Questão 2
//3 7 2 4
    
//Questão 3
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
		
		if (al.n1 >= 6)		
			insere_Fila(fi_2, al);	
	}
	
	//Reconstruindo fila original
	while(!Fila_vazia(fi_aux)) {
		consulta_Fila(fi_aux, &al);
		remove_Fila(fi_aux);
		insere_Fila(fi_1, al);
	}	
}

//Questão 4
void intercala(Fila* fi_1, Fila* fi_2, Fila* fi_3) {
		
	if ( (Fila_vazia(fi_1)) && (Fila_vazia(fi_2)) ) {
		return;
	}
	
	struct aluno al;
	Fila* aux_fi_1 = cria_Fila();
    Fila* aux_fi_2 = cria_Fila();
    
    //Intercalando 
	while  ( (!Fila_vazia(fi_1)) && (!Fila_vazia(fi_2)) ) {			
		consulta_Fila(fi_1, &al);
		remove_Fila(fi_1);
        insere_Fila(aux_fi_1, al);
		insere_Fila(fi_3, al);						
		consulta_Fila(fi_2, &al);
		remove_Fila(fi_2);
        insere_Fila(aux_fi_2, al);
		insere_Fila(fi_3, al);				
	}
	
	while(!Fila_vazia(fi_1)) {
		consulta_Fila(fi_1, &al);
		remove_Fila(fi_1);
        insere_Fila(aux_fi_1, al);
		insere_Fila(fi_3, al);
	}
	
	while(!Fila_vazia(fi_2)) {
		consulta_Fila(fi_2, &al);
		remove_Fila(fi_2);
        insere_Fila(aux_fi_2, al);
		insere_Fila(fi_3, al);
	}

	//Reconstruindo filas originais
    while(!Fila_vazia(aux_fi_1)) {
		consulta_Fila(aux_fi_1, &al);
		remove_Fila(aux_fi_1);
		insere_Fila(fi_1, al);
	}
    
    while(!Fila_vazia(aux_fi_2)) {
		consulta_Fila(aux_fi_2, &al);
		remove_Fila(aux_fi_2);
		insere_Fila(fi_2, al);
	}
}

//Questão 5
void reverso(Fila* fi_1, Fila* fi_2) {
	
	if (Fila_vazia(fi_1))  {
		return;
	}
	
	struct aluno al;
    Fila* aux_fi_1 = cria_Fila();
    
	//reverso
	while(!Fila_vazia(fi_1)) {
		consulta_Fila_Final(fi_1, &al);
		remove_Fila_Final(fi_1);
		insere_Fila(aux_fi_1, al);
		insere_Fila(fi_2, al);
	}
}


//Questão 6


//Questão 7
void concatena(Fila* fi_1, Fila* fi_2) {
		
	if ( Fila_vazia(fi_2) ) {
		return;
	}
	
	struct aluno al;

    if(!Fila_vazia(fi_2)){
   		consulta_Fila(fi_2, &al);     
        remove_Fila(fi_2);
        insere_Fila(fi_1, al);
        concatena(fi_1, fi_2);
    }
}

int main(){
    //Declarações
    struct aluno a[4] = {{2,"Andre",10.0,5.8,10.5},
                         {4,"Ricardo",5.5,5.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",10.7,6.1,7.4}};
    
    struct aluno b[4]= {{5,"João",10.0,10.0,10.5},
                         {6,"Maria",4.3,5.7,6.8},
                         {7,"José",9.7,7.7,8.4},
                         {8,"Divina",10.7,6.1,7.4}};
   
    Fila* fi_1 = cria_Fila();
    Fila* fi_2 = cria_Fila();
    Fila* fi_3 = cria_Fila();
    Fila* fi_4 = cria_Fila();
    Fila* fi_5 = cria_Fila();
    Fila* fi_6 = cria_Fila();
    int i;
    for(i=0; i < 4; i++){
        insere_Fila(fi_1,a[i]);
        insere_Fila(fi_2,b[i]);
        insere_Fila(fi_6,a[i]);
    }

    //Questões
    printf("\nQuestão 3\n");
    fila_aprovados(fi_1,fi_3);
    imprime_Fila(fi_3);

    printf("\nQuestão 4\n");
    intercala(fi_1,fi_2,fi_4);
    imprime_Fila(fi_4);
   
    printf("\nQuestão 5\n");
    reverso(fi_1,fi_5);
    imprime_Fila(fi_5);
    imprime_Fila(fi_1);
    
    printf("\nQuestão 6\n");
    struct aluno al = {8,"Divina",10.7,6.1,7.4};
    insere_Fila_Ordenada(fi_1, &al);

    printf("\nQuestão 7\n");
    concatena(fi_6,fi_2);
    imprime_Fila(fi_6);
    imprime_Fila(fi_2);

    libera_Fila(fi_1);
    libera_Fila(fi_2);
    libera_Fila(fi_3);
    libera_Fila(fi_4);
    libera_Fila(fi_5);
    libera_Fila(fi_6);
    return 0;
}

//g++ *.c -o a.out.run
