/* 
	04 -> Classe "Produto": Métodos de Interface
	Enunciado: crie um programa/classe. Nesse programa crie uma classe 
	"Produto" com os seguintes atributos: Código do produto (int); 
	Designação do produto (string); Quantidade por unidade (float); 
	Número de unidades existentes (int); Preço atual (float); 
	Data de validade (string); Secção (string). Nessa classe defina cinco 
	construtores e um destructor. Defina também o código dos "setters" e 
	"getters" da classe. Neste exercício acrescente os métodos de leitura e 
	métodos de escrita de dados. O programa deve ler os dados de um produto 
	e apresenta10s no monitor utilizando os métodos de leitura e de escrita criados.
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
	private:
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
	}
	
	// 2.2 Função Destrutora
	// Função chamada antes da eliminação do objeto. Tem o mesmo nome da classe
	~Produto()
	{
		cout<<" Eliminaçao de um objeto 'Produto': ";
		cout<<designacao<<".";
		cout<<endl;
	}


	//2.3 Funcoes setters
	// Funcoes de atribuicao de valores a cada um dos dados do objeto
	//Pode-se inserir codigo de validacao
 	
	void setCodProduto	(int codP)
		{ codProduto = codP; }
	void setDesignacao (string d)
		{ designacao = d; }
	void setDesignacao (char * d)
		{ designacao.assign(d); }
	void setQuantidadeUnidade (float qU)
		{ quantidadeUnidade = qU; }
	void setUnidade	(string u)
		{ unidade = u; }
	void setUnidade (char * u) 
		{ unidade = u; }
	void setNumUnidades	(int nU) 
		{ numUnidades = nU; }
	void setPreco (float p)
		{ preco = p; }
	void setTaxaIVA	(float tIVA)
		{ taxaIVA = tIVA; } 
	void setDataValidade (string dV)
		{ dataValidade = dV; }
	void setDataValidade (char * dV)
		{ dataValidade = dV; }
	void setSecao (string s)
		{ secao = s ; }
	void setSecao (char * s)
		{ secao = s; }
	void setPrecisaFrio	(bool pF)
		{ precisaFrio = pF; }

 	// 2.4 Funções "Getters"
	// Funções de obtenção de valores de cada um dos dados do objeto .
	// Pode-se inserir código de verificação de acesso
	
	int getCodProduto()
		{ return codProduto; }
	string getDesignacao ()
		{ return designacao; }
	float getQuantidadeUnidade ()
		{ return quantidadeUnidade; }
	string getUnidade	()
		{ return unidade; }
	int getNumUnidades	() 
		{ return numUnidades; }
	float getPreco ()
		{ return preco; }
	float getTaxaIVA ()
		{ return taxaIVA; } 
	string getDataValidade ()
		{ return dataValidade; }
	string getSecao ()
		{ return secao; }
	bool getPrecisaFrio	()
		{ return precisaFrio; }


	
// Fungção principal
 
int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	// 1 . 1 Dados
	// Declaração do objeto .
	
	Produto produto;
	int codProduto = 0; string designacao = "";
	float quantidadeUnidade = 0; string unidade = ""; 
	int numUnidades = 0; float preco = 0; float taxaIVA = 0;
	string dataValidade = ""; string secao = ""; bool precisaFrio = false;
	
	// 1.2 Entrada de dados
	cout<<"Qual é o código do produto? "; cin>>codProduto;
	produto.setCodProduto(codProduto);
	cin.ignore();  
	
	cout<<"Qual é a designação do produto? ";
	getline(cin, designacao); produto.setDesignacao(designacao);
	
	cout<<"Qual é a unidade de medida? ";
	getline (cin, unidade); produto.setUnidade(unidade);
	
	cout<<"Qual é a quantidade por unidade? ";
	cin>>quantidadeUnidade; produto.setQuantidadeUnidade(quantidadeUnidade);
	
	cout<<"Qual é o número de unidades em inventário? ";
	cin>>numUnidades; produto.setNumUnidades(numUnidades);
	
	cout<<"Qual é o preço de cada unidade? ";
	cin>>preco; produto.setPreco(preco);
	
	cout<<"Qual é a taxa de IVA? "; 
	cin>>taxaIVA; produto.setTaxaIVA(taxaIVA);
	cin.ignore();	
	
	cout<<"Qual é a data de validade (DD/MM/AAAA)? ";
	getline (cin, dataValidade); produto.setDataValidade(dataValidade);
	
	cout<<"Qual é a seção do produto? ";
	getline (cin,secao); produto.setSecao(secao);
	
	string resposta = "";
	cout<<"O produto precisa de frio (sim/nao)? ";
	cin>>resposta;
	if (resposta == "sim") 
		precisaFrio = true;
	else
		precisaFrio = false;
		
	// 1.3 Apresentação de dados
	cout<<"Dados inseridos para o Produto: "<<endl;
	cout<<"Código:	"<<produto.getCodProduto ()<<"."<<endl;
	cout<<"Designação: "<<produto.getDesignacao ()<<"."<<endl;
	cout<<"Inventario: "<<produto.getNumUnidades ()<<" unidades."<<endl;
	cout<<"Cada unidade tem "
	<<produto.getQuantidadeUnidade() <<" "<<produto.getUnidade()<<"."<<endl;
	cout<<"Custa "<<produto.getPreco ()<<" euros com um IVA de "
		<<produto.getTaxaIVA ()<<"%."<<endl;
	cout<<"Data de validade: "<<produto.getDataValidade ()<<"."<<endl;
	cout<<"O produto está na secção de "<<produto.getSecao()<<"."<<endl;
	cout<<"Precisa de frio? ";
		if(produto.getPrecisaFrio() == false) 
			cout<<"não."<<endl;
		else
			cout<<"sim."<<endl;
system("pause");
return 0;
}












