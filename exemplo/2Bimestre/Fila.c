#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int valor;
    struct no *proximo;
}No;

// ** para alterar valor na fila
void inserir_na_fila( No **fila, int num) {
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        // checar se a fila está vazia
        if(*fila == NULL){
            *fila = novo;
        }
        else {
            // Se a fila já estiver preenchida tem que percorrer e checar
            aux = *fila;
            // percorrer fila até o último valor
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            // chegando no final , o último recebe novo
            aux->proximo = novo;
        }

    }
    else {
        printf("Erro na alocação \n");
    }
}

// Retornar um ponteiro para o nó
No* remover_da_fila(No **fila){
    No *remover = NULL;
// verificar se a fila não está vazia
    if(*fila){
        // remover pega o primeiro elemento
        remover = *fila;
        // Fila recebe o próximo elemento
        *fila = remover->proximo;
    }
    else{
        printf("Fila vazia\n");
    }
    return remover;
}


void imprimir(No *fila) {
    printf("\n FILA \n");

    while(fila != NULL){
        printf("%d ", fila->valor);
        // percorrer fila
        fila = fila->proximo;
    }

    printf("\n FIM FILA \n");

}

int main () {
   No  *r, * fila = NULL;

    int opcao, valor;

    do{
        printf("\n0-sair\n 1- inserir\n 2- remover\n 3 - imprimir\n\n ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            // Chamar a função de inserir passando o endereço da fila e o valor a ser inserido
            inserir_na_fila(&fila, valor);
            break;
        case 2:
            // remover primeiro elemento
            r = remover_da_fila(&fila);
            if(r != NULL){
                printf("Removido com sucesso!\n");
                printf("%d\n", r->valor);
                // liberar ponteiro
                free(r);
            }
            break;
        case 3:
            // Passar o ponteiro para o primeiro no da fila
            imprimir(fila);
            break;
        default:
            if(opcao != 0){
                printf("Opção inválida\n");
            }
            break;
        }

    } while(opcao != 0);

   return 0;
}