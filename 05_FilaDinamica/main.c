#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"
int main(){


    /*Questão 1 
    a) Sua estrutura de dados se baseia em que o primeiro item inserido será o primeiro removido
    b) São utilizadas em situações do mundo real, como por exemplo fila de impressora
    
    Questão 2
    3 7 2 4
    */

    struct aluno al,a[4] = {{2,"Andre",10.0,5.8,10.5},
                         {4,"Ricardo",5.5,5.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",10.7,6.1,7.4}};
    
	Fila* fi = cria_Fila();
    Fila* l1 = cria_Fila();
    Fila* l2 = cria_Fila();
    Fila* l3 = cria_Fila();

    int i;
    for(i=0; i < 4; i++){
        insere_Fila(fi,a[i]);
        insere_Fila(l2,a[i]);
        insere_Fila(l1,a[i]);
    }
//Questão 3 
    remove_reprovados(fi);
    imprime_Fila(fi);
//Questão 4 
    intercala_Fila(l1,l2,l3);
    imprime_Fila(l3);
//Questão 5 
    reverso_Fila(l1);
    



    libera_Fila(fi);
    system("pause");
    return 0;
}

//g++ *.c -o a.out.run
