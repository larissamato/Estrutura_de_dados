**1.Responda:**
**a) O que é um Tipo Abstrato de Dados (TAD) e qual a característica fundamental na sua utilização?**
Um tipo abstrato de dados é um conjunto de valores que tem seu comportamento definido por operações em forma de funções. Essas operações são definidas pelo programador.
Sua característica fundamental é ocultar a implementação das funções do usuário.
**b) Quais as vantagens de se programar com TADs?**
Encapsulamento, segurança pois evita que o usuário manipule os dados de maneira imprópria, flexibilidade pois altera o TAD sem alterar as aplicações e reutilização já que é feita em um módulo diferente do programa do usuário.

**c) Como um TAD é implementado na linguagem C?**
Por meio de dois arquivos, um .h em que é declarado os protótipos, sendo visível ao usuário e o outro .c em que os dados estão ocultos.

**2. Faca a especificação de um sistema de controle de reservas de um clube que aluga quadras poliesportivas usando TAD utilizando a linguagem C, da seguinte forma:
• No arquivo “.H”, declare tudo aquilo que será visível para o programador.
• No arquivo “.C”, defina tudo aquilo que deve ficar oculto do usuário da biblioteca. Para especificação do sistema, não é necessário implementar o corpo das as funções.**

Se encontra na pasta TAD_questao_2

**3. Desenvolva um TAD para um retângulo. Inclua as funções de inicializações necessárias, as operações para obtenção dos dados armazenados no TAD (base e altura), e a operação que retorne a área do retângulo (A = Base x Altura).**

Se encontra na pasta TAD_questao_3

**4. Crie um TAD para o desenvolvimento de um sistema para representar e gerenciar de livros de uma biblioteca. A sua tarefa é implementar um TAD para representar os livros neste sistema. Sabe-se que um livro é representado pelo seguinte tipo estruturado:**

```
struct livro {
char titulo[50];
char autor[30];
char genero[10];
int ano;
};
```

**As funções que devem ser implementadas pelo TAD Livro (na interface do TAD), são as seguintes: 
•Função criaLivro que recebe por parâmetro o título, autor, gênero e ano de publicação do livro, cria um livro com esses dados e retorna um ponteiro para o novo Livro.
•Funções de obtenção dos dados armazenados em um TAD Livro (denominadas obtemGenero, obtemAutor, obtemTitulo, e obtemAno) que recebem um ponteiro para Livro e retornam o valor em questão.
•Função verificaNoModernismo que recebe um ponteiro para Livro e verifica se esse livro pertence ao segundo período do modernismo brasileiro (1930 a 1945). Esta função retorna -1 se o ano da obra for anterior a 1930, retorna 0 se for no período 1930 a 1945, e retorna 1 se o ano
for posterior a 1945. **

**Escreva o conteúdo do arquivo Livro.h com a interface deste TAD Livro, incluindo a definição da estrutura e também todas as funções disponíveis para o usuário. Em seguida, escrevendo o módulo (arquivo Livro.c ) que implementa todas as funções do TAD Livro.**

**Em seguida, escreve o modulo principal de um programa (Principal.c) que crie e inicialize um vetor de ponteiros para Livro utilizando as funções disponibilizadas pelo TAD e insera vários registros neste vetor (no mínimo cinco). Em seguida, imprima o conteúdo dos registros do vetor de ponteiros para Livros.**

Se encontra na pasta TAD_questao_4
