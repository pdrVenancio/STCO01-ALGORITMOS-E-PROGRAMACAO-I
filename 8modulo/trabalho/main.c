
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// bibliotecas do projeto
#include "pilha.h"

// protótipo da função que cria um dado 
int criar_dado(int *dado);

void imprimirtudo(Pilha *p1, Pilha *p2, Pilha *p3);


// funcao principal
int main(void) {

    // no início a pilha está vazia, logo, o ponteiro inicio tem valor NULL
    //o ponteiro inicio conterá o endereço do primeiro elemento da pilha
    Pilha *p1 = NULL, *p2 = NULL, *p3 = NULL, *pTeste = NULL, *Listadado = NULL;
    int opcao, pos , nDiscos;
    char ok[2];
    int dado, dadotop, tira, poe, quantMov, numDeMovimentoMin, vit = 0;;

    // menu de opções para execuções de operações sobre a pilha

    //Seleciona o numero de discos que deseja jogar
    printf("================ BEM VINDO À TORRE DE HANÓI ================\n");
    printf("\n--> Digite a quantidade de discos que desejas em seu jogo: ");
    scanf(" %d" , &nDiscos);
    system("clear");

    numDeMovimentoMin = pow(2, nDiscos) -1;


    do
    {
        printf("\n==========================");
        printf("\n1 - Criar partida");
        printf("\n2 - Jogar partida");
        printf("\n0 - Finalizar partida");
        printf("\n==========================\n");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                if(p1 != NULL && p2 != NULL && p3 != NULL) {
                    printf("Partida já iniciada, encerre a partida atual para criar outra\n");
                    break;
                }

                // criar pilha
                p1 = criar_pilha();
                p2 = criar_pilha();
                p3 = criar_pilha();
                pTeste = criar_pilha();

                if(p1 == NULL || p2 == NULL || p3 == NULL || pTeste == NULL)
                    printf("Falha na criação de listas");

                //preenche a primeira pilha
                for (int i = nDiscos; i > 0 ; i--)
                {
                    empilhar(p1, i);
                    empilhar(pTeste, i);
                }
                system("clear");
                imprimirtudo(p1, p2, p3);
                printf("\n");


                break;

            // joga escolhida pelo jogador
            // le informa de qual pilha ele vai tirar e em qual ele vai colocar
            case 2:
                    if(p1 == NULL || p2 == NULL || p3 == NULL || pTeste == NULL) {
                      printf("Inicie a partida para conseguir jogar!!\n");
                      break;
                    }
              
                    do{
                        printf("\nDigite de qual pilha voce deseja tirar (1, 2 ou 3): ");
                        scanf(" %d", &tira);
                        if(tira != 1 && tira != 2 && tira != 3) {
                          printf("Insira 1, 2 ou 3\n");
                          continue;
                        }

                        if(tira == 1) {
                            dado = desempilhar(p1);
                            Listadado = p1;
                        }
                        else if(tira == 2) {
                            dado = desempilhar(p2);
                            Listadado = p2;
                        }
                        else if(tira == 3) {
                            dado = desempilhar(p3);
                            Listadado = p3;
                        }

                            if(dado == 0) {
                                printf("Pilha vazia ou inexistente, remova de outra pilha\n");
                                continue;
                            }

                        printf("\nDigite em qual pilha colocar o elemento retirado(1, 2 ou 3): ");
                        scanf(" %d", &poe);
                        if(poe != 1 && poe != 2 && poe != 3) {
                          printf("Insira 1, 2 ou 3\n");
                          continue;
                        }

                        if(poe == 1) {
                            consultar_topo_pilha(p1, &dadotop);
                            if(consultar_topo_pilha(p1, &dadotop) == 1 && dadotop < dado) {
                                empilhar(Listadado, dado);
                                system("clear");
                                printf("\nImpossivel colocar elementos aqui!! O item abaixo não pode ser menor que o item atual!\n");
                
                                imprimirtudo(p1, p2, p3);
                                printf("\n");
                                printf("\n");
                                continue;
                            }
                            else {
                              empilhar(p1, dado); 
                              quantMov++;
                            }
                        }
                        else if(poe == 2) {
                            consultar_topo_pilha(p2, &dadotop);
                            if(consultar_topo_pilha(p2, &dadotop) == 1 && dadotop < dado){
                                empilhar(Listadado, dado);
                                system("clear");
                                printf("\nImpossivel colocar elementos aqui!! O item abaixo não pode ser menor que o item atual!\n");
                                imprimirtudo(p1, p2, p3);
                                printf("\n");
                                continue;
                            }
                            else {empilhar(p2, dado); quantMov++;}
                        }
                        else if(poe == 3) {
                            consultar_topo_pilha(p3, &dadotop);
                            if(consultar_topo_pilha(p3, &dadotop) == 1 && dadotop < dado) {
                                empilhar(Listadado, dado);
                                system("clear");
                                printf("\nImpossivel colocar elementos aqui!! O item abaixo não pode ser menor que o item atual!\n");
                                imprimirtudo(p1, p2, p3);
                                printf("\n");
                                continue;
                            }
                            else {
                              empilhar(p3, dado);
                              quantMov++;
                            }
                        }
                      
                        system("clear");
                        imprimirtudo(p1, p2, p3);


                        if(verificar_vitoria(p2, pTeste) == 1 || verificar_vitoria(p3, pTeste) == 1) {
                            
                            system("clear");
                            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                            printf("\tVocê ganhou!! :D\n");
                            printf("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                            printf("-> O número de movimentos feitos por você: [ %d ]\n", quantMov);
                            printf("-> Número mínimo de movimentos possíveis com %d peças: [ %d ]", nDiscos, numDeMovimentoMin);
                            if(quantMov == numDeMovimentoMin) printf("\n\nVocê é um gênio\n");
                            else if(quantMov < numDeMovimentoMin) printf("\n\nPoderia ser melhor :/\n");
                            else if(quantMov >= (numDeMovimentoMin * 1.3)) {
                              printf("\n\nPorque você precisou de tantas tentativas? Seu teclado está ruim?\n");
                            }

                            liberar_pilha(p1);
                            liberar_pilha(p2);
                            liberar_pilha(p3);
                            liberar_pilha(pTeste);

                            vit = 1;
                          
                            exit(1);
                        }
                        
                    }while(vit != 1);
                    
                break;
            default:
                printf("\nOpção inválida!");
                break;
        }

    }while(opcao != 0);

    liberar_pilha(p1);
    liberar_pilha(p2);
    liberar_pilha(p3);
    liberar_pilha(pTeste);

    return 0;
}

int criar_dado(int *dado)
{
        printf("\nDigite um caractere: ");
        scanf(" %d", dado);

        return 1;
}

void imprimirtudo(Pilha *p1, Pilha *p2, Pilha *p3) {
      printf("\nP1 ||");
      imprimir(p1);
      printf("\nP2 ||");
      imprimir(p2);
      printf("\nP3 ||");
      imprimir(p3);
}