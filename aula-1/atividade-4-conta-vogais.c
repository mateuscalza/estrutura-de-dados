/**
 * Imprime sequência Fibonacci
 *
 * @author Mateus Calza
**/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int numero_de_vogais(char *str)
{
  int vogais = 0;
  char *character = str;
  while (*character != '\0')
  {
    if (
        tolower(*character) == 'a' ||
        tolower(*character) == 'e' ||
        tolower(*character) == 'i' ||
        tolower(*character) == 'o' ||
        tolower(*character) == 'u' ||
        tolower(*character) == 'y')
    {
      vogais++;
    }
    character++;
  }
  return vogais;
}

int main()
{
  char str[] = "ariticum";
  printf("A palavra %s tem ", str);

  int vogais = numero_de_vogais(str);
  printf("%d vogais.", vogais);
}
