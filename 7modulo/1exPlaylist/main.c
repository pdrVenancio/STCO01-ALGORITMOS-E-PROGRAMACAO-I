/*************************************************************
# Lista Duplamente Encadeada

### Autores:
2023010066 - PEDRO VENÂNCIO DOS SANTOS
2023003929 - BRENO VIEIRA NOGUEIRA CARNEIRO
2023005075 - MATHEUS LAZARO DE LIMA

***************************************************************/

#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Lista *li = NULL;
  Lista *l2 = NULL;
  int opcao, res, res2, op;

  do {
    printf("\n\n ♫  ♪  ♫  ♪   MENU DE MUSICAS   ♫  ♪  ♩  ♫\n");
    printf("\n\t\t\t0 - Sair\n\t\t\t1 - Criar lista");
    printf("\n\t\t\t2 - Liberar lista\n\t\t\t3 - Inserir música");
    printf("\n\t\t\t4 - Remover especifico\n\t\t\t5 - Imprimir lista");
    printf("\n\t\t\t6 - Player de músicas\n");
    printf("\nOpção: ");
    // Volume: ▁▂▃▄▅▆▇ 100%
    // Fazer uma lista para aumentar e diminuir o som

    scanf("%d", &opcao);

    switch (opcao) {

    case 0:
      liberarLista(li);
      liberarLista(l2);
      printf("\nFinalizando...\n\n");
      return 0;
      break;
    case 1:
      li = alocarLista();
      l2 = alocarLista();

      if (li != NULL && l2 != NULL) {
        printf("\nLista criada com sucesso!");
        Volume(l2);
      }
      else
        printf("\nLista nao criada!");

      break;
    case 2:
      res = liberarLista(li);
      res2 = liberarLista(l2);
      li = NULL;
      l2 = NULL;

      if (res && res2)
        printf("\nLista liberada com sucesso!");
      else
        printf("\nLista nao liberada!");

      break;

    case 3:
      res = inserirFinalLista(li);

      if (res == 1)
        printf("\nInsercao realizada com sucesso!");
      else
        printf("\nFalha na insercao!");

      break;
    case 4:
      res = removerEspecifico(li);

      if (res == 1)
        printf("\nRemocao realizada com sucesso!");
      else
        printf("\nFalha na remocao, elemento nao encontrado!");

      break;

    case 5:
      imprimirLista(li);
      break;
    case 6:
      system("clear");
      player(li, l2);

      break;
    default:
      printf("\nOpcao invalida!");
      break;
    }

  } while (1 == 1);

  return 0;
}