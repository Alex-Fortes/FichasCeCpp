//*
//*		2) Utilizando o exercicio apresentado, crie um programa que permita a
//*		operação com uma fila numa lista ligada.
//*		com as seguintes opções de menu:
//*		
//*		   - Listar fila
//*		   - Inserir elemento
//*		   - Obter primeiro elemento
//*		   - Remover elemento
//*		   - Sair do programa.
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include "Exercicio2_funcoes.cpp"
//*********************************************
//* Função principal
//*********************************************
int main() 
	{
	setlocale(LC_ALL, "Portuguese");

    // 1. Definição das constantes 
    //    Declaração e inicialização das variáveis
	
	// Ponteiro para a base da fila
    struct Elemento *base = NULL;

    char escolha = '\0';
    bool queroSair = false;   // Declaração de uma variável booleana
    
        
  do {
    // 2. Apresentação do menu   
    system("cls");
    system("color A");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*            Fila                       *\n");
    printf("*                                       *\n");
    printf("*      1. Listar fila.                  *\n");
    printf("*      2. Inserir fila.                 *\n");
    printf("*      3. Obter primeiro elemento.      *\n");
    printf("*      4. Remover elemento.             *\n");    
    printf("*      5. Sair do programa.             *\n");
    printf("*                                       *\n");  
    printf("*****************************************\n");      
    if (isEmpty(base))
    {
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*          Fila VAZIA!!!               *\n");
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
    // 5. Apresentação de saida
    switch (escolha) {
       case '1':   // Listar elementos da fila.
        printf("Lista de Elementos. \n"); 
		show; printf("\n"); 
        system("pause");  
        break;
       case '2':  // Inserir elemento da fila.
         {
         int dado=0;
         printf("Qual o dado a inserir? ");
         scanf("%d", &dado);
         insert(dado);
         printf("Dado inserido com sucesso!\n");
         system("pause");
         break;
         }
       case '3':  // Primeiro elemento da fila.
         {
         if (!isEmpty(base)) 
		    {	
            printf("Primeiro elemento da fila: %d.\n\n",
		        peek(base));
		    }
		 else 
            {
            printf("Não encontrou dados: a fila está vazia.\n");
            printf("Empty stack!!\n");
            }
         system("pause");
         break;
         }          
       case '4':  // Remover elemento da fila.
         {
         if (!isEmpty(base)) 
		    {	
            int dado=0;
            printf("Dado a remover: %d.\n",peek(base));
            remove(base&);
            printf("Dado removido com sucesso!\n");
         	}
		 else 
            {
            printf("Não encontrou dados: fila está vazia.\n");
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
          printf("Escolha inválida! Tente de novo!\n");
          system("pause");
    } // Fim do "switch" 
  } while (! queroSair);  //"!" - Não 

printf("\nObrigado por ter usado o nosso programa.\n");
system("pause");
return 0;

} // Fim da função "main()".

