
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "filaEncadeada.h"

// protótipo da função que cria um dado
int criar_dado(int *dado);

// funcao principal
int main(void) {

  // no início a fila está vazia, logo, o ponteiro inicio tem valor NULL
  // o ponteiro inicio conterá o endereço do primeiro elemento da fila
  Fila *fi_caixa_conv = NULL;
  Fila *fi_caixa_pref = NULL;
  Fila *fi_negocial_conv = NULL;
  Fila *fi_negocial_pref = NULL;
  Fila *fi_main = NULL;

  int opcao, ok, pos, op;
  int dado;
  int n, ficha;

  printf("Digite o numero maximos de fichas do dia: ");
  scanf("%d", &n);

  // menu de opções para execuções de operações sobre a fila
  do {
    printf("\n\nMenu de opções");
    printf("\n1  - Liberar fila");
    printf("\n2  - Adicionar elementos as filas criadas");
    printf("\n3  - Retirar Ficha main");
    printf("\n4  - Consultar inicio da fila Caixa");
    printf("\n5  - Consultar inicio da fila Negocial");
    printf("\n6  - Criar filas");
    printf("\n7  - Retirar ficha Caixa");
    printf("\n8  - Retirar ficha Negocial");
    printf("\n9 - Chama pessoa");
    printf("\n0  - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:

      // liberar fila
      ok = liberar_fila(fi_caixa_conv);
      fi_caixa_conv = NULL;

      ok = liberar_fila(fi_caixa_pref);
      fi_caixa_pref = NULL;

      ok = liberar_fila(fi_negocial_conv);
      fi_negocial_conv = NULL;

      ok = liberar_fila(fi_negocial_pref);
      fi_negocial_pref = NULL;

      if (ok) {
        printf("\n Fila liberada com sucesso!");
      } else {
        printf("\n Fila não liberada!");
      }
      break;

    case 2:

      // enfileirar elemento
      for (int i = 0; i <= n; i++) {
        ok = enfileirar(fi_caixa_conv, i);
        ok = enfileirar(fi_caixa_pref, i);
        ok = enfileirar(fi_negocial_conv, i);
        ok = enfileirar(fi_negocial_pref, i);
      }

      if (ok == 1) {
        printf("\n Inserção realizada com sucesso!");
      } else {
        printf("\n Falha na inserção!");
      }

      break;

      //RETIRAR FICHA DA MAIN
    case 3:
      ok = desenfileirar_main(fi_main);

      

      if (ok == 1) {
        printf("\n Remoção realizada com sucesso!");
      } else {
        printf("\n Falha na remoção!");
      }
      break;

    //Primeiro elemento fila Caixa
    case 4:
      printf("\n1 - Preferencial\t2 - Convencional\n");

      scanf(" %d", &op);
      if (op == 1)
        ok = consultar_inicio_fila(fi_caixa_pref, &dado);
      else if (op == 2)
        ok = consultar_inicio_fila(fi_caixa_conv, &dado);
      else
        printf("Opcao invalida!");
      

      if (ok) {
        printf("\n Busca realizada com sucesso!");
        printf("\n Elemento no início da fila: ");
        printf("%d", dado);
      } else {
        printf("\n Fila vazia!");
      }

      break;
      
    //Primeiro elemento fila Negocial
    case 5:
      printf("\n1 - Preferencial\t2 - Convencional\n");

      scanf(" %d", &op);
      if (op == 1)
        ok = consultar_inicio_fila(fi_negocial_pref, &dado);
      else if (op == 2)
        ok = consultar_inicio_fila(fi_negocial_conv, &dado);
      else
        printf("Opcao invalida!");


      if (ok) {
        printf("\n Busca realizada com sucesso!");
        printf("\n Elemento no início da fila: ");
        printf("%d", dado);
      } else {
        printf("\n Fila vazia!");
      }
      
    //CRIAR FILAS
    case 6:
      fi_main = criar_fila(n);
      fi_caixa_conv = criar_fila(n);
      fi_caixa_pref = criar_fila(n);
      fi_negocial_conv = criar_fila(n);
      fi_negocial_pref = criar_fila(n);

    
      if (fi_main != NULL && fi_negocial_conv != NULL && fi_negocial_conv != NULL && fi_caixa_conv != NULL && fi_caixa_pref != NULL  ) {
        printf("\n Fila criada com sucesso!");
      } else {
        printf("\n Fila não criada!");
      }

      break;

    // RETIRADAS DE FICHAS
      //caixa
    case 7:
      printf("\n1 - Preferencial\t2 - Convencional\n");

      scanf(" %d", &op);
      if (op == 1)
      {
        ficha = desenfileirar(fi_caixa_pref);
        printf("\n\t Seu numero e: XP%d", ficha);
        char code[2] = "XP";
        enfileirar_main(fi_caixa_pref, ficha , code);    
      }

      else if (op == 2)
      {
        desenfileirar(fi_caixa_conv);
        printf("\n\t Seu numero e: XC%d", ficha);
        char code[2] = "XC";
        enfileirar_main(fi_caixa_conv, ficha , code);
      }

      else
        printf("Opcao invalida!");

      
      break;
      //negocial
    case 8:
      printf("\n1 - Preferencial\t2 - Convencional\n");

      scanf(" %d", &op);
      if (op == 1)
      {
        ficha = desenfileirar(fi_negocial_pref);
        printf("\n\t Seu numero e: NP%d", ficha);
        char code[2] = "NP";
        enfileirar_main(fi_negocial_pref, ficha , code);
      }

      else if (op == 2)
      {
        desenfileirar(fi_negocial_conv);
        printf("\n\t Seu numero e: NC%d", ficha);
        char code[2] = "NC";
        enfileirar_main(fi_negocial_conv, ficha , code);
      }

      else
        printf("Opcao invalida!");


      break;
    case 0:

      // libera memória e finaliza programa
      liberar_fila(fi_caixa_conv);
      liberar_fila(fi_caixa_pref);
      liberar_fila(fi_negocial_conv);
      liberar_fila(fi_negocial_pref);
      printf("\nFinalizando...");
      break;

    default:
      printf("\nOpção inválida!");
      break;
    }

  } while (opcao != 0);

  return 0;
}

// int criar_dado(int *dado) {
//   printf("\nDigite um número inteiro: ");
//   scanf("%d", dado);
//
//   return 1;
// }