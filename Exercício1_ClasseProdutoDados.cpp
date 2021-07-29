/* 
	01 -> Classe "Produto": Campos ou Dados
	Enunciado: crie um programa/classe. Nesse programa crie uma classe 
	"Produto" com os seguintes atributos: C�digo do produto (int); 
	Designa��o do produto (string); Quantidade por unidade (float); 
	N�mero de unidades existentes (int); Pre�o atual (float); 
	Data de validade (string); Sec��o (string). O programa deve ler os 
	dados de um produto e apresenta-los no monitor.
*/
 
//  Bibliotecas do C
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Bibliotecas de C++
#include <iostream> 
#include <iomanip> 

using namespace std;
 
// Defini��o da Classe
 
class Produto { 
public:
	// 1. Dados da classe 
	int	codProduto; 
	string designacao;
	float quantidadeUnidade;
	string unidade;
	int	numUnidades; 
	float preco; 
	float taxaIVA; 
	string dataValidade;
	string secao; 
	bool precisaFrio;
}; // Fim da classe.
 
// Fung��o principal
 
int main()
{
	setlocale (LC_ALL, "Portuguese");
	// Dados
	// Declara��o de vari�veis
	// Defini��o de constantes
Produto produto;
	// Declara��o de um objeto da classe "Produto"
	
	// Declara��o de um vetor est�tico de caracteres: C 
	char linhaTexto[100];
	for(int cLetra=0; cLetra<100; cLetra++)
		linhaTexto[cLetra]='\0';
		
	// Declara��o de um vetor dinamico de caracteres: C 
	char *linhaTexto2 = (char*) malloc(100*sizeof(char));
		// (char* ) - cast - convers�o for�ada 
	for(int cLetra=0; cLetra<100; cLetra++)
	linhaTexto2[cLetra]='\0';
	
	// 2. Entrada de dados
	cout<<"Qual � o c�digo do produto? ";
	cin>>produto.codProduto;
	cin.ignore();
	
	cout<<"Qual � a designa��o do produto? ";
	// cin>>produto.designacao; // -> s� l� uma palavra
	
	getline(cin,produto.designacao);
	cout<<"Qual � a unidade de medida? ";
	getline(cin,produto.unidade);
	cout<<"Qual � a quantidade por unidade? ";
	cin>>produto.quantidadeUnidade;
	cout<<"Qual � o n�mero de unidades em invent�rio? ";
	cin>>produto.numUnidades;
	cout<<"Qual � o pre�o de cada unidade? ";
	cin>>produto.preco;
	
	cout<<"Qual � a taxa de IVA? ";
	cin>>produto.taxaIVA; 
	cin.ignore();
	
	cout<<"Qual � a data de validade (DD /MM/AAAA)? ";
	getline(cin,produto.dataValidade);
	
	cout<<"Qual � a se��o do produto? ";
	getline(cin,produto.secao);
	
	string resposta = "";
	cout<<"O produto precisa de frio (sim/nao)? ";
	cin>>resposta;
	if(resposta.compare("sim") == 0)
		produto.precisaFrio = true;
	else
		produto.precisaFrio = false;
		
	// 3. Apresenta��o de dados 
	cout<<"Dados inseridos para o Produto: "<<endl;
	cout<<"C�digo: "<<produto.codProduto<<"."<<endl;
	cout<<"Designa��o: "<<produto.designacao<<"."<<endl;
	cout<<"Invent�rio: "<<produto.numUnidades
		<<" unidades."<<endl;
	cout<<"Cada unidade tem "<<produto.quantidadeUnidade
		<<" "<<produto.unidade<<"."<<endl;
	cout<<"Custa "<<produto.preco<<" euros com um IVA de "
		<<produto.taxaIVA<<"%."<<endl;
	cout<<"Data de validade: "<<produto.dataValidade<<"."<<endl;
	cout<<"O produto est� na sec��o de "<<produto.secao<<"."<<endl;
	cout<<"Precisa de frio? ";
		if(produto.precisaFrio == false) 
			cout<<"n�o."<<endl;
		else
			cout<<"sim."<<endl;
system("pause");
return 0;
} 







