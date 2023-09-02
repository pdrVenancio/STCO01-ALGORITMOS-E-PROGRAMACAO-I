#include "estoque.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// li == Lista
// ok == verdadeiro(deu certo) 0 falco(erro) 1

int main() {

  lista *li = NULL;
  
  int ok, op , n, p1, p2;

  do{
    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Inserir produtos");
    printf("\n4 - Imprimir lista");
    printf("\n5 - Retorne o produto de menor preço");
    printf("\n6 - Remova os n últimos elementos de uma lista");
    printf("\n7 - Receba a posição de dois elementos da lista e os troque de lugar");
    printf("\n0- Sair");
    printf("\nOpção: ");
    
    scanf(" %d", &op);
    switch(op){

      case 1:
// criar lista
        li = criarLista();
        if (li != NULL)
          printf("\n\tMemoria alocada com sucesso\n");
        else
          printf("\n\tErro ao alocar memoria\n");
      break;
      
      case 2:
// liberar llista
        ok = liberarLista(&li);
        if (ok)
          printf("\n\tMemoria liberada\n");
        else
          printf("\n\tErro ao liberar Memoria\n");
      break;

      case 3:
// inserir produtos
        ok = inserirItem(li);
        if (ok)
          printf("\n\tProduto inserido com sucesso\n");
        else
          printf("\n\tFalha ao inserir produto\n");
      break;
      
      case 4:
//imprimir lista
        printf("\nEsses sao os produtos presentes na lista\n\n");
        imprimirProduto(li, 0);
      break;
//Buscar menor preco
      case 5:
        buscarMenorPreco(li);  
      break;
//Remova os n últimos elementos de uma lista
      case 6:
        printf("\nDigite a quantidade de elementos que deseja retirar do final da lista: ");
        scanf("%d", &n);

        ok = removerUltimosElementos(li, n);
        
        if (ok == 1) {
        printf("Últimos %d elementos removidos.\n", n);
        } else {
            printf("Não foi possível remover os últimos %d elementos.\n", n);
        }
      break;
//Receba a posição de dois elementos da lista e os troque de lugar
      case 7:
        printf("\nDigite a posicao dos elementos que deseja trocar de lugar: ");
        scanf("%d %d", &p1 , &p2);

        ok = trocarElementos(li, p1 - 1, p2 - 1);
         if (ok == 1) {
        printf("A posicao %d e %d trocaram de lugar\n", p1, p2);
        } else {
            printf("Não foi possível trocar a posicao %d %d.\n", p1, p2);
        }
      break;
      case 0:
        liberarLista(&li);
        printf("\nencerrando execucao...\n");
      break;
      
      default:
        printf("\nOpção inválida!");
        break;
    }
    
  }while(op != 0);

  return 0;
}