/**
 * Pilhas
 *
 * @author Mateus Calza
**/

#include <stdio.h>
#include <stdlib.h>

struct pilha
{
  int informacao;
  struct pilha *anterior;
};
typedef struct pilha Pilha;

Pilha *criar(void)
{
  return NULL;
}

Pilha *push(Pilha *pilha, int informacao)
{
  Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
  novo->informacao = informacao;
  novo->anterior = pilha;
  return novo;
}

Pilha *pop(Pilha *pilha, int *saidaInformacao)
{
  if (pilha != NULL)
  {
    Pilha *auxiliar = pilha->anterior;
    *saidaInformacao = pilha->informacao;
    free(pilha);
    return auxiliar;
  }
  printf("Pilha vazia!\n");
  *saidaInformacao = 0;
  return NULL;
}

void desalocar(Pilha *pilha)
{
  Pilha *auxiliar = pilha;
  while (auxiliar != NULL)
  {
    Pilha *temporario = auxiliar->anterior;
    free(auxiliar);
    auxiliar = temporario;
  }
}

int main(void)
{
  Pilha *pilha = criar();
  pilha = push(pilha, 1);
  pilha = push(pilha, 2);
  pilha = push(pilha, 3);
  int out;
  pilha = pop(pilha, &out);
  pilha = push(pilha, 4);
  pilha = pop(pilha, &out);
  pilha = pop(pilha, &out);
  pilha = pop(pilha, &out);
  pilha = pop(pilha, &out);
  desalocar(pilha);
  return 0;
}
