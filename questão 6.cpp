/* Questão 6 - Crie uma struct chamada "Estudante" com campos para nome, matrícula e notas em três disciplinas. Implemente funções para calcular a média das notas e 
determinar se um aluno está aprovado (média maior ou igual a 7).*/
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
	printf("---------------------------------------------------\n");
	printf("Universidade Catolica de Brasilia\n");
	printf("Aluna: Izabelle Ferreira da silva\n");
	printf("Turma: GPE02M0411 - Esrrutura de dados");
	printf("\n-------------------------------------------------\n");
	printf("Bem-vindos ao sistema integrado a boletim de aluno!\n");
	printf("---------------------------------------------------\n");
	
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


	printf("-----------------------------------------\n");
	printf("Fim!\n");
	
    return 0;
}
