#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
int main(){
    struct aluno al, a[6] = {{2,"Andre",2.1,2.2,2.3},
                         {4,"Ricardo",4.1,4.2,4.3},
                         {1,"Bianca",1.1,1.2,1.3},
                         {3,"Ana",3.1,3.2,3.3},						 
						  {5,"Carla",5.1,5.1,5.3},
						  {7,"Luana",7.1,7.2,7.3}					 
						 
						 };
    Lista* li = NULL;
	li = cria_lista();
    
    int i;
    for(i=0; i < 6; i++)
        insere_lista_final(li,a[i]);
  
    imprime_lista(li);  
	
	/*
	Lista p = endereco_elemento(li, 3);	  
	if (p != NULL) 
		printf("-> %d", p); 
	else
		printf("Nao foi possivel retornar o endereco"); 
    */
    
    /*
	int qtde = qtde_elementos(li);  	  
	printf("-> Qtde: %d", qtde);  
	*/
	  
	 
	float m_nota3 = media_n3(li); 
	printf("-> Media - N3: %f", m_nota3);
	 
        
    Lista* li_2 = cria_lista();
    struct aluno x_a = {8,"AAAA",2.1,2.2,2.3};
    insere_lista_final(li_2,x_a); 
	struct aluno x_b = {9,"BBBB",2.1,2.2,2.3};
    insere_lista_final(li_2,x_b); 
    struct aluno x_c = {10,"CCCC",2.1,2.2,2.3};
    insere_lista_final(li_2,x_c); 
    	
	imprime_lista(li_2);
	    
   	printf("\n\n");     
      
	Lista* li_3 = cria_lista();  
	
	concatena(li, li_2, li_3);	
	imprime_lista(li_3); 
    libera_lista(li);
    libera_lista(li_2);
    libera_lista(li_3);
    system("pause");
    return 0;
}


