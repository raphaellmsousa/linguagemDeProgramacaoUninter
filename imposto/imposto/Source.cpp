/*
Local: Cajazeiras - PB
Data: 24/10/2020
Autor: Raphaell Maciel de Sousa
Descrição: programa para cálculo do imposto. 
Solução do exercício 2 da atividade prática
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca para definição de idioma de saída de dados

struct cadastro_de_funcionarios  /*Criando a struct*/
{
	char nome[50];
	float salario;
}; struct cadastro_de_funcionarios cadastro; /*variavel tipo strut 
											 para referência ao 
											 cadastro_de_funcionarios*/

/*Declaração de funções*/
void print_table();
void calculo_faixa_salarial(float salario);
void calculo_do_imposto(float salario);

int *faixa;
int faixa_salarial;

int main()
{
	setlocale(LC_ALL, "Portuguese"); //Define a lingua portuguesa para saída de da
	
	printf("Olá, por favor, insira seu nome: \n\n");
	fflush(stdin);
	fgets(cadastro.nome, 50, stdin); //Leitura do nome

	printf("\n\nSeja bem vindo %s\n\n", cadastro.nome);
	while (1)
	{
		faixa = &faixa_salarial;

		printf("Vamos calcular o seu imposto, por favor, informe seu salários: \n\n");
		scanf_s("%f", &cadastro.salario);

		/*Chamada de função para vizualização de dados no prompt*/
		print_table();

		/*Chamada de função para a definição da faixa salarial*/
		calculo_faixa_salarial(cadastro.salario);

		printf("Sua faixa salarial é: %d\n\n", *faixa);		

		/*Chamada de função para o cálculo imposto devido*/
		calculo_do_imposto(cadastro.salario);
	}

	system("Pause");
	return 0;
}

void print_table()
{
	printf("\n************************************************************\n");
	printf("Base de Cálculo Mensal em R$ \tAliquota em %%\tFaixa\n\n");
	printf("Até 1.637,11 \t\t\t -\t\t1\n");
	printf("De 1637,12 até 2.456,50 \t 7,5\t\t2\n");
	printf("De 2.453,51 até 3.271,38 \t 15,0\t\t3\n");
	printf("De 3.271,39 até 4.087,65 \t 22,5\t\t4\n");
	printf("Acima de 4.087,65 \t\t 27,5\t\t5\n");
	printf("************************************************************");
	printf("\n\n");
}

void calculo_faixa_salarial(float salario)
{	
	if (salario <= 1.63711e3f)
		faixa_salarial = 1;
	if (salario > 1.63711e3f && salario <= 2.45350e3f)
		faixa_salarial = 2;
	if (salario > 2.45350e3f && salario <= 3.27138e3f)
		faixa_salarial = 3;
	if (salario > 3.27138e3f && salario <= 4.08765e3f)
		faixa_salarial = 4;
	if (salario > 4.08765e3f)
		faixa_salarial = 5;	
}

void calculo_do_imposto(float salario)
{
	float imposto_devido = 0;
	if (*faixa == 1)
	{
		printf("\nVocê está isento de impostos!\n");
	}
	if (*faixa == 2)
	{
		imposto_devido = salario * 0.075;
		float liquido = salario - imposto_devido;
		printf("O salário bruto é de: R$ %.2f\n", salario);
		printf("Total de impostos retidos: R$ %.2f\n", imposto_devido);
		printf("O salário líquido é de: R$ %.2f\n", liquido);
	}
	if (*faixa == 3)
	{
		imposto_devido = salario * 0.15;
		float liquido = salario - imposto_devido;
		printf("O salário bruto é de: R$ %.2f\n", salario);
		printf("Total de impostos retidos: R$ %.2f\n", imposto_devido);
		printf("O salário líquido é de: R$ %.2f\n", liquido);
	}
	if (*faixa == 4)
	{
		imposto_devido = salario * 0.225;
		float liquido = salario - imposto_devido;
		printf("O salário bruto é de: R$ %.2f\n", salario);
		printf("Total de impostos retidos: R$ %.2f\n", imposto_devido);
		printf("O salário líquido é de: R$ %.2f\n", liquido);
	}
	if (*faixa == 5)
	{
		imposto_devido = salario * 0.275;
		float liquido = salario - imposto_devido;
		printf("O salário bruto é de: R$ %.2f\n", salario);
		printf("Total de impostos retidos: R$ %.2f\n", imposto_devido);
		printf("O salário líquido é de: R$ %.2f\n", liquido);
	}
	printf("\n\n");
}