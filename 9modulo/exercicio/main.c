
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "filaEncadeada.h"

// funcao principal
int main(void) {

  // no início a fila está vazia, logo, o ponteiro inicio tem valor NULL
  // o ponteiro inicio conterá o endereço do primeiro elemento da fila
  Fila *fi_caixa_conv = NULL;
  Fila *fi_caixa_pref = NULL;
  Fila *fi_negocial_conv = NULL;
  Fila *fi_negocial_pref = NULL;
  Fila *fi_main = NULL;

  int opcao, ok, ok2, pos, op;
  int n, pre = 0, cont_n = 0, cont_caixa = 0, cont_negocial = 0, cont_max = 0;
  char tipo;

  //Numero limite de senhas no dia 
  printf("Digite o numero maximos de fichas do dia: ");
  scanf("%d", &n);

  //cria as filas ao iniciar o programa
  fi_main = criar_fila(n);
  fi_caixa_conv = criar_fila(n);
  fi_caixa_pref = criar_fila(n);
  fi_negocial_conv = criar_fila(n);
  fi_negocial_pref = criar_fila(n);

  if (fi_main != NULL && fi_negocial_conv != NULL && fi_negocial_conv != NULL && fi_caixa_conv != NULL && fi_caixa_pref != NULL) {
    printf("\n Fila criada com sucesso!");
    //enfileirar elementos        
  } else {
    printf("\n Fila não criada!");
  }
  //preenche todas as filas com numeros de 0 ate N
  for (int i = 0; i <= n; i++) {
    ok = enfileirar(fi_caixa_conv, i);
    ok = enfileirar(fi_caixa_pref, i);
    ok = enfileirar(fi_negocial_conv, i);
    ok = enfileirar(fi_negocial_pref, i);
  }

  // menu de opções para execuções de operações sobre a fila
  do {
    printf("\n\nMenu de opções");
    printf("\n1  - Retirar Ficha main");
    printf("\n2  - Verifica se fila esta vazia");
    printf("\n3  - Retirar ficha Caixa");
    printf("\n4  - Retirar ficha Negocial");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {
// RETIRAR FICHA DA MAIN
    case 1:
      cont_max++;
      
      ok = verifica_pref(fi_main);
      ok2 = verifica_com(fi_main);

      if(ok && ok2)
      {
        if (pre < 2) {
          tipo = 'P';
          desenfileirar_main(fi_main, tipo);
          pre++;
        }else{
          tipo = 'C';
          desenfileirar_main(fi_main, tipo);
          pre = 0;
        }
      }else if (!ok){
        tipo = 'C';
        desenfileirar_main(fi_main, tipo);
        
      }else if(!ok2){
        tipo = 'P';
        desenfileirar_main(fi_main, tipo);
      }
      printf("\nFila principal: ");
      printa_main(fi_main);

      break;

// Verifica se lista esta vazia
    case 2:

      ok = tamanho_fila(fi_main);
      if(ok == 0)
        printf("\nFila vazia!");
      else
        printf("\nFila ainda possui %d senhas para atendimento!",ok);

      break;

//Pegar senha para o caixa
    case 3:
      if(cont_n < n){
        cont_caixa++;
        printf("\n1 - Preferencial\t2 - Convencional\n");

        scanf(" %d", &op);
        if (op == 1) {
          int fichaXP = desenfileirar(fi_caixa_pref);
          char fila = 'X';
          char tipo = 'P';
          ok = enfileirar_main(fi_main, fichaXP, fila, tipo);
          cont_n++;

          if (ok)
            printf("\nFicha adicionada a fila principal!\nFila Rincipal: ");
            printa_main(fi_main);
        } else if (op == 2) {
          int fichaXC = desenfileirar(fi_caixa_conv);
          char fila = 'X';
          char tipo = 'C';
          ok = enfileirar_main(fi_main, fichaXC, fila, tipo);
          cont_n++;

          if (ok)
            printf("\nFicha adicionada a fila principal!\nFila Rincipal: ");
            printa_main(fi_main);
        }

        else
          printf("Opcao invalida!");
      }else
        printf("\nNumero maximo de senhas geradas!\n\t");
      
      break;
      
//Pegar senha para o negocial
    case 4:
      if(cont_n < n){
        cont_negocial++;
        printf("\n1 - Preferencial\t2 - Convencional\n");

        scanf(" %d", &op);
        if (op == 1) {
          int fichaNP = desenfileirar(fi_negocial_pref);
          char fila = 'N';
          char tipo = 'P';
          ok = enfileirar_main(fi_main, fichaNP, fila, tipo);
          cont_n++;

          if (ok)
          printf("\nFicha adicionada a fila principal!\nFila Rincipal: ");
          printa_main(fi_main);
        }

        else if (op == 2) {
          int fichaNC = desenfileirar(fi_negocial_conv);
          char fila = 'N';
          char tipo = 'C';
          ok = enfileirar_main(fi_main, fichaNC, fila, tipo);
          cont_n++;

          if (ok)
            printf("\nFicha adicionada a fila principal!\nFila Rincipal: ");
            printa_main(fi_main);
        }
        else
          printf("Opcao invalida!");
      }else
        printf("\nNumero maximo de senhas geradas! ");
      


      break;
    default:
      printf("\nOpção inválida!");
      break;
    }

  } while (cont_max < n);

  printf("\n\n\tATENDIMENTOS FINALIZADOS");
  printf("\n\tAtentendimestos no caixa: %d", cont_caixa);
  printf("\n\tAtentendimestos no negocial: %d", cont_negocial);
  liberar_fila(fi_caixa_conv);
  liberar_fila(fi_caixa_pref);
  liberar_fila(fi_negocial_conv);
  liberar_fila(fi_negocial_pref);
  printf("\n\nFinalizando...");
  
  return 0;
}
