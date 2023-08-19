/* Questão 5 - Crie uma struct chamada "Livro" com campos para título, autor e ano de publicação. Escreva um programa que permita ao usuário adicionar informações de livros, 
listar todos os livros cadastrados e buscar livros por autor */

#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100

typedef struct
{
    char titulo[100];
    char autor[100];
    int anoPublicacao;
} Livro;

void adicionarLivro(Livro livros[], int *numLivros)
{
    if (*numLivros < MAX_LIVROS)
    {
        Livro novoLivro;
        printf("Digite o titulo do livro: ");
        scanf(" %[^\n]", novoLivro.titulo);
        printf("Digite o autor do livro: ");
        scanf(" %[^\n]", novoLivro.autor);
        printf("Digite o ano de publicacao do livro: ");
        scanf("%d", &novoLivro.anoPublicacao);

        livros[*numLivros] = novoLivro;
        (*numLivros)++;

        printf("Livro adicionado com sucesso!\n");
    }
    else
    {
        printf("Não e possivel adicionar mais livros. A lista esta cheia.\n");
    }
}

void listarLivros(Livro livros[], int numLivros)
{
    printf("Lista de Livros:\n");
    for (int i = 0; i < numLivros; i++)
    {
        printf("Titulo: %s, Autor: %s, Ano de Publicacao: %d\n", livros[i].titulo, livros[i].autor, livros[i].anoPublicacao);
    }
}

void buscarLivrosPorAutor(Livro livros[], int numLivros, const char *autor)
{
    int encontrados = 0;
    printf("Livros do autor %s:\n", autor);
    for (int i = 0; i < numLivros; i++)
    {
        if (strcmp(livros[i].autor, autor) == 0)
        {
            printf("Titulo: %s, Ano de Publicação: %d\n", livros[i].titulo, livros[i].anoPublicacao);
            encontrados = 1;
        }
    }
    if (!encontrados)
    {
        printf("Nenhum livro encontrado para o autor %s.\n", autor);
    }
}

int main()
{
    Livro livros[MAX_LIVROS];
    int numLivros = 0;
    int opcao;

    do
    {
        printf("\nMenu:\n");
        printf("1 - Adicionar Livro\n");
        printf("2 - Listar Livros\n");
        printf("3 - Buscar Livros por Autor\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                adicionarLivro(livros, &numLivros);
                break;
            case 2:
                listarLivros(livros, numLivros);
                break;
            case 3:
                {
                    char autorBusca[100];
                    printf("Digite o autor a ser buscado: ");
                    scanf(" %[^\n]", autorBusca);
                    buscarLivrosPorAutor(livros, numLivros, autorBusca);
                }
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção invalida. Escolha uma opcao valida.\n");
        }
    } while (opcao != 4);

    return 0;
}

