#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"



//criar lista de produto
estoque* criarLista()
{
  estoque *li = (estoque*)malloc(sizeof(estoque));

  if(li != NULL)
  {
    li->qnt = 0;
  }
  return li;
}

//Liberar lista
int liberarLista(estoque **li)
{
  if(*li == NULL)
    return 0;
  
  free(*li);
  *li = NULL;
  return 1;
}

// verificar se a lista esta cheia
int cheiaLista(estoque *li)
{
  if(li == NULL)
    return -1;
  if(li->qnt == MAX)
    return 1;
  
  return 0;
}

// inserir elemento na lista
int inserirLista(estoque *li, int cod, float preco, char nome)
{
  if(li == NULL)
    return 0;
  if(cheiaLista(li) == 1)
    return 0;

  li->cod[li->qnt] = cod;
  li->preco[li->qnt] = preco;
  li->nome
  
}