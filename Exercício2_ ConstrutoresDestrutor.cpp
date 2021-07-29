/* 
	02 -> Classe "Produto": Construtores e Destrutor
	Crie um programa/classe. Nesse programa crie uma classe 'Produto" 
	com os seguintes atributos: C�digo do produto (int); Designa��o do produto
	(string); Quantidade por unidade (float); N�mero de unidades existentes 
	(int); Pre�o atual (float); Data de validade (string); Sec��o (string). 
	Neste exerc�cio acrescente cinco construtores e um destructor. 
	O programa deve ler os dados de um produto e apresenta-los no monitor 
	utilizando pelo menos tr�s dos construtores criados.

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
	
	public: 
	Produto()
	{
		codProduto = 0; designacao = "";
		quantidadeUnidade = 0 ; unidade = "";
		numUnidades = 0; preco = 0; taxaIVA = 0;
		dataValidade = "";
		secao = ""; precisaFrio = false;
	}
	// Construtor com dois argumentos
	Produto (int codP, string d)
	{
		codProduto = codP; designacao  = d;
		quantidadeUnidade = 0; unidade = "";
		numUnidades = 0; preco = 0; taxaIVA = 0;
		dataValidade = "";
		secao = ""; precisaFrio = false;
	}
	// Construtor com cinco argumentos
	Produto (int codP, string d, float qU, string unid, int numU)
	{
		codProduto = codP; designacao = d;
		quantidadeUnidade = qU; unidade = unid; 
		numUnidades = numU; preco = 0;
		taxaIVA	= 0; dataValidade = "";
		secao = ""; precisaFrio = false;
	}

	// Construtor com seis argumentos
	Produto (int codP, string d, float qU, string unid, int numU, string dV)
	{
		codProduto = codP; designacao = d;
		quantidadeUnidade = qU; unidade = unid; 
		numUnidades = numU; preco = 0; taxaIVA = 0;
		dataValidade = dV; secao = ""; precisaFrio = false;
	}
	
	// Construtor com oito argumentos
	Produto (int codP, string d, float qU, 
	string unid, int numU, string dV , float p, float tIVA)
	{
		codProduto = codP; designacao = d;
		quantidadeUnidade = qU; unidade= unid; 
		numUnidades = numU; preco = p; taxaIVA = tIVA;
		dataValidade = dV; secao = ""; precisaFrio = false;
	}
	
	// Construtor com todos os argumentos
	Produto (int codP, string d, float qU, string unid,
	int numU , float p, float tIVA, string dv, string sec, bool pFrio)
	{
		codProduto = codP; designacao = d;
		quantidadeUnidade = qU; unidade = unid; 
		numUnidades = numU; preco = 0; taxaIVA = tIVA; 
		dataValidade = dv; 
		secao = sec; precisaFrio = pFrio;
	// 2.2 Fun��o Destrutora
	// Fun��o chamada antes da elimina��o do objeto. Tem o mesmo nome da classe
}
	~Produto()
	{
		cout<<" Elimina�ao de um objeto 'Produto': ";
		cout<<designacao<<".";
		cout<<endl;
	}
}; // Fim da classe.
 
// Fung��o principal
 
int main()
{
	setlocale(LC_ALL, "Portuguese");
	// 1 . Teste do construtor sem argumentos
	// 1 . 1 Dados
	// Declara��o do objeto .
	
	Produto produto;
	
	// 1.2 Entrada de dados
	cout<<"1. Teste do Construtor sem argumentos! "<<endl; cout<<endl;
	cout<<"Qual � o c�digo do produto? "; cin>>produto.codProduto;
	cin.ignore();  
	
	cout<<"Qual � a designa��o do produto? ";
	getline(cin,produto.designacao);
	
	cout<<"Qual � a unidade de medida? ";
	getline (cin,produto.unidade);
	
	cout<<"Qual � a quantidade por unidade? ";
	cin>>produto.quantidadeUnidade;
	
	cout<<"Qual � o n�mero de unidades em invent�rio? ";
	cin>>produto.numUnidades;
	
	cout<<"Qual � o pre�o de cada unidade? ";
	cin>>produto.preco;
	
	cout<<"Qual � a taxa de IVA? "; cin>>produto.taxaIVA; 
	cin.ignore();	
	
	cout<<"Qual � a data de validade (DD/MM/AAAA)? ";
	getline (cin,produto.dataValidade);
	
	cout<<"Qual � a se��o do produto? ";
	getline (cin,produto.secao);
	
	string resposta = "";
	cout<<"O produto precisa de frio (sim/nao)? ";
	cin>>resposta;
	if (resposta == "sim") 
		produto.precisaFrio = true;
	else
		produto.precisaFrio = false;
		
	// 1.3 Apresenta��o de dados
	cout<<"Dados inseridos para o Produto 1: "<<endl;
	cout<<"C�digo:	"<<produto.codProduto<<"."<<endl;
	cout<<"Designa��o: "<<produto.designacao<<"."<<endl;
	cout<<"Inventario: "<<produto.numUnidades<<" unidades."<<endl;
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
system("cls");


	// 5. Teste do construtor com todos os argumentos
	// 5 . 1 Dados 
	int	codProduto = 0;
	string designacao = "";
	float quantidadeUnidade = 0;
	string unidade = "";
	int	numUnidades = 0; 
	float preco = 0;
	float taxaIVA = 0;
	string dataValidade = "";
	string secao = "";
	bool precisaFrio = false;
	
// 5 . 2 Entrada de dados
  	cout<<"5. Teste do Construtor com todos os argumentos! "<<endl;cout<<endl;
  	cout<<"Qual � o c�digo do produto? ";
	cin>>codProduto; cin.ignore(); 
	
	cout<<"Qual � a designa��o do produto? ";
	getline (cin,designacao);
	
	cout<<"Qual � a unidade de medida? ";
	getline (cin,unidade);
	
	cout<<"Qual � a quantidade por unidade? ";
	cin>>quantidadeUnidade;
	
	cout<<"Qual � o n�mero de unidades em invent�rio? ";
	cin>>numUnidades;
	
	cout<<"Qual � o pre�o de cada unidade? ";
	cin>>preco;
	
	cout<<"Qual � a taxa de IVA? "; cin>>taxaIVA; 
	cin.ignore();	
	
	cout<<"Qual � a data de validade (DD/MM/AAAA)? ";
	getline (cin,dataValidade);
	
	cout<<"Qual � a se��o do produto? ";
	getline (cin,secao);
	
	string resposta5 = "";
	cout<<"O produto precisa de frio (sim/nao)? ";
	cin>>resposta5;
	if (resposta5 == "sim") 
		precisaFrio = true;
	else
		precisaFrio = false;
	
	// 5.3 Dados
	// Declara��o do objeto
	
	Produto produto5 (codProduto, designacao, quantidadeUnidade, 
	unidade, numUnidades, preco, taxaIVA, 
	dataValidade, secao, precisaFrio);
	
	// 5.4 Apresenta��o de dados 
	cout<<"Dados inseridos para o Produto 5: "<<endl;
	cout<<"C�digo:	"<<produto5.codProduto<<"."<<endl;
	cout<<"Designa��o: "<<produto5.designacao<<"."<<endl;
	cout<<"Inventario: "<<produto5.numUnidades<<" unidades."<<endl;
	cout<<"Cada unidade tem "<<produto5.quantidadeUnidade
		<<" "<<produto5.unidade<<"."<<endl;
	cout<<"Custa "<<produto5.preco<<" euros com um IVA de "
		<<produto5.taxaIVA<<"%."<<endl;
	cout<<"Data de validade: "<<produto5.dataValidade<<"."<<endl;
	cout<<"O produto est� na sec��o de "<<produto5.secao<<"."<<endl;
	cout<<"Precisa de frio? ";
		if(produto5.precisaFrio == false) 
			cout<<"n�o."<<endl;
		else
			cout<<"sim."<<endl;

return 0;
}











