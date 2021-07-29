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
		printf("Quantas notas quer inserir? ");
		scanf("%d", &numNotas);
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

	printf("******************************************\n");
	printf("*                                        *\n");
	printf("*         Estatística de Notas           *\n");
 	printf("*                                        *\n");
	printf("*    1. Inserção de notas.               *\n");
	printf("*    2. Listar notas.                    *\n");	
	printf("*    3. Apresentar a média das notas.    *\n");
	printf("*    4. Apresentar a nota máxima.        *\n");
	printf("*    5. Apresentar a nota minima.        *\n");	
	printf("*    6. Apagar as notas.                 *\n");
	printf("*    7. Sair do programa.                *\n");
	printf("*                                        *\n");
 	printf("******************************************\n");
  
	printf("\n");
}

	//Função obtemEscolha()

char obtemEscolha(char escolha, int numOpcoes, bool isDigit)
{
	if(isDigit)
	{
		int ultimaOp = numOpcoes;
		printf("Qual é a sua escolha (1-%d)? ",ultimaOp);
	}
	else
	{
	char ultimaOp = (char)(numOpcoes+64);
	printf("Qual é a sua escolha (1-%c)? ",ultimaOp);
	}
	scanf("%c", &escolha); fflush(stdin);
		return escolha;
	}//fim da função
	
	
	//função sair do programa

	bool sairDoPrograma(bool queroSair)
	{
		printf("Tem a certeza que quer sair (S/N)? ");
		char resposta = '\0';
		fflush(stdin); scanf("%c", &resposta); fflush(stdin); 
		if (resposta == 's' || resposta == 'S')
		return true;
		else
		return false;
} //fim da função

		
	//função escolaInvalida()
	void escolhaInvalida(char escolha, int numOpcoes, bool isDigit)
	{
		printf("\"%c\"; é uma escolha inválida!\n", escolha);
		if (isDigit)
		{
			int ultimaOp = numOpcoes;
			printf("Escolha inválida! Escolhas de 1 a %d.\n",ultimaOp);
				}
				else
			{
				char ultimaOp = (char) (numOpcoes+64);
				printf("Escolha inválida!Escolhas de 1 a %c.\n",
				ultimaOp);
			}
			pausaC();		
	}//fim da função
	
	//função despedida
	void despedida()
	{
	printf("\nObrigado por ter usado o nosso programa.\n"); 
	pausaC();
} // Fim da função.

//* Função "pausaC()"

void pausaC()
	{
	printf("Prima qualquer tecla para continuar	");
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
	printf("Insira %d notas:\n",numNotas);
		for (int cValor=0; cValor < numNotas; cValor++)
		{
		printf("Insira a nota %d ",(cValor+1));
		scanf("%f", &notas[cValor]);
	}
	fflush(stdin);
	break;
}
	case '2' :	// Listar notas.
	{
	if (numNotas >0)
		{
		printf("Listagem das notas:\n");
			for (int cValor=0; cValor < numNotas; cValor++)
			{
			printf("Nota %d:     %3.1f.\n",  (cValor+1),
			notas[cValor]);
		}
	printf("\n");	
	}
	else
		printf("Não definiu o numero de notas.\n"); 
		pausaC();
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
	printf("Média de notas: %5.2f.\n",media);
	printf("\n");
	}
	else
		printf("Não definiu o número de notas.\n");
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
	printf("Máximo: %5.2f.\n",maximo);
	printf("\n");
	}
	else
		printf("Não definiu o número de notas.\n"); 
		pausaC();
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
	printf("Mínimo: %5.2f.\n",minimo);
	printf("\n");
	}
	else
		printf("Não definiu o número de notas.\n");
		pausaC();
break;
	}
	case '6':	// Apagar as notas.
	{
	inicializaVetor(notas, numNotas); 
	printf("Vetor limpo com sucesso.\n\n"); 
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

