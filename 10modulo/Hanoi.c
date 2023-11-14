/*********************************************************************************
Programa para mostrar a sequencia de movimentos para resolver o problema da
Torre de Hanoi para n discos, utilizando uma função recursiva.
**********************************************************************************/
#include <stdio.h>

// protótipos das funções
void hanoi(int n, char origem, char destino, char auxiliar);


/**********************************************************************
Função principal
**********************************************************************/
int main()
{
	int n;

  // lê o número de discos do problema
	printf("Digite o numero de discos: ");
	scanf("%d",&n);

  printf("\n\n-------------------------------------------------------------\n");
	printf(" Sequência de movimentos de %d discos da base A para a base C\n", n);
  printf("-------------------------------------------------------------\n");

  // chamada da função recursiva para mover os n discos da base de origem (A) 
  // para a base destino (C) utilizando uma base auxiliar (B)
  hanoi(n,'A','C','B');

	printf("\n");

	return 0;
}

/**********************************************************************
Função recursiva que move n discos da base de origem para a base destino. 
Os discos estão nomeados de 1 a n, onde 1 é o menor e o n é o maior disco.
Parâmetros: n - numero de discos
            origem - base onde estão os discos inicialmente
            destino - base para qual os discos devem ser movidos
            auxiliar - base auxiliar para resolver o problema
**********************************************************************/
// 
void hanoi(int n, char origem, char destino, char auxiliar)
{
	// caso base: as chamadas recursivas param quando sobra apenas um disco a ser movido para a base destino
	if(n == 1){ 
		printf("\n Mover o disco %d de %c para %c (CASO BASE) ", n, origem, destino);
		return;
	}

	// mover os n-1 discos da base de origem para a base auxiliar, usando a base destino como auxiliar
  hanoi(n-1, origem, auxiliar, destino);

  // imprime o movimento do maior disco da pilha
  printf("\n\n Mover o disco %d de %c para %c \n", n, origem, destino);
  
	// Mover os n-1 discos da base de auxiliar para a base destino, usando a base origem como auxiliar
	hanoi(n-1, auxiliar, destino, origem);

  
}
