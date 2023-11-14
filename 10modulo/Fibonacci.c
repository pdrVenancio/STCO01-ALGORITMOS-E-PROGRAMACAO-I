/**********************************************************************
Programa para encontrar a posição de um número inteiro n na sequencia de 
Fibonacci (0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...),
onde um número é igual a soma dos dois anteriores, utilizando uma
função recursiva.
**********************************************************************/
#include <stdio.h>

// protótipo das funções
int fibonacci(int n); 


/**********************************************************************
Função principal
**********************************************************************/
int main(void) 
{
  int n;

  printf("\nDigite um número: ");
  scanf("%d", &n);

  printf("Fibonacci(%d) = %d", n, fibonacci(n));

  return 0;
}

/**********************************************************************
Função para encontrar a posição do número da sequencia de Fibonacci 
considerando que a sequencia começa na posição zero.
**********************************************************************/
int fibonacci(int n)
{
  // caso base: as chamadas recursivas param quando n é igual a 0 ou 1 e retorna n, 
  // pois não tem dois números anteriores para serem somados
  if(n==0 || n==1)
    return n;

  // passo recursivo onde fibonacci é a soma dos 2 números anteriores a n
  return fibonacci(n-1) + fibonacci(n-2);
}


