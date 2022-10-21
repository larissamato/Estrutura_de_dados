#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD-Livro.h"

int main(int argc, char *argv[]) {
	
	Livro* vetor[3];
	
	char* tipo;

	char name[]="AAAA";
	char name2[]="BBBB";
	char name3[]="CCCC";
	
	vetor[0] = criaLivro(name, name, name, 1915);
	vetor[1] = criaLivro(name2, name2, name2, 1935);
	vetor[2] = criaLivro(name3, name3, name3, 2020);
	
	for(int i=0; i<3; i++) {
		printf("\n----------------\n");
		
		int tipo = verificaModernismo(vetor[i]);
		
		printf("%s %d %d", 
				obterTitulo(vetor[i]),obterAno(vetor[i]), tipo);
	}
	printf("\n----------------\n");
	//Desalocando 
	for(int i=0; i<3; i++) {
		destroi(vetor[i]);
	}
		
	
	return 0;
}


// g++ *.c -o a.out.run
// ./a.out.run





