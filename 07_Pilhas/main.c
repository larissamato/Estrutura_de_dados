#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
/*
1. Responda as seguintes questões:
a) O que é e para que serve uma pilha?
b) Em que situações uma pilha pode ser utilizada?
c) Suponha que uma pilha possua 4 valores na seguinte ordem: 1, 2, 3 e 4. Qual seria a sequência
correta de operações de inserção (I) e eliminação (E) para se obter os registros na ordem 2 4 3 1?
2. Escreva uma função para transferir elementos de uma pilha P1 para uma pilha P2 (cópia).
3. Escreva um algoritmo que use uma pilha para inverter a ordem dos elementos. Por exemplo, para a
string “Instituto Federal de Goias” o resultado deve ser “saioG ed laredeF otutitsnI”.
4. Escreva um programa que utilize uma pilha para verificar se expressões aritméticas estão com a
parentização (com parênteses e colchetes) correta. O programa deve verificar expressões para ver se
cada “abre parênteses ou colchetes” tem um “fecha parênteses ou colchetes” correspondente. Ex.:
• Correto: ( [ ( ) ] )
• Incorreto: ( [ ( ] ( )
5. Considere uma pilha que armazene caracteres. Escreva uma função na linguagem C para determinar
se uma string é da forma XY, onde X é uma cadeia formada por caracteres arbitrários e Y é o reverso
de X.
Por exemplo,
se x = ABCD, então y = DCBA.
Considere que x e y são duas strings distintas.
*/
int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    
	Pilha* pi = cria_Pilha();
    
    int i;
    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);

    imprime_Pilha(pi);
    
    libera_Pilha(pi);
    system("pause");
    return 0;
}

