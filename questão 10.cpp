/* Questão 10 - Crie uma struct chamada "Moeda" que possa armazenar valores em dólares e euros. Escreva um programa 
que permita ao usuário escolher uma moeda e converter um valor entre dólares e euros, usando a taxa de câmbio 
atual. */

#include <stdio.h>

typedef struct
{
    float dolares;
    float euros;
} Moeda;

void converterDolarParaEuro(Moeda *moeda, float taxaDolarParaEuro)
{
    float valorDolar;
    printf("Digite o valor em dolares: ");
    scanf("%f", &valorDolar);

    float valorEuro = valorDolar * taxaDolarParaEuro;
    printf("%.2f dolares equivalem a %.2f euros.\n", valorDolar, valorEuro);

    moeda->dolares -= valorDolar;
    moeda->euros += valorEuro;
}

void converterEuroParaDolar(Moeda *moeda, float taxaEuroParaDolar)
{
    float valorEuro;
    printf("Digite o valor em euros: ");
    scanf("%f", &valorEuro);

    float valorDolar = valorEuro * taxaEuroParaDolar;
    printf("%.2f euros equivalem a %.2f dolares.\n", valorEuro, valorDolar);

    moeda->euros -= valorEuro;
    moeda->dolares += valorDolar;
}

int main()
{
    Moeda moeda;
    moeda.dolares = 100.0; // Valor inicial em dólares
    moeda.euros = 0.0;    // Valor inicial em euros

    float taxaDolarParaEuro = 5.40; // Taxa de câmbio atual
    float taxaEuroParaDolar = 4.97; // Taxa de câmbio atual

    int opcao;

    do
    {
        printf("\nMenu:\n");
        printf("1 - Converter Dolar para Euro\n");
        printf("2 - Converter Euro para Dolar\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                converterDolarParaEuro(&moeda, taxaDolarParaEuro);
                break;
            case 2:
                converterEuroParaDolar(&moeda, taxaEuroParaDolar);
                break;
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção invalida. Escolha uma opcao valida.\n");
        }
    } while (opcao != 3);

    printf("Saldo final: %.2f dolares, %.2f euros\n", moeda.dolares, moeda.euros);

    return 0;
}
