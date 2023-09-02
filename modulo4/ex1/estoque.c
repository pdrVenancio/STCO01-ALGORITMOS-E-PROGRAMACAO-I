#include "estoque.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct produto {
  char nome[30];
  int cod;
  int qnt;
  float preco;
};

struct lista {
  produto *item[MAX];
  int cont;
};

// criar lista
lista *criarLista() {
  lista *li = (lista *)malloc(sizeof(lista));
  
  if (li != NULL){
    li->cont = 0;
  }
   return li;
}

// liberar lista
int liberarLista(lista **li){
  if(li == NULL)
    return 0;

  free(*li);
  *li = NULL;

  return 1;
}
int listaCheia(lista *li) {
	if (li == NULL) {
		return -1;
	}

	if (li->cont == MAX) {
		return 1;
	}

	return 0;
}


int inserirItem(lista *li){
  if (li == NULL) {
    return 0;
  }
  if (listaCheia(li) == 1) {
		return 0;
	}
  
  li->item[li->cont] = (produto *)malloc(sizeof(produto));
  
  printf("\nInsira o nome: ");
  scanf(" %s", li->item[li->cont]->nome);
  printf("Insira o codigo: ");
  scanf(" %d", &li->item[li->cont]->cod);
  printf("Insira a quantidade: ");
  scanf(" %d", &li->item[li->cont]->qnt);
  printf("Insira o preco: ");
  scanf("%f", &li->item[li->cont]->preco);
  
  li->cont++;

  return 1;
}

// Imprimir produtos recursivamente
void imprimirProduto(lista *li, int i) {
  if (i >= li->cont) 
    return;

  printf("\nCódigo: %d\nNome: %s\nPreço: %.2f\nQuantidade: %d\n\n", li->item[i]->cod, li->item[i]->nome, li->item[i]->preco, li->item[i]->qnt);

  imprimirProduto(li, i + 1);
}

// buscar menor produto
produto *buscarMenorPreco(lista *li) {
    produto *menor = li->item[0];
    for (int i = 1; i < li->cont; i++) {
        if (li->item[i]->preco < menor->preco) {
            menor = li->item[i];
        }
    }

    printf("Produto de menor preço:\nCodigo: %d\nNome: %s\nPreço: %.2f\nQntidade: %d\n\n",menor->cod,menor->nome, menor->preco, menor->qnt);
  
    return 0;
}
//Remova os n últimos elementos de uma lista
int removerUltimosElementos(lista *li, int n){
  if (n < 0 || n > li->cont) {
        return 0;
    }
    
    li->cont -= n;
    return 1;
  
}
//Receba a posição de dois elementos da lista e os troque de lugar
int trocarElementos(lista *li, int pos1, int pos2) {
    if (pos1 < 0 || pos1 >= li->cont || pos2 < 0 || pos2 >= li->cont) {
        return 0;
    }

    produto *temp = li->item[pos1];
    li->item[pos1] = li->item[pos2];
    li->item[pos2] = temp;

    return 1;
}