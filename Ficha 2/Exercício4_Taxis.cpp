/*
	Taxis
	Fazer um programa que gere uma frota de 10 taxis. O programa deve 
	apresentar um menu com as seguintes op��es: - Listar taxi; 
	- Reservar taxi; - Chamar taxi; - Libertar taxi; - Sair do programa.   
*/

// Inclus�o de Bibliotecas: C
#include <stdio.h>  // Fun��es: "scanf()", "printf()"
#include <stdlib.h> // Fun��es: "system()".
#include <locale.h> // "setlocale()"
#include <math.h>   // "pow()", "sqrt()"
#include <conio.h>  // "getch()"

// Inclus�o de Bibliotecas: C++

#include <iostream> // Cont�m o "cin" e o "cout"
#include <iomanip>  // Cont�m "setprecision()"
using namespace std; // Selecionar o "std" como espa�o de nomes
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
	//* Fun��o "inicializaTaxis()"
	void inicializaTaxis(char taxis[], int numElementos)
	{
	for(int cTaxi= 0; cTaxi < numElementos;	cTaxi++) 
	taxis[cTaxi] = LIVRE;
}

 //* Fun��o "mostraMenu()"

	void mostraMenu()
	{
	system("cls"); system("color A");
	printf("**********************************\n");
	printf("*                                *\n");
	printf("*                                *\n");
	printf("*         Taxis Guest            *\n");
	printf("*                                *\n");
	printf("*         A. Listar t�xis        *\n");	
	printf("*         B. Reservar t�xi       *\n");
	printf("*         C. Chamar t�xi         *\n");
	printf("*         D. Libertar t�xi       *\n");
	printf("*         E. Sair do programa.   *\n");
	printf("*                                *\n");
	printf("**********************************\n");
	printf("\n");
} // Fim da fun��o.

	//* Fun��o "obtemEscolha()"

	char obtemEscolha(char escolha)
	{
	fflush(stdin);
	printf("Qual a sua escolha (A-E)? "); scanf("%c", &escolha);
	fflush(stdin);
return escolha;
}

	//* Fun��o "processaEscolha()"

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
}	// Fim da fun��o.

// Fun��o "listarTaxis()"

	void listarTaxis(char taxis[], int numTaxis)
	{
	printf("Listagem de t�xis: \n"); 
	for (int cTaxi=0; cTaxi < numTaxis; cTaxi++)
	{
	printf("T�xi %d",(cTaxi+1)); 
	if (taxis[cTaxi] == LIVRE)
		printf("1ivre.\n");
	else if (taxis[cTaxi] == RESERVADO) 
		printf("reservado.\n");
	else
		printf("ocupado.\n");
	}
system("pause");
}	// Fim da fun��o.

// Fun��o "marcarTaxi()"
	
	void reservarTaxi(char taxis[], int numTaxis)
	{
	int numTaxi = 0;
	do{
		printf("Qual o t�xi a reservar (1-%d)? ", numTaxis);
		scanf("%d", &numTaxi);

	if (numTaxi >= 1 && numTaxi <= numTaxis)
	{
	if (taxis[numTaxi-1] == RESERVADO || taxis[numTaxi-1] == OCUPADO)
	{
	printf("O t�xi escolhido, j� est�"); 
	printf(" reservado ou ocupado!\n");
	}
	else
		{
		taxis[numTaxi-1] = RESERVADO;
		printf("T�xi reservado com sucesso!\n");
		}
	}
	else
		{
		printf("Os t�xis devem estar entre 1 e %d!\n", numTaxis);
	}
} while(numTaxi <1 || numTaxi > numTaxis);
system("pause");
}	// Fim da fun��o

//Fun��o "marcarTaxi()"
	void marcarTaxi(char taxis[], int numTaxis)
	{
	int numTaxi = 0;
	do{
	printf("Qua1 o t�xi a ocupar (l-%d)? ", numTaxis);
	scanf("%d", &numTaxi);

	if (numTaxi >= 1 && numTaxi <= numTaxis)
	{
	if (taxis[numTaxi-1] == LIVRE || taxis[numTaxi-1] == RESERVADO)
	{
	printf("T�xi ocupado com sucesso!\n");
	}
	else
		{
		printf("O t�xi escolhido, j� est�"); 
		printf(" ocupado!\n");
		}
	}
	else
		{
		printf("Os t�xis devem estar entre 1 e %d!\n", numTaxis);
		}
	} while(numTaxi <1 || numTaxi > numTaxis || taxis[numTaxi-1] == OCUPADO); 
	taxis[numTaxi-1] = OCUPADO; 
system("pause");
}	// Fim da fun��o.

//* Fun��o "libertarTaxi()"
	void libertarTaxi(char taxis[], int numTaxis)
	{
	int numTaxi = 0;
	do {
		printf("Qual o t�xi a libertar (l-%d)? ", numTaxis);
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
	printf("O taxi escolhido, j� est�"); 
	printf(" livre!\n");
		}
	}
	else
		{
		printf("Os taxis devem estar entre 1 e %d!\n",numTaxis);
	}
} while(numTaxi <1 || numTaxi > numTaxis);
 system("pause");
} // Fim da fun��o.

//* Fun��o "sairDoPrograma()"
	
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
} //fim da fun��o
	
	//* Fun�ao "escolhalnvalida()"

	void escolhaInvalida(char escolha)
		{
		printf("\"%c\"");
		printf(" � uma escolha inv�lida!\n");
	system("pause");
}
//* Fun��o "despedida()"

	void despedida()
		{
		printf("Obrigado por ter usado o programa.\n"); 
	system("pause");
}
		//Fun��o "pausaC()"
		void pausaC()
		{
			printf("Prima qualquer tecla para continuar ....");
			getch();
}


