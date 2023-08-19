/*Questão 4 - Crie uma struct chamada "Contato" que armazene o nome e o número de telefone de uma pessoa. escreva um programa que permita ao usuário adicionar contatos,
listar todos os contatos e buscar um contato pelo nome.*/

#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct
{
    char nome[50];
    char telefone[20];
} Contato;

void adicionarContato(Contato contatos[], int *numContatos)
{
    if (*numContatos < MAX_CONTATOS)
    {
        Contato novoContato;
        printf("Digite o nome do contato: ");
        scanf("%s", novoContato.nome);
        printf("Digite o telefone do contato: ");
        scanf("%s", novoContato.telefone);

        contatos[*numContatos] = novoContato;
        (*numContatos)++;

        printf("Contato adicionado com sucesso!\n");
    }
    else
    {
        printf("Nao e possivel adicionar mais contatos. A lista esta cheia.\n");
    }
}

void listarContatos(Contato contatos[], int numContatos)
{
    printf("Lista de Contatos:\n");
    for (int i = 0; i < numContatos; i++)
    {
        printf("Nome: %s, Telefone: %s\n", contatos[i].nome, contatos[i].telefone);
    }
}

void buscarContato(Contato contatos[], int numContatos, const char *nome)
{
    int encontrado = 0;
    for (int i = 0; i < numContatos; i++)
    {
        if (strcmp(contatos[i].nome, nome) == 0)
        {
            printf("Contato encontrado:\n");
            printf("Nome: %s, Telefone: %s\n", contatos[i].nome, contatos[i].telefone);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
    {
        printf("Contato nao encontrado.\n");
    }
}

int main()
{
    Contato contatos[MAX_CONTATOS];
    int numContatos = 0;
    int opcao;

    do
    {
        printf("\nMenu:\n");
        printf("1 - Adicionar Contato\n");
        printf("2 - Listar Contatos\n");
        printf("3 - Buscar Contato por Nome\n");
        printf("4 - Sair\n");
        printf("Escolha uma opçcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                adicionarContato(contatos, &numContatos);
                break;
            case 2:
                listarContatos(contatos, numContatos);
                break;
            case 3:
                {
                    char nomeBusca[50];
                    printf("Digite o nome a ser buscado: ");
                    scanf("%s", nomeBusca);
                    buscarContato(contatos, numContatos, nomeBusca);
                }
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Escolha uma opcao valida.\n");
        }
    } while (opcao != 4);

    return 0;
}

