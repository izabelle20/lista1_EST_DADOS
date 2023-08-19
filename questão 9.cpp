/*Questão 9 - Crie uma struct chamada "Funcionario" com campos para nome, cargo, salário e data de admissão. 
Implemente funções para dar um aumento de salário e calcular quanto tempo um funcionário está na empresa.*/

#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char nome[100];
    char cargo[100];
    float salario;
    struct tm dataAdmissao; // Usando struct tm para armazenar data e hora
} Funcionario;

void darAumento(Funcionario *funcionario, float percentual)
{
    funcionario->salario *= (1 + percentual / 100);
    printf("Aumento de salario aplicado com sucesso. Novo salario: %.2f\n", funcionario->salario);
}

double calcularTempoTrabalho(Funcionario *funcionario)
{
    time_t now;
    time(&now);

    double tempoTrabalho = difftime(now, mktime(&(funcionario->dataAdmissao)));
    return tempoTrabalho / (365 * 24 * 60 * 60); // Converter para anos
}

int main()
{
    Funcionario funcionario;
    strcpy(funcionario.nome, "Joao");
    strcpy(funcionario.cargo, "Analista");
    funcionario.salario = 980.0;

    // Definindo a data de admissão (por exemplo, 1º de janeiro de 2020)
    funcionario.dataAdmissao.tm_year = 120; // 2020 - 1900
    funcionario.dataAdmissao.tm_mon = 0;    // Janeiro (0-11)
    funcionario.dataAdmissao.tm_mday = 1;   // Dia 1

    printf("Dados do funcionario:\n");
    printf("Nome: %s\n", funcionario.nome);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("Salario: %.2f\n", funcionario.salario);

    darAumento(&funcionario, 10.0);
    printf("Tempo de trabalho na empresa: %.2f anos\n", calcularTempoTrabalho(&funcionario));

    return 0;
}

