#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro
{
  int id;
  char *nome;
};
typedef struct registro Registro;

char *randstring(size_t length)
{

  static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  char *randomString = NULL;

  if (length)
  {
    randomString = malloc(sizeof(char) * (length + 1));

    if (randomString)
    {
      for (int n = 0; n < length; n++)
      {
        int key = rand() % (int)(sizeof(charset) - 1);
        randomString[n] = charset[key];
      }

      randomString[length] = '\0';
    }
  }

  return randomString;
}

void bolha(Registro *lista, int tamanho)
{
  int a, b;
  Registro troca;

  for (a = 1; a < tamanho; a++)
  {
    for (b = tamanho - 1; b >= a; b--)
    {
      if (strcmp(lista[b - 1].nome, lista[b].nome) > 0)
      {
        // troca os elementos
        troca = lista[b - 1];
        lista[b - 1] = lista[b];
        lista[b] = troca;
      }
    }
  }
}

int main(void)
{
  Registro registros[50];
  printf("Gerados: \n");
  for (int indice = 0; indice < 50; indice++)
  {
    registros[indice].id = indice;
    registros[indice].nome = randstring(50);
    printf("String gerada: %s\n", registros[indice].nome);
  }
  printf("\n");

  bolha(registros, 50);

  printf("Ordenados: \n");
  for (int indice = 0; indice < 50; indice++)
  {
    printf("%s\n", registros[indice].nome);
  }
  printf("\n");

  return 0;
}
