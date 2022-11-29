#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

//Questão 1 
//a) Sua estrutura de dados se baseia em que o primeiro item inserido será o primeiro removido
//b) São utilizadas em situações do mundo real, como por exemplo fila de impressora
    
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

//Questão 4
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

//Questão 5
/*void reverso(Fila* fi_1, Fila* fi_2) {
	
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
		insere_Fila(fi_2, al);	
	}
    reverso_Fila(fi_2);	
	//Reconstruindo fila original
	while(!Fila_vazia(fi_aux)) {
		consulta_Fila(fi_aux, &al);
		remove_Fila(fi_aux);
		insere_Fila(fi_1, al);
	}	
	
}
*/

void reverso (Fila* fi_1, Fila* fi_2){
    if (Fila_vazia(fi_1))  {
		return;
	}
    struct aluno al;
    if (!Fila_vazia(fi_1)){
        consulta_Fila(fi_1, &al);
        remove_Fila(fi_1);
        insere_Fila(fi_2, al);
        reverso(fi_1, fi_2);
    }

}

int main(){
    struct aluno a[4] = {{2,"Andre",10.0,5.8,10.5},
                         {4,"Ricardo",5.5,5.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",10.7,6.1,7.4}};

    struct aluno b[4]= {{5,"João",10.0,10.0,10.5},
                         {6,"Maria",4.3,5.7,6.8},
                         {7,"José",9.7,7.7,8.4},
                         {8,"Divina",10.7,6.1,7.4}};
    
    Fila* f1 = cria_Fila();
    Fila* f2 = cria_Fila();

    int i;
    for(i=0; i < 4; i++){
        insere_Fila(f1,a[i]);
        insere_Fila(f2,b[i]);
    }
    
    printf("\nQuestão 3\n");
    Fila* f3 = cria_Fila();
    fila_aprovados(f1,f3);
    imprime_Fila(f3);
    /*printf("\nQuestão 4\n");
    Fila* f4 = cria_Fila();
    intercala(f1,f2,f4);
    imprime_Fila(f4);
   */
    printf("\nQuestão 5\n");
    Fila* f5 = cria_Fila();
    reverso(f1,f5);
    imprime_Fila(f5);

    libera_Fila(f1);
    libera_Fila(f2);
    //libera_Fila(f3);
    //libera_Fila(f4);
    system("pause");
        return 0;
}

//g++ *.c -o a.out.run
