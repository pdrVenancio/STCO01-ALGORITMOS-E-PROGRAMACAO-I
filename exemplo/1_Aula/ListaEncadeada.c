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
        printf("Falha na alocacao de memoria...\n");

}

int main(){




    return 0;
}