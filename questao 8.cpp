/*Questão 8 - Crie uma struct chamada "Produto" com campos para nome, preço e quantidade em estoque. Escreva um 
programa que permita ao usuário comprar produtos, atualizando o estoque e calculando o total da compra. */

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct
{
    char nome[100];
    float preco;
    int quantidadeEstoque;
} Produto;

void comprarProduto(Produto produtos[], int numProdutos, const char *nome, int quantidade)
{
    for (int i = 0; i < numProdutos; i++)
    {
        if (strcmp(produtos[i].nome, nome) == 0)
        {
            if (produtos[i].quantidadeEstoque >= quantidade)
            {
                float total = produtos[i].preco * quantidade;
                produtos[i].quantidadeEstoque -= quantidade;
                printf("Compra realizada com sucesso!\n");
                printf("Total da compra: %.2f\n", total);
            }
            else
            {
                printf("Quantidade insuficiente em estoque.\n");
            }
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

int main()
{
    Produto produtos[MAX_PRODUTOS];
    int numProdutos = 0;

    produtos[numProdutos++] = (Produto){"arroz", 12.90, 20};
    produtos[numProdutos++] = (Produto){"feijao", 10.88, 15};
    produtos[numProdutos++] = (Produto){"salada", 26.50, 10};

    printf("Lista de Produtos:\n");
    for (int i = 0; i < numProdutos; i++)
    {
        printf("%d. %s - Preco: %.2f, Estoque: %d\n", i + 1, produtos[i].nome, produtos[i].preco, produtos[i].quantidadeEstoque);
    }

    char nomeCompra[100];
    int quantidadeCompra;
    printf("\nDigite o nome do produto que deseja comprar: ");
    scanf(" %[^\n]", nomeCompra);
    printf("Digite a quantidade que deseja comprar: ");
    scanf("%d", &quantidadeCompra);

    comprarProduto(produtos, numProdutos, nomeCompra, quantidadeCompra);

    return 0;
}

