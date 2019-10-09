/**
 * Leitura, escrita, ordenação e busca
 *
 * @author Mateus Calza
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro
{
  int codigo;
  int idade;
  char nome[80];
};
typedef struct registro Registro;

char *randstring(size_t length)
{

  static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
  char *randomString = NULL;

  if (length)
  {
    randomString = malloc(sizeof(char) * (length + 1));

    if (randomString)
    {
      for (int n = 0; n < length; n++)
      {
        int key = rand() % (int)(sizeof(charset) - 1);
        randomString[n] = charset[key];
      }

      randomString[length] = '\0';
    }
  }

  return randomString;
}

void ordenaNomeCrescente(Registro *registros, int tamanho)
{
  int a, b;
  Registro troca;

  for (a = 1; a < tamanho; a++)
  {
    for (b = tamanho - 1; b >= a; b--)
    {
      if (strcmp(registros[b - 1].nome, registros[b].nome) > 0)
      {
        troca = registros[b - 1];
        registros[b - 1] = registros[b];
        registros[b] = troca;
      }
    }
  }
}

void ordenaCodigoCrescente(Registro *registros, int tamanho)
{
  int a, b;
  Registro troca;

  for (a = 1; a < tamanho; a++)
  {
    for (b = tamanho - 1; b >= a; b--)
    {
      if (registros[b - 1].codigo > registros[b].codigo)
      {
        troca = registros[b - 1];
        registros[b - 1] = registros[b];
        registros[b] = troca;
      }
    }
  }
}

void ordenaIdadeDecrescente(Registro *registros, int tamanho)
{
  int a, b;
  Registro troca;

  for (a = 1; a < tamanho; a++)
  {
    for (b = tamanho - 1; b >= a; b--)
    {
      if (registros[b - 1].idade < registros[b].idade)
      {
        troca = registros[b - 1];
        registros[b - 1] = registros[b];
        registros[b] = troca;
      }
    }
  }
}

void insereRegistro(Registro *registros, int tamanho)
{
  printf("Digite o nome: \n");
  fgets(registros[tamanho].nome, 80, stdin);
  int size = strlen(registros[tamanho].nome);
  registros[tamanho].nome[size - 1] = '\0';
  scanf(" %[^\t\n]s", registros[tamanho].nome);
  printf("Digite o código: \n");
  scanf("%d", &registros[tamanho].codigo);
  printf("Digite a idade: \n");
  scanf("%d", &registros[tamanho].idade);
}

void insereRegistroAleatorio(Registro *registros, int tamanho)
{
  registros[tamanho].codigo = rand() % 100;
  registros[tamanho].idade = rand() % 100 + 1;
  strcpy(registros[tamanho].nome, randstring(80));
}

void listar(Registro *registros, int tamanho)
{
  printf("Registros: \n");
  for (int indice = 0; indice < tamanho; indice++)
  {
    printf("Código %d - %d anos - %s\n", registros[indice].codigo, registros[indice].idade, registros[indice].nome);
  }
  printf("\n");
}

void menu()
{
  Registro registros[50];
  int tamanho = 0;

  for (int indice = 0; indice < 10; indice++)
  {
    insereRegistroAleatorio(registros, tamanho);
    tamanho++;
  }

  int opcao;
  do
  {
    printf("-------------------------\n");
    printf("Escolha uma opção:\n");
    printf("1 - Inserir registro\n");
    printf("2 - Ordenar em ordem crescente por código\n");
    printf("3 - Ordenar em ordem crescente por nome\n");
    printf("4 - Ordenar em ordem descrescente por idade\n");
    printf("9 - Sair\n");
    printf("-------------------------\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      insereRegistro(registros, tamanho);
      printf("\nInserido com sucesso!");
      tamanho++;
      break;

    case 2:
      ordenaCodigoCrescente(registros, tamanho);
      listar(registros, tamanho);
      break;

    case 3:
      ordenaNomeCrescente(registros, tamanho);
      listar(registros, tamanho);
      break;

    case 4:
      ordenaIdadeDecrescente(registros, tamanho);
      listar(registros, tamanho);
      break;

    case 9:
      exit(0);
    default:
      printf("\nOpção inválida.");
    }
    printf("\n\n");
  } while (opcao != 9);
}

int main()
{
  menu();

  return 0;
}
