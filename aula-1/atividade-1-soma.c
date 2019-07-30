/**
 * Soma
 *
 * @author Mateus Calza
**/

#include <stdio.h>

double soma(double valor_1, double valor_2)
{
  return valor_1 + valor_2;
}

int main()
{
  printf("Soma de dois valores: \n");
  printf("Resultado: %.2f", soma(123, 456));
  printf("\n\n");
}
