#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Huffman.h" 

typedef struct FILA {
	No* Fila[100];
	int TAM;
} FILA;

CodigoHuffman* cria_CodigoHuffman(){
    CodigoHuffman* cHuffman = (CodigoHuffman*) malloc(sizeof(CodigoHuffman));
    if(cHuffman != NULL){
        
        int i;
		for(i=0; i<256; i++) {		
			char simbolo[2];
			simbolo[0] = (char)(i);
			simbolo[1] = '\0'; 
			strcpy(cHuffman->listaSimbolos[i].simbolo, simbolo);
			cHuffman->listaSimbolos[i].freq = 0; 
			cHuffman->inicioArvore = NULL;  
		}
    }
    return cHuffman;
}

FILA* criaFila() {
	FILA* fi = (FILA*) malloc(sizeof(FILA));
	        
	fi->TAM = 0;
	int i;
	for(i=0; i<100; i++) {
		fi->Fila[i] = NULL;
	}
    return fi;	
}

No* enfilera(FILA* fi, Item* dados) {
	
	int i = 0;
	while ( (i < fi->TAM) && (dados->freq > fi->Fila[i]->dados->freq) ) {
		i++;	
	}
		                               		
	int j;	
	for(j=fi->TAM; j >= i; j--) {	
		fi->Fila[j+1] = fi->Fila[j];			
	}

	fi->Fila[i] = (No*) malloc(sizeof(No));	
	fi->Fila[i]->dir = NULL;
	fi->Fila[i]->esq = NULL;		
	fi->Fila[i]->dados = dados;	
	fi->TAM++;
	return fi->Fila[i];
}

int filaVazia(FILA* fi) {
	return (fi->TAM == 0);		
}

int tamFila(FILA* fi) {
	return fi->TAM;		
}

No* desenfilera(FILA* fi) {
		
	if (!filaVazia(fi)) {
		No* aux = fi->Fila[0];
			
		int i ;
		for(i=0; i < fi->TAM-1; i++) {
			fi->Fila[i] = fi->Fila[i+1];	
		}
		
		fi->Fila[fi->TAM-1] = NULL;	
		fi->TAM--;
		return aux;
	}	
	return NULL;	
}

void imprimeFila(FILA* fi) {	
	printf("\n");
	int i=0;
	while(i < fi->TAM) {
		printf("%-30s %-4d\n", fi->Fila[i]->dados->simbolo, fi->Fila[i]->dados->freq);			
		i++;
	}
	printf("---------------------------------------\n");		
}

void gerarArvore(FILA* fi) {
	
	No* i1 = desenfilera(fi);
	No* i2 = desenfilera(fi);	
	
	No* iEsq;
	No* iDir;
	
	Item* itemAux = (Item*) malloc(sizeof(Item));		
		
	if (strlen(i1->dados->simbolo) == 1) {
		iEsq = i1;
		iDir = i2;
	} else if (strlen(i2->dados->simbolo) == 1) {
		iEsq = i2;
		iDir = i1;
	}
	else if ( strlen(i1->dados->simbolo) <= strlen(i2->dados->simbolo) ) {
		iEsq = i1;
		iDir = i2;
	} else {
		iEsq = i2;
		iDir = i1;
	}

	strcpy(itemAux->simbolo, iEsq->dados->simbolo);	
	strcat(itemAux->simbolo, iDir->dados->simbolo);		
	itemAux->freq = iEsq->dados->freq + iDir->dados->freq;
	No* novoNo = enfilera(fi, itemAux);	
	novoNo->esq = iEsq;
	novoNo->dir = iDir;
}

void TravessiaEmPreOrdem(No* p) {    
  if (p != NULL) {
	printf("--> %-4s\n", p->dados->simbolo);	
	TravessiaEmPreOrdem(p->esq);		
	TravessiaEmPreOrdem(p->dir);
	
  }

}

void converterInteiroparaBinario(int numero , char* binario) {
	char aux[9];
	strcpy(aux, "");
		
	int resto, i=0;	
	do {
	
		resto = numero % 2;
		numero = numero / 2;	
		
		aux[i] = (resto) ? '1': '0';
		i++;
	
	}while(numero);
	aux[i] = '\0';
	
	int j=0;
	i--;
	
	if(strlen(aux) == 7) {
		binario[j] = '0';
		j++;
	}
	
	for(; i>=0; i--) {
		binario[j] = aux[i];
		j++;
	}
		
	binario[j] = '\0';
}

void gerarBitsPorTravessiaEmPos(CodigoHuffman* cHuffman, No* p, char* repBits, int i) { 
  if (p != NULL) {  				
	
	if (p->esq != NULL)
		strcat(repBits, "0");
		
	gerarBitsPorTravessiaEmPos(cHuffman, p->esq, repBits, i+1);
	
	if (p->dir != NULL) {			
		repBits[i] = '\0';
		strcat(repBits, "1");
	}
			
	gerarBitsPorTravessiaEmPos(cHuffman, p->dir, repBits, i+1);
	
	if (strlen(p->dados->simbolo) == 1) {
		strcpy(cHuffman->listaSimbolos[(int)(p->dados->simbolo[0])].codigoHuffman,repBits);		
		char str_binario[9];
		converterInteiroparaBinario((int)(p->dados->simbolo[0]), str_binario);
		strcpy(cHuffman->listaSimbolos[(int)(p->dados->simbolo[0])].repBinaria, str_binario);
	}
	
  }
}

void gerarBits(CodigoHuffman* cHuffman, No* p) {	
	char repBits[100];
	strcpy(repBits, "");
	gerarBitsPorTravessiaEmPos(cHuffman, p, repBits, 0);
}

void contarFreqSimbolos(CodigoHuffman* cHuffman, char* texto) {
	int i=0;
	while(texto[i] != '\0') {
		
		int indice;
		if ((int)(texto[i]) != 32)
			indice = (int)(texto[i]);
		else
			indice = 64;
		
		cHuffman->listaSimbolos[indice].freq++;
			
		i++;
	}
}

void gerarCodigoHuffman(CodigoHuffman* cHuffman, char* texto) {
		
	FILA* fi = criaFila();
	
	contarFreqSimbolos(cHuffman, texto);
	
	for(int i=64; i<=90; i++) {
		if (cHuffman->listaSimbolos[i].freq > 0) {			
			Item* itemA = (Item*) malloc(sizeof(Item));	
			itemA->simbolo[0] = (char)(i);
			itemA->simbolo[1] = '\0';
			itemA->freq = cHuffman->listaSimbolos[i].freq;			
			enfilera(fi, itemA);			
		}
	}		
				
	imprimeFila(fi);	

	while (tamFila(fi) != 1) {
		gerarArvore(fi);
		imprimeFila(fi);
	} 

	gerarBits(cHuffman, fi->Fila[0]);
	cHuffman->inicioArvore = fi->Fila[0];
}

void imprimeTabela(CodigoHuffman* cHuffman) {	
	
	printf("\n%-10s %-4s %-8s %-12s %-12s\n", "SIMBOLO",  "INT", "FREQ", "BINARIO", "COD HUFFMAN");
  	printf("---------------------------------------------------\n"); 
	for(int i=64; i<=90; i++) {		
		if (cHuffman->listaSimbolos[i].freq > 0) {
			printf("%-10s %-4d %-8d %-12s %-12s \n", 
			cHuffman->listaSimbolos[i].simbolo, 
			(int)(cHuffman->listaSimbolos[i].simbolo[0]),
			cHuffman->listaSimbolos[i].freq,
			cHuffman->listaSimbolos[i].repBinaria,
			cHuffman->listaSimbolos[i].codigoHuffman
			);
		}
		
	}	
}

void imprimeTexto(CodigoHuffman* cHuffman, char* texto) {
	
	printf("\n\nTexto\n");
	printf("%s", texto);
	
	printf("\n\nRepresentacao Binaria\n");
	
	int i=0;
	while(texto[i] != '\0') {
		
		int indice;
		if ((int)(texto[i]) != 32)
			indice = (int)(texto[i]);
		else
			indice = 64;	
			
		printf("%s ", cHuffman->listaSimbolos[indice].repBinaria);
			
		i++;
	}
	
	printf("\n\nRepresentacao Comprimida\n");
	
	i=0;
	while(texto[i] != '\0') {
		
		int indice;
		if ((int)(texto[i]) != 32)
			indice = (int)(texto[i]);
		else
			indice = 64;
		
		printf("%s ", cHuffman->listaSimbolos[indice].codigoHuffman);		
			
		i++;
	}
	
	printf("\n\n");
	
}

