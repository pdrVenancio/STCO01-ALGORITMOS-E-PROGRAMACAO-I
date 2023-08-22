#include<stdio.h>
#include<stdlib.h>
// importando a biblioteca
#include "complex.h"

int main()
{
  NumComp *a, *b;

  a = numeroCriar(4, 7);

  numeroImp(a);
  numeroImp(b);
  

  Libera(a);
  Libera(b);


  
  return 0;
}
