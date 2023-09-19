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
        }
        else
        {
            auxiliar = lista->inicio;

            while (auxiliar->proximo)// != NULL // Percorre a lista ate ser NULL o q indica que é o final da lista
                auxiliar = auxiliar->proximo;

            auxiliar->proximo = novo;
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
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else{
             auxiliar = lista->inicio;

            while (auxiliar->valor != anterior && auxiliar->proximo)// caso o valor informado ano esxistir o novo sera inserido no final da lista
                auxiliar = auxiliar->proximo;
            
            novo->proximo = auxiliar->proximo;
            auxiliar->proximo = novo;
        }  

       lista->tam++;
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

        if(lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;

        }
        else if (novo->valor < lista->inicio->valor)
        {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }else
        {
            aux = lista->inicio;
            while (aux->proximo && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
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
    No *aux, *remove = NULL;

    if(lista->inicio)
    {
        if (lista->inicio->valor == num)
        {
            remove = lista->inicio;
            lista->inicio = remove->proximo;
            lista->tam--;
        }
        else{
            aux = lista->inicio;
            while (aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
          
            if(aux->proximo)
            {
                remove = aux->proximo;
                aux->proximo = remove->proximo;
                lista->tam--;
            }
        }
    }
    return remove;
}
// Aula 253 -  Buscar
No* buscar(Lista *lista, int num){
    No *aux, *no = NULL;

    aux = lista->inicio;

    while(aux && aux->valor != num)
        aux = aux->proximo;
    if(aux)
        no = aux;
    
   

    return no;
}
//Aula 254 - Copiar lista
void copiar_lista(Lista *l1, Lista *l2){

    No *aux = l1->inicio;

    while (aux)
    {
        inserir_no_final(l2, aux->valor);
        aux = aux->proximo;
    }
    
}
int main(){

    int op, valor, anterior;
   
    Lista l1 ,l2 ,l3;
    No* removido = NULL;
    criar_lista(&l1);
    criar_lista(&l2);
    criar_lista(&l3);

    do{
        printf("\n\tOpcao: \n\t0 - sair \n\t1 - Insrir no inicio\n\t2 - Inserir no final\n\t3 - Inserir no Meio\n\t4 - Inserir ordenado\n\t5 - imprimir\n\t6 - remover\n\t7 - Buscar\n\t8 - copiar lista\n\n");
        scanf("%d", & op);

        switch (op)
        {
        case 1:
            printf("digite o valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&l1, valor);
            
            printf("digite o valor L2: ");
            scanf("%d", &valor);
            inserir_no_inicio(&l2, valor);

            break;
        case 2:
            printf("digite o valor L2: ");
            scanf("%d", &valor);
            inserir_no_final(&l2, valor);

            break;
        case 3:
            printf("digite o valor e o valor de referencia: ");
            scanf("%d %d", &valor, &anterior);
            inserir_no_meio(&l1, valor, anterior);

            break;
        case 4:
            printf("digite o valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&l1, valor);
            break;
        case 5:
       
            printf("\nlista1:");
            imprimir_lista(l1);
            printf("\nlista2:");
            imprimir_lista(l2);
            printf("\nlista3:");
            imprimir_lista(l3);
            break;
        case 6:
            printf("digite o valor: ");
            scanf("%d", &valor);
            removido = remover(&l3, valor);
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
                removido = buscar(&l3, valor);
                if (removido)
                {
                    printf("Busca feita com sucesso: %d...", removido->valor);
                    free(removido);
                }else
                    printf("VAlor nao encontrado");

                break;
            case 8:
                copiar_lista(&l1, &l3);
                copiar_lista(&l2, &l3);
                
                break;
        default:
            if(op != 0)
                printf("\n\tOpcao invalida...\n");
            break;
        }

    }while(op != 0);


    return 0;
}