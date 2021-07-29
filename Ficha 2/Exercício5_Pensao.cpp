/*
	Pensao
	Fazer um programa que gere uma pensão de três andares e cinco quartos 
	por andar. O programa deve apresentar um menu com as seguintes opções: 
	- Listar quartos; - Reservar quarto; - Ocupar quarto; - Desocupar quarto;
	 - Sair do programa.    
*/

// Inclusão de Bibliotecas: C
#include <stdio.h>  // Funções: "scanf()", "printf()"
#include <stdlib.h> // Funções: "system()".
#include <locale.h> // "setlocale()"
#include <windows.h>
#include <time.h>
#include <math.h>   // "pow()", "sqrt()"
#include <conio.h>  // "getch()"
#include <ctype.h>

// Inclusão de Bibliotecas: C++

#include <iostream> // Contém o "cin" e o "cout"
#include <iomanip>  // Contém "setprecision()"
#include <string>
using namespace std; // Selecionar o "std" como espaço de nomes
                     // predefinido.

//* 2. Dados Globais
	const char LIVRE = 'L', RESERVADO = 'R', OCUPADO = 'O' ;
	const int NUMANDARES = 3, NUMQUARTOSPORANDAR = 7;
	void gotoxy(int coluna, int linha)
		{
			COORD cur = {coluna, linha};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cur);
		}
	void inicializaPensao(char quartos[][NUMQUARTOSPORANDAR], int ,int);
	void mostraMenu();
	char obtemEscolha(char escolha); 
	bool processaEscolha(char ,
		char quartos[][NUMQUARTOSPORANDAR],int,int,bool );
	void despedida();

	void listarQuartos(char quartos[][NUMQUARTOSPORANDAR],int,int); 
	void reservarQuarto(char quartos[][NUMQUARTOSPORANDAR],int,int); 
	void checkIN(char quartos[][NUMQUARTOSPORANDAR],int,int); 
	void checkOUT(char quartos[][NUMQUARTOSPORANDAR],int,int); 
	bool sairDoPrograma(bool);
	void escolhaInvalida(char);

int main()
{
setlocale(LC_ALL, "Portuguese");

// 1. Dados
	char quartos[NUMANDARES][NUMQUARTOSPORANDAR];
	bool queroSair = false; 
	char escolha = '\0' ;

	
	// Inicialização do vetor 
	inicializaPensao(quartos, NUMANDARES, NUMQUARTOSPORANDAR);
	do {
		mostraMenu();
		escolha = obtemEscolha(escolha); 
		queroSair = processaEscolha(escolha,quartos,NUMANDARES, 
		NUMQUARTOSPORANDAR, queroSair);
	}while(!queroSair); 
	despedida();
return 0;
}
	// Função "inicializaPensao()""
	void inicializaPensao(
		char quartos[][NUMQUARTOSPORANDAR], 
		int numAndares,
		int numQuartosPorAndar)
	{
	for(int cAndar=0; cAndar < numAndares; cAndar++) 
	for(int cQuarto=0; cQuarto<numQuartosPorAndar;
	cQuarto++) 
	quartos[cAndar][cQuarto] = LIVRE;
}

 // Função "mostraMenu()"

	void mostraMenu()
	{
	system("cls"); system("color A");
	printf("**********************************\n");
	printf("*                                *\n");
	printf("*                                *\n");
	printf("*         Pensão Guest           *\n");
	printf("*                                *\n");
	printf("*         A. Listar quartos      *\n");	
	printf("*         B. Reservar quarto     *\n");
	printf("*         C. Check-in            *\n");
	printf("*         D. Check-out           *\n");
	printf("*         E. Sair do programa.   *\n");
	printf("*                                *\n");
	printf("**********************************\n");
printf("\n");
} // Fim da função.

	//* Função "obtemEscolha()"

	char obtemEscolha(char escolha)
	{
	fflush(stdin);
	printf("Qual a sua escolha (A-E)? "); scanf("%c", &escolha);
	fflush(stdin);
return escolha;
}

//* Função "processaEscolha()"

 	bool processaEscolha(char escolha, 
 		char quartos[] [NUMQUARTOSPORANDAR],
		int numAndares, int numQuartosPorAndar,
		bool queroSair)
	{
	switch(escolha)
	{
	case 'a': case 'A': 
	listarQuartos(quartos,numAndares,numQuartosPorAndar); 
	break;
	case 'b': case 'B': 
	reservarQuarto(quartos,numAndares,numQuartosPorAndar); break;
	case 'c': case 'C': 
	checkIN(quartos,numAndares,numQuartosPorAndar); break;
	case 'd': case 'D': 
	checkOUT(quartos,numAndares,numQuartosPorAndar); break;
	case 'e': case 'E':
	queroSair = sairDoPrograma(queroSair); break;
	default: 
	escolhaInvalida(escolha);
}
return queroSair;
}	// Fim da função.

		// Função "listarQuartos()"

	void listarQuartos(
		char quartos[][NUMQUARTOSPORANDAR],
		int numAndares, int numQuartosPorAndar)
		{
		gotoxy(1,14); 
		printf("Listagem de quartos: \n");
		for(int cAndar=0; cAndar<numAndares; cAndar++)
		{
		gotoxy(1+cAndar*24,15); 
		printf("Andar   %d:\n",cAndar+1); 
		for(int cQuarto=0; cQuarto<numQuartosPorAndar; cQuarto++)
		{
		gotoxy(1+cAndar*24,16+cQuarto); 
		
		if (quartos[cAndar][cQuarto] == LIVRE)
			printf("Quarto %d: livre.\n", cQuarto+1);
		else if (quartos[cAndar][cQuarto] == RESERVADO) 
			printf("Quarto %d: reservado.\n", cQuarto+1);
		else
		printf("Quarto %d: ocupado.\n", cQuarto+1);
		} 
	} 
	system("pause");
} // Fim da função.

		// Função "reservarQuarto()"
	
	void reservarQuarto(char quartos[][NUMQUARTOSPORANDAR],
	int numAndares, int numQuartosPorAndar)
	{
	int numAndar = 0, numQuarto = 0; 
	printf("Qual é o andar a selecionar (l-%d): ",
	NUMANDARES); scanf("%d", &numAndar);
	printf("Nesse piso, qual é o quarto a reservar (l-%d): ",
		NUMQUARTOSPORANDAR); scanf("%d", &numQuarto);
	
	quartos[numAndar-1][numQuarto-1] = RESERVADO; 
	printf("Quarto reservado com sucesso!\n"); 
system("pause");
}	// Fim da função

	//Função "checkIN()"
	void checkIN(char quartos[][NUMQUARTOSPORANDAR],
	int numAndares, int numQuartosPorAndar)
	{
	int numAndar = 0, numQuarto = 0; 
	printf("Qual é o andar a selecionar (1-%d): ",
		NUMANDARES); scanf("%d", &numAndar);
	printf("Nesse piso, qual é o quarto a ocupar (1-%d): ",
		NUMQUARTOSPORANDAR); scanf("%d", &numQuarto);

	quartos[numAndar-1][numQuarto-1] = OCUPADO; 
	printf("Quarto ocupado com sucesso!\n"); 
system("pause");
}	// Fim da função.

			// Função "checkOUT()"
	void checkOUT(char quartos[][NUMQUARTOSPORANDAR],
	int numAndares, int numQuartosPorAndar)
	{
	int numAndar = 0, numQuarto = 0; 
	printf("Qual é o andar a selecionar (l-%d): ",
		NUMANDARES); scanf("%d", &numAndar);
	printf("Nesse piso, qual é o quarto a libertar (l-%d): ",
		NUMQUARTOSPORANDAR); scanf("%d", &numQuarto);

	quartos[numAndar-1][numQuarto-1] = LIVRE; 
	printf("Quarto libertado com sucesso!\n"); 
 system("pause");
} // Fim da função.

		// Função "sairDoPrograma()"
	
	bool sairDoPrograma(bool queroSair)
		{
		printf("Tem a certeza que quer sair (S/N)? ");
		char resposta = '\0';
		fflush(stdin); 
		scanf("%c", &resposta); 
		fflush(stdin); 
		if (resposta == 's' || resposta == 'S')
		return true;
		else
		return false;
} //fim da função
	
	//* Funçao "escolhalnvalida()"

	void escolhaInvalida(char escolha)
		{
		printf("\n");
		printf("Escolha \" %c\" inválida! ", escolha);
		printf("Deve inserir de A a E!\n");
		printf("\n");
	system("pause") ;
}  // Fim da função.

//* Função "despedida()"

	void despedida()
		{
		printf("Obrigado por ter usado o software!!"); 
		printf("C FOREVER!!");
		printf("\n");
system("pause");
}

