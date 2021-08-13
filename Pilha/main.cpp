//*
//*		1) Utilizando o exercicio apresentado, crie um programa que permita a
//*		operação com uma pilha num vetor estático
//*		com as seguintes opções de menu:
//*		
//*		   - Listar pilha
//*		   - Inserir elemento
//*		   - Obter último elemento
//*		   - Remover elemento
//*		   - Sair do programa.
//*
//*
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include "funcoes.cpp"

//*********************************************************************
//* Variáveis globais
//*********************************************************************




//*********************************************
//* Função principal
//*********************************************
int main() 
	{
	
	setlocale(LC_ALL, "Portuguese");

    // 1. Definição das constantes 
    //    Declaração e inicialização das variáveis
    const int NUMMAXVALORES = 8;       
    int pilha[NUMMAXVALORES];     
    int topo = -1;            // Topo da pilha  
    const int LIVRE = 0, OCUPADO = 1;
    char escolha = '\0';
    bool queroSair = false;   
     
    for(int contaLugar=0; contaLugar < NUMMAXVALORES; contaLugar++) 
        pilha[contaLugar] = LIVRE;
        
  do {
    // 2. Apresentação do menu   
    system("cls");
    system("color A");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*             Stack - Pilha             *\n");
    printf("*                                       *\n");
    printf("*      1. Listar pilha.                 *\n");
    printf("*      2. Inserir pilha.                *\n");
    printf("*      3. Obter último elemento.        *\n");
    printf("*      4. Remover elemento.             *\n");    
    printf("*      5. Sair do programa.             *\n");
    printf("*                                       *\n");  
    printf("*****************************************\n");      
    if (isFull(topo,NUMMAXVALORES))
    {
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*          Pilha CHEIA!!!               *\n");
    printf("*                                       *\n");  
    printf("*****************************************\n"); 
	printf("\n");   	
    }
    if (isEmpty(topo))
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
    // 5. Apresentação de saida
    switch (escolha) {
       case '1':   // Listar elementos da pilha.
        printf("Lista de Elementos na Vertical: \n"); 
		showV(pilha,topo); printf("\n"); 
        system("pause");  
        break;
       case '2':  // Inserir elemento da pilha.
        {
        if (!isFull(topo,NUMMAXVALORES)) 
		    {	
            int dado=0;
            printf("Qual o dado a inserir? ");
            scanf("%d", &dado);
            topo = push(pilha,dado,topo,NUMMAXVALORES);
            printf("Dado inserido com sucesso!\n");
            }
            else 
            {
            printf("Não pode inserir dados: pilha está cheia.\n");
            printf("Stack overflow!!\n");
            }   
        system("pause");
        break;
        }
       case '3':  // Último elemento da pilha.
         {
         if (!isEmpty(topo)) 
		    {	
            printf("Último elemento da pilha: %d.\n",
		        peek(pilha,topo));
		    }
		 else 
            {
            printf("Não encontrou dados: pilha está vazia.\n");
            printf("Empty stack!!\n");
            }
         system("pause");
         break;
         }          
       case '4':  // Remover elemento da pilha.
         {
         if (!isEmpty(topo)) 
		    {	
            int dado=0;
            printf("Dado a remover: %d.\n",peek(pilha,topo));
            topo = pop(pilha,topo);
            printf("Dado removido com sucesso!\n");
            }
		 else 
            {
            printf("Não encontrou dados: pilha está vazia.\n");
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


