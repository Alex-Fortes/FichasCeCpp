/* 
	01 -> Classe "Produto": Campos ou Dados
	Enunciado: crie um programa/classe. Nesse programa crie uma classe 
	"Produto" com os seguintes atributos: Código do produto (int); 
	Designação do produto (string); Quantidade por unidade (float); 
	Número de unidades existentes (int); Preço atual (float); 
	Data de validade (string); Secção (string). O programa deve ler os 
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
 
// Definição da Classe
 
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
 
// Fungção principal
 
int main()
{
	setlocale (LC_ALL, "Portuguese");
	// Dados
	// Declaração de variáveis
	// Definição de constantes
Produto produto;
	// Declaração de um objeto da classe "Produto"
	
	// Declaração de um vetor estático de caracteres: C 
	char linhaTexto[100];
	for(int cLetra=0; cLetra<100; cLetra++)
		linhaTexto[cLetra]='\0';
		
	// Declaração de um vetor dinamico de caracteres: C 
	char *linhaTexto2 = (char*) malloc(100*sizeof(char));
		// (char* ) - cast - conversão forçada 
	for(int cLetra=0; cLetra<100; cLetra++)
	linhaTexto2[cLetra]='\0';
	
	// 2. Entrada de dados
	cout<<"Qual é o código do produto? ";
	cin>>produto.codProduto;
	cin.ignore();
	
	cout<<"Qual é a designação do produto? ";
	// cin>>produto.designacao; // -> só lê uma palavra
	
	getline(cin,produto.designacao);
	cout<<"Qual é a unidade de medida? ";
	getline(cin,produto.unidade);
	cout<<"Qual é a quantidade por unidade? ";
	cin>>produto.quantidadeUnidade;
	cout<<"Qual é o número de unidades em inventário? ";
	cin>>produto.numUnidades;
	cout<<"Qual é o preço de cada unidade? ";
	cin>>produto.preco;
	
	cout<<"Qual é a taxa de IVA? ";
	cin>>produto.taxaIVA; 
	cin.ignore();
	
	cout<<"Qual é a data de validade (DD /MM/AAAA)? ";
	getline(cin,produto.dataValidade);
	
	cout<<"Qual é a seção do produto? ";
	getline(cin,produto.secao);
	
	string resposta = "";
	cout<<"O produto precisa de frio (sim/nao)? ";
	cin>>resposta;
	if(resposta.compare("sim") == 0)
		produto.precisaFrio = true;
	else
		produto.precisaFrio = false;
		
	// 3. Apresentação de dados 
	cout<<"Dados inseridos para o Produto: "<<endl;
	cout<<"Código: "<<produto.codProduto<<"."<<endl;
	cout<<"Designação: "<<produto.designacao<<"."<<endl;
	cout<<"Inventário: "<<produto.numUnidades
		<<" unidades."<<endl;
	cout<<"Cada unidade tem "<<produto.quantidadeUnidade
		<<" "<<produto.unidade<<"."<<endl;
	cout<<"Custa "<<produto.preco<<" euros com um IVA de "
		<<produto.taxaIVA<<"%."<<endl;
	cout<<"Data de validade: "<<produto.dataValidade<<"."<<endl;
	cout<<"O produto está na secção de "<<produto.secao<<"."<<endl;
	cout<<"Precisa de frio? ";
		if(produto.precisaFrio == false) 
			cout<<"não."<<endl;
		else
			cout<<"sim."<<endl;
system("pause");
return 0;
} 







