 

// bibliotecas do sistema
#include <stdio.h>

// bibliotecas do projeto
#include "ListaEncadeadaCircular.h"

int criar_dado(int *dado);

// funcao principal
int main(void) {
  
  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *l1 = NULL;
  Lista *l2 = NULL;
  int opcao, dado, ok, pos;

  ///***************************************************************************//
  //              deicxandoa as listas ja preenxidas

  l1 = criar_lista();
  l2 = criar_lista();


  inserir_lista_inicio(l1, 12);
  inserir_lista_inicio(l1, 1);
  inserir_lista_inicio(l1, 23);
  inserir_lista_inicio(l1, 2);
  inserir_lista_inicio(l1, 2);
  inserir_lista_inicio(l1, 1);
  

  //inserir_lista_inicio(l2, 10);
  //inserir_lista_inicio(l2, 1);
  //inserir_lista_inicio(l2, 0);
  //inserir_lista_inicio(l2, 100);
  //inserir_lista_inicio(l2, 32);
  
  
  
 
  // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Inserir elemento no início");
    printf("\n4 - Inserir elemento no final");
    printf("\n5 - Inserir elemento (ordenado)");
    printf("\n6 - Remover elemento do início");
    printf("\n7 - Remover elemento do final");
    printf("\n8 - Remover elemento (qualquer)");
    printf("\n9 - Buscar elemento pela posição");
    printf("\n10 - Buscar elemento pelo dado");
    printf("\n11 - Imprimir lista");    
    printf("\n12 - Sair");
    printf("\n13 - Concatenar lista");
    printf("\n14 - Copiar valores repetidos de L1 para L2");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1: 

        // criar lista
        l1 = criar_lista();

        if(l1 != NULL){
          printf("\n Lista criada com sucesso!");
        }else{
          printf("\n Lista não criada!");
        }
        break;


      case 2: 
        
        // liberar lista
        ok = liberar_lista(l1);
        l1 = NULL; 

        if(ok){
          printf("\n Lista liberada com sucesso!");
        }else{
          printf("\n Lista não liberada!");
        }
        break;

      case 3:

        // inserir elemento no início
        ok = criar_dado(&dado);               
        ok = inserir_lista_inicio(l1, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 4:

        // inserir elemento no final
        ok = criar_dado(&dado);
        ok = inserir_lista_final(l1, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 5:

        // inserir elemento de forma ordenada
        ok = criar_dado(&dado);
        ok = inserir_lista_ordenada(l1, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 6:    

        // remover elemento do início 
        ok = remover_lista_inicio(l1);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 7:    

        // remover elemento do final 
        ok = remover_lista_final(l1);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 8:    
      
        // remover elemento do meio 
        printf("\n Código a ser removido: ");
        scanf("%d", &dado); 

        ok = remover_lista_meio(l1, dado);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;


      case 9:
      
        // busca elemento pela posicao
        printf("\n Posição do elemento a ser buscado: ");
        scanf("%d", &pos); 

        ok = buscar_lista_posicao(l1, pos, &dado);

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ", pos);
          printf("%d", dado);
        }else{
          printf("\n Posição não existe!");
        }

        break;

      case 10:
      
        // busca elemento pelo dado
        printf("\n Código a ser buscado: ");
        scanf("%d", &dado); 

        ok = buscar_lista_dado(l1, dado, &pos);

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento com código %d na lista: ", dado);
          printf("%d", pos);
        }else{
          printf("\n Elemento não encontrado!");
        }

        break;

      case 11:

        // imprime a lista
        printf("\n Lista encadeada circular L1: ");
        imprimir_lista(l1);

        
        printf("\n Lista encadeada circular L2: ");
        if(*l2 != NULL)
          imprimir_lista(l2);  
        
        break;
      
      case 12:

        // libera memória e finaliza programa
        liberar_lista(l1);
        printf("\nFinalizando...");
        break;

      case 13:
        ok = concatenar_lista(l1, l2);
        if(ok == 1)
          printf("listaNULL");
        else if (ok == 0)
          printf("\n\tLista concatenada com sucesso!\n");
        break;
      
      case 14:
        
        ok = valores_repetidos(l1, l2);
        if(ok == 1)
          printf("Listas vazias");
        else if (ok == 0)
          printf("\n\tElementos transferidos com sucesso!\n");
        break;

      default: 
        printf("\nOpção inválida!");
        break;
    }
    

  }while(opcao != 12);


//*********************************************************
  liberar_lista(l1);
  liberar_lista(l2);


  return 0;
}

int criar_dado(int *dado)
{
    printf("\nDigite um valor: ");
    scanf("%d", dado);

    return 1;
}