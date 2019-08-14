/**
 * Conta pares.
 *
 * @author Mateus Calza
**/
#include <stdio.h>
#include <string.h>

struct aluno {
  char nome [81];
  char matricula [8];
  char turma;
  float nota1;
  float nota2;
  float nota3;
};
typedef struct aluno Aluno;

void lerDados(Aluno *p) {
  printf("Digite o nome: ");
  scanf("%s", (*p).nome);
  // printf("Digite a matrícula: ");
  // scanf("%i", &(*p).matricula);
  // printf("Digite a primeira nota: ");
  // scanf("%f", &(*p).nota1);
  // printf("Digite a segunda nota: ");
  // scanf("%f", &(*p).nota2);
}

void mostrarDados(Aluno *p) {
  printf("Nome: %s\n", (*p).nome);
  // printf("Matrícula: %i\n", (*p).matricula);
  
  // float media = ((*p).nota1 + (*p).nota2) / 2;
  // printf("Média: %.2f\n", media);
}

int main() {
  Aluno aluno;

  lerDados(&aluno);
  mostrarDados(&aluno);
}
