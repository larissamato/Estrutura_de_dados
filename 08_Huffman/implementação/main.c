#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Huffman.h"

int main(){	
	
	CodigoHuffman* cHuffman = cria_CodigoHuffman();
	
	char texto[100];		
	strcpy(texto, "O RATO ROEU A ROUPA DO REI DE ROMA");	
		
	gerarCodigoHuffman(cHuffman, texto);	
	
	imprimeTabela(cHuffman);
			
	printf("\nArvore de Huffman - Travessia em Pre-Ordem\n");
	TravessiaEmPreOrdem(cHuffman->inicioArvore);
		
	imprimeTexto(cHuffman, texto);
		    
    system("pause");
    return 0;
}




