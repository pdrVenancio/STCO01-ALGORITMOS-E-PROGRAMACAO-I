#include <stdio.h>
#include "complex.h"

int main()
{
  complexo *soma, *sub, *mult, *div, *n1, *n2;

  n1 = complexoLe();
  n2 = complexoLe();

  soma = complexoSoma(n1,n2);
  sub = complexoSub(n1,n2);
  div = complexoDiv(n1, n2);
  mult = complexoMult(n1, n2);
  
  printf("\nSoma: ");
  complexoPrint(soma);
  printf("\nSubtração: ");
  complexoPrint(sub);
  printf("\nDivisão: ");
  complexoPrint(div);
  printf("\nMultiplicação: ");
  complexoPrint(mult);
  
  complexoLiberar(soma);
  complexoLiberar(mult);
  complexoLiberar(div);
  complexoLiberar(sub);
  complexoLiberar(n1);
  complexoLiberar(n2);

  return  0;
}