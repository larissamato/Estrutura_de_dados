#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"

int main(int argc, char *argv[]) {	
		
	Retangulo* ret1 = criaRetangulo(10, 5);	
	
	imprime(ret1);
	printf("%f\n", area(ret1));		
	
	float base = obterBase(ret1) * 2;
	float altura = obterAltura(ret1) * 2;
	
	//O retangulo dois tem o dobro da 
	//base e altura de ret1
	/*Retangulo* ret2 = criaRetangulo(base, altura);	
	
	alteraBase(ret2, base*2);	
	imprime(ret2);
	printf("%f\n", area(ret2));	
	
	destroi(ret1);
	destroi(ret2);		*/
	
	return 0;
}

//g++ *.c -o a.out.run

