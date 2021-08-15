//*
//*		1) Utilizando o exercicio apresentado, crie um programa que permita a
//*		opera��o com uma fila num vetor est�tico
//*		com as seguintes op��es de menu:
//*		
//*		   - Listar fila
//*		   - Inserir elemento
//*		   - Obter primeiro elemento
//*		   - Remover elemento
//*		   - Sair do programa.
//*
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include "Exercicio1_funcoes.cpp"

//*********************************************
//* Fun��o principal
//*********************************************
//*********************************************
//* Fun��o principal
//*********************************************
int main() 
	{
	
	setlocale(LC_ALL, "Portuguese");

    // 1. Defini��o das constantes 
    //    Declara��o e inicializa��o das vari�veis
    const int NUMMAXVALORES = 8;       
    int fila[NUMMAXVALORES];     
    int topo = -1;            // Topo da fila  
    const int LIVRE = 0, OCUPADO = 1;
    char escolha = '\0';
    bool queroSair = false;   
     
    for(int contaLugar=0; contaLugar < NUMMAXVALORES; contaLugar++) 
        fila[contaLugar] = LIVRE;
        
  do {
    // 2. Apresenta��o do menu   
    system("cls");
    system("color A");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*              Fila                     *\n");
    printf("*                                       *\n");
    printf("*      1. Listar fila.                  *\n");
    printf("*      2. Inserir fila.                 *\n");
    printf("*      3. Obter primeiro elemento.      *\n");
    printf("*      4. Remover elemento.             *\n");    
    printf("*      5. Sair do programa.             *\n");
    printf("*                                       *\n");  
    printf("*****************************************\n");      
    
    // 3. ENTRADA: Obter a escolha do utilizador
    fflush(stdin); 
    printf("\nQual a sua escolha (1-5)? "); 
	scanf("%c", &escolha);
	printf("\n");
    
    // 4. Procesamento 
    // 5. Apresenta��o de saida
    switch (escolha) {
       case '1':   // Listar elementos da fila.
        printf("Lista de Elementos: \n"); 
		show; printf("\n"); 
        system("pause");  
        break;
       case '2':  // Inserir elemento da fila.
        {
        if (!isFull(fila)) 
		    {	
            int dado=0;
            printf("Qual o dado a inserir? ");
            scanf("%d", &dado);
            topo = push(fila,dado,topo,NUMMAXVALORES);
            printf("Dado inserido com sucesso!\n");
            }
            else 
            {
            printf("N�o pode inserir dados: fila est� cheia.\n");
            printf("Stack overflow!!\n");
            }   
        system("pause");
        break;
        }
       case '3':  //  primeiro elemento.
         {
         if (!isEmpty(topo)) 
		    {	
            printf("Primeiro elemento da fila: %d.\n",
		        peek(fila,topo));
		    }
		 else 
            {
            printf("N�o encontrou dados: fila est� vazia.\n");
            printf("Empty stack!!\n");
            }
         system("pause");
         break;
         }          
       case '4':  // Remover elemento da fila.
         {
         if (!isEmpty(topo)) 
		    {	
            int dado=0;
            printf("Dado a remover: %d.\n",peek(fila,topo));
            topo = pop(fila,topo);
            printf("Dado removido com sucesso!\n");
            }
		 else 
            {
            printf("N�o encontrou dados: fila est� vazia.\n");
            printf("Empty stack!!\n");
            }
         system("pause");
         break;
         } 
       case '5': // Sair do programa   
          {
          char resposta = '\0';
          fflush(stdin);  // "stdin" - "STanDard INput"
          printf("Tem a certeza (S/N)? ");
          scanf("%c", &resposta);
          if (resposta == 's' || resposta == 'S')
              queroSair = true;
          break;
          }
       default:
          printf("Escolha inv�lida! Tente de novo!\n");
          system("pause");
    } // Fim do "switch" 
  } while (! queroSair);  //"!" - N�o 

printf("\nObrigado por ter usado o nosso programa.\n");
system("pause");
return 0;
} // Fim da fun��o "main()".

