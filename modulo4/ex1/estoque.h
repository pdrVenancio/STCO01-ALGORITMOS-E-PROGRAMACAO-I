#define MAX 100

typedef struct estoque{
  int cod[MAX], qnt;
  char nome[30];
  float preco[MAX];
}estoque;

estoque* criarLista();
int liberarLista(estoque **li);
int cheiaLista(estoque *li);

//estoque* novoProduto();
//estoque* alocarProduto(int cod, char nome[30], float preco, int qnt);


