#include <stdio.h>
#include <stdlib.h>
#include "FilaPrioridadeHeap.h"

//Questão 1 
/*
a) Uma fila de prioridade é um tipo de fila que generaliza a ideia de ordenação, nesse caso
os elementos possuem uma informação a mais: sua prioridade. 

b)Lista dinâmica encadeada, array desordenado, array ordenado, heap binária.

c)As duas propriedades para o max_heap são: O nó raiz sempre 
tem que ser elemento com a maior chave na estrutura, e  se B é um nó filho de A, então chave(A) ≥ chave(B).
Já as duas propriedades para o min_heap são> O nó raiz sempre 
tem que ser o elemento com a menor chave na estrutura, e se B 
um nó filho de A, então chave(A) ≤ chave(B).

d)A realização das operações matemáticas em que o pai deve estar na posição em relação ao filho: (i div 2)– 1 + (i % 2)
Ou o filho em relação ao pai na posição i: 2i+1 e 2i+2
Se o filho for maior ou menor o código verifica e realiza as
operações de promover ou rebaixar respectivamente.

Questão 2

a) 33 32 28 31 26 29 25 30 27
F 28<29
b) 36 32 28 31 29 26 25 30 27
V
c) 33 32 28 30 29 26 25 31 27
F 31>30
d) 35 31 28 33 29 26 25 30 27
F 33>31
*/

int main(){
    struct paciente itens[6] = {{"Andre",1},
                                {"Bianca",2},
                                {"Carlos",5},
                                {"Nilza",8},
                                {"Inacio",6},
                                {"Edu",4}};

    FilaPrio* fp;
    fp = cria_FilaPrio();

    int i;
    for (i=0; i< 6; i++){
        printf("%d) %d %s\n",i,itens[i].prio, itens[i].nome);
        insere_FilaPrio(fp, itens[i].nome,itens[i].prio);
    }
    printf("=================================\n");

    imprime_FilaPrio(fp);    
    libera_FilaPrio(fp);
    system("pause");
    return 0;
}



