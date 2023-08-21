/*Questão 1 - Crie uma struct chamada "Pessoa" que contenha os seguintes campos: nome, idade e altura. Em seguida, escreva um programa que declare uma variável do tipo Pessoa,
preencha seus campos e imprima os valores..*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char Nome[50];
    int Idade;
    float Altura;
} Pessoa;

void ImprimePessoa(Pessoa P)
{
    printf("Nome: %s \n", P.Nome);
    printf("Idade: %d \n", P.Idade);
    printf("Altura: %.2f \n", P.Altura);
}

void SetPessoa(Pessoa *P, char nome[], int idade, float altura)
{
    strcpy(P->Nome, nome);
    P->Idade = idade;
    P->Altura = altura;
}

int main()
{
	printf("-----------------------------------------\n");
	printf("Universidade Catolica de Brasilia\n");
	printf("Aluna: Izabelle Ferreira da silva\n");
	printf("Turma: GPE02M0411 - Esrrutura de dados");
	printf("\n---------------------------------------\n");
	printf("Bem-vindos ao sistema integrado a pessoa!\n");
	printf("-----------------------------------------\n");

    Pessoa Izabelle;
    SetPessoa(&Izabelle, "Izabelle", 21, 1.50);

    ImprimePessoa(Izabelle);

	printf("-----------------------------------------\n");
	printf("Fim!\n");
    return 0;
}
