/**
 * Escrita/leitura
 *
 * @author Mateus Calza
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int idAluno;
    char nome[100];
    float nota;
    char disciplina[100];
    int idDisciplina;
} ALUNO;

FILE *arquivo;
ALUNO notas[100];
char disciplinas[100][100];
char alunos[100][100];
int posicao = 0;
int posicaoAlunos = 0;
int posicaoDisciplina = 0;

void importar() {
    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "r");

    char linha[4098];
    while (fgets(linha, 4098, arquivo)) {
        if (strlen(linha)) {
            char *token;
            int parte = 0;
            if (strlen(linha) > 0) {
                token = strtok(linha, ";");

                while (token != NULL) {
                    if (parte == 0) {
                        strcpy(notas[posicao].nome, token);
                        notas[posicao].idAluno = -1;
                        for(int id = 0; id < 100; id++)
                        {
                            if (alunos[id] != NULL && strcmp(notas[posicao].nome, alunos[id]) == 0) {
                                notas[posicao].idAluno = id;
                            }
                        }
                        if (notas[posicao].idAluno == -1) {
                            strcpy(alunos[posicaoAlunos], token);
                            notas[posicao].idAluno = posicaoAlunos;
                            posicaoAlunos++;
                        }
                    } else if (parte == 1) {
                        strcpy(notas[posicao].disciplina, token);
                        notas[posicao].idDisciplina = -1;
                        for(int idDisciplina = 0; idDisciplina < 100; idDisciplina++)
                        {
                            if (disciplinas[idDisciplina] != NULL && strcmp(notas[posicao].disciplina, disciplinas[idDisciplina]) == 0) {
                                notas[posicao].idDisciplina = idDisciplina;
                            }
                        }
                        if (notas[posicao].idDisciplina == -1) {
                            strcpy(disciplinas[posicaoDisciplina], token);
                            notas[posicao].idDisciplina = posicaoDisciplina;
                            posicaoDisciplina++;
                        }
                    } else {
                        sscanf(token, "%f", &(notas[posicao].nota));
                    }

                    token = strtok(NULL, ";");
                    parte++;
                }
                posicao++;
            }
        }
    }
    fclose(arquivo);
    printf("Importado com sucesso!\n");
}


void listar() {
    printf("Alunos: \n");
    for (int indice = 0; indice < posicao; indice++) {
        printf("Aluno %d\t-\t%s\t-\t%.2f\t-\t%s\t-\tDisciplina %d\n", notas[indice].idAluno, notas[indice].nome, notas[indice].nota, notas[indice].disciplina, notas[indice].idDisciplina);
    }
}


void mediaDisciplina() {
    float somaGeral = 0;
    for(int idDisciplina = 0; idDisciplina < 100; idDisciplina++)
    {
        if (disciplinas[idDisciplina] != NULL && strlen(disciplinas[idDisciplina]) > 0) {
            float contagem = 0;
            float soma = 0;
            for (int indice = 0; indice < posicao; indice++) {
                if (idDisciplina == notas[indice].idDisciplina) {
                    soma += notas[indice].nota;
                    somaGeral += notas[indice].nota;
                    contagem++;
                }
            }
            float media = soma / contagem;
            printf("Disciplina %s\t-\tMédia %.2f\n", disciplinas[idDisciplina], media);
        }
    }
    printf("Média geral %.2f\n", somaGeral / posicao);
}


void mediaAlunos() {
    float somaGeral = 0;
    for(int idAluno = 0; idAluno < 100; idAluno++)
    {
        if (alunos[idAluno] != NULL && strlen(alunos[idAluno]) > 0) {
            float contagem = 0;
            float soma = 0;
            for (int indice = 0; indice < posicao; indice++) {
                if (idAluno == notas[indice].idAluno) {
                    soma += notas[indice].nota;
                    somaGeral += notas[indice].nota;
                    contagem++;
                }
            }
            float media = soma / contagem;
            printf("Aluno %s\t-\tMédia %.2f\n", alunos[idAluno], media);
        }
    }
    printf("Média geral %.2f\n", somaGeral / posicao);
}

void inserirNota() {
    FILE *arquivo = fopen("arquivo.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("Digite o nome: ");
    scanf("%s", notas[posicao].nome);
    notas[posicao].idAluno = -1;
    for(int id = 0; id < 100; id++)
    {
        if (alunos[id] != NULL && strcmp(notas[posicao].nome, alunos[id]) == 0) {
            notas[posicao].idAluno = id;
        }
    }
    if (notas[posicao].idAluno == -1) {
        strcpy(alunos[posicaoAlunos], notas[posicao].nome);
        notas[posicao].idAluno = posicaoAlunos;
        posicaoAlunos++;
    }

    printf("Digite a disciplina: ");
    scanf("%s", notas[posicao].disciplina);
    notas[posicao].idDisciplina = -1;
    for(int idDisciplina = 0; idDisciplina < 100; idDisciplina++)
    {
        if (disciplinas[idDisciplina] != NULL && strcmp(notas[posicao].disciplina, disciplinas[idDisciplina]) == 0) {
            notas[posicao].idDisciplina = idDisciplina;
        }
    }
    if (notas[posicao].idDisciplina == -1) {
        strcpy(disciplinas[posicaoDisciplina], notas[posicao].disciplina);
        notas[posicao].idDisciplina = posicaoDisciplina;
        posicaoDisciplina++;
    }

    printf("Digite a nota: ");
    scanf("%f", &(notas[posicao].nota));

    fprintf(arquivo, "%s;%s;%.2f\n", notas[posicao].nome, notas[posicao].disciplina, notas[posicao].nota);
    posicao++;
    fclose(arquivo);
    printf("Nota salva com sucesso!\n");
}

void menu() {
    int opcao;
    do {
        printf("\n\n\n-------------------------\n");
        printf("Escolha uma opção:\n");
        printf("0 - Importar\n");
        printf("1 - Listar arquivo \n");
        printf("2 - Calcular média das disciplinas \n");
        printf("3 - Calcular média dos alunos \n");
        printf("4 - Inserir um registro \n");
        printf("9 - Sair \n");
        printf("-------------------------\n");
        scanf("%d", &opcao);

        switch (opcao) {

            case 0:
                importar();
                break;

            case 1:
                listar();
                break;

            case 2:
                mediaDisciplina();
                break;

            case 3:
                mediaAlunos();
                break;

            case 4:
                inserirNota();
                break;

            case 9:
                exit(0);
            default:
                printf("\nOpção inválida.\n");
        }

    } while (opcao != 9);
}

int main() {
    menu();

    return 0;
}