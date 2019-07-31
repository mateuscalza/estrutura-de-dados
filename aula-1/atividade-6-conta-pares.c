/**
 * Conta pares.
 *
 * @author Mateus Calza
**/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int pares(int n, int *vet)
{
  int pares = 0;

  for (int indice = 0; indice < n; indice++)
  {
    if (vet[indice] % 2 == 0)
    {
      pares++;
    }
  }

  return pares;
}

int main()
{
  int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int n = sizeof(vet) / sizeof(vet[0]);

  int quantidade_pares = pares(n, vet);
  printf("Pares: %d", quantidade_pares);
}
