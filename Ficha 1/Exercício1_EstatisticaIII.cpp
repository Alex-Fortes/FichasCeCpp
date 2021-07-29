/*
	NotasIII
	Fazer um progama que recebe as notas de final de período de uma turma de
	seis alunos. O programa apresenta um menu que tem as seguintes opções:
	- Inserção de notas; Listas notas; Apresentas a média das notas; apresentar
	a mpta máxima; apresentas a nota mínima; apagar notas; sair do programa.
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

// Função principal
// Função "main()"
int obtemNumNotas(int numNotas);
void inicializaVetor(float[] , int numNotas); void mostraMenu();
char obtemEscolha(char escolha, int numOpcoes, bool); 
bool sairDoPrograma(bool queroSair);
void escolhaInvalida(char escolha, int numOpcoes, bool); void despedida();
void pausaC();
bool processaEscolha(char escolha,
float[] , int numNotas, int numopcoes,
bool	queroSair);

int main()
{
setlocale(LC_ALL, "Portuguese");

// 1. Dados
	  int numNotas = 0; 
	  int numOpcoes = 7; 
	  char escolha = '\0' ; 
	  bool queroSair = false;
	       
  // 2. Algoritmo
	// 2.0 Definir o número de notas
		numNotas = obtemNumNotas (numNotas);
		float notas [numNotas];
		inicializaVetor (notas, numNotas);
	do {
		mostraMenu();
		escolha = obtemEscolha(escolha, numOpcoes, true);
		queroSair = processaEscolha(escolha, notas, numNotas,numOpcoes,queroSair);
	}while(!queroSair);
	despedida();
	return 0;	
}

// Definição das funções
//função "obtemNumNotas()"
int obtemNumNotas(int numNotas)
{
	while (numNotas <= 0){
		cout<<"Quantas notas quer inserir? ";
		cin>>numNotas;
	}
	fflush(stdin);
	return numNotas;
}//fim da função

//Função inicializaVetor

void inicializaVetor(float notas [], int numNotas)
{
	for (int cValor=0; cValor<numNotas; cValor++)
	{
		notas[cValor]=0;
	}
}//fim da função

// função mostraMenu
void mostraMenu()
{
	
  system("cls"); 
  system("color A");

	cout<<"******************************************"<<endl;
	cout<<"*                                        *"<<endl;
	cout<<"*         Estatística de Notas           *"<<endl;
 	cout<<"*                                        *"<<endl;
	cout<<"*    1. Inserção de notas.               *"<<endl;
	cout<<"*    2. Listar notas.                    *"<<endl;	
	cout<<"*    3. Apresentar a média das notas.    *"<<endl;
	cout<<"*    4. Apresentar a nota máxima.        *"<<endl;
	cout<<"*    5. Apresentar a nota minima.        *"<<endl;	
	cout<<"*    6. Apagar as notas.                 *"<<endl;
	cout<<"*    7. Sair do programa.                *"<<endl;
	cout<<"*                                        *"<<endl;
 	cout<<"******************************************"<<endl;
  

	cout<<"\n";
}

	//Função obtemEscolha()

char obtemEscolha(char escolha, int numOpcoes, bool isDigit)
{
	if(isDigit)
	{
		int ultimaOp = numOpcoes;
		cout<<"Qual é a sua escolha (1-"<<ultimaOp<<")? ";
	}
else
{
	char ultimaOp = (char)(numOpcoes+64);
	cout<<"Qual é a sua escolha (1-"<<ultimaOp<<")? ";
	}
		cin>>escolha; fflush(stdin);
		return escolha;
	}//fim da função
	
	
	//função sair do programa

	bool sairDoPrograma(bool queroSair)
	{
		cout<<"Tem a certeza que quer sair (S/N)? ";
		char resposta = '\0';
		fflush(stdin); cin>>resposta; fflush(stdin); 
		if (resposta == 's' || resposta == 'S')
		return true;
		else
		return false;
} //fim da função

		
	//função escolaInvalida()
	void escolhaInvalida(char escolha, int numOpcoes, bool isDigit)
	{
		cout<<"\""<<escolha<<"\"";
				cout<<"Escolha inválida!"<<endl;
		if (isDigit)
		{
			int ultimaOp = numOpcoes;
			cout<<"Escolha inválida! Escolhas de 1 a "<<ultimaOp<<".\n";
				}
				else
			{
				char ultimaOp = (char) (numOpcoes+64);
				cout<<"Escolha inválida!Escolhas de 1 a "<<ultimaOp<<"\.n";
			}
			pausaC();		
	}//fim da função
	
	//função despedida
	void despedida()
	{
	cout<<"\nObrigado por ter usado o nosso programa.\n"; pausaC();
} // Fim da função.

//* Função "pausaC()"

void pausaC()
	{
	cout<<"Prima qualquer tecla para continuar	";
//getche();	// Ecoa o caracter 
getch();	// Nào ecoa o caracter
} // Fim da funçao.

//* Função processaEscolha()"

	bool processaEscolha(char escolha, float notas[], int numNotas,
	int numOpcoes, bool	queroSair)
{
	switch(escolha)
{
	case '1':	// Inserção de notas.
	{
	cout<<"Insira "<<numNotas<<" notas:\n";
		for (int cValor=0; cValor < numNotas; cValor++)
		{
		cout<<"Insira a nota "<<(cValor+1)<<": "; cin>>notas[cValor];
	}
	fflush(stdin);
	break;
}
	case '2' :	// Listar notas.
	{
	if (numNotas >0)
		{
		cout<<"Listagem das notas:\n";
			for (int cValor=0; cValor < numNotas; cValor++)
			{
			cout<<"Nota "<<(cValor+1)<<": "
			<<fixed<<setw(6)<<setprecision(2)
			<<notas[cValor]<<".\n";
		}
	cout<<"\n";
}
	else
		cout<<"Não definiu o numero de notas.\n"; pausaC();
			break;
}
	case '3' :	// Apresentar a média das notas.
	{
	if (numNotas >0)
	{
	float media = 0;
	for (int cValor=0; cValor < numNotas; cValor++)
	{
	media += notas[cValor]/numNotas;
	}
	cout<<"Média de notas: "
	<<fixed<<setw(6)<<setprecision(2)
	<<media<<" \n"; cout<<"\n";
	}
	else
		cout<<"Não definiu o número de notas.\n";
pausaC ( ) ; 
break ;
	}
	case '4' :	// Apresentar a nota máxima.
		{
		if (numNotas >0)
			{
			float maximo = 0;
		for (int cValor=0; cValor < numNotas; cValor++)
		{
		if (cValor == 0 || maximo < notas[cValor]) maximo = notas[cValor];
	}
	cout<<"Máximo: "
<<fixed<<setw(6)<<setprecision(2)
<<maximo<<".\n"; cout<<"\n";
}
	else
		cout<<"Não definiu o número de notas.\n"; pausaC();
	break;
}
	case '5' :	// Apresentar a nota minima.
	{
	if (numNotas >0)
	{
	float minimo = 0;
	for (int cValor=0; cValor < numNotas; cValor++)
	{
		if (cValor == 0 || minimo > notas[cValor]) minimo = notas[cValor] ;
	}
cout<<"Mínimo: "
<<fixed<<setw(6)<<setprecision(2)
<<minimo<<".\n"; cout<<"\n";
}
	else
		cout<<"Não definiu o número de notas.\n"; pausaC();
break;
}

	case '6':	// Apagar as notas.
	{
	inicializaVetor(notas, numNotas); cout<<"Vetor limpo com sucesso.\n\n"; 
	pausaC();
break;
}
  case '7' :
  	{
  	queroSair = sairDoPrograma(queroSair);
break;
}
default: 
{
	escolhaInvalida(escolha, numOpcoes, true);
}//fim do switch
}
return queroSair;
}
//fim da função

