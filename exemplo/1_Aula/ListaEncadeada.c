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
        }
        else
        {
            auxiliar = *lista;

            while (auxiliar->proximo)// != NULL // Percorre a lista ate ser NULL o q indica que é o final da lista
                auxiliar = auxiliar->proximo;

            auxiliar->proximo = novo;
        }
    
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
//AULA 246 - Imprimir
void impprimir_lista(No *no)
{
    printf("\nLISTA: ");

    while(no)
    {
        printf("%d ",no->valor);
        no = no->proximo;
    }
}

int main(){

    int op, valor, anterior;
    No *lista = NULL;
    do{
        printf("\n\tOpcao: \n\t0 - sair \n\t1 - Insrir no inicio\n\t2 - Inserir no final\n\t3 - Inserir no Meio\n\t4 - Imprimir\n");
        scanf("%d", & op);

        switch (op)
        {
        case 1:
            printf("digite o valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);

            break;
        case 2:
            printf("digite o valor: ");
            scanf("%d", &valor);
            inserir_no_final(&lista, valor);

            break;
        case 3:
            printf("digite o valor e o valor de referencia: ");
            scanf("%d %d", &valor, &anterior);
            inserir_no_meio(&lista, valor, anterior);

            break;
        case 4:
            impprimir_lista(lista);
            break;
        default:
            if(op != 0)
                printf("\n\tOpcao invalida...\n");
            break;
        }

    }while(op != 0);


    return 0;
}