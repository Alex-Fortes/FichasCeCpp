/*
	Taxis
	Fazer um programa que gere uma frota de 10 taxis. O programa deve 
	apresentar um menu com as seguintes opções: - Listar taxi; 
	- Reservar taxi; - Chamar taxi; - Libertar taxi; - Sair do programa.   
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
	const char LIVRE = 'L', RESERVADO = 'R', OCUPADO = 'O' ;

	void inicializaTaxis(char[], int); 
	void mostraMenu();
	char obtemEscolha(char );
	bool processaEscolha(char, char[], int, bool); 
	void listarTaxis(char[], int); 
	void reservarTaxi(char[], int); 
	void marcarTaxi(char[], int); 
	void libertarTaxi(char[], int); 
	bool sairDoPrograma(bool);
	void escolhaInvalida(char); 
	void despedida();

int main()
{
setlocale(LC_ALL, "Portuguese");

// 1. Dados
	const int NUMTAXIS = 7; 
	char taxis[NUMTAXIS]; 
	char escolha = '\0' ; 
	bool queroSair = false;
	
	inicializaTaxis(taxis, NUMTAXIS); 
	do {
		mostraMenu();
		escolha = obtemEscolha(escolha); 
		queroSair = processaEscolha(escolha,taxis,NUMTAXIS, queroSair);
	}while(!queroSair); 
	despedida();
return 0;
}
	//* Função "inicializaTaxis()"
	void inicializaTaxis(char taxis[], int numElementos)
	{
	for(int cTaxi= 0; cTaxi < numElementos;	cTaxi++) 
	taxis[cTaxi] = LIVRE;
}

 //* Função "mostraMenu()"

	void mostraMenu()
	{
	system("cls"); system("color A");
	printf("**********************************\n");
	printf("*                                *\n");
	printf("*                                *\n");
	printf("*         Taxis Guest            *\n");
	printf("*                                *\n");
	printf("*         A. Listar táxis        *\n");	
	printf("*         B. Reservar táxi       *\n");
	printf("*         C. Chamar táxi         *\n");
	printf("*         D. Libertar táxi       *\n");
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
 		char taxis[], int numTaxis, bool queroSair)
	{
	switch(escolha)
	{
	case 'a': case 'A': 
	listarTaxis(taxis, numTaxis); break;
	case 'b': case 'B': 
	reservarTaxi(taxis, numTaxis); break;
	case 'c': case 'C': 
	marcarTaxi(taxis, numTaxis); break;
	case 'd': case 'D': 
	libertarTaxi(taxis, numTaxis); break;
	case 'e': case 'E':
	queroSair = sairDoPrograma(queroSair); break;
	default: 
	escolhaInvalida(escolha);
}
return queroSair;
}	// Fim da função.

// Função "listarTaxis()"

	void listarTaxis(char taxis[], int numTaxis)
	{
	printf("Listagem de táxis: \n"); 
	for (int cTaxi=0; cTaxi < numTaxis; cTaxi++)
	{
	printf("Táxi %d",(cTaxi+1)); 
	if (taxis[cTaxi] == LIVRE)
		printf("1ivre.\n");
	else if (taxis[cTaxi] == RESERVADO) 
		printf("reservado.\n");
	else
		printf("ocupado.\n");
	}
system("pause");
}	// Fim da função.

// Função "marcarTaxi()"
	
	void reservarTaxi(char taxis[], int numTaxis)
	{
	int numTaxi = 0;
	do{
		printf("Qual o táxi a reservar (1-%d)? ", numTaxis);
		scanf("%d", &numTaxi);

	if (numTaxi >= 1 && numTaxi <= numTaxis)
	{
	if (taxis[numTaxi-1] == RESERVADO || taxis[numTaxi-1] == OCUPADO)
	{
	printf("O táxi escolhido, já está"); 
	printf(" reservado ou ocupado!\n");
	}
	else
		{
		taxis[numTaxi-1] = RESERVADO;
		printf("Táxi reservado com sucesso!\n");
		}
	}
	else
		{
		printf("Os táxis devem estar entre 1 e %d!\n", numTaxis);
	}
} while(numTaxi <1 || numTaxi > numTaxis);
system("pause");
}	// Fim da função

//Função "marcarTaxi()"
	void marcarTaxi(char taxis[], int numTaxis)
	{
	int numTaxi = 0;
	do{
	printf("Qua1 o táxi a ocupar (l-%d)? ", numTaxis);
	scanf("%d", &numTaxi);

	if (numTaxi >= 1 && numTaxi <= numTaxis)
	{
	if (taxis[numTaxi-1] == LIVRE || taxis[numTaxi-1] == RESERVADO)
	{
	printf("Táxi ocupado com sucesso!\n");
	}
	else
		{
		printf("O táxi escolhido, já está"); 
		printf(" ocupado!\n");
		}
	}
	else
		{
		printf("Os táxis devem estar entre 1 e %d!\n", numTaxis);
		}
	} while(numTaxi <1 || numTaxi > numTaxis || taxis[numTaxi-1] == OCUPADO); 
	taxis[numTaxi-1] = OCUPADO; 
system("pause");
}	// Fim da função.

//* Função "libertarTaxi()"
	void libertarTaxi(char taxis[], int numTaxis)
	{
	int numTaxi = 0;
	do {
		printf("Qual o táxi a libertar (l-%d)? ", numTaxis);
		scanf("%d", &numTaxi);
	if (numTaxi >= 1 && numTaxi <= numTaxis)
		{
		if (taxis[numTaxi-1] == OCUPADO
		|| taxis[numTaxi-1] == RESERVADO)
		{
		taxis[numTaxi-1] = LIVRE;
		printf("Taxi libertado com sucesso!\n");
	}
	else
	{
	printf("O taxi escolhido, já está"); 
	printf(" livre!\n");
		}
	}
	else
		{
		printf("Os taxis devem estar entre 1 e %d!\n",numTaxis);
	}
} while(numTaxi <1 || numTaxi > numTaxis);
 system("pause");
} // Fim da função.

//* Função "sairDoPrograma()"
	
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
		printf("\"%c\"");
		printf(" é uma escolha inválida!\n");
	system("pause");
}
//* Função "despedida()"

	void despedida()
		{
		printf("Obrigado por ter usado o programa.\n"); 
	system("pause");
}
		//Função "pausaC()"
		void pausaC()
		{
			printf("Prima qualquer tecla para continuar ....");
			getch();
}


