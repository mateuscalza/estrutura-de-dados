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
  int valor;
  struct lista *anterior;
  struct lista *proximo;
};
typedef struct lista Lista;

Lista *lista_cria(void)
{
  return NULL;
}

//Inserção no início da lista
Lista *lista_insere(Lista *lista, int valor)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));

  novo->valor = valor;
  novo->proximo = lista;
  novo->anterior = NULL;

  if (lista != NULL)
  {
    lista->anterior = novo;
  }

  return novo;
}

void lista_imprime(Lista *lista)
{
  Lista *atual; //Variável auxiliar para percorrer a lista.
  for (atual = lista; atual != NULL; atual = atual->proximo)
  {
    printf("Valor: % d\n", atual->valor);
  }
}

Lista *lista_busca(Lista *lista, int valor)
{
  Lista *atual;

  for (atual = lista; atual != NULL; atual = atual->proximo)
  {
    if (atual->valor == valor)
    {
      return atual;
    }
  }

  // Não achou o elemento
  return NULL;
}

Lista *lista_remove_item(Lista *lista, Lista *item)
{
  // Refaz lista
  if (item->anterior == NULL)
  {
    if (item->proximo == NULL)
    {
      return NULL;
    }
    return item->proximo;
  }

  // Remove a referência no anterior
  item->anterior->proximo = item->proximo;
  if (item->proximo != NULL)
  {
    // Remove a referência no posterior
    item->proximo->anterior = item->anterior;
  }

  free(item);

  return lista;
}

Lista *lista_retira(Lista *lista, int v)
{
  Lista *atual;
  for (atual = lista; atual != NULL; atual = atual->proximo)
  {
    if (atual->valor == v)
    {
      printf("Removendo: %d\n", atual->valor);
      lista = lista_remove_item(lista, atual);
    }
  }
  return lista;
}

Lista *lista_libera(Lista *lista)
{
  Lista *atual = lista;
  while (atual != NULL)
  {
    Lista *proximo = atual->proximo;
    free(atual);
    atual = proximo;
  }
  return NULL;
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
  Lista *lista;

  int valor;
  int opcao;
  do
  {
    opcao = seleciona_atividade();

    switch (opcao)
    {
    case 1:
      printf("\nCriar Lista\n");
      lista = lista_cria();
      break;
    case 2:
      printf("\nInserir Registros\n");
      printf("Digite o valor: ");

      scanf("%d", &valor);

      lista = lista_insere(lista, valor);
      break;
    case 3:
      printf("\nRetirar Registros\n");
      printf("Digite o valor: ");

      scanf("%d", &valor);

      lista = lista_retira(lista, valor);
      break;
    case 4:
      printf("\nOrdenar Registros\n");
      break;
    case 5:
      printf("\nImprimir Lista\n");
      lista_imprime(lista);
      break;
    case 6:
      printf("\nLiberar Lista\n");
      lista = lista_libera(lista);
      break;

    default:
      break;
    }
  } while (opcao != 9);

  return 0;
}
