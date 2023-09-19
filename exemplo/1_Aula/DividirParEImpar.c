// AULA 243 - Inserir no inicio da li

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

// Criando li 

void criar_lista(Lista *li){
    li->inicio = NULL;
    li->tam = 0;
}

// procedimento para inserir no inicio
void inserir_no_inicio(Lista *li, int num)
{
    No *novo = malloc(sizeof(No));
    
    if (novo)
    {
        novo->valor = num;
        novo->proximo = li->inicio;
        li->inicio = novo;
        li->tam++;
    }
    else
        printf("Falha na alocacao de memoria...\n\n");
}

//aula 244 - procedimento para isnserir no final
void inserir_no_final(Lista *li, int num)
{
    No *auxiliar, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // verifica se aLista esta vazia ja q se sestiver o 
        // elemento vai ser inserido no inicio da li

        if(li->inicio == NULL)
        {
            li->inicio = novo;
        }
        else
        {
            auxiliar = li->inicio;

            while (auxiliar->proximo)// != NULL // Percorre a li ate ser NULL o q indica que é o final da li
                auxiliar = auxiliar->proximo;

            auxiliar->proximo = novo;
        }
        
        li->tam++;

    }else
        printf("Erro na alocacao de memoria...\n\n");
}

// aula 245 - rocedimento para inserir no meio
void inserir_no_meio(Lista *li, int num, int anterior)
{
    No *auxiliar, *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->valor = num;
        novo->proximo = NULL;

        if(li->inicio == NULL)
        {
            novo->proximo = NULL;
            li->inicio = novo;
        }
        else{
             auxiliar = li->inicio;

            while (auxiliar->valor != anterior && auxiliar->proximo)// caso o valor informado ano esxistir o novo sera inserido no final da li
                auxiliar = auxiliar->proximo;
            
            novo->proximo = auxiliar->proximo;
            auxiliar->proximo = novo;
        }  

       li->tam++;
    }
    else
        printf("Erro na alocacao de memoria...\n\n");   
}
//AULA 248 - inserir ordenado
void inserir_ordenado(Lista *li, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;

        if(li->inicio == NULL)
        {
            novo->proximo = NULL;
            li->inicio = novo;

        }
        else if (novo->valor < li->inicio->valor)
        {
            novo->proximo = li->inicio;
            li->inicio = novo;
        }else
        {
            aux = li->inicio;
            while (aux->proximo && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        li->tam++;
        
    }
    else
        printf("erro ao alocar memoria...");

}
//AULA 246 - Imprimir
void imprimir_lista(Lista li)
{

    No *no = li.inicio;

    printf("\nLISTA tamanho(%d): ", li.tam);

    while(no)
    {
        printf("%d ",no->valor);
        no = no->proximo;
    }
}
No* remover(Lista *li, int num){
    No *aux, *remove = NULL;

    if(li->inicio)
    {
        if (li->inicio->valor == num)
        {
            remove = li->inicio;
            li->inicio = remove->proximo;
            li->tam--;
        }
        else{
            aux = li->inicio;
            while (aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
          
            if(aux->proximo)
            {
                remove = aux->proximo;
                aux->proximo = remove->proximo;
                li->tam--;
            }
        }
    }
    return remove;
}
// Aula 253 -  Buscar
No* buscar(Lista *li, int num){
    No *aux, *no = NULL;

    aux = li->inicio;

    while(aux && aux->valor != num)
        aux = aux->proximo;
    if(aux)
        no = aux;
    
   

    return no;
}
//Aula 255 - Dividir a lista em impara e par
void impar_par(Lista *li, Lista *l_P, Lista *l_IM){
    No *aux = li->inicio;

    while (aux)
    {
        if(aux->valor % 2 == 0)
            inserir_no_inicio(l_P, aux->valor);
        else
            inserir_no_inicio(l_IM, aux->valor);
        
        aux = aux->proximo;
    }
   
}

int main(){

    int op, valor, anterior;
   // No *li = NULL;
    Lista li ,lP , lIM;
    No* removido = NULL;

    criar_lista(&li);
    criar_lista(&lP);
    criar_lista(&lIM);

    do{
        printf("\n\tOpcao: \n\t0 - sair \n\t1 - Insrir no inicio\n\t2 - Inserir no final\n\t3 - Inserir no Meio\n\t4 - Inserir ordenado\n\t5 - imprimir\n\t6 - remover\n\t7 - Buscar\n\t8 - Separar I/P\n");
        scanf("%d", & op);

        switch (op)
        {
        case 1:
            printf("digite o valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&li, valor);

            break;
        case 2:
            printf("digite o valor: ");
            scanf("%d", &valor);
            inserir_no_final(&li, valor);

            break;
        case 3:
            printf("digite o valor e o valor de referencia: ");
            scanf("%d %d", &valor, &anterior);
            inserir_no_meio(&li, valor, anterior);

            break;
        case 4:
            printf("digite o valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&li, valor);
            break;
        case 5:

            imprimir_lista(li);
            printf("\n\nIMPAR:");
            imprimir_lista(lIM);
            printf("\n\nPAR: ");
            imprimir_lista(lP);
            break;
        case 6:
            printf("digite o valor: ");
            scanf("%d", &valor);
            removido = remover(&li, valor);
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
            removido = buscar(&li, valor);
            if (removido)
            {
                printf("Busca feita com sucesso: %d...", removido->valor);
                free(removido);
            }else
                printf("VAlor nao encontrado");

            break;
        case 8:
            impar_par(&li, &lP, &lIM);
           
            break;
        default:
            if(op != 0)
                printf("\n\tOpcao invalida...\n");
            break;
        }

    }while(op != 0);


    return 0;
}