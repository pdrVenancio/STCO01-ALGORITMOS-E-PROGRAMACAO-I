// AULA 243 - Inserir no inicio da lista

#include<stdlib.h>
#include<stdio.h>

typedef struct no
{
    int valor;
    struct no *proximo;
}No;

// procedimento para inserir no inicio
void inserir_no_inicio(No **lista, int num)
{
    No *novo = malloc(sizeof(No));
    
    if (novo)
    {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
        printf("Falha na alocacao de memoria...\n\n");
}

//aula 244 - procedimento para isnserir no final
void inserir_no_final(No **lista, int num)
{
    No *auxiliar, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // verifica se aLista esta vazia ja q se sestiver o 
        // elemento vai ser inserido no inicio da lista

        if(*lista == NULL)
        {
            *lista = novo;
        }else
        {
            auxiliar = *lista;

            while (auxiliar->proximo)// != NULL // Percorre a lista ate ser NULL o q indica que é o final da lista
                auxiliar = auxiliar->proximo;

            auxiliar->proximo = novo;
        }
        
        *lista = novo;
    }else
        printf("Erro na alocacao de memoria...\n\n");
}

// aula 245 - rocedimento para inserir no final meio
void inserir_no_meio(No **lista, int num, int anterior)
{
    No *auxiliar, *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->valor = num;
        novo->proximo = NULL;

        if(*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        }
           

        auxiliar = *lista;

        while (auxiliar->valor != anterior && auxiliar->proximo)// caso o valor informado ano esxistir o novo sera inserido no final da lista
            auxiliar = auxiliar->proximo;
        
        novo->proximo = auxiliar->proximo;
        auxiliar->proximo = novo;
    }
    else
        printf("Erro na alocacao de memoria...\n\n");   
}
int main(){

    return 0;
}