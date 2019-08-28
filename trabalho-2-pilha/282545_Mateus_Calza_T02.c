/**
 * Pilhas
 *
 * @author Mateus Calza
 *
 * Baseado no exemplo do Professor Kurt Schneider
**/

#include <stdio.h>
#include <stdlib.h>

struct pilha
{
    int informacao;
    struct pilha *anterior;
};
typedef struct pilha Pilha;

Pilha *criar(void)
{
    return NULL;
}

Pilha *push(Pilha *pilha, int informacao)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->informacao = informacao;
    novo->anterior = pilha;
    return novo;
}

Pilha *pop(Pilha *pilha, int *saidaInformacao)
{
    if (pilha != NULL)
    {
        Pilha *auxiliar = pilha->anterior;
        *saidaInformacao = pilha->informacao;
        free(pilha);
        return auxiliar;
    }
    printf("Pilha vazia!\n");
    *saidaInformacao = 0;
    return NULL;
}

Pilha *desalocar(Pilha *pilha)
{
    Pilha *auxiliar = pilha;
    while (auxiliar != NULL)
    {
        Pilha *temporario = auxiliar->anterior;
        free(auxiliar);
        auxiliar = temporario;
    }

    return criar();
}


void imprimir(Pilha *pilha) {
    Pilha *auxiliar = pilha;
    while (auxiliar != NULL)
    {
        Pilha *temporario = auxiliar->anterior;
        printf("Valor: %d\n", auxiliar->informacao);
        auxiliar = temporario;
    }
}

Pilha *insereOrdenado(Pilha *pilha, int valor) {
    Pilha *auxiliar = pilha;
    int temporario;
    if (pilha == NULL || valor > pilha->informacao) {
        auxiliar = push(pilha, valor);
    } else {
        auxiliar = pop(auxiliar, &temporario);
        auxiliar = insereOrdenado(auxiliar, valor);
        auxiliar = push(auxiliar, temporario);
    }

    return auxiliar;
}

Pilha *ordenar(Pilha *pilha) {
    Pilha *auxiliar = pilha;
    Pilha *ordenada = criar();
    while (auxiliar != NULL)
    {
        Pilha *temporario = auxiliar->anterior;
        ordenada = insereOrdenado(ordenada, auxiliar->informacao);
        auxiliar = temporario;
    }
    return ordenada;
}

int seleciona_atividade()
{
    printf("---------------------\n");
    printf("1 - Criar Pilha\n");
    printf("2 - Inserir Registros (Push)\n");
    printf("3 - Retirar Registros (Pop)\n");
    printf("4 - Ordenar Registros\n");
    printf("5 - Imprimir Pilha\n");
    printf("6 - Liberar Pilha\n");
    printf("9 - Sair\n");
    printf("---------------------\n");

    printf("Digite uma opção: ");
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

int main()
{
    Pilha *pilha;

    int valor;
    int opcao;
    do
    {
        opcao = seleciona_atividade();

        switch (opcao)
        {
            case 1:
                printf("\nCriar Pilha\n");
                pilha = criar();
                break;
            case 2:
                printf("\nInserir Registros\n");
                printf("Digite o valor: ");

                scanf("%d", &valor);

                pilha = push(pilha, valor);
                break;
            case 3:
                printf("\nRetirar Registros\n");

                pilha = pop(pilha, &valor);
                printf("Valor removido: %d\n", valor);
                break;
            case 4:
                printf("\nOrdenar Registros\n");
                pilha = ordenar(pilha);
                break;
            case 5:
                printf("\nImprimir Pilha\n");
                imprimir(pilha);
                break;
            case 6:
                printf("\nLiberar Pilha\n");
                pilha = desalocar(pilha);
                break;

            default:
                break;
        }
    } while (opcao != 9);

    return 0;
}
