#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho_palavra 100

struct celula {
  struct celula *ant;
  char valor[tamanho_palavra];
  struct celula *prox;
};

void criarValor(char valor[]) {
  printf("Digite uma musica: ");
  scanf(" %[^\n]", valor);
}

Celula *alocarCelula() {
  Celula *no = (Celula *)malloc(sizeof(Celula));

  return no;
}

Lista *alocarLista() {
  Lista *li = (Lista *)malloc(sizeof(Lista));

  if (li != NULL)
    *li = NULL;

  return li;
}

int liberarLista(Lista *li) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  Celula *no;
  while (*li != NULL) // percorre os nos liberando o ultimo repetidamente
  {
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  free(li); // libera a cabeca da lista

  return 1;
}

//////////////////////////////////////////////////////////
int inserirFinalLista(Lista *li) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  char dado[tamanho_palavra];
  criarValor(dado);
  Celula *no = alocarCelula();

  if (no == NULL) // verifica se no foi criado corretamente
    return 0;

  if ((*li) == NULL) // se lista vazia, insere no inicio
  {
    strcpy(no->valor, dado);
    no->prox = no->ant = NULL;
    *li = no;
  } else // se cheia, insere no final
  {
    Celula *aux;
    aux = *li;

    while (aux->prox != NULL) // percorre a lista ate o final
      aux = aux->prox;

    strcpy(no->valor, dado);
    no->ant = aux;
    no->prox = NULL;
    aux->prox = no;
  }

  return 1;
}

// int removerInicioLista(Lista *li) {
//   if (li == NULL) // verifica se a lista existe
//     return 0;

//   if ((*li) == NULL)
//     return 0;

//   Celula *atual;
//   atual = *li;
//   *li = atual->prox;

//   if (atual->prox != NULL)
//     atual->prox->ant = NULL;

//   free(atual);

//   return 1;
// }

// int removerFinalLista(Lista *li) {
//   if (li == NULL) // verifica se a lista existe
//     return 0;

//   if ((*li) == NULL)
//     return 0;

//   Celula *atual;
//   atual = *li;

//   while (atual->prox != NULL)
//     atual = atual->prox;

//   if (atual->ant == NULL)
//     *li = atual->prox;
//   else
//     atual->ant->prox = NULL;

//   free(atual);

//   return 1;
// }

int removerEspecifico(Lista *li) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  if ((*li) == NULL)
    return 0;

  char dado[100];
  criarValor(dado);

  Celula *atual;
  atual = *li;

  while (atual != NULL && strcmp(atual->valor, dado) != 0)
    atual = atual->prox;

  if (atual == NULL)
    return 0;

  if (atual->ant == NULL)
    *li = atual->prox;
  else
    atual->ant->prox = atual->prox;

  if (atual->prox != NULL)
    atual->prox->ant = atual->ant;

  free(atual);
  return 1;
}

// int buscaCelulaPosicao(Lista *li) {
//   int pos;
//   printf("\nPosição do elemento a ser buscado: ");
//   scanf("%d", &pos);

//   if (li == NULL || (*li) == NULL || pos <= 0)
//     return 0;

//   Celula *no = *li;
//   int i = 1;

//   while (no != NULL && i < pos) {
//     no = no->prox;
//     i++;
//   }

//   if (no == NULL) // verifica se no foi criado corretamente
//     return 0;

//   printf("\nElemento da %dª posição: %d", pos, no->valor);

//   return 1;
// }

// int buscaCelulaDado(Lista *li) {
//   if (li == NULL || (*li) == NULL)
//     return 0;

//   int valor, pos = 1;
//   printf("\nValor a ser buscado: ");
//   scanf("%d", &valor);

//   Celula *no = *li;

//   while (no != NULL && no->valor != valor) {
//     no = no->prox;
//     pos++;
//   }

//   if (no == NULL) // verifica se no foi criado corretamente
//     return 0;

//   printf("\nElemento %d está na %dª posição", valor, pos);

//   return 1;
// }

int imprimirLista(Lista *li) {
  if (li == NULL || (*li) == NULL) {
    printf("\nLista não encontrada!");
    return 0;
  }

  printf("\nLISTA:\n");

  Celula *aux = (*li);

  int i = 1;

  while (aux->prox != NULL) {
    printf("%d -", i);
    printf(" %s \n", aux->valor);

    aux = aux->prox;
    i++;
  }

  printf("%d -", i);
  printf(" %s ", aux->valor);

  return 1;
}
void player(Lista *li) {
    if (li == NULL || *li == NULL) {
        printf("Lista nao existe ou esta vazia.\n");
        return;
    }
    int op;
    Celula *aux = *li;

    printf("\nTocando:\n\t%s\n",aux->valor);
    do{
      
      printf("\n1 - ant\t2 - prox\t0 - sair\nOpcao: ");
      scanf(" %d", &op);
      if(op == 1)
      {
        if (aux->ant != NULL) {
          aux = aux->ant;
          printf("\nTocando:\n\t%s\n", aux->valor);
        } else {
          printf("Nao existe musica anterior.\n");
        }
      }else if (op == 2)
      {
        if (aux->prox != NULL) {
          aux = aux->prox;
          printf("\nTocando:\n\t%s\n", aux->valor);
        } else {
          printf("Nao existe proxima musica.\n");
        }
      }else if(op == 0)
        printf("\n\tSaindo do modo player...\n\n");
      else
        printf("Opcao invalida");
      
    }while(op != 0);
    
}