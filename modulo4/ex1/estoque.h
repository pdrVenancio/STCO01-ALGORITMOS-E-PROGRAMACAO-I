#ifndef _LISTA_ESTATICA
#define _LISTA_ESTATICA

typedef struct produto produto;
typedef struct lista lista;

lista *criarLista();
int liberarLista(lista **li);
int inserirItem(lista *li);
int listaCheia(lista *li);
void imprimirProduto(lista *li , int i);
produto *buscarMenorPreco(lista *li);
int removerUltimosElementos(lista *li, int n);
int trocarElementos(lista *li, int pos1, int pos2);

#endif