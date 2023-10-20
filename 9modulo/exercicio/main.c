
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
  
  int opcao, ok, pos, op;
  int dado;
  int n;

  printf("Digite o numero maximos de fichas do dia: ");
  scanf("%d", &n);
  
  // menu de opções para execuções de operações sobre a fila
  do {
    printf("\n\nMenu de opções");
    printf("\n2 - Liberar fila");
    printf("\n3 - Adicionar elemento");
    printf("\n4 - Retirar elemento");
    printf("\n5 - Consultar início da fila");
    printf("\n6 - Criar fila Caixa");
    printf("\n7 - Criar fila Negocial");
    printf("\n0 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 2:

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

    case 3:

      // enfileirar elemento
      for( int i = n; i >= 0 ; i--)
        {
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

    case 4:

      // desenfileirar elemento
      ok = desenfileirar(fi_caixa_conv);

      if (ok == 1) {
        printf("\n Remoção realizada com sucesso!");
      } else {
        printf("\n Falha na remoção!");
      }
      break;

    case 5:

      ok = consultar_inicio_fila(fi_caixa_conv, &dado);

      if (ok) {
        printf("\n Busca realizada com sucesso!");
        printf("\n Elemento no início da fila: ");
        printf("%d", dado);
      } else {
        printf("\n Fila vazia!");
      }

      break;
      
    //Negocial
    case 6:
      // criar fila
      printf("\n1 - Preferencial\t2 - Convencional\n");

      scanf(" %d", &op);
      if(op == 1)
        fi_negocial_pref = criar_fila();
      else if (op == 2)
        fi_negocial_conv = criar_fila();
      else
        printf("Opcao invalida!");
      
      if (fi_negocial_conv != NULL && fi_negocial_pref != NULL) {
        printf("\n Fila criada com sucesso!");
      } else {
        printf("\n Fila não criada!");
      }
      break;
      
    //Caixa
    case 7:
      printf("\n1 - Preferencial\t2 - Convencional\n");
      
      scanf(" %d", &op);
      if(op == 1)
        fi_caixa_pref = criar_fila();
      else if (op == 2)
        fi_caixa_conv = criar_fila();
      else
        printf("Opcao invalida!");
      

      if (fi_caixa_conv != NULL && fi_caixa_pref != NULL) {
        printf("\n Fila criada com sucesso!");
      } else {
        printf("\n Fila não criada!");
      }
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

//int criar_dado(int *dado) {
//  printf("\nDigite um número inteiro: ");
//  scanf("%d", dado);
//
//  return 1;
//}