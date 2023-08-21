/*Questão 3 - Crie uma struct chamada "Ponto" que represente um ponto no plano cartesiano com coordenadas x e y. Em seguida, implemente funções para calcular a distância entre 
dois pontos e a inclinação da reta que os conecta. */ 

#include <stdio.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} Ponto;

float calcularDistancia(Ponto p1, Ponto p2)
{
    float deltaX = p2.x - p1.x;
    float deltaY = p2.y - p1.y;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

float calcularInclinacao(Ponto p1, Ponto p2)
{
    if (p2.x - p1.x == 0) 
        return INFINITY;   
    return (p2.y - p1.y) / (p2.x - p1.x);
}

int main()
{
	
	printf("----------------------------------------------------\n");
	printf("Universidade Catolica de Brasilia\n");
	printf("Aluna: Izabelle Ferreira da silva\n");
	printf("Turma: GPE02M0411 - Esrrutura de dados");
	printf("\n--------------------------------------------------\n");
	printf("Bem-vindos ao sistema integrado ao plano cartesiano!\n");
	printf("----------------------------------------------------\n");
	
    Ponto ponto1 = {7.5, 1.0};
    Ponto ponto2 = {10.8, 90.78};

    printf("Coordenadas do Ponto 1: (%.2f, %.2f)\n", ponto1.x, ponto1.y);
    printf("Coordenadas do Ponto 2: (%.2f, %.2f)\n", ponto2.x, ponto2.y);

    float distancia = calcularDistancia(ponto1, ponto2);
    printf("Distancia entre os pontos: %.2f\n", distancia);

    float inclinacao = calcularInclinacao(ponto1, ponto2);
    if (isinf(inclinacao))
    {
        printf("Inclinacao da reta: Infinita (reta vertical)\n");
    }
    else
    {
        printf("Inclinacao da reta: %.2f\n", inclinacao);
    }


	printf("-----------------------------------------\n");
	printf("Fim!\n");
    return 0;
}
