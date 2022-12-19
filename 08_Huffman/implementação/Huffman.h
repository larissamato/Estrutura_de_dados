typedef struct Item {
	 char simbolo[30];
	 int freq;	
	 char repBinaria[9];
	 char codigoHuffman[9]; 	  
} Item;

typedef struct No {
	Item* dados;	
	struct No *esq;
	struct No *dir;
 } No;
 
typedef struct CodigoHuffman {
	 Item listaSimbolos[256];
	 struct No *inicioArvore;		 
} CodigoHuffman;

CodigoHuffman* cria_CodigoHuffman();
void gerarCodigoHuffman(CodigoHuffman* cHuffman, char* texto);
void imprimeTabela(CodigoHuffman* cHuffman);
void TravessiaEmPreOrdem(No* p);
void imprimeTexto(CodigoHuffman* cHuffman, char* texto);
