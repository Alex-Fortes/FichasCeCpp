//*
//*			2) Utilizando o exercicio apresentado, crie um programa que permita a
//*		opera��o com uma pilha numa lista ligada.
//*		com as seguintes op��es de menu:
//*
//*	   - Listar pilha
//*	   - Inserir elemento
//*	   - Obter �ltimo elemento
//*	   - Remover elemento
//*	   - Sair do programa.
//*
//*
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include "Exercicio2_funcoes.cpp"

//*********************************************
//* Fun��o principal
//*********************************************
int main() 
	{
	setlocale(LC_ALL, "Portuguese");

    // 1. Defini��o das constantes 
    //    Declara��o e inicializa��o das vari�veis
	
	// Ponteiro para a base da pilha
    struct Elemento *base = NULL;
 

    char escolha = '\0';
    bool queroSair = false;   // Declara��o de uma vari�vel booleana
     

        
  do {
    // 2. Apresenta��o do menu   
    system("cls");
    system("color A");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*             Stack - Pilha             *\n");
    printf("*                                       *\n");
    printf("*      1. Listar pilha.                 *\n");
    printf("*      2. Inserir pilha.                *\n");
    printf("*      3. Obter �ltimo elemento.        *\n");
    printf("*      4. Remover elemento.             *\n");    
    printf("*      5. Sair do programa.             *\n");
    printf("*                                       *\n");  
    printf("*****************************************\n");      
    if (isEmpty(base))
    {
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*          Pilha VAZIA!!!               *\n");
    printf("*                                       *\n");  
    printf("*****************************************\n"); 
	printf("\n"); 	
    }    

    // 3. ENTRADA: Obter a escolha do utilizador
    fflush(stdin); 
    printf("\nQual a sua escolha (1-5)? "); 
	scanf("%c", &escolha);
	printf("\n");
    
    // 4. Procesamento 
    // 5. Apresenta��o de saida
    switch (escolha) {
       case '1':   // Listar elementos da pilha.
        printf("Lista de Elementos na Vertical: \n"); 
		showV(base); printf("\n"); 
        system("pause");  
        break;
       case '2':  // Inserir elemento da pilha.
         {
         int dado=0;
         printf("Qual o dado a inserir? ");
         scanf("%d", &dado);
         base = push(base,dado);
         printf("Dado inserido com sucesso!\n");
         system("pause");
         break;
         }
       case '3':  // �ltimo elemento da pilha.
         {
         if (!isEmpty(base)) 
		    {	
            printf("�ltimo elemento da pilha: %d.\n\n",
		        peek(base));
		    }
		 else 
            {
            printf("N�o encontrou dados: pilha est� vazia.\n");
            printf("Empty stack!!\n");
            }
         system("pause");
         break;
         }          
       case '4':  // Remover elemento da pilha.
         {
         if (!isEmpty(base)) 
		    {	
            int dado=0;
            printf("Dado a remover: %d.\n",peek(base));
            pop(&base);
            printf("Dado removido com sucesso!\n");
         	}
		 else 
            {
            printf("N�o encontrou dados: pilha est� vazia.\n");
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

