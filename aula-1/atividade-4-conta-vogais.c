/**
 * Conta vogais em um char[]
 *
 * @author Mateus Calza
**/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int numero_de_vogais(char *str)
{
  int vogais = 0;
  char *caractere = str;
  while (*caractere != '\0')
  {
    char caractere_minusculo = tolower(*caractere);
    if (
        caractere_minusculo == 'a' ||
        caractere_minusculo == 'e' ||
        caractere_minusculo == 'i' ||
        caractere_minusculo == 'o' ||
        caractere_minusculo == 'u' ||
        caractere_minusculo == 'y')
    {
      vogais++;
    }
    caractere++;
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
