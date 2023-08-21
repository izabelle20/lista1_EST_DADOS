/*Questão 2 - Crie uma struct chamada "Tipo" que possa armazenar um valor do tipo inteiro, um valor do tipo ponto flutuante e uma letra. Escreva um programa que demonstre o uso da struct, 
atribuindo valores de diferentes tipos e imprimindo-os. */

#include <stdio.h>
#include <string.h>

typedef struct
{
    char Letra[2];
    int ValorInteiro;
    float ValorFlutuante;
} Tipo;

void ImprimeTipo(Tipo T)
{
    printf("Valor Flutuante: %f \n", T.ValorFlutuante);
    printf("ValorInteiro: %i \n", T.ValorInteiro);
    printf("Letra: %s \n", T.Letra);
}

void SetTipo(Tipo *T, const char letra[], int valorinteiro, float valorflutuante)
{
    strcpy(T->Letra, letra);
    T->ValorInteiro = valorinteiro;
    T->ValorFlutuante = valorflutuante;
}

int main()
{
    printf("--------------------------------------------------\n");
	printf("Universidade Catolica de Brasilia\n");
	printf("Aluna: Izabelle Ferreira da silva\n");
	printf("Turma: GPE02M0411 - Esrrutura de dados");
	printf("\n------------------------------------------------\n");
	printf("Bem-vindos ao sistema integrado a tipo de valores!\n");
	printf("--------------------------------------------------\n");

    Tipo A;
    SetTipo(&A, "A", 20, 2345.89);

    ImprimeTipo(A); 


	printf("-----------------------------------------\n");
	printf("Fim!\n");
    return 0;
}
