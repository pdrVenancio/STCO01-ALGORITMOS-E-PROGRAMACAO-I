#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct ListaEstatica
{
    int num[MAX], qnt;
}Lista;


//Inserir no inicio
int inserir_inicio(Lista *li, int num){
    //verifico se lista esta cheia

    //verifico se a lista esta vazia


    // Passar os elementos do ultimo para o primeiro para nao sobrescrever nenum elemento
    for (int i = li->qnt - 1; i >= 0; i--)
    {
        li->num[i + 1] = li->num[li->qnt];

    }
    li->num[0] = num;

    li->qnt++;

    return 0;
}

//inserir no final
int inserir_final(Lista *li, int num){
    // verifica se a lisa existe 

    li->num[li->qnt] = num;
    li->qnt++;

    return 0;
}

int  inserir_ordenado(Lista *li, int num){
    //verificações padrões

    int k, i = 0;

    //verifica qual posição o elemento novo vai ocupar
    while (i < li->qnt && num > li->num[i])
        i++;
    
    //libera a posição q o elemento novo vai ocupar deslocando os elementos seguintes para frente
    for ( k = li->qnt - 1; k >= i ; k--)
        li->num[k + 1] = li->num[k];
    
    li->num[i] = num;
    li->qnt++;

    return 0;
}

//remoçoes

int remover_inicio(Lista *li){


    for (int i = 0; i < li->qnt - 1; i++)
        li->num[i] = li->num[i + 1];


    li->qnt--;
    
    return 0;
} 
int remover_final(Lista *li){

    //vrificaçoes padrao

    li->qnt--;
    
    return 0;
}

int remover_meio(Lista *li, int num){

    int k, i = 0;

    while (i < li->qnt - 1 && num != li->num[i]) 
        i++;
    
    // se i ==  li->qnt significa que nao tem o elemento na lista

    for ( k = i; k <= li->qnt - 1; k++)
        li->num[k] = li->num[k + 1];

    li->qnt--;
    
    return 0;
}
int main(){
    Lista *li = NULL;

    return 0;
}