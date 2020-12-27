/*
Descri��o: Solu��o do exerc�cio 1 da atividade pr�tica da disciplina de linguagem de programa��o
Author: Raphaell Maciel de Sousa
Data: 22/10/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca para defini��o de idioma de sa�da de dados
#include <ctype.h> // cont�m fun��es e macros para manipula��o de caracteres

//Defini��o de vari�veis
int tabuleiro[8][8]; 
char player[50];
bool control_out = 0;

int peoes = 0;
int cavalos = 0;
int torres = 0;
int bispos = 0;
int reis = 0;
int rainhas = 0;

void print_menu();
void read_user_choices(char option);
void reset_tabuleiro();
void read_tabuleiro();
void show_tabuleiro();

int main()
{
	setlocale(LC_ALL, "Portuguese"); //Define a lingua portuguesa para sa�da de dados
	printf("Ol�, vamos iniciar...\n");
	printf("Esse � o nosso xadrez 1.0\n");

	reset_tabuleiro(); //Inicialmente, vamos zerar todas as posi��es do tabuleiro

	while(control_out == 0)
	{
		printf("\n\nEscolha uma das seguintes op��es\n\n");
		print_menu(); //chamada da fun��o de apresenta��o do menu
		
		char option = getchar();
		
		/* Ignora o resto da linha */
		while (getchar() != '\n');

		printf("\n\nSua escolha foi [%c], vamos nessa!\n", toupper(option));

		read_user_choices(toupper(option)); //chama a fun��o que seleciona o que o usu�rio deseja realizar
	}

	system("Pause"); //N�o � necess�rio na vers�o 2019 do visual Studio
	return 0;
}

//Fun��o para apresenta��o do menu
void print_menu() 
{
	printf("[N] - Inserir nome do jogador\n");
	printf("[I] - Inserir pe�as no tabuleiro\n");
	printf("[M] - Mostra tabuleiro\n");
	printf("[R] - Reset tabuleiro\n");
	printf("[Q] - Quantidade de pe�as\n");
	printf("[S] - Sair\n\n");
}

//Fun��o de reset do tabuleiro, escreve zero em todas as posi��es da matriz
void reset_tabuleiro()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tabuleiro[i][j] = 0;
		}
	}
	peoes = 0;
	cavalos = 0;
	torres = 0;
	bispos = 0;
	reis = 0;
	rainhas = 0;
}

//Solicita do usu�rio o posicionamento das pe�as do xadrez
void read_tabuleiro()
{
	printf("\nOk, vamos preencher o tabuleiro com as posi��es das pe�as...\n\n");
	for (int i = 0; i < 8; i++)
	{
		printf("\n************linha %d ************\n\n", i + 1);

		for (int j = 0; j < 8; j++)
		{
			printf("Input [%d][%d]: ", i+1, j+1);
			int input;
			scanf_s("%d", &input);
			while (getchar() != '\n');
			tabuleiro[i][j] = input;

			//Condi��es para contagem da quantidade de pe�as
			if (input == 1)
				peoes = peoes + 1;
			if (input == 2)
				cavalos = cavalos + 1;
			if (input == 3)
				torres = torres + 1;
			if (input == 4)
				bispos = bispos + 1;
			if (input == 5)
				reis = reis + 1;
			if (input == 6)
				rainhas = rainhas + 1;
		}		
	}

	// mostrando a matriz na tela
	printf("\n\nO tabuleiro foi organizado da seguinte forma: \n\n");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d \t", tabuleiro[i][j]);
		}
		printf("\n\n");
	}
}

//Esta fun��o exibe no prompt o tabuleiro
void show_tabuleiro()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d \t", tabuleiro[i][j]);
		}
		printf("\n\n");
	}
}

//Fun��o de sele��o de tarefas escolhidas pelo usu�rio
void read_user_choices(char option) 
{
	switch (option)
	{
	case 'N': 
		printf("\nInsira o nome do Jogador\n\n");
		scanf_s("%s", &player, 50);		
		while (getchar() != '\n'); // Ignora o resto da linha 
		printf("\nSeja Bem vindo %s\n\n", player);
		break;
	case 'I': 
		printf("\nOk, vamos inserir as pe�as do tabuleiro...");
		printf("\n1 - Pe�o    \t4 - Bispos \t0 - Aus�ncia de Pe�as");
		printf("\n2 - Cavalos \t5 - Reis");
		printf("\n3 - Torres  \t6 - Rainhas\n\n");
		read_tabuleiro();
		break;
	case 'M':
		printf("\n\nOk, vamos ver como est� a distribui��o de pe�as no tabuleiro\n\n");
		show_tabuleiro();
		break;
	case 'R':
		reset_tabuleiro();
		break;
	case 'Q':
		printf("\n\nA quantidade de pe�as escolhidas �:\n\n");
		printf("%d Pe�es\n", peoes);
		printf("%d Cavalos\n", cavalos);
		printf("%d Torres\n", torres);
		printf("%d Bispos\n", bispos);
		printf("%d Reis\n", reis);
		printf("%d Rainhas\n\n", rainhas);
		break;
	case 'S':
		control_out = 1;
		printf("\n\nAt� a pr�xima!\n\n");
		break;
	default: printf("\nOp��o Inv�lida!\n\n");
		break;
	}
}