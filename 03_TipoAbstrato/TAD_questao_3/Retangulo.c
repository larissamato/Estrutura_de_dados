#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"

struct retangulo {
	float base;
	float altura;
};

Retangulo* criaRetangulo(float b, float a) {
	Retangulo* r = (Retangulo*)malloc(sizeof(Retangulo));
	r->base = b;
	r->altura = a;
	return r;
}

float area(Retangulo* r) {
	return r->base * r->altura;
}

void imprime(Retangulo* r) {
	printf("%f %f\n", r->base, r->altura);
}

float obterBase(Retangulo* r) {
	return r->base;
}

float obterAltura(Retangulo* r) {
	return r->altura;
}

/*int alteraBase(Retangulo* r, int b) {
	if (b <= 0)
		return 0;
	
	r->base = b;
}

int alteraAltura(Retangulo* r, int a) {
	if (a <= 0)
		return 0;
	
	r->altura = a;
}

void destroi(Retangulo* r) {
	free(r);
}
*/