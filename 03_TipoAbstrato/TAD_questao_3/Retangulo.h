//Definindo o tipo Retangulo com base
//em struct retangulo, que será visivel no main()
typedef struct retangulo Retangulo;

Retangulo* criaRetangulo(float b, float a);

float area(Retangulo* r);
void imprime(Retangulo* r);
float obterBase(Retangulo* r);
float obterAltura(Retangulo* r);
/*int alteraBase(Retangulo* r, int b);
int alteraAltura(Retangulo* r, int a);
void destroi(Retangulo* r);*/