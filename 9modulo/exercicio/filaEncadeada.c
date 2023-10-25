// TAD para Fila Dinâmica Encadeada baseado no livro "Estrutura de dados
// descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "filaEncadeada.h"

// criando elemento
struct elemento {
  char fila;
  char tipo;
  int dado;
  struct elemento *prox;
};

// typedef do elemento
typedef struct elemento Elemento;

// criando nó descritor
struct descritor {
  Elemento *inicio;
  Elemento *fim;
  int quant;
  int qnt_max;
};

// função para alocar memória do tipo Fila
Fila *criar_fila(int n) {
  Fila *fi = (Fila *)malloc(sizeof(Fila));

  if (fi != NULL) {
    fi->inicio = NULL;
    fi->fim = NULL;
    fi->quant = 0;
    fi->qnt_max = n;
  }
  return fi;
}

// função para liberar memória
int liberar_fila(Fila *fi) {

  if (fi == NULL) {
    return 0;
  }

  Elemento *atual;

  // percorre a fila a partir do início removendo os elementos
  while (fi->inicio != NULL) {
    atual = fi->inicio;

    fi->inicio = fi->inicio->prox;
    fi->quant--;

    free(atual);
  }

  free(fi);

  return 1;
}

// função para alocar memória do tipo Elemento
Elemento *criar_elemento() { return (Elemento *)malloc(sizeof(Elemento)); }

// função para inserir elemento no final da fila
int enfileirar(Fila *fi, int dado) {
  if (fi == NULL) {
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if (no == NULL) {
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = NULL;

  // se a fila estiver vazia, insere no início da fila
  if (fi->inicio == NULL) {
    fi->inicio = no;

    // senão insere elemento no final da fila
  } else {
    (fi->fim)->prox = no;
  }

  fi->fim = no;
  fi->quant++;

  return 1;
}
int enfileirar_main(Fila *fi, int dado, char fila, char tipo) {
  if (fi == NULL) {
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if (no == NULL) {
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->fila = fila;
  no->tipo = tipo;
  no->prox = NULL;

  // se a fila estiver vazia, insere no início da fila
  if (fi->inicio == NULL) {
    fi->inicio = no;

    // senão insere elemento no final da fila
  } else {
    (fi->fim)->prox = no;
  }

  fi->fim = no;
  fi->quant++;

  return 1;
}
// função para remover elemento do início da fila
int desenfileirar(Fila *fi) {
  if (fi == NULL) {
    return 0;
  }

  // fila vazia, não remove nada
  if (fi->inicio == NULL) {
    return 0;
  }

  // remove elemento do início da fila
  Elemento *no;
  no = fi->inicio;
  int ficha = fi->inicio->dado;

  fi->inicio = fi->inicio->prox;
  fi->quant--;

  // libera Elemento no
  free(no);

  // se a fila ficou vazia
  if (fi->inicio == NULL) {
    fi->fim = NULL;
  }

  return ficha;
}

void desenfileirar_main(Fila *fi, char tipo) {
  if (fi == NULL) {
    printf("fi = null\n");
  }

  // Fila vazia, não remove nada
  if (fi->inicio == NULL) {
  }
  Elemento *aux = fi->inicio;
  int tipo_fi;

  if (tipo == 'P') {
    
    //verifico se existe negocial e caixa
    if ((verifica_neg(fi) && verifica_pref(fi)) && (verifica_cai(fi) && verifica_pref(fi))) {
      srand(time(NULL));
      tipo_fi = rand() % 2;
      
    //devo verificar se nao tem pessoas para serem atendidas no caixa mas existem para
    //serem atendidas no negocial
    } else if (!verifica_cai(fi) && (verifica_pref(fi) && verifica_neg(fi)))
      tipo_fi = 1;

    //devo verificar se nao tem pessoas para serem atendidas no negocial mas existem para
    //serem atendidas no caixa
    else if (!verifica_neg(fi) && (verifica_cai(fi) && verifica_neg(fi)))
      tipo_fi = 0;
    
    if (tipo_fi == 0) {
      while (aux != NULL) {
        if (aux->fila == 'X' && aux->tipo == 'P') {
          printf("\nSenha: %c%c%d", aux->fila, aux->tipo, aux->dado);
          break;
        }
        aux = aux->prox;
      }

    }else if (tipo_fi == 1) {
      while (aux != NULL) {
        if (aux->fila == 'N' && aux->tipo == 'P') {
          printf("\nSenha: %c%c%d", aux->fila, aux->tipo, aux->dado);
          break;
        }
        aux = aux->prox;
      }
    }
  }else if (tipo == 'C'){
    //verifico se existe negocial e caixa
    if ((verifica_neg(fi) && verifica_com(fi)) && (verifica_cai(fi) && verifica_com(fi))) {
      srand(time(NULL));
      tipo_fi = rand() % 2;

    //devo verificar se nao tem pessoas para serem atendidas no caixa mas existem para
    //serem atendidas no negocial
    } else if (!verifica_cai(fi) && (verifica_com(fi) && verifica_neg(fi)))
      tipo_fi = 1;

    //devo verificar se nao tem pessoas para serem atendidas no negocial mas existem para
    //serem atendidas no caixa
    else if (!verifica_neg(fi) && (verifica_com(fi) && verifica_cai(fi)))
      tipo_fi = 0;
    
    if(tipo_fi == 0){
      while (aux != NULL) {
        if (aux->fila == 'X' && aux->tipo == 'C') {
          printf("\nSenha: %c%c%d", aux->fila, aux->tipo, aux->dado);
          break;
        }
        aux = aux->prox;
      }

    } else if (tipo_fi == 1) {

      while (aux != NULL) {
        if (aux->fila == 'N' && aux->tipo == 'C') {
          printf("\nSenha: %c%c%d", aux->fila, aux->tipo, aux->dado);
          break;
        }
        aux = aux->prox;
      }
    } 
  }
  Elemento *anterior = fi->inicio;
  if (aux != NULL) {
    // Caso seja o primeiro
    if (aux == fi->inicio) {
      fi->inicio = aux->prox;
    } else {
      // Caso seja o ultimo.

      while (anterior->prox != aux) {
        anterior = anterior->prox;
      }
      anterior->prox = aux->prox;
    }

    //caso seja o ultimo
    if (aux == fi->fim) {
      fi->fim = anterior;
    }
    
    free(aux);
    fi->quant--;
  }
}

void printa_main(Fila * fi){
  Elemento *aux = fi->inicio;

  while (aux != NULL) {
    printf("\t%c%c%d", aux->fila, aux->tipo, aux->dado);
    aux = aux->prox;
  }
}
int verifica_pref(Fila * fi) {
  Elemento *aux = fi->inicio;
  while (aux != NULL) {
    if (aux->tipo == 'P')
      return 1;

    aux = aux->prox;
  }
  return 0;
}
int verifica_com(Fila * fi) {
  Elemento *aux = fi->inicio;
  while (aux != NULL) {
    if (aux->tipo == 'C')
      return 1;

    aux = aux->prox;
  }
  return 0;
}
int verifica_cai(Fila * fi) {
  Elemento *aux = fi->inicio;
  while (aux != NULL) {
    if (aux->fila == 'X')
      return 1;

    aux = aux->prox;
  }
  return 0;
}
int verifica_neg(Fila * fi) {
  Elemento *aux = fi->inicio;
  while (aux != NULL) {
    if (aux->fila == 'N')
      return 1;

    aux = aux->prox;
  }
  return 0;
}

// função para consultar o primeiro elemento
int consultar_inicio_fila(Fila * fi, int *dado) {
  // verifica se a fila foi criada corretamente e se não está vazia
  if (fi == NULL || fi->inicio == NULL) {
    return 0;
  }

  // copia o dado do início da fila
  *dado = fi->inicio->dado;

  return 1;
}

// função que devolve o tamanho da fila
int tamanho_fila(Fila * fi) {
  if (fi == NULL) {
    return -1;
  }
  return fi->quant;
}
