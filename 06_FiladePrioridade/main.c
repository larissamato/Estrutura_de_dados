#include <stdio.h>
#include <stdlib.h>
#include "FilaPrioridadeHeap.h"
#include <stdio.h>
#include <string.h>

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

int consultaVetor(char * vetor, FilaPrio* fi_1){
    if (estaVazia_FilaPrio(fi_1)){
        return 0;
    }

    char nome[30];
    FilaPrio* fi_aux = cria_FilaPrio();

    while(!estaVazia_FilaPrio(fi_1)){
        consulta_FilaPrio(fi_1, &nome[0]);
        remove_FilaPrio(fi_1);
        if(strcmp(vetor, nome) != 0){
            return 1;
        }else{
            return 2;
        }
    }
    return 0;
}

int main(){
    struct paciente itens[6] =  {{"Andre",9},
        {"Bianca",8},
        {"Carlos",7},
        {"Nilza",6},
        {"Inacio",5},
        {"Edu",4}};
    FilaPrio* fp;
    FilaPrio* fp_min;
    fp = cria_FilaPrio(); 
    fp_min = cria_FilaPrio();
    int i = 0;
    int result = 1;

    for (int i=0; i< 6; i++){
        insere_FilaPrio(fp, itens[i].nome,itens[i].prio);
        insere_FilaPrioMin(fp_min, itens[i].nome,itens[i].prio);
    }

    //Questão 3
    printf("\n=====================================\n");
    while (i< 6){
        int verifica;
        verifica = consultaVetor(itens[i].nome, fp);
        if (verifica == 1){
            i = 6;
            result = 0;
            printf("O vetor não está na ordem de prioridade");
        } 
        i++;
    }
    if (result == 1)
        printf("O vetor está na ordem");

    //Questão 4
    printf("\n=====================================\n");
    imprime_FilaPrio(fp_min);
    remove_FilaPrioMin(fp_min);
    printf("\n=====================================\n");
    imprime_FilaPrio(fp_min);


    libera_FilaPrio(fp);
    return 0;
}
