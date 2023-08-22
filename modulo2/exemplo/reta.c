/*********************************************************************** 
Implementação do TAD Reta oculta aos usuários do TAD - função main()
- Só pode ser acessada através da interface "reta.h"
***********************************************************************/

// --------------------------
// definição de bibliotecas 
// --------------------------

// bibliotecas padrões da linguagem C
#include <stdio.h>
#include <stdlib.h>

// biblioteca que contém a definição dos protótipos das funções implementadas abaixo
#include "reta.h"

// --------------------------
// definição de structs 
// --------------------------
struct reta{
  Ponto *p1;
  Ponto *p2;
};


// --------------------------
// implementação das funções 
// --------------------------

// função para criar uma novo reta
Reta* retaCriar(Ponto *p1, Ponto *p2)
{
  Reta* r = (Reta*) malloc(sizeof(Reta));

  if(r != NULL){
    r->p1 = p1;
    r->p2 = p2;
  }
  
  return r;
}

// função para liberar a memória de uma reta
void retaLiberar(Reta* r)
{
  free(r);
}

// função para atribuir valores para os pontos p1 e p2
int retaAtribuir(Reta* r, Ponto *p1, Ponto *p2)
{
  // se a memória do ponteiro p não foi alocada retorna como erro
  if(r == NULL)
    return 0;
  
  r->p1 = p1;
  r->p2 = p2;

  return 1;
}

// função para acessar os valores dos pontos p1 e p2
int retaAcessar(Reta* r, Ponto *p1, Ponto *p2)
{
  // se a memória do ponteiro p não foi alocada retorna como erro
  if(r == NULL)
    return 0;
  
  // parâmetros x e y foram passados por referência pois se alteram aqui 
  p1 = r->p1;
  p2 = r->p2;

  return 1;
}

// função para imprimir a reta
void retaImprimir(Reta* r)
{
  printf("\nReta: ");
  pontoImprimir(r->p1);
  pontoImprimir(r->p2);
}