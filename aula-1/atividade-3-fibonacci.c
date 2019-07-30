/**
 * Imprime sequência Fibonacci
 *
 * @author Mateus Calza
**/

#include <stdlib.h>
#include <stdio.h>

void imprime_fibonacci(int n)
{
  int atual = 1;
  int a = 0;
  int b = 1;
  while (1)
  {
    printf("%d ", atual);

    atual = a + b;
    a = b;
    b = atual;

    if (atual > n)
    {
      return;
    }
  }
}

int main()
{
  int n = 100;
  imprime_fibonacci(n);
}
