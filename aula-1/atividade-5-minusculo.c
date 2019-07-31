/**
 * Converte para minúsculas.
 *
 * @author Mateus Calza
**/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *minusculo(char *str)
{
  int vogais = 0;
  char *minuscula = str;

  for (int i = 0; i < strlen(str); i++)
  {
    minuscula[i] = tolower(str[i]);
  }

  return minuscula;
}

int main()
{
  char str[] = "ARITICUM";
  printf("A palavra %s em minúsculo: ", str);

  char *str_minuscula = minusculo(str);
  printf("%s", str_minuscula);
}
