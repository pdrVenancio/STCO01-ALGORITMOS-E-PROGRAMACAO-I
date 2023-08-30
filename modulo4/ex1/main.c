/*
      PLANO

    1 - fazer a inserção no final da lista
    2 - funcao para verificar se a lista esta cheia
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "estoque.h"

int main(void) {
  
  estoque *li = NULL;
  int op, dado, ok;
  estoque *a;

  do {

    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Buscar item");
    printf("\n4 - Remova os n últimos elementos de uma lista");
    printf("\n5 - Receba a posição de dois elementos da lista e os troque de lugar");
    printf("\n6 - Imprimir todos os itens da lista.");
    printf("\n7 - Adcionar Iten.");    
    printf("\n0 - Sair");
    printf("\nOpção: ");
    scanf(" %d", &op);
    
    switch (op) {
    case 1:
      //CRIAR LISTA

      li = criarLista();

      if(li != NULL)
      {
        printf("\nLista criada com sicesso!\n");
      }else
        printf("\n Lista nao criada(case 1 criarLista)");

      break;
    case 2:
      //LIBERAR LISTA

      ok = liberarLista(&li);

      if(ok)
        printf("\nLista liberada com sucesso %p ",li);
      else
        printf("\nlista nao liberada");
      
      break;
    case 3:
      //BUSCA
      printf("\nDigite o produto que deseja buscar: ");

      break;
    case 4:
     // Retornar SIM ou NÃO

      break;
    case 5:
      // Retornar SIM ou NÃO
      break;
    case 6:
      //Imprimir todos os itens 
      printf("Aquis estao todos os elementos da Lista:\n");
      
      break;
    }

  } while (op != 0);

  return 0;
}

estoque *novoProduto(estoque *a) {

    printf("\nCodigo: ");
    scanf("%d ", &a->cod);
    printf("\nNome: ");
    scanf("[^\n] ", a->nome);
    printf("\nPreco: ");
    scanf("%f ", &a->preco);
    printf("\nQuantidade: ");
    scanf("%d ", &a->qnt);
  
  return 0;
}