// TAD para Fila Dinâmica Encadeada baseado no livro "Estrutura de dados
// descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "filaEncadeada.h"

// criando elemento
struct elemento {
  char cod[2];
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
int enfileirar_main(Fila *fi, int dado, char cod[2]) {
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
  strcpy(no->cod, cod);
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

int desenfilerar_main(Fila *fi){
  if (fi == NULL) {
    return 0;
  }

  // fila vazia, não remove nada
  if (fi->inicio == NULL) {
    return 0;
  }
  srand(time(NULL));
  // remove elemento do início da fila
  Elemento *no;
  int c = 0;
  no = fi->inicio;

  int tipo = rand() % 2;
  //1 - Caixa
  //2 - Negocial
  if(tipo == 1)
  {
    do{ 
      if(strcmp(&(no->cod[0]), "X") == 0)
      {
        if(strcmp(&(no->cod[1]), "P") == 0)
        {
    
        } 
      }
  
      fi->inicio = fi->inicio->prox;
    }while(fi->inicio != NULL);
  }


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

// função para consultar o primeiro elemento
int consultar_inicio_fila(Fila *fi, int *dado) {
  // verifica se a fila foi criada corretamente e se não está vazia
  if (fi == NULL || fi->inicio == NULL) {
    return 0;
  }

  // copia o dado do início da fila
  *dado = fi->inicio->dado;

  return 1;
}

// função que devolve o tamanho da fila
int tamanho_fila(Fila *fi) {
  if (fi == NULL) {
    return -1;
  }
  return fi->quant;
}
