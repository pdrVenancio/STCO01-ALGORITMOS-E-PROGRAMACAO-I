// AULA 243 - Inserir no inicio da lista

#include<stdlib.h>
#include<stdio.h>

typedef struct no
{
    int valor;
    struct no *proximo;
}No;

//aula - 247
typedef struct
{
    No* inicio;
    No* fim;
    int tam;    
}Lista;

// Criando lista 

void criar_lista(Lista *li){
    li->inicio = NULL;
    li->fim = NULL;
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
        lista->inicio = novo;
        if(lista->fim == NULL)
            lista->fim = novo;
        lista->fim->proximo = lista->inicio;
        lista->tam++;
    }
    else
        printf("Falha na alocacao de memoria...\n\n");
}

//aula 244 - procedimento para isnserir no final
void inserir_no_final(Lista *lista, int num)
{
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;

        // verifica se aLista esta vazia ja q se sestiver o 
        // elemento vai ser inserido no inicio da lista

        //vazia?
        if(lista->inicio == NULL)
        {
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
        }
        else
        {
            lista->fim->proximo = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;

            
        }
        
        lista->tam++;

    }else
        printf("Erro na alocacao de memoria...\n\n");
}

// aula 245 - rocedimento para inserir no meio
void inserir_no_meio(Lista *lista, int num, int anterior)
{
    No *auxiliar, *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->valor = num;
        novo->proximo = NULL;

        if(lista->inicio == NULL)
        {
           inserir_no_inicio(lista, num);
        }
        else{
            auxiliar = lista->inicio;

            while (auxiliar->valor != anterior && auxiliar->proximo)// caso o valor informado ano esxistir o novo sera inserido no final da lista
                auxiliar = auxiliar->proximo;
            
            novo->proximo = auxiliar->proximo;
            auxiliar->proximo = novo;
            lista->tam++;
        }        
    }
    else
        printf("Erro na alocacao de memoria...\n\n");   
}
//AULA 248 - inserir ordenado
void inserir_ordenado(Lista *lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;
          //lista vazia?
        if(lista->inicio == NULL){
            inserir_no_inicio(lista, num);
        }// O elemanto q vamos enserir é o menor elemento d alista?
        else if (novo->valor < lista->inicio->valor){
            inserir_no_inicio(lista, num);
        }
        else{
            aux = lista->inicio;
            while (aux->proximo != lista->inicio && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            // VErifica se o eçemeto é o maior da lita(vai ficar no final)
            if (aux->proximo == lista->inicio)
                inserir_no_final(lista, num);
            else{
                novo->proximo = aux->proximo;
                aux->proximo = novo;
                lista->tam++;    
            }
        }
       
        
    }
    else
        printf("erro ao alocar memoria...");

}
//AULA 246 - Imprimir
void imprimir_lista(Lista lista)
{

    No *no = lista.inicio;

    printf("\nLISTA tamanho(%d): ", lista.tam);

    if (no)
    {
        do
        {
            printf(" %d", no->valor);
            no = no->proximo;
        } while (no != lista.inicio);
        printf("\nInicio: %d\n", no->valor);
    }
    
}

No* remover(Lista *lista, int num){
    No *aux, *remove = NULL;

    if(lista->inicio)
    {   //verifica se a lista tem apenas 1 elemento
        if (lista->inicio == lista->fim && lista->inicio->valor == num)
        {
            remove = lista->inicio;
            lista->fim = NULL;
            lista->inicio = NULL;
            lista->tam--;
        }
        //verifica se vai remover o primeiro numero
        else if(lista->inicio->valor == num)
        {
            remove = lista->inicio;
            lista->inicio = remove->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tam--;
        }
        else{
            aux = lista->inicio;
            while (aux->proximo != lista->inicio && aux->proximo->valor != num)
                aux = aux->proximo;

            if (aux->proximo->valor == num){
                //final
                if (lista->fim == aux->proximo){
                    remove = aux->proximo;
                    aux->proximo = remove->proximo;
                    lista->fim = aux;
                }//meio
                else{
                    remove = aux->proximo;
                    aux->proximo =remove->proximo;

                }
                lista->tam--;
            }
        }
    }
    return remove;
}
// Aula 253 -  Buscar
No* buscar(Lista *lista, int num){
    No *aux = lista->inicio;

    if(aux)
        do
        {
            if(aux->valor == num)
                return aux;

            aux = aux->proximo;
             
        }while (aux != lista->inicio);

    return NULL;
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