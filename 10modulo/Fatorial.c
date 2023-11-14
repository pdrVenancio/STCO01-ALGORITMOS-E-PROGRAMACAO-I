
/*********************************************************
Programa para calcular o fatorial de um número inteiro n,
onde n! = 1 * (n+1) * (n+2) * ... * n
através de um função iterativa e através de recursão
*********************************************************/

#include <stdio.h>

// protótipo das funções
int fatorialIterativo(int n);
int fatorialRecursivo(int n);

/*********************************************************
Função principal
*********************************************************/
int main(void) {
  
  int n;

  // lê o número n para ser calculado o fatorial
  printf("\nDigite o valor para calcular o fatorial: ");
  scanf("%d", &n);

  // imprime o valor do fatorial de número n, calculado pelo método iterativo
  printf("\n(Função iterativa) O fatorial de %d é %d.", n, fatorialIterativo(n) );

  // imprime o valor do fatorial de número n, calculado pelo método recursivo
  printf("\n(Função recursiva) O fatorial de %d é %d.", n, fatorialRecursivo(n) );

  return 0;

}

/*********************************************************
Função iterativa para calcular o fatorial de n
*********************************************************/
int fatorialIterativo(int n)
{
  int f = 1;
  
  // cálculo de fatorial de n >>>>> n! = 1 * (n+1) * (n+2) * ... * n
  for(int i=2; i<=n; i++){
    f = f * i;    
  }
  
  return f;
}

/*********************************************************
Função recursiva para calcular o fatorial de n
*********************************************************/
int fatorialRecursivo(int n)
{
  // caso base: as chamadas recursivas param quando n é igual a 0
  if(n == 0)
    return 1; // retorna 1 pois o fatorial de 0 é igual a 1
  
  // cálculo de fatorial de n >>>>> n! = n * ( (n-1) * ( (n-2) * ... * 1 ) )
  return n * fatorialRecursivo(n-1);
}