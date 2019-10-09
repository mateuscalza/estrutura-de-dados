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
  int id;
  char nome[80];
  char telefone[12];
  int dia;
  int mes;
  int ano;
};
typedef struct registro Registro;

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

void atualizaArquivo(Registro *registros, int tamanho)
{
}

void insereRegistro(Registro *registros, int tamanho)
{
  // ID
  printf("Digite o ID: \n");
  scanf("%d", &registros[tamanho].id);

  // Nome
  printf("Digite o nome: \n");
  fgets(registros[tamanho].nome, 80, stdin);
  int size = strlen(registros[tamanho].nome);
  registros[tamanho].nome[size - 1] = '\0';
  scanf(" %[^\t\n]s", registros[tamanho].nome);

  // Telefone
  printf("Digite o telefone: \n");
  fgets(registros[tamanho].telefone, 12, stdin);
  size = strlen(registros[tamanho].telefone);
  registros[tamanho].telefone[size - 1] = '\0';
  scanf(" %[^\t\n]s", registros[tamanho].telefone);

  // Data de nascimento
  printf("Digite a data de nascimento: \n");
  scanf("%d/%d/%d", &registros[tamanho].dia, &registros[tamanho].mes, &registros[tamanho].ano);

  // Atualiza arquivo
  atualizaArquivo(registros, tamanho + 1);
}

void listar(Registro *registros, int tamanho)
{
  printf("Registros: \n");
  for (int indice = 0; indice < tamanho; indice++)
  {
    printf(
      "\nCódigo: %d\nNome: %s\nTelefone: %s\nData de nascimento: %d/%d/%d\n",
      registros[indice].id,
      registros[indice].nome,
      registros[indice].telefone,
      registros[indice].dia,
      registros[indice].mes,
      registros[indice].ano
    );
  }
  printf("\n");
}

void menu()
{
  Registro registros[50];
  int tamanho = 0;

  int opcao;
  do
  {
    printf("-------------------------\n");
    printf("Escolha uma opção:\n");
    printf("1 - Inserir registro\n");
    printf("2 - Remover contato\n");
    printf("3 - Pesquisar pelo nome\n");
    printf("4 - Listar todos\n");
    printf("5 - Listar aniversariantes do mês\n");
    printf("6 - Listar contatos pela inicial\n");
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

    case 4:
      ordenaNomeCrescente(registros, tamanho);
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
