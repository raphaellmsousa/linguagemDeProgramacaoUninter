#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca para definição de idioma de saída de dados
#include <ctype.h> 

FILE* stream;
//using namespace std;
char fileName[10];

char frase1[50];
char frase2[50];
char frase3[50];
char frase4[50];
char frase5[50];

char FRASE1[50];
char FRASE2[50];
char FRASE3[50];
char FRASE4[50];
char FRASE5[50];

int i = 0;
char line[50];

int main()
{
	//string filename;	
	setlocale(LC_ALL, "Portuguese"); //Define a lingua portuguesa para saída de dados
	printf("Insira o nome do arquivo\n\n");	
	fgets(fileName, 10, stdin); //Leitura do nome	
	fflush(stdin);
	while (getchar() != '\n'); // Ignora o resto da linha 
			
	printf("Insira a primeira frase\n");	
	fgets(frase1, 50, stdin); //Leitura do nome
	fflush(stdin);

	// Loop para converter as letras em maiúsculas
	while (frase1[i]) {
		FRASE1[i] = toupper(frase1[i]);
		//printf("%c", toupper(FRASE1[i]));
		i++;
	}
	i = 0;

	printf("Insira a segunda frase\n");	
	fgets(frase2, 50, stdin); //Leitura do nome
	fflush(stdin);

	// Loop para converter as letras em maiúsculas
	while (frase2[i]) {
		FRASE2[i] = toupper(frase2[i]);
		//printf("%c", toupper(FRASE1[i]));
		i++;
	}
	i = 0;
		
	printf("Insira a terceira frase\n");	
	fgets(frase3, 50, stdin); //Leitura do nome
	fflush(stdin);
	
	// Loop para converter as letras em maiúsculas
	while (frase3[i]) {
		FRASE3[i] = toupper(frase3[i]);
		//printf("%c", toupper(FRASE1[i]));
		i++;
	}
	i = 0;

	printf("Insira a quarta frase\n");	
	fgets(frase4, 50, stdin); //Leitura do nome
	fflush(stdin);

	// Loop para converter as letras em maiúsculas
	while (frase4[i]) {
		FRASE4[i] = toupper(frase4[i]);
		//printf("%c", toupper(FRASE1[i]));
		i++;
	}
	i = 0;

	printf("Insira a quinta frase\n");	
	fgets(frase5, 50, stdin); //Leitura do nome
	fflush(stdin);

	// Loop para converter as letras em maiúsculas
	while (frase5[i]) {
		FRASE5[i] = toupper(frase5[i]);
		//printf("%c", toupper(FRASE1[i]));
		i++;
	}
	i = 0;

	//Cria um arquivo no modo escrita com o nome informado pelo usuário
	fopen_s(&stream, fileName, "w+");
	
	if (stream)
	{
		fputs(FRASE1, stream);
		fputs(FRASE2, stream);
		fputs(FRASE3, stream);
		fputs(FRASE4, stream);
		fputs(FRASE5, stream);
		
		fclose(stream);
	}	
	
	//Abre o arquivo criado no modo de leitura
	fopen_s(&stream, fileName, "r");
	if (stream)
	{
		//Leitura dos dados do arquivo
		char str[50];
		fgets(str, 50, stream);
		printf("%s\n", str);

		char str2[50];
		fgets(str2, 50, stream);
		printf("%s\n", str2);

		char str3[50];
		fgets(str3, 50, stream);
		printf("%s\n", str3);

		char str4[50];
		fgets(str4, 50, stream);
		printf("%s\n", str4);

		char str5[50];
		fgets(str5, 50, stream);
		printf("%s\n", str5);

		fclose(stream);
	}

	return 0;
}