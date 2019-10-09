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

Registro registros[500];
int tamanho = 0;

char caractereMinusculo(char caractere)
{
  if (caractere >= 'A' && caractere <= 'Z')
  {
    return caractere + 32;
  }
  return caractere;
}

void minusculo(char string[])
{
  int indice = 0;

  while (string[indice] != '\0')
  {
    string[indice] = caractereMinusculo(string[indice]);
    indice++;
  }
}

int validaMes(mes)
{
  if (mes >= 1 && mes <= 12)
  {
    return 1;
  }
  else
  {
    printf("Mês inválido!\n");
    return 0;
  }
}

int validaDia(dia, mes, ano)
{
  if (ano >= 1900 && ano <= 9999)
  {
    if (mes >= 1 && mes <= 12)
    {
      if ((dia >= 1 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))
      {
        return 1;
      }
      else if ((dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
      {
        return 1;
      }
      else if ((dia >= 1 && dia <= 28) && (mes == 2))
      {
        return 1;
      }
      else if (dia == 29 && mes == 2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)))
      {
        return 1;
      }
      else
      {
        printf("Dia inválido!\n");
        return 0;
      }
    }
    else
    {
      printf("Mês inválido!\n");
      return 0;
    }
  }
  else
  {
    printf("Ano inválido!\n");
    return 0;
  }

  return 1;
}

void ordenar()
{
  int a, b;
  Registro troca;

  for (a = 1; a < tamanho; a++)
  {
    for (b = tamanho - 1; b >= a; b--)
    {
      char nomeAnterior[80];
      strcpy(nomeAnterior, registros[b - 1].nome);
      minusculo(nomeAnterior);

      char nome[80];
      strcpy(nome, registros[b].nome);
      minusculo(nome);

      if (strcmp(nomeAnterior, nome) > 0)
      {
        troca = registros[b - 1];
        registros[b - 1] = registros[b];
        registros[b] = troca;
      }
    }
  }
}

void exportar()
{
  FILE *arquivo = fopen("contato_unoesc.txt", "w");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir arquivo!\n");
    return;
  }

  for (int indice = 0; indice < tamanho; indice++)
  {
    fprintf(
        arquivo,
        "%d;%s;%s;%d;%d;%d\n",
        registros[indice].id,
        registros[indice].nome,
        registros[indice].telefone,
        registros[indice].dia,
        registros[indice].mes,
        registros[indice].ano);
  }
  fclose(arquivo);
}

void cadastrar()
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
  printf("Digite a data de nascimento no formato dia/mês/ano: \n");
  scanf("%d/%d/%d", &registros[tamanho].dia, &registros[tamanho].mes, &registros[tamanho].ano);

  if (validaDia(registros[tamanho].dia, registros[tamanho].mes, registros[tamanho].ano) == 0)
  {
    cadastrar();
    return;
  }

  tamanho++;
}

int iniciaCom(char *a, char *b)
{
  if (strncmp(a, b, strlen(b)) == 0)
  {
    return 1;
  }
  return 0;
}

void listar()
{
  printf("Registros: \n");
  printf("ID\tNome\tTelefone\tData de Nascimento\n");
  for (int indice = 0; indice < tamanho; indice++)
  {
    printf(
        "%d\t%s\t%s\t%d/%d/%d\n",
        registros[indice].id,
        registros[indice].nome,
        registros[indice].telefone,
        registros[indice].dia,
        registros[indice].mes,
        registros[indice].ano);
  }
  printf("\n");
}

void listarAniversariantes()
{
  int mes;
  printf("Digite o número do mês: \n");
  scanf("%d", &mes);

  if (validaMes(mes) == 0)
  {
    listarAniversariantes();
    return;
  }

  printf("Aniversariantes: \n");
  int aniversariantesContagem = 0;
  printf("ID\tNome\tTelefone\tData de Nascimento\n");
  for (int indice = 0; indice < tamanho; indice++)
  {
    if (mes == registros[indice].mes)
    {
      printf(
          "%d\t%s\t%s\t%d/%d/%d\n",
          registros[indice].id,
          registros[indice].nome,
          registros[indice].telefone,
          registros[indice].dia,
          registros[indice].mes,
          registros[indice].ano);
      aniversariantesContagem++;
    }
  }
  printf("\n");

  if (aniversariantesContagem == 0)
  {
    printf("Sem aniversariantes no mês selecionado!\n");

    int opcao;
    printf("-------------------------\n");
    printf("Escolha uma opção:\n");
    printf("1 - Tentar outro mês\n");
    printf("2 - Voltar ao menu principal\n");
    printf("-------------------------\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      listarAniversariantes();
      break;
    case 2:
      printf("\nVoltando ao menu principal...");
      break;

    default:
      printf("\nOpção inválida, voltando ao menu principal...");
      break;
    }
  }
}

void removerBusca(char *busca)
{
  for (int indice = 0; indice < tamanho; indice++)
  {
    char nome[80];
    strcpy(nome, registros[indice].nome);
    minusculo(nome);

    if (iniciaCom(nome, busca) == 1)
    {
      printf(
          "\nRemovendo %s de código %d",
          registros[indice].nome,
          registros[indice].id);

      for (int indiceRemocao = indice; indiceRemocao < tamanho - 1; indiceRemocao++)
      {
        registros[indiceRemocao] = registros[indiceRemocao + 1];
      }

      tamanho--;
      removerBusca(busca);
      return;
    }
  }
}

void remover()
{
  printf("Digite a busca para remoção: \n");
  char busca[80];
  fgets(busca, 80, stdin);
  int size = strlen(busca);
  busca[size - 1] = '\0';
  scanf(" %[^\t\n]s", busca);

  minusculo(busca);

  printf("\nRegistros removidos: \n");
  removerBusca(busca);
}

void buscar()
{
  printf("Digite a busca: \n");
  char busca[80];
  fgets(busca, 80, stdin);
  int size = strlen(busca);
  busca[size - 1] = '\0';
  scanf(" %[^\t\n]s", busca);

  minusculo(busca);
  printf("\nLower: %s\n", busca);

  printf("Registros: \n");
  for (int indice = 0; indice < tamanho; indice++)
  {
    char nome[80];
    strcpy(nome, registros[indice].nome);
    minusculo(nome);

    if (iniciaCom(nome, busca) == 1)
    {
      printf(
          "%d\t%s\t%s\t%d/%d/%d\n",
          registros[indice].id,
          registros[indice].nome,
          registros[indice].telefone,
          registros[indice].dia,
          registros[indice].mes,
          registros[indice].ano);
    }
  }
  printf("\n");
}

void listarInicial()
{

  printf("Digite a busca: \n");
  char busca[80];
  fgets(busca, 80, stdin);
  int size = strlen(busca);
  busca[size - 1] = '\0';
  scanf(" %[^\t\n]s", busca);

  if (strlen(busca) > 1)
  {
    printf("Apenas a letra inicial deve ser inserida. \n");
  }

  char inicial = busca[0];

  printf("Registros: \n");
  printf("ID\tNome\tTelefone\tData de Nascimento\n");
  for (int indice = 0; indice < tamanho; indice++)
  {
    if (strlen(registros[indice].nome) > 0 && caractereMinusculo(registros[indice].nome[0]) == caractereMinusculo(inicial))
    {

      printf(
          "%d\t%s\t%s\t%d/%d/%d\n",
          registros[indice].id,
          registros[indice].nome,
          registros[indice].telefone,
          registros[indice].dia,
          registros[indice].mes,
          registros[indice].ano);
    }
  }
  printf("\n");
}

void importar()
{

  FILE *arquivo;
  arquivo = fopen("contato_unoesc.txt", "r");

  char linha[4098];
  while (fgets(linha, 4098, arquivo))
  {
    if (strlen(linha) > 2)
    {
      char *token;
      int parte = 0;
      if (strlen(linha) > 0)
      {
        token = strtok(linha, ";");

        while (token != NULL)
        {
          if (parte == 0)
          {
            sscanf(token, "%d", &(registros[tamanho].id));
          }
          else if (parte == 1)
          {
            strcpy(registros[tamanho].nome, token);
          }
          else if (parte == 2)
          {
            strcpy(registros[tamanho].telefone, token);
          }
          else if (parte == 3)
          {
            sscanf(token, "%d", &(registros[tamanho].dia));
          }
          else if (parte == 4)
          {
            sscanf(token, "%d", &(registros[tamanho].mes));
          }
          else if (parte == 5)
          {
            sscanf(token, "%d", &(registros[tamanho].ano));
          }

          token = strtok(NULL, ";");
          parte++;
        }
        tamanho++;
      }
    }
  }
  fclose(arquivo);
}

void menu()
{
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
      cadastrar();
      printf("\nInserido com sucesso!");
      break;

    case 2:
      remover();
      break;

    case 3:
      ordenar();
      buscar();
      break;

    case 4:
      ordenar();
      listar();
      break;

    case 5:
      ordenar();
      listarAniversariantes();
      break;

    case 6:
      ordenar();
      listarInicial();
      break;

    case 9:
      exportar();
      exit(0);
    default:
      printf("\nOpção inválida.");
    }
    printf("\n\n");
  } while (opcao != 9);
}

int main()
{
  importar();
  menu();

  return 0;
}
