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
    // Se não for o início, aloca para o anterior
    lista->anterior = novo;
  }

  return novo;
}
Lista *inserir_ordenado(Lista *lista, int valor)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->valor = valor;
  novo->anterior = NULL;
  novo->proximo = NULL;

  Lista *aux = lista;
  if (aux == NULL)
    return novo;
  while (aux->proximo != NULL && aux->proximo->valor < valor)
    aux = aux->proximo;
  if (aux->anterior == NULL && aux->valor > valor)
  {
    novo->proximo = lista;
    lista->anterior = novo;
    return novo;
  }
  if (aux->proximo == NULL && aux->valor < valor)
  {
    aux->proximo = novo;
    novo->anterior = aux;
  }
  else
  {
    novo->anterior = aux;
    novo->proximo = aux->proximo;
    aux->proximo = novo;
    novo->proximo->anterior = novo;
  }
  return lista;
}

void lista_imprime(Lista *lista)
{
  Lista *atual;
  for (atual = lista; atual != NULL; atual = atual->proximo)
  {
    // Exibe valor de cada item
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
      // Retorna elemento encontrado
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
    // Procura por um valor específico
    if (atual->valor == v)
    {
      printf("Removendo: %d\n", atual->valor);
      lista = lista_remove_item(lista, atual);
    }
  }
  return lista;
}

Lista *lista_ordena(Lista *lista)
{
  Lista *atual = lista;
  Lista *lista_ordenada = NULL;
  while (atual != NULL)
  {
    lista_ordenada = inserir_ordenado(lista_ordenada, atual->valor);
    atual = atual->proximo;
  }
  return lista_ordenada;
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
      lista = lista_ordena(lista);
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
