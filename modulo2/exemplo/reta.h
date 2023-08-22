/****************************************************************************** 
Interface do TAD Reta visível aos usuários do TAD - função main()
*******************************************************************************/

// --------------------------
// definição de bibliotecas 
// --------------------------

// biblioteca do projeto usada pela TAD Reta
#include "ponto.h"

// --------------------------
// definição de structs 
// --------------------------
typedef struct reta Reta; 


// --------------------------
// protótipos das funções
// --------------------------

// função para criar uma novo reta
Reta* retaCriar(Ponto *p1, Ponto *p2);

// função para liberar a memória de uma reta
void retaLiberar(Reta* r);

// função para atribuir valores para os pontos p1 e p2
int retaAtribuir(Reta* r, Ponto *p1, Ponto *p2);

// função para acessar os valores dos pontos p1 e p2
int retaAcessar(Reta* r, Ponto *p1, Ponto *p2);

// função para imprimir a reta
void retaImprimir(Reta* r);
