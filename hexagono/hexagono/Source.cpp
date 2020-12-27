#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca para definição de idioma de saída de dados
#include <math.h> /* pow */

float L, area, perimetro;

void calc_hexa(float L, float* area, float* perimetro);

int main()
{
	setlocale(LC_ALL, "Portuguese"); //Define a lingua portuguesa para saída de dados
	printf("Por favor, informe o tamanho do lado L [em metros]:\n\n");
	scanf_s("%f", &L);

	/*Início do loop para chamada de função e entrada de dados*/
	while (L > 0) {
		calc_hexa(L, &area, &perimetro);
		printf("\nA area e perímetro do hexagono com lado %.2f [metros] é %.2f [metros quadrados]  e  %.2f [metros], respectivamente\n\n", L, area, perimetro);

		printf("Por favor, informe o tamanho do lado L [em metros]:\n\n");
		scanf_s("%f", &L);
	}
	return 0;
}

/*Função de cálculo da área e perímetro do hexágono*/
void calc_hexa(float L, float* area, float* perimetro)
{
	*area = (3.0 * pow(L, L) * sqrt(3.0)) * 0.5;
	*perimetro = 6 * L;
}