#include <stdio.h>
#include <stdlib.h>

void quicksort_exemplo2(int vetor[10], int inicio, int fim)
{
  int pivo, aux, i, j, meio;
  i = inicio;
  j = fim;
  meio = (int)((i + j) / 2);
  pivo = vetor[meio];
  do
  {
    while (vetor[i] < pivo)
      i = i + 1;
    while (vetor[j] > pivo)
      j = j - 1;
    if (i <= j)
    {
      aux = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = aux;
      i = i + 1;
      j = j - 1;
    }
  } while (j > i);

  if (inicio < j)
    quicksort_exemplo2(vetor, inicio, j);
  if (i < fim)
    quicksort_exemplo2(vetor, i, fim);
}

int encontrapivo(int vetor[], int esq, int dir)
{
  int x;
  int aux_troca;  // usado para troca de posi��o
  int cont = esq; // posicao que vai come�ar a ordenar
  for (x = esq + 1; x <= dir; x++)
  {
    if (vetor[x] < vetor[esq])
    {
      cont++;
      aux_troca = vetor[x];
      vetor[x] = vetor[cont];
      vetor[cont] = aux_troca;
    }
  }
  aux_troca = vetor[esq];
  vetor[esq] = vetor[cont];
  vetor[cont] = aux_troca;

  return 0;
}

void quicksort_exemplo1(int vetor[], int esq, int dir)
{
  int pivo;
  if (esq < dir)
  {
    pivo = encontrapivo(vetor, esq, dir);
    quicksort_exemplo1(vetor, esq, pivo - 1);
    quicksort_exemplo1(vetor, pivo + 1, dir);
  }
}

int main()
{
  int vetor[] = {3, 5, 8, 1, 9, 2, 4, 7, 0, 6};
  int n = 10;
  int i;

  printf("\n\n\n");
  for (i = 0; i < n; i++)
    printf("%d - ", vetor[i]);

  quicksort_exemplo1(vetor, 0, n);
  // quicksort_exemplo2(vetor, 0, n);

  printf("\n\n\n");
  for (i = 0; i < n; i++)
    printf("%d - ", vetor[i]);

  printf("\n\n\n");
  // system("pause");
  return 0;
}
