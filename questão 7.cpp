/* Questão 7 - Crie uma struct chamada "ContaBancaria" com campos para nome do titular, número da conta e saldo. 
Implemente funções para depositar, sacar e verificar o saldo */

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nomeTitular[100];
    int numeroConta;
    float saldo;
} ContaBancaria;

void depositar(ContaBancaria *conta, float valor)
{
    conta->saldo += valor;
    printf("Deposito de %.2f realizado com sucesso. \n Saldo atual: %.2f\n", valor, conta->saldo);
}

void sacar(ContaBancaria *conta, float valor)
{
    if (valor <= conta->saldo)
    {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso. \n Saldo atual: %.2f\n", valor, conta->saldo);
    }
    else
    {
        printf("Saldo insuficiente para realizar o saque.\n");
    }
}

void verificarSaldo(const ContaBancaria *conta)
{
    printf("Saldo da conta de %s (Conta #%d): %.2f\n", conta->nomeTitular, conta->numeroConta, conta->saldo);
}

int main()
{    printf("------------------------------------------------\n");
	printf("Universidade Catolica de Brasilia\n");
	printf("Aluna: Izabelle Ferreira da silva\n");
	printf("Turma: GPE02M0411 - Esrrutura de dados");
	printf("\n-----------------------------------------------\n");
	printf("Bem-vindos ao sistema integrado ao banco digital!\n");
	printf("-------------------------------------------------\n");
	
    ContaBancaria conta;
    strcpy(conta.nomeTitular, "Joao");
    conta.numeroConta = 20487;
    conta.saldo = 250.0;

    printf("Conta criada para %s (Conta #%d) com saldo inicial de %.2f.\n", conta.nomeTitular, conta.numeroConta, conta.saldo);

    depositar(&conta,600.0);
    sacar(&conta, 50.0);
    verificarSaldo(&conta);


	printf("-----------------------------------------\n");
	printf("Fim!\n");
	
    return 0;
}
