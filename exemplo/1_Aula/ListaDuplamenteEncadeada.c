// AULA 257 - Lista duplamente encadeada

#include<stdlib.h>
#include<stdio.h>

typedef struct no
{
    int valor;
    struct no *proximo;
    struct no *anterior;
}No;

//aula - 247
typedef struct
{
    No* inicio;
    int tam;    
}Lista;

// Criando lista 

void criar_lista(Lista *li){
    li->inicio = NULL;
    li->tam = 0;
}

// procedimento para inserir no inicio
void inserir_no_inicio(Lista *lista, int num)
{
    No *novo = malloc(sizeof(No));
    
    if (novo)
    {
        novo->valor = num;
        novo->proximo = lista->inicio;
        novo->anterior = NULL;
       
        if(lista->inicio)// Faz o antigo primeiro elemento apontar para o novo primeiro elemento
            lista->inicio->anterior = novo;

        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("Falha na alocacao de memoria...\n\n");
}

//aula 244 - procedimento para isnserir no final
void inserir_no_final(Lista *lista, int num)
{
    No *auxiliar, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // verifica se aLista esta vazia ja q se sestiver o 
        // elemento vai ser inserido no inicio da lista

        if(lista->inicio == NULL)
        {
            lista->inicio = novo;
            novo->anterior = NULL;
        }
        else
        {
            auxiliar = lista->inicio;

            while (auxiliar->proximo)// != NULL // Percorre a lista ate ser NULL o q indica que é o final da lista
                auxiliar = auxiliar->proximo;

            auxiliar->proximo = novo;
            novo->anterior = auxiliar;
        }
        
        lista->tam++;

    }else
        printf("Erro na alocacao de memoria...\n\n");
}

// aula 245 - rocedimento para inserir no meio
void inserir_no_meio(Lista *lista, int num, int ant)
{
    No *auxiliar, *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->valor = num;
        novo->proximo = NULL;

        if(lista->inicio == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            lista->inicio = novo;
        }
        else{
            auxiliar = lista->inicio;
            while(auxiliar->valor != ant && auxiliar->proximo)
                auxiliar = auxiliar->proximo;
            novo->proximo = auxiliar->proximo;
            if(auxiliar->proximo)
                auxiliar->proximo->anterior = novo;
            novo->anterior = auxiliar;
            auxiliar->proximo = novo;
        } 
       lista->tam++;
    }
    else
        printf("Erro na alocacao de memoria...\n\n");   
}
//AULA 248 - inserir ordenado
void inserir_ordenado(Lista *lista, int num){
    No *auxiliar, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;

        if(lista->inicio == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            lista->inicio = novo;
        }
        else if (novo->valor < lista->inicio->valor)
        {
            novo->proximo = lista->inicio;
            lista->inicio->anterior = novo;
            lista->inicio = novo;
        }else
        {
            auxiliar = lista->inicio;
            while (auxiliar->proximo && novo->valor > auxiliar->proximo->valor)
            {
                auxiliar = auxiliar->proximo;
            }
            novo->proximo = auxiliar->proximo;
            auxiliar->proximo->anterior = novo;
            novo->anterior = auxiliar;
            auxiliar->proximo = novo;
        }
        lista->tam++;
        
    }
    else
        printf("erro ao alocar memoria...");

}
//AULA 246 - Imprimir
void imprimir_lista(Lista lista)
{

    No *no = lista.inicio;

    printf("\nLISTA tamanho(%d): ", lista.tam);

    while(no)
    {
        printf("%d ",no->valor);
        no = no->proximo;
    }
}
No* remover(Lista *lista, int num){
    No *auxiliar, *remove = NULL;

    if(lista->inicio)
    {
        if (lista->inicio->valor == num)
        {
            remove = lista->inicio;
            lista->inicio = remove->proximo;
            if(lista->inicio)
                lista->inicio->anterior = NULL;
            lista->tam--;
        }
        else{
            auxiliar = lista->inicio;
            while (auxiliar->proximo && auxiliar->proximo->valor != num)
                auxiliar = auxiliar->proximo;
          
            if(auxiliar->proximo)
            {
                remove = auxiliar->proximo;
                auxiliar->proximo = remove->proximo;
                
                if(auxiliar->proximo)
                    auxiliar->proximo->anterior = auxiliar;
                    
                lista->tam--;
            }
        }
    }
    return remove;
}
// Aula 253 -  Buscar
No* buscar(Lista *lista, int num){
    No *auxiliar, *no = NULL;

    auxiliar = lista->inicio;

    while(auxiliar && auxiliar->valor != num)
        auxiliar = auxiliar->proximo;
    if(auxiliar)
        no = auxiliar;
    
   

    return no;
}

int main(){

    int op, valor, anterior;
   // No *lista = NULL;
    Lista lista;
    No* removido = NULL;
    criar_lista(&lista);

    do{
        printf("\n\tOpcao: \n\t0 - sair \n\t1 - Insrir no inicio\n\t2 - Inserir no final\n\t3 - Inserir no Meio\n\t4 - Inserir ordenado\n\t5 - imprimir\n\t6 - remover\n\t7 - Buscar\n");
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
            printf("digite o valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 5:
            imprimir_lista(lista);
            break;
        case 6:
            printf("digite o valor: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if (removido)
            {
                printf("Elemento removido...\n\n");
                free(removido);
            }else
                printf("Falha ao remover");
            
            break;
            case 7:
                printf("digite o valor: ");
                scanf("%d", &valor);
                removido = buscar(&lista, valor);
                if (removido)
                {
                    printf("Busca feita com sucesso: %d...", removido->valor);
                    free(removido);
                }else
                    printf("VAlor nao encontrado");

                break;
        default:
            if(op != 0)
                printf("\n\tOpcao invalida...\n");
            break;
        }

    }while(op != 0);


    return 0;
}