typedef struct livro Livro;
Livro* criaLivro(char* tit, char* autor, char* gen, int ano);
char* obterTitulo(Livro* l);

void destroi(Livro* l);
int verificaModernismo(Livro* l);
int	obterAno(Livro* lv);
