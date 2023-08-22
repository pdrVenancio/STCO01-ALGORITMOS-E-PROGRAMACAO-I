/*********************************************************************** 
Exemplo de programa utilizando funções das TADs Ponto e Reta 
***********************************************************************/

// --------------------------
// definição de bibliotecas 
// --------------------------

// bibliotecas padrões da linguagem C
#include <stdio.h>
#include <stdlib.h>

// bibliotecas que estão dentro do projeto
#include "ponto.h"
#include "reta.h"


// --------------------------
// implementação das funções 
// --------------------------

// função principal do programa que cria dois pontos e uma reta entre eles 
int main(void) {

  Ponto *p, *q; // necessário declarar ponteiros para acessar a TAD

  // cria dois pontos: p e q
  p = pontoCriar(10, 21);
  q = pontoCriar(7, 25);

  // imprimir as coordenadas dos pontos p e q
  printf("\nPonto p = ");
  pontoImprimir(p);

  printf("\nPonto q = ");
  pontoImprimir(q);

  // cria uma reta entre os pontos p e q
  Reta *r = retaCriar(p, q);

  // imprimir as coordenadas dos pontos p e q que formam a reta r
  retaImprimir(r);

  // libera memória alocada para a reta r
  retaLiberar(r);
  
  // libera memória alocada para os pontos p e q
  pontoLiberar(q);
  pontoLiberar(p);
  
  printf("\n\n");
  return 0;
  
}



