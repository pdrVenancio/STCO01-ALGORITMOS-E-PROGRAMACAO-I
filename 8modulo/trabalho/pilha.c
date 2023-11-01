// TAD para Pilha Dinâmica Encadeada usando Nó Descritor com topo no início da pilha

#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"


//criando elemento
struct elemento{
    int dado;
    struct elemento *prox;
};

//typedef do elemento
typedef struct elemento Elemento;

//criando nó descritor
struct descritor{
    struct elemento *inicio;
    struct elemento *fim;
    int quant;
};


// função para alocar memória do tipo Pilha
Pilha* criar_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->inicio = NULL;
        pi->fim = NULL;
        pi->quant = 0;
    }
    return pi;
}

// função para liberar memória
int liberar_pilha(Pilha *pi){

  if(pi == NULL){    
    return 0;
  }

  Elemento *atual;

  if(pi->inicio == NULL){
      pi->fim = NULL;

  }else{
    while (pi->fim != NULL){
      atual = pi->inicio;
      pi->inicio = atual->prox;
      free(atual);

      if(pi->inicio == NULL){
        pi->fim = NULL;
      }
    }

    free(pi);
  }

  return 1;
}

// função para alocar memória do tipo Elemento
Elemento* criar_elemento(){
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL){
        return 0;
    }

    return no;
}


// função para inserir elemento no topo da pilha (início da lista)
int empilhar(Pilha *pi, int dado){

  if(pi == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = pi->inicio;

  if(pi->inicio == NULL)
    pi->fim = no;

  // insere elemento no início da pilha
  pi->inicio = no;  
  pi->quant++;

  return 1;
}

// função para remover elemento do topo da pilha (início da lista)
int desempilhar(Pilha *pi){

  if(pi == NULL){
    return 0;
  }

  // pilha vazia, não remove nada
  if((pi->inicio) == NULL){
    return 0;
  }

  int valor;
  // muda inicio para o proximo elemento
  Elemento *no;
  
  no = pi->inicio;
  valor = no->dado;
  pi->inicio = no->prox;
  pi->quant--;

  // libera Elemento no
  free(no);

  if(pi->inicio == NULL)
    pi->fim = NULL;

  return valor;
}

// função para consultar o primeiro elemento
int consultar_topo_pilha(Pilha *pi, int *dado){

  // verifica se a pilha foi criada corretamente e se não está vazia
  if(pi == NULL || pi->inicio == NULL){
    return 0;
  }

  // copia o dado do topo da pilha (início da lista)
  *dado = pi->inicio->dado;

  return 1;
}

void imprimir(Pilha *pi)
{
  //pilha vazia, não remove nada
  if((pi->inicio) == NULL || pi == NULL){
    printf("");
  }else{
    struct elemento *aux = pi->inicio;
    printf("");
    do{
      printf("  %d ", aux->dado);
      aux = aux->prox;
      
    }while (aux != NULL);
  }  
}
// função que devolve o tamanho da pilha
int tamanho_pilha(Pilha *pi){
    if(pi == NULL){
        return -1;
    }
    return pi->quant;
}

int verificar_vitoria(Pilha *p, Pilha *pTeste) {

    struct elemento *aux = p->inicio;
    struct elemento *aux2 = pTeste->inicio;
    
    if(tamanho_pilha(p) == tamanho_pilha(pTeste)) {
        for(int i = 0; i < tamanho_pilha(p); i++) {   
            if(aux->dado == aux2->dado) {
                aux = aux->prox;
                aux2 = aux2->prox;
            }
            else return 0; // se retornar 0, o objetivo do jogo não foi cumprido ainda
        }
    }
    else return 0;

    // so vai chegar aqui se tudo tiver igual a pilha teste
    return 1; // se retornar 1, o objetivo do jogo foi cumprido
}