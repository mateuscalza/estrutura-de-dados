/**
 * Soma
 *
 * @author Mateus Calza
**/

#include <stdio.h>

double soma(double valor1, double valor2)
{
  return valor1 + valor2;
}

int main()
{
  printf("Soma de dois valores: \n");
  printf("Resultado: %.2f", soma(123, 456));
  printf("\n\n");
}
