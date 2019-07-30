/**
 * Verifica números primos
 *
 * @author Mateus Calza
**/

#include <stdlib.h>
#include <stdio.h>

int primo(int valor_entrada)
{
  // Valor absoluto para funcionar com números negativos também
  int valor = abs(valor_entrada);

  // 0 é uma indeterminação, 1 é divisível apenas por ele mesmo
  if (valor == 0 || valor == 1)
  {
    return 0;
  }

  // Decresce o valor para usar os números inferiores (e maiores que 1) como divisor
  for (int indice = valor - 1; indice > 1; indice--)
  {
    // Se encontrar uma divisão exata, não é primo
    if (valor % indice == 0)
    {
      return 0;
    }
  }

  return 1;
}

int main()
{
  int valor = 89;

  printf("%d é primo? ", valor);
  if (primo(valor))
  {
    printf("É primo!\n");
  }
  else
  {
    printf("Não é primo!\n");
  }
}
