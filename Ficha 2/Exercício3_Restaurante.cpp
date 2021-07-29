/*
	Restaurante
	Fazer um programa que gere 10 mesas de um restaurante. 
	O programa deve apresentar um menu com as seguintes op��es: 
	- Listar mesas; - Reservar mesa; - Ocupar mesa; - Desocupar mesa; 
	- Sair do programa.  
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
	const char LIVRE = 'L', RESERVADA = 'R'
	, OCUPADA = 'O' ;

	void inicializaMesas(char[], int); 
	void mostraMenu();
	char obtemEscolha(char );
	bool processaEscolha(char, char[], int, bool); 
	void listarMesas(char[], int); 
	void reservarMesa(char[], int); 
	void marcarMesa(char[], int); 
	void libertarMesa(char[], int); 
	bool sairDoPrograma(bool);
	void escolhaInvalida(char); 
	void despedida();
	void pausaC();

int main()
{
setlocale(LC_ALL, "Portuguese");

// 1. Dados
	const int NUMMESAS = 7; 
	char mesas[NUMMESAS]; 
	char escolha = '\0'; 
	bool queroSair = false;
	
	inicializaMesas(mesas, NUMMESAS); 
		do {
			mostraMenu();
			escolha = obtemEscolha(escolha); queroSair =
			processaEscolha (escolha ,mesas ,
								NUMMESAS, queroSair);
}while(!queroSair); 
despedida();
return 0;
}

	void inicializaMesas(char mesas[],
	int numElementos)
	{
	for(int cMesa= 0; cMesa < numElementos;
	cMesa++) mesas[cMesa] = LIVRE;
}

 //* Fun��o "mostraMenu()"

	void mostraMenu()
	{
	system("cls"); system("color A");
	printf("**********************************\n");
	printf("*                                *\n");
	printf("*                                *\n");
	printf("*       Restaurante Guest        *\n");
	printf("*                                *\n");
	printf("*         A. Listar mesas        *\n");	
	printf("*         B. Reservar mesa       *\n");
	printf("*         C. Ocupar mesa         *\n");
	printf("*         D. Libertar mesa       *\n");
	printf("*         E. Sair do programa.   *\n");
	printf("*                                *\n");
	printf("**********************************\n");
printf("\n");
} // Fim da fun��o.

	//* Fun��o "obtemEscolha()"

	char obtemEscolha(char escolha)
	{
	printf("Qual a sua escolha (A-E)? "); scanf("%c", &escolha);
	fflush(stdin);
return escolha;
}

//* Fun��o "processaEscolha()"

 	bool processaEscolha(char escolha, 
 		char mesas[], int numMesas, 
		 bool queroSair)
	{
	switch(escolha)
	{
	case 'a': case 'A': 
	listarMesas(mesas, numMesas); break;
	case 'b': case 'B': 
	reservarMesa(mesas, numMesas); break;
	case 'c': case 'C': 
	marcarMesa(mesas, numMesas); break;
	case 'd': case 'D': 
	libertarMesa(mesas, numMesas); break;
	case 'e': case 'E':
	queroSair = sairDoPrograma(queroSair); break;
	default: 
	escolhaInvalida(escolha);
}
return queroSair;
}	// Fim da fun��o.

//* Fun��o "listarMesas"

	void listarMesas(char mesas[],
			int numMesas)
	{
	printf("Listagem de mesas: \n");
	for (int cMesa=0; cMesa < numMesas;	cMesa++)
	{
	printf("Mesa %d", (cMesa+1)); 
	if (mesas[cMesa] == LIVRE)
		printf("livre.\n");
	else if (mesas[cMesa] == RESERVADA) 
		printf("reservada.\n");
	else
		printf("ocupada.\n");
	}
system("pause");
}	// Fim da fun��o.

//* Fun��o "marcarMesa()"
	
	void reservarMesa(char mesas[], int numMesas)
		{
		int numMesa = 0; 
		do {
		printf("Qual a mesa a reservar (l-%d)? ", numMesas);
	
	if (numMesa >= 1 && numMesa <= numMesas)
		{
		if (mesas[numMesa-1] == RESERVADA
			|| mesas[numMesa-1] == OCUPADA)
			{
			printf("A mesa escolhida, j� est�"); 
			printf(" reservada ou ocupada!\n");
			}
		else
			{
			mesas[numMesa-1] = RESERVADA;
			printf("Mesa reservada com sucesso!\n");
			}
		}
	else
		{
		printf("Os mesas devem estar entre 1 e %d!\n", numMesas);
	}
} while(numMesa <1 || numMesa > numMesas);
system("pause");
}	// Fim da fun��o
//Fun��o "MARCARMESA()"
	void marcarMesa(char mesas[], int numMesas)
	{
	int numMesa = 0;
	do{
	printf("Qua1 a mesa a ocupar (l-%d)? ", numMesas);

	if (numMesa >= 1 && numMesa <= numMesas)
	{
	if (mesas[numMesa-1] == LIVRE
	|| mesas[numMesa-1] == RESERVADA)
	{
	printf("Mesa ocupada com sucesso!\n");
	}
	else
		{
		printf("A mesa escolhida, j� est�");
		printf(" ocupada!\n");
		}
	}
	else
		{
		printf("Os mesas devem estar entre 1 e %d!\n", numMesas);
	}
} while(numMesa <1 || numMesa > numMesas
		|| mesas[numMesa-1] == OCUPADA); 
		mesas[numMesa-1] = OCUPADA; 
system("pause");
}	// Fim da fun��o.

//* Fun��o "libertarMesa()"
	void libertarMesa(char mesas[], int numMesas)
	{
	int numMesa = 0; 
	do {
		printf("Qual a mesa a libertar (1-%d)? ", numMesas);
		scanf("%d", &numMesa);
		
		if (numMesa >= 1 && numMesa <= numMesas)
		{
		if (mesas[numMesa-1] == OCUPADA
		|| mesas[numMesa-1] == RESERVADA)
	{
	mesas[numMesa-1] = LIVRE;
	printf("Mesa libertada com sucesso!\n");
	}
	else
		{
		printf("A mesa escolhida, j� est�"); 
		printf(" livre!\n");
		}
	}
	else
		{
		printf("As mesas devem estar entre 1 e %d!\n", numMesas);
	}
} while(numMesa <1 || numMesa > numMesas);
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
	system("pause") ;
}  // Fim da fun��o.

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

