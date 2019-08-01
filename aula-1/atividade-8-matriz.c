/**
 * Matriz.
 *
 * @author Mateus Calza
**/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

float ** cria_matriz (int lin, int col) {
  float** matriz = malloc(lin * sizeof(float*));

  for (int linha_atual = 0; linha_atual < lin; linha_atual++) {
    float* valores = calloc(col, sizeof(float));
    matriz[linha_atual] = valores;
    for (int coluna_atual = 0; coluna_atual < col; coluna_atual++) {
      matriz[linha_atual][coluna_atual] = linha_atual * coluna_atual;
    }
  }

  return matriz;
}

void imprime(int lin, int col, float **mat) {
  for (int linha_atual = 0; linha_atual < lin; linha_atual++) {
    for (int coluna_atual = 0; coluna_atual < col; coluna_atual++) {
      printf("%.1f ", mat[linha_atual][coluna_atual]);
    }
    printf("\n");
  }
}

int main()
{
  int lin = 10;
  int col = 15;
  float** matriz = cria_matriz(lin, col);
  imprime(lin, col, matriz);
}
