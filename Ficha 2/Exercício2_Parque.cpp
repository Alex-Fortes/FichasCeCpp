/*
	Parque
	Fazer um programa que gere um parque de estacionamento com sete posições.
	 O programa deve apresentar um menu com as seguintes op?ões: 
	 - Listar lugares; - Marcar lugar; - Libertar lugar; - Sair do progroma.  
*/

// Inclusão de Bibliotecas: C
#include <stdio.h>  // Funções: "scanf()", "printf()"
#include <stdlib.h> // Funções: "system()".
#include <locale.h> // "setlocale()"
#include <math.h>   // "pow()", "sqrt()"
#include <conio.h>  // "getch()"

// Inclusão de Bibliotecas: C++

#include <iostream> // Contém o "cin" e o "cout"
#include <iomanip>  // Contém "setprecision()"
using namespace std; // Selecionar o "std" como espaço de nomes
                     // predefinido.

//* 2. Dados Globais
	const char LIVRE = 'L', OCUPADO = 'O' ;
	
	void inicializaParque(char[], int); 
	void mostraMenu();
	char obtemEscolha(char );
	bool processaEscolha(char, char[],
									int, bool) ; 
	void listarLugares(char[], int); 
	void marcarLugar(char[], int);
	void libertarLugar(char[], int); 
	bool sairDoPrograma(bool);
	void escolhaInvalida(char); 
	void despedida();
	void pausaC();

int main()
{
setlocale(LC_ALL, "Portuguese");

// 1. Dados
	  const int NUMLUGARES = 7; 
	  char lugares[NUMLUGARES]; 
	  char escolha = '\0' ;
	  bool queroSair = false;    
 	inicializaParque(lugares, NUMLUGARES);
	do{
		
	mostraMenu();
	escolha = obtemEscolha(escolha); queroSair =
	processaEscolha(escolha,lugares,
	NUMLUGARES, queroSair);
	}while(!queroSair); 
	despedida();
return 0;
}
 //* Função "inicializaParque()"


	void inicializaParque(char lugares[], int numElementos)
	{
	for(int cLugar= 0; cLugar < numElementos;
	cLugar++) lugares[cLugar] = LIVRE;
} // Fim da função.

 //* Função "mostraMenu()"

	void mostraMenu()
	{
	
	system("cls"); system("color A");
	printf("**********************************\n");
	printf("*                                *\n");
	printf("*                                *\n");
	printf("*       Parque Guest             *\n");
	printf("*                                *\n");
	printf("*         A. Listar              *\n");	
	printf("*         B. Marcar lugar.       *\n");
	printf("*         C. Libertar lugar.     *\n");
	printf("*         D. Sair do programa.   *\n");
	printf("*                                *\n");
	printf("**********************************\n");
	printf("\n");
} // Fim da função.

	//* Função "obtemEscolha()"


	char obtemEscolha(char escolha)
	{
	fflush(stdin);
	printf("Qual a sua escolha (A-D)? ");
	scanf("%c", &escolha);
	fflush(stdin);
return escolha;
}

//* Função "processaEscolha()"

 bool processaEscolha(char escolha, char lugares[], int numLugares, bool queroSair)
{
	switch(escolha)
	{
	case 'a': case 'A': 
	listarLugares(lugares, numLugares); break;
	case 'b': case 'B': 
	marcarLugar(lugares, numLugares); break;
	case 'c': case 'C':
	libertarLugar(lugares, numLugares); break;
	case 'd': case 'D':
	queroSair = sairDoPrograma(queroSair); break;
	default: escolhaInvalida(escolha);
}
return queroSair;
}	// Fim da função.

//* Função "listarLugares()"

	void listarLugares(char lugares[],
	int numLugares)
	{
	printf("Listagem de lugares: \n");
	for (int cLugar=0; cLugar < numLugares;cLugar++)
	{
	printf("Lugar %d: ",(cLugar+1));
	if (lugares[cLugar] == LIVRE)
		printf("livre.\n"); 
	else
		printf("ocupado.\n");	
	}
system("pause");
}	// Fim da função.

//* Função "marcarLugar()"

	void marcarLugar(char lugares[], int numLugares)
{
	int numLugar = 0; 
	do {
	printf("Qua1 o lugar a ocupar (1-%d)? ",
	numLugares); scanf("%d", &numLugar);
	if (numLugar >= 1 && numLugar <= numLugares)
	{
		if (lugares[numLugar-1] == LIVRE)
		{
		printf("Lugar ocupado com sucesso!\n");
	}
	else
	{
	printf("O lugar escolhido, já está");
	printf(" ocupado!\n");
	}
	}
	else
	{
		printf("Os lugares devem estar entre 1 e %d!\n",
		numLugares);
	}
} while(numLugar < 1 || numLugar > numLugares || lugares[numLugar-1]== OCUPADO);
lugares[numLugar-1] = OCUPADO; 
system("pause");
}	// Fim da função.


//* Função "libertarLugar()"

		void libertarLugar(char lugares[], int numLugares)
	{
		int numLugar = 0;
	do{
		printf("Qua1 o lugar a libertar (1-%d)? ",numLugares); 
		scanf("%d", &numLugar);
	if (numLugar >= 1 && numLugar <= numLugares)
		{
		 if (lugares[numLugar-1] == OCUPADO)
			{
			 lugares[numLugar-1] = LIVRE;
				printf("Lugar libertado com sucesso!\n");
	}
	else
		{
		printf("O lugar escolhido, já está"); 
		printf(" livre!\n");
	}
}
else
	{
	printf("Os lugares devem estar entre 1 e %d!\n",
	numLugares);
	}
} while(numLugar <1 || numLugar > numLugares); 
system("pause");
} // Fim da função.

	//função "obtemEscolha"
	
	char obtemEscolhaII(char escolha, int numOpcoes,
	bool isDigit)
	{
		char ultimaOp = '\0';
		
		if (isDigit)
		{
			ultimaOp = numOpcoes;
			printf("Qual é a sua escolha (1-%d)? ", ultimaOp);
		}
		else
		{
			ultimaOp = (char)(numOpcoes+64);
			printf("Qual é a sua escolha (1-%c)? ", ultimaOp);
		}
		scanf("%c", &escolha);
		fflush(stdin);
		return escolha;
	}
//* Função "sairDoPrograma()"
	
	bool sairDoPrograma(bool queroSair)
		{
		printf("Tem a certeza que quer sair (S/N)? ");
		char resposta = '\0';
		fflush(stdin); scanf("%c", &resposta);
		fflush(stdin); 
		if (resposta == 's' || resposta == 'S')
		return true;
		else
		return false;
} //fim da função
	
	// Funçao "escolhalnvalida()"

	void escolhaInvalida(char escolha)
		{
		printf("\"%c\"");
		printf(" é uma escolha inválida!\n");
	system("pause") ;
}  // Fim da função.
	
	// Funçao "escolhalnvalida()"
	void escolhaInvalidaII(char escolha, int numOpcoes,
	bool isDigit)
	{
		char ultimaOp = '\0';
		
		printf("\"%c\" é uma escolha inválida!\n", escolha);
		
		if (isDigit)
		{
			ultimaOp = numOpcoes;
			printf("Escolha inválida! Escolhas de 1 a %d.\n",
			ultimaOp);
		}
		else
		{
			ultimaOp = (char) (numOpcoes+64);
			printf("Escolha inválida! Escolhas de 1 a %c.\n",
			ultimaOp);
		}
		pausaC();
	}
//* Função "despedida()"

	void despedida()
		{
		printf("Obrigado por ter usado o programa.\n"); 
		pausaC();
}
	//Função "pausaC ()"
	
	void pausaC()
	{
		printf("Prima qualquer tecla para continuar ...");
		getch();
	}

