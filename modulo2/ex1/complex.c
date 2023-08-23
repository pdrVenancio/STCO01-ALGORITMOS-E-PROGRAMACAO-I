#include<stdio.h>
#include<math.h>
#include<stdlib.h>
// Importar o arquivo q chama as funções
#include"complex.h"


/*******************************************/
/*       FUNCOES PRINCIPAIS                */
/*******************************************/

// ARMAZENA MEMORIA

complexo *complexoCriar(double real, double imag) {
	complexo *c = (complexo *) malloc(sizeof(complexo));

	if (c != NULL) {
		c->real = real;
		c->imag = imag;

    return c;
  }
	else {
    	printf("Memoria nao alocado!!\n");
		return NULL;
  	}
}
// LE OS NUMEROS IMAGINARIOS
complexo *complexoLe()
{
  complexo *n = (complexo*) malloc(sizeof(complexo));

  if( n != NULL){
    printf("Digite a parte real e em seguida a imaginaria:\n");
    scanf(" %lf %lf", &n->real, &n->imag);
  }
  
  return complexoCriar(n->real, n->imag);
}

// IMPRIMIR NA TELA

void complexoPrint(complexo *n)
{
  if(n->imag >= 0)
		printf("%.2f + %.2fi\n", n->real, n->imag);
	else {
		printf("%.2f - %.2fi\n", n->real, (n->imag * (-1)));
	}
}

// LIBERAR A MEMORIA ALOCADA 

void complexoLiberar(complexo *n)
{
  free(n);
}

// SUBITRAÇÃO

complexo *complexoSub(complexo *n1, complexo *n2)
{
  complexo *n = complexoCriar((n1->real - n2->real), (n1->imag - n2->imag));

  return n;
}

// SOMA

complexo *complexoSoma(complexo *n1, complexo *n2)
{
  complexo *n = complexoCriar((n1->real + n2->real), (n1->imag + n2->imag));

  return n;
}

// MULTIPLICAÇÃO

complexo *complexoMult(complexo *n1, complexo *n2)
{
  double realMult = n1->real * n2->real - n1->imag * n2->imag;
	double imagMult = n1->imag * n2->real + n1->real * n2->imag;
	return complexoCriar(realMult, imagMult);
}

// DIVISÃO

complexo *complexoDiv(complexo *n1, complexo *n2)
{
  double realDiv = ((n1->real * n2->real + n1->imag * n2->imag) / (n2->real * n2->real + n2->imag * n2->imag));
	double imagDiv = ((n1->imag * n2->real - n1->real * n2->imag) / (n2->real * n2->real + n2->imag * n2->imag));
	return complexoCriar(realDiv, imagDiv);
}