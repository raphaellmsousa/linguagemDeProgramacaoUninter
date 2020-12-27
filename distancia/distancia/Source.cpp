#include <stdio.h>
#include <math.h>   /* pow and sqrt */
#include <locale.h> //biblioteca para defini��o de idioma de sa�da de dados

struct ponto2d {
	int x;
	int y;
};
void read_point(struct ponto2d* p);
float distancia(struct ponto2d ponto_inicial, struct ponto2d ponto_final);

void print_menu();
void read_user_choices(int option);

bool control_out = 0;
struct ponto2d ponto_inicial, ponto_final;

int main()
{
	setlocale(LC_ALL, "Portuguese"); //Define a lingua portuguesa para sa�da de dados
	int input;

	while (control_out == 0)
	{		
		print_menu();
		scanf_s("%d", &input);
		while (getchar() != '\n');
		read_user_choices(input);
	}

	return 0;
}

//Fun��o para apresenta��o do menu
void print_menu()
{
	printf("[1] - Digitar os valores do primeiro ponto\n");
	printf("[2] - Digitar os valores do segundo ponto\n");
	printf("[3] - Mostrar a dist�ncia entre os pontos\n");
	printf("[4] - Sair\n\n");
}

//Fun��o de sele��o de tarefas escolhidas pelo usu�rio
void read_user_choices(int option)
{
	switch (option)
	{
	case 1: 
		printf("\nOp��o 1\n");
		printf("\nInforme as coodenadas do ponto inicial:\n");
		read_point(&ponto_inicial);
		break;
	case 2:
		printf("\nOp��o 2\n");
		printf("\nInforme as coodenadas do ponto final:\n");
		read_point(&ponto_final);
		break;
	case 3:
		printf("\nOp��o 3\n");
		printf("\n\nDistancia entre os pontos: %.2f\n\n", distancia(ponto_inicial, ponto_final));
		break;
	case 4:
		printf("\nOp��o 4\n");
		control_out = 1;
		break;	
	default: printf("\nOp��o Inv�lida!\n");
		break;
	}
}

void read_point(struct ponto2d* p)
{
	int x, y;
	scanf_s("%d%d", &x, &y);
	p->x = x;
	p->y = y;
}

float distancia(struct ponto2d ponto_inicial, struct ponto2d ponto_final)
{
	float term1, term2;
	term1 = pow((ponto_inicial.x - ponto_final.x), 2);   /* Funcao pow(x,y) retorna x^y */
	term2 = pow((ponto_inicial.y - ponto_final.y), 2);
	return sqrt(term1 + term2);    /* Funcao sqrt(x) retorna a raiz quadrada de x */
}

/*

#include <stdio.h>
#include <math.h>   
struct ponto2d {
	int x;
	int y;
};
void read_point(struct ponto2d* p);
float distancia(struct ponto2d ponto_inicial, struct ponto2d ponto_final);

void main(void)
{
	struct ponto2d ponto_inicial, ponto_final;
	printf("\nDistancia entre os pontos:\n");
	printf("\nInforme as coodenadas do ponto inicial:\n\n");
	read_point(&ponto_inicial);
	printf("\nInforme as coodenadas do ponto final:\n\n");
	read_point(&ponto_final);
	printf("\n\nDistancia entre os pontos: %.2f\n", distancia(ponto_inicial, ponto_final));
}
void read_point(struct ponto2d* p)
{
	int x, y;
	scanf_s("%d%d", &x, &y);
	p->x = x;
	p->y = y;
}
float distancia(struct ponto2d ponto_inicial, struct ponto2d ponto_final)
{
	float term1, term2;
	term1 = pow((ponto_inicial.x - ponto_final.x), 2);   
	term2 = pow((ponto_inicial.y - ponto_final.y), 2);
	return sqrt(term1 + term2);    
}*/