

struct produto {
	int codigo;
	char nome[30];
	float preco;
	int qtde;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct produto p);
void imprime_lista(Lista* li);
int lista_vazia(Lista* li);
float menorPreco(Lista* li);
float media_n3(Lista* li);
int tamanho_lista(Lista* li);
Lista endereco_elemento(Lista* li, int pos);
Lista endereco_ant_elemento(Lista* li, int pos);
void concatena(Lista* li_1, Lista* li_2, Lista* li_3);
int troca(Lista* li, int pos1, int pos2);
void divide(Lista* li,Lista* li2, int par);
void troca_dados(Lista* li, int i, int j);
//int troca_elemento(Lista* li, int elem1, int elem2);
int insere_lista_ordenada(Lista* li, struct produto pro);

