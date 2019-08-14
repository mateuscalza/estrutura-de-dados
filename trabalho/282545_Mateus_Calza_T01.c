/**
 * Listas duplamente encadeadas
 *
 * @author Mateus Calza
**/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct lista
{
  int info;
  struct lista *proximo;
};
typedef struct lista Lista;

Lista *lista_cria(void)
{
  return NULL;
}

Lista *lista_insere(Lista *l, int i)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->info = i;
  novo->proximo = l;
  return novo;
}

void lista_imprime(Lista *l)
{
  Lista *p; //Variável auxiliar para percorrer a lista.
  for (p = l; p != NULL; p = p->proximo)
  {
    printf("info = % d\n", p->info);
  }
}

int lista_vazia(Lista *l)
{
  if (l == NULL)
  {
    return 1; //retorna 1 se a lista estiver vazia
  }
  else
  {
    return 0; //retorna 0 se a lista não estiver vazia
  }
}

Lista *lista_busca(Lista *l, int valor)
{
  Lista *p;
  for (p = l; p != NULL; p = p->proximo)
  {
    if (p->info == valor)
    {
      return p;
    }
  }
  return NULL; //Não achou o elemento
}

Lista *lista_retira(Lista *l, int v)
{
  Lista *anterior = NULL;
  Lista *p = l;
  //procura um elemento na lista guardando o anterior
  while (p != NULL && p->info != v)
  {
    anterior = p;
    p = p->proximo;
  }
  //verifica se achou o elemento
  if (p == NULL)
    return l;
  //retira o elemento da lista
  if (anterior == NULL)
  { //retira o elemento do início da lista
    l = p->proximo;
  }
  else
  { //retira o elemento do meio da lista
    anterior->proximo = p->proximo;
  }
  free(p); //libera a posição do elemento
  return l;
}

void lista_libera(Lista *l)
{
  Lista *p = l;
  while (p != NULL)
  {
    Lista *t = p->proximo; //Referência pro próximo elemento
    free(p);               //Libera a memória apontada por p
    p = t;                 //Faz p apontar para o próximo
  }
}

Lista *lista_insere_ordenado(Lista *l, int v)
{
  Lista *novo;            //ponteiro para o novo elemento
  Lista *anterior = NULL; //ponteiro para o elemento anterior
  Lista *p = l;           //ponteiro para percorrer a lista
  while (p != NULL && p->info < v)
  { //procura posição de inserção
    anterior = p;
    p = p->proximo;
  }
  //cria novo elemento
  novo = (Lista *)malloc(sizeof(Lista));
  novo->info = v;
  //encadeia o elemento
  if (anterior == NULL)
  { //insere o elemento no início
    novo->proximo = l;
    l = novo;
  }
  else
  { //insere o elemento no meio da lista
    novo->proximo = anterior->proximo;
    anterior->proximo = novo;
  }
  return l;
}

int seleciona_atividade()
{
  printf("---------------------\n");
  printf("1 - Criar Lista\n");
  printf("2 - Inserir Registros\n");
  printf("3 - Retirar Registros\n");
  printf("4 - Ordenar Registros\n");
  printf("5 - Imprimir Lista\n");
  printf("6 - Liberar Lista\n");
  printf("9 - Sair\n");
  printf("---------------------\n");

  printf("Digite uma opção: ");
  int opcao;
  scanf("%d", &opcao);
  return opcao;
}

int main()
{
  Lista *l; //Declara uma lista não inicializada.

  int opcao;
  do
  {
    opcao = seleciona_atividade();

    switch (opcao)
    {
    case 1:
      printf("\nCriar Lista\n");
      break;
    case 2:
      printf("\nInserir Registros\n");
      break;
    case 3:
      printf("\nRetirar Registros\n");
      break;
    case 4:
      printf("\nOrdenar Registros\n");
      break;
    case 5:
      printf("\nImprimir Lista\n");
      break;
    case 6:
      printf("\nLiberar Lista\n");
      break;

    default:
      break;
    }
  } while (opcao != 9);

  // l = lista_cria();        //Cria e inicializa a lista como vazia.
  // l = lista_insere(l, 23); //Insere na lista o elemento 23.
  // l = lista_insere(l, 45); //Insere na lista o elemento 45.
  // lista_imprime(l);

  return 0;
}
