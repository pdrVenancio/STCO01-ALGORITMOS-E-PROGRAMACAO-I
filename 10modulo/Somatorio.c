
/**********************************************************************
Programa para calcular a soma de n números de um vetor, ou seja, 
Somatorio(n) = 1 + 2 + ... + n 
utilizando uma função recursiva.
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>

// protótipos das funções
int soma(int tamanho, int *vetor);

/**********************************************************************
Função principal
**********************************************************************/
int main(void) 
{
  int *vetor;
  int n;

  // lê o tamanho n do vetor
  printf("\nDigite o tamanho vetor: "); 
  scanf("%d", &n);

  // aloca memória dinamicamente para o vetor com n números inteiros
  vetor = (int *) malloc(n * sizeof(int));

  // se a memória for alocada corretamente, preenche o vetor
  if(vetor != NULL){

    // preenche o vetor automaticamente com 1, 2, 3, ..., n
    for(int i=0; i<n; i++){
      vetor[i] = i+1;
      printf("\nVetor[%d] = %d", i, vetor[i]);
    }

    // imprime o resultado da soma dos valores do vetor (somatório)
    printf("\nSomatório(%d) = %d ", n, soma(n, vetor));

  }

  return 0;
}

/**********************************************************************
Função para calcular o somatório utilizando abordagem que diminui 
o vetor da cada passo recursivo em uma posição
**********************************************************************/
int soma(int n, int *vetor)
{
  // caso base: as chamadas recursivas param quando o vetor tem tamanho n igual a 1
  if(n == 1)
    return vetor[0]; // retorna o valor da primeira posição do vetor

  // passo recursivo
  return vetor[n - 1] + soma(n - 1, vetor);  
}