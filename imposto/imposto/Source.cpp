/*
Local: Cajazeiras - PB
Data: 24/10/2020
Autor: Raphaell Maciel de Sousa
Descri��o: programa para c�lculo do imposto. 
Solu��o do exerc�cio 2 da atividade pr�tica
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca para defini��o de idioma de sa�da de dados

struct cadastro_de_funcionarios  /*Criando a struct*/
{
	char nome[50];
	float salario;
}; struct cadastro_de_funcionarios cadastro; /*variavel tipo strut 
											 para refer�ncia ao 
											 cadastro_de_funcionarios*/

/*Declara��o de fun��es*/
void print_table();
void calculo_faixa_salarial(float salario);
void calculo_do_imposto(float salario);

int *faixa;
int faixa_salarial;

int main()
{
	setlocale(LC_ALL, "Portuguese"); //Define a lingua portuguesa para sa�da de da
	
	printf("Ol�, por favor, insira seu nome: \n\n");
	fflush(stdin);
	fgets(cadastro.nome, 50, stdin); //Leitura do nome

	printf("\n\nSeja bem vindo %s\n\n", cadastro.nome);
	while (1)
	{
		faixa = &faixa_salarial;

		printf("Vamos calcular o seu imposto, por favor, informe seu sal�rios: \n\n");
		scanf_s("%f", &cadastro.salario);

		/*Chamada de fun��o para vizualiza��o de dados no prompt*/
		print_table();

		/*Chamada de fun��o para a defini��o da faixa salarial*/
		calculo_faixa_salarial(cadastro.salario);

		printf("Sua faixa salarial �: %d\n\n", *faixa);		

		/*Chamada de fun��o para o c�lculo imposto devido*/
		calculo_do_imposto(cadastro.salario);
	}

	system("Pause");
	return 0;
}

void print_table()
{
	printf("\n************************************************************\n");
	printf("Base de C�lculo Mensal em R$ \tAliquota em %%\tFaixa\n\n");
	printf("At� 1.637,11 \t\t\t -\t\t1\n");
	printf("De 1637,12 at� 2.456,50 \t 7,5\t\t2\n");
	printf("De 2.453,51 at� 3.271,38 \t 15,0\t\t3\n");
	printf("De 3.271,39 at� 4.087,65 \t 22,5\t\t4\n");
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
		printf("\nVoc� est� isento de impostos!\n");
	}
	if (*faixa == 2)
	{
		imposto_devido = salario * 0.075;
		float liquido = salario - imposto_devido;
		printf("O sal�rio bruto � de: R$ %.2f\n", salario);
		printf("Total de impostos retidos: R$ %.2f\n", imposto_devido);
		printf("O sal�rio l�quido � de: R$ %.2f\n", liquido);
	}
	if (*faixa == 3)
	{
		imposto_devido = salario * 0.15;
		float liquido = salario - imposto_devido;
		printf("O sal�rio bruto � de: R$ %.2f\n", salario);
		printf("Total de impostos retidos: R$ %.2f\n", imposto_devido);
		printf("O sal�rio l�quido � de: R$ %.2f\n", liquido);
	}
	if (*faixa == 4)
	{
		imposto_devido = salario * 0.225;
		float liquido = salario - imposto_devido;
		printf("O sal�rio bruto � de: R$ %.2f\n", salario);
		printf("Total de impostos retidos: R$ %.2f\n", imposto_devido);
		printf("O sal�rio l�quido � de: R$ %.2f\n", liquido);
	}
	if (*faixa == 5)
	{
		imposto_devido = salario * 0.275;
		float liquido = salario - imposto_devido;
		printf("O sal�rio bruto � de: R$ %.2f\n", salario);
		printf("Total de impostos retidos: R$ %.2f\n", imposto_devido);
		printf("O sal�rio l�quido � de: R$ %.2f\n", liquido);
	}
	printf("\n\n");
}