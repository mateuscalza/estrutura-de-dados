/**
 * Conta pares.
 *
 * @author Mateus Calza
**/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void inverte(int n, int *vet)
{
  int novo_vet[n];
  for (int indice = 0; indice < n; indice++)
  {
    novo_vet[indice] = vet[n - indice - 1];
    printf("%d ", novo_vet[indice]);
  }
}

int main()
{
  int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int n = sizeof(vet) / sizeof(vet[0]);

  inverte(n, vet);
}
