#include<stdio.h>
#include<stdlib.h>

#include "complex.h"

struct NumeroComplexo
{
  float a, b;
};

NumComp* numeroCriar(float a, float b)
{
  NumComp* n = (NumComp*) malloc(sizeof(NumComp));

  if( n != NULL )
  {
    n->a = a;
    n->b = b;
  }

  return n;
}
float numeroAtribuir(NumComp* n, float a, float b)
{
  if( n == NULL)
    return 0;

  n->a = a;
  n->b = b;

  return 1;
}

void numeroImp(NumComp* n)
{
  printf("A = %.2f B = %.2f\n", n->a, n->b);
}

void Liberar(NumComp* n)
{
  free(n);
}