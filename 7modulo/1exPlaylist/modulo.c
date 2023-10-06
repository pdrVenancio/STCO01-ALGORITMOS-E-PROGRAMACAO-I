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
  if (li == NULL)
    return 0;

  Celula *no;
  while (*li != NULL) {
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  free(li);

  return 1;
}

int inserirFinalLista(Lista *li) {
  if (li == NULL)
    return 0;

  char dado[tamanho_palavra];
  criarValor(dado);
  Celula *no = alocarCelula();

  if (no == NULL)
    return 0;

  if ((*li) == NULL) {
    strcpy(no->valor, dado);
    no->prox = no->ant = NULL;
    *li = no;
  } else {
    Celula *aux;
    aux = *li;

    while (aux->prox != NULL)
      aux = aux->prox;

    strcpy(no->valor, dado);
    no->ant = aux;
    no->prox = NULL;
    aux->prox = no;
  }

  return 1;
}

int removerEspecifico(Lista *li) {
  if (li == NULL)
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
void player(Lista *li, Lista *l2) {
  if (li == NULL || *li == NULL) {
    printf("Lista nao existe ou esta vazia.\n");
    return;
  }
  int op;
  Celula *aux = *li;
  Celula *aux2 = *l2;

  printf("__________________________________________________\n");
  printf("\nTOCANDO AGORA: \033[32m%s\033[0m\n", aux->valor);
  printf("\t\t─●───────────────\n");
  printf("\t\t    ◁   ❚❚ㅤ ▷ㅤ\n\n");
  printf("\t\t%s\n", aux2->valor);
  printf("__________________________________________________\n");
  do {

    printf("\n1: Tocar musica anterior\n2: Tocar proxima musica\n3: Diminuir Volume\n4: Aumentar Volume\n0: Sair do player\n\nOpcao: ");
    scanf(" %d", &op);
    if (op == 1) {
      if (aux->ant != NULL) {
        aux = aux->ant;
        printf("__________________________________________________\n");
        printf("\nTOCANDO AGORA: \033[32m%s\033[0m\n", aux->valor);
        printf("\t\t─●───────────────\n");
        printf("\t\t    ◁   ❚❚ㅤ ▷ㅤ\n\n");
        printf("\t\t%s\n", aux2->valor);
        printf("__________________________________________________\n");
      } else {
        printf("\nNao existe musica anterior.\n");
      }
    } else if (op == 2) {
      if (aux->prox != NULL) {
        aux = aux->prox;
        printf("__________________________________________________\n");
        printf("\nTOCANDO AGORA: \033[32m%s\033[0m\n", aux->valor);
        printf("\t\t─●───────────────\n");
        printf("\t\t    ◁   ❚❚ㅤ ▷ㅤ\n\n");
        printf("\t\t%s\n", aux2->valor);
        printf("__________________________________________________\n");
      } else {
        printf("\nNao existe proxima musica.\n");
      }
    } else if (op == 3) {
      if (aux2->prox != NULL) {
        aux2 = aux2->prox;
        printf("__________________________________________________\n");
        printf("\nTOCANDO AGORA: \033[32m%s\033[0m\n", aux->valor);
        printf("\t\t─●───────────────\n");
        printf("\t\t    ◁   ❚❚ㅤ ▷ㅤ\n\n");
        printf("\t\t%s\n", aux2->valor);
        printf("__________________________________________________\n");
      } else {
        printf("\nSe abaixar mais não tem música. Vou abaixar não kk.\n");
      }
    } else if (op == 4) {
        if (aux2->ant != NULL) {
        aux2 = aux2->ant;
        printf("__________________________________________________\n");
        printf("\nTOCANDO AGORA: \033[32m%s\033[0m\n", aux->valor);
        printf("\t\t─●───────────────\n");
        printf("\t\t    ◁   ❚❚ㅤ ▷ㅤ\n\n");
        printf("\t\t%s\n", aux2->valor);
        printf("__________________________________________________\n");
      } else {
        printf("\nVolume já está no máximo.\n");
      }
    } else if (op == 0)
      system("clear");
    else
      printf("Opcao invalida");

  } while (op != 0);
}

void Volume(Lista *l2) {
  char volumes[7][100] = {
    "Volume: ▁ 10%",
    "Volume: ▁▂ 20%",
    "Volume: ▁▂▃ 30%",
    "Volume: ▁▂▃▄ 50%",
    "Volume: ▁▂▃▄▅ 70%",
    "Volume: ▁▂▃▄▅▆ 80%",
    "Volume: ▁▂▃▄▅▆▇ 100%"
  };

  for (int i = 0; i < 7; i++) {
    Celula *no = alocarCelula();

    if (*l2 == NULL) {
      strcpy(no->valor, volumes[i]);
      no->prox = no->ant = NULL;
      *l2 = no;
    } else {
      strcpy(no->valor, volumes[i]);
      no->ant = NULL;
      no->prox = *l2;
      (*l2)->ant = no;
      *l2 = no;
    }
  }
}