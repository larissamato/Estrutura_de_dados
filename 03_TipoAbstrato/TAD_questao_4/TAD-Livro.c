#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD-Livro.h"

struct livro {
	char titulo[50];
	char autor[30];
	char genero[10];
	int ano;
}; 

Livro* criaLivro(char* tit, char* autor, char* gen, int ano) {
					
	Livro* lv = (Livro*) malloc(sizeof(Livro));
	
	if (lv != NULL) {
		lv->ano = ano;
		strcpy(lv->titulo,tit);
		strcpy(lv->autor,autor);
		strcpy(lv->genero,gen);
	}
		
	return lv;
}

char* obterTitulo(Livro* l) {
	if (l != NULL)
		return l->titulo;
	return NULL;
}

int	obterAno(Livro* lv) {
	return lv->ano;
}

void destroi(Livro* l) {
	free(l);
}

int verificaModernismo(Livro* l) {
	
	if (l->ano < 1930)
		return -1;
	else if (l->ano > 1945)
		return 1;
	else
		return 0;
	
}







