/* Quest�o 6 - Crie uma struct chamada "Estudante" com campos para nome, matr�cula e notas em tr�s disciplinas. Implemente fun��es para calcular a m�dia das notas e 
determinar se um aluno est� aprovado (m�dia maior ou igual a 7).*/
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[100];
    int matricula;
    float notas[3];
} Estudante;

float calcularMedia(const Estudante *estudante)
{
    float somaNotas = 0.0;
    for (int i = 0; i < 3; i++)
    {
        somaNotas += estudante->notas[i];
    }
    return somaNotas / 3.0;
}

void verificarAprovacao(const Estudante *estudante)
{
    float media = calcularMedia(estudante);
    printf("Media de %s: %.2f\n", estudante->nome, media);
    
    if (media >= 7.0)
    {
        printf("O aluno esta aprovado.\n");
    }
    else
    {
        printf("O aluno esta reprovado.\n");
    }
}

int main()
{
    Estudante aluno;

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", aluno.nome);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno.matricula);

    for (int i = 0; i < 3; i++)
    {
        printf("Digite a nota %d do aluno: ", i + 1);
        scanf("%f", &aluno.notas[i]);
    }

    verificarAprovacao(&aluno);

    return 0;
}
