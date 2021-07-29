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
	cout<<"**********************************"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*         Taxis Guest            *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*         A. Listar t�xis        *"<<endl;	
	cout<<"*         B. Reservar t�xi       *"<<endl;
	cout<<"*         C. Chamar t�xi         *"<<endl;
	cout<<"*         D. Libertar t�xi       *"<<endl;
	cout<<"*         E. Sair do programa.   *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"**********************************"<<endl;
cout<<endl;
} // Fim da fun��o.

	//* Fun��o "obtemEscolha()"

	char obtemEscolha(char escolha)
	{
	cout<<"Qual a sua escolha (A-E)? "; cin>>escolha;
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
	cout<<"Listagem de t�xis: "<<endl; 
	for (int cTaxi=0; cTaxi < numTaxis; cTaxi++)
	{
	cout<<"T�xi "<<(cTaxi+1)<<": "; 
	if (taxis[cTaxi] == LIVRE)
		cout<<"1ivre."<<endl;
	else if (taxis[cTaxi] == RESERVADO) 
		cout<<"reservado."<<endl;
	else
		cout<<"ocupado."<<endl;
	}
system("pause");
}	// Fim da fun��o.

// Fun��o "marcarTaxi()"
	
	void reservarTaxi(char taxis[], int numTaxis)
	{
	int numTaxi = 0;
	do{
		cout<<"Qual o t�xi a reservar (1-"; 
		cout<<numTaxis<<")? "; cin>>numTaxi;

	if (numTaxi >= 1 && numTaxi <= numTaxis)
	{
	if (taxis[numTaxi-1] == RESERVADO || taxis[numTaxi-1] == OCUPADO)
	{
	cout<<"O t�xi escolhido, j� est�"; 
	cout<<" reservado ou ocupado!"<<endl;
	}
	else
		{
		taxis[numTaxi-1] = RESERVADO;
		cout<<"T�xi reservado com sucesso!"<<endl;
		}
	}
	else
		{
		cout<<"Os t�xis devem estar entre 1"; 
		cout<<" e "<<numTaxis<<"!"<<endl;
	}
} while(numTaxi <1 || numTaxi > numTaxis);
system("pause");
}	// Fim da fun��o

//Fun��o "marcarTaxi()"
	void marcarTaxi(char taxis[], int numTaxis)
	{
	int numTaxi = 0;
	do{
	cout<<"Qua1 o t�xi a ocupar (l-";
	cout<<numTaxis<<")? ";	cin>>numTaxi;

	if (numTaxi >= 1 && numTaxi <= numTaxis)
	{
	if (taxis[numTaxi-1] == LIVRE || taxis[numTaxi-1] == RESERVADO)
	{
	cout<<"T�xi ocupado com sucesso!"<<endl;
	}
	else
		{
		cout<<"O t�xi escolhido, j� est�"; 
		cout<<" ocupado!"<<endl;
		}
	}
	else
		{
		cout<<"Os t�xis devem estar entre 1";
		cout<<" e "<<numTaxis<<"!"<<endl;
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
		cout<<"Qual o t�xi a libertar (l-"; 
		cout<<numTaxis<<")? "; cin>>numTaxi;
	if (numTaxi >= 1 && numTaxi <= numTaxis)
		{
		if (taxis[numTaxi-1] == OCUPADO
		|| taxis[numTaxi-1] == RESERVADO)
		{
		taxis[numTaxi-1] = LIVRE;
		cout<<"Taxi libertado com sucesso!"<<endl;
	}
	else
	{
	cout<<"O taxi escolhido, j� est�"; 
	cout<<" livre!"<<endl;
		}
	}
	else
		{
		cout<<"Os taxis devem estar entre 1"; 
		cout<<" e "<<numTaxis<<"!"<<endl;
	}
} while(numTaxi <1 || numTaxi > numTaxis);
 system("pause");
} // Fim da fun��o.

//* Fun��o "sairDoPrograma()"
	
	bool sairDoPrograma(bool queroSair)
	{
		cout<<"Tem a certeza que quer sair (S/N)? ";
		char resposta = '\0';
		fflush(stdin); cin>>resposta; fflush(stdin); 
		if (resposta == 's' || resposta == 'S')
		return true;
		else
		return false;
} //fim da fun��o
	
	//* Fun�ao "escolhalnvalida()"

	void escolhaInvalida(char escolha)
		{
		cout<<"\""<<escolha<<"\"";
		cout<<" � uma escolha inv�lida!\n";
	system("pause") ;
}  // Fim da fun��o.

//* Fun��o "despedida()"

	void despedida()
		{
		cout<<"Obrigado por ter usado o programa."; 
		cout<<endl;
system("pause");
}

