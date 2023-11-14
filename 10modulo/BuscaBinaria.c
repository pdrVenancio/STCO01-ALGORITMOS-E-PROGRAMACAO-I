/**********************************************************************
Programa para realizar busca binária de um número em um vetor,
utilizando uma função recursiva.
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>

// protótipos de funções
int buscaBinaria(int *vetor, int numero, int inicio, int fim);

/**********************************************************************
Função principal
**********************************************************************/
int main(void) 
{
  int *vetor;
  int n, r, numero;

  // lê o tamanho n do vetor
  printf("\nDigite o tamanho do vetor: ");
  scanf("%d", &n);

  // aloca memória dinamicamente para o vetor com n números inteiros
  vetor = (int*) malloc(n * sizeof(int));

  // se a memória for alocada corretamente, preenche o vetor
  if(vetor != NULL){

    // preenche o vetor automaticamente com 1, 2, 3, ..., n
    for(int i=0; i<n; i++){
      vetor[i] = i+1;
      printf("\nVetor[%d] = %d", i, vetor[i]);
    }

    // lê o número a ser buscado no vetor
    printf("\nDigite o número a ser buscado no vetor: ");
    scanf("%d", &numero);

    // chamada de função para realizar a busca binária, sendo r a posição onde o valor se encontra
    r = buscaBinaria(vetor, numero, 0, n-1);
    
    if(r == -1){
      printf("\nNúmero não foi encontrado no vetor!");

    }else{
      printf("\nNúmero %d está na posição %d do vetor!", numero, r);
    }
  }

  return 0;
}


/**********************************************************************
Função recursiva para encontrar um número no vetor usando busca binária
>> Caso base: as chamadas recursivas param se o número não for encontrado 
      (inicio > fim) ou se o número for encontrado (vetor[meio] = numero)
**********************************************************************/
int buscaBinaria(int *vetor, int numero, int inicio, int fim)
{
  // se o número não for encontrado no vetor, retorna -1 (erro)
  if(inicio > fim){
    return -1;
  }

  // encontra a posição do meio do vetor para dividir o mesmo em dois
  int meio = (inicio+fim)/2;

  // busca na primeira metade do vetor, se o número procurado for menor que o número do meio do vetor
  if(numero < vetor[meio]){
    return buscaBinaria(vetor, numero, inicio, meio);

  }
  // busca na segunda metade do vetor, se o número procurado for maior que o número do meio do vetor
  else if(numero > vetor[meio]){
    return buscaBinaria(vetor, numero, meio+1, fim);  

  }
  // se for igual, então o número foi encontrado e retorna a posição do meio (aquela onde o número está)
  else{
    return meio;   
  } 
}







