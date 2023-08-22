/***************************************************************************************************
Programa para preencher e imprimir um vetor e uma matriz, ambos alocados dinamicamente na memória.

Última atualização: em 10/08/2023 por Elisa Rodrigues. 
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// cria novo tipo de dado Agenda
struct agenda{
  int codigo;
  char nome[20];
  int telefone;
};

typedef struct agenda Agenda;

// protótipos das funções
void preencherRegistroAgenda(Agenda *agenda);
void imprimirRegistroAgenda(Agenda agenda);

Agenda *alocarVetor(int nV);
void desalocarVetor(Agenda *vetor);
void preencherVetor(int nV, Agenda *vetor);
void imprimirVetor(int nV, Agenda *vetor);

Agenda **alocarMatriz(int m, int nM);
void desalocarMatriz(int m, Agenda **matriz);
void preencherMatriz(int m, int nM, Agenda **matriz);
void imprimirMatriz(int m, int nM, Agenda **matriz);


// função principal
int main () {

  // declaração dos variáveis
  int m, nV, nM; 

  // declaração de ponteiros
  Agenda *vetor; // vetor 
  Agenda **matriz; // matriz

  // definição de tamanho do vetor (nV) e da matriz (número de linhas (m) e número de colunas (nM))
  nV = 1;
  m = 1;
  nM = 1;

  // alocação de memória para um vetor de inteiros com nV posições
  vetor = alocarVetor(nV);

  // alocação de memória para uma matriz de inteiros com m linhas e nM colunas)
  matriz = alocarMatriz(m, nM);

  // preencher o vetor
  preencherVetor(nV, vetor);

  // preencher a matriz
  preencherMatriz(m, nM, matriz);

  // imprimir o vetor    
  imprimirVetor(nV, vetor);

  // imprimir a matriz
  printf("\n");
  imprimirMatriz(m, nM, matriz);

  // liberar a memória
  desalocarVetor(vetor);
  desalocarMatriz(m, matriz);
  
  return(0);
}


Agenda *alocarVetor(int nV)
{
  return (Agenda*) malloc(nV * sizeof(Agenda));
}


Agenda **alocarMatriz(int m, int nM)
{
  Agenda **matriz = (Agenda**) malloc(m * sizeof(Agenda*));
  for(int i=0; i<m; i++){
    matriz[i] = alocarVetor(nM);
  }

  return matriz;
}

void desalocarVetor(Agenda *vetor)
{
  free(vetor);
}

void desalocarMatriz(int m, Agenda **matriz)
{
  for(int i=0; i<m; i++){
    free(matriz[i]);  
  } 
  free(matriz);
}


void preencherRegistroAgenda(Agenda *agenda)
{
  printf("\nCódigo = ");
  scanf("%d", &agenda->codigo);
  
  printf("Nome = ");
  scanf("%s", agenda->nome);
  
  printf("Telefone = ");
  scanf("%d", &agenda->telefone);
}

// Função para preencher um vetor de inteiros
// Parâmetros: nV - tamanho do vetor 
//             vetor - ponteiro do tipo inteiro
void preencherVetor(int nV, Agenda *vetor)
{
  for(int i=0; i<nV; i++){  
    preencherRegistroAgenda(&vetor[i]);    
  }
}

void imprimirRegistroAgenda(Agenda agenda)
{
  printf("\n\n Código: %d", agenda.codigo);
  printf("\n Nome: %s", agenda.nome);
  printf("\n Telefone: %d", agenda.telefone);  
}

// Função para imprimir um vetor de inteiros
// Parâmetros: nV - tamanho do vetor 
//             vetor - ponteiro do tipo inteiro
void imprimirVetor(int nV, Agenda *vetor)
{
  for(int i=0; i<nV; i++){
    imprimirRegistroAgenda(vetor[i]);
  }
}

// Função para preencher uma matriz de inteiros
// Parâmetros: m - número de linhas da matriz
//             nM - número de colunas da matriz
//             matriz - ponteiro de ponteiro do tipo inteiro
void preencherMatriz(int m, int nM, Agenda **matriz)
{
  for(int i=0; i<m; i++){
    for(int j=0; j<nM; j++){
      preencherRegistroAgenda(&matriz[i][j]);
    }
  }
}

// Função para imprimir uma matriz de inteiros
// Parâmetros: m - número de linhas da matriz
//             nM - número de colunas da matriz
//             matriz - ponteiro de ponteiro do tipo inteiro
void imprimirMatriz(int m, int nM, Agenda **matriz)
{
  for(int i=0; i<m; i++){
    for(int j=0; j<nM; j++){
      imprimirRegistroAgenda(matriz[i][j]);
    }
    printf("\n");
  }
}