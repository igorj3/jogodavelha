// Jogo da Velha.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

int op;

void cabecalho() {
	printf("\t\t\t\t\t==============================================\n");
	printf("\t\t\t\t\t================ JOGO DA VELHA ===============\n");
	printf("\t\t\t\t\t==============================================\n\n\n");
	
}

void menu() {
	printf("|======================|\n");
	printf("|========= MENU =======|\n");
	printf("|======================|\n");
	printf("| 1- regra do jogo     |\n");
	printf("| 2- comeca o jogo     |\n");
	printf("| 3- sair              |\n");
	printf("|______________________|\n");
	printf("|Escolha um opcao:  ");
	scanf("%d",&op);
	printf("\n");


}
 void regra() {
 	printf("\t\t\t|=======================|\n");
	printf("\t\t\t|==== regra do jogo ====|\n");
	printf("\t\t\t|=======================|\n");
 }
 void sair(){
 printf("\t\t\t\t============================\n");
 printf("\t\t\t\t======== SAIR DO JOGO =====\n"); 
 printf("\t\t\t\t============================\n");
 }
	
  void imprime_tabuleiro(char tabuleiro[3][3]) { 
  printf("1- x\n");
  printf("2- o\n");
  
  	printf("\t          (COLUNA)           \n");
  	printf("\t      1        2       3      \n\n");
   	printf("\t           |       |         \n");
    printf("\t# 1    %c   |   %c   |   %c    \n", tabuleiro[0][0],tabuleiro[0][1],tabuleiro[0][2]);
    printf("\tL   _______|_______|_______  \n");
   	printf("\tI          |       |          \n");
	printf("\tN 2    %c   |   %c   |   %c      \n", tabuleiro[1][0],tabuleiro[1][1],tabuleiro[1][2]);
    printf("\tH   _______|_______|_______  \n");
    printf("\tA          |       |          \n");
	printf("\t# 3    %c   |   %c   |   %c     \n", tabuleiro[2][0],tabuleiro[2][1],tabuleiro[2][2]);
	printf("\t           |       |          \n");
    printf("\n\n");
}
  
void jogo() {
setlocale(LC_ALL, "portuguese");
char tabuleiro[3][3],jogador;
int i,j,linha,coluna,rodada,ganhou;
	
   for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tabuleiro[i][j] = ' ';
    }
  }

cabecalho();
imprime_tabuleiro(tabuleiro);
ganhou = 0;

  
  for (rodada = 1; rodada <= 9 && ganhou == 0; rodada++) {

    
    
    if (rodada % 2 == 1) {
      jogador = 'X';
    }
    else {
      jogador = 'O';
    }
    
	
    
    do {

        printf("\nDigite as coordenadas de 1 a 3 a linha e coluna \n",jogador);
		printf("\nDigite a linha: ",jogador);
		 scanf("%d", &linha);
		printf("\nDigite a coluna: ",jogador);
        scanf("%d", &coluna);
        
		    if(linha = linha){
			  printf("\nrepetil linha e coluna");
			  

		}
        
} while(linha < 1 || linha > 3 || coluna < 1 || coluna > 3 ||  tabuleiro[linha-1][coluna-1] != ' ');
    	
   			 
    
    system("cls");
    tabuleiro[linha-1][coluna-1] = jogador;
    
   	cabecalho();
    imprime_tabuleiro(tabuleiro);
	
  
    
    if (tabuleiro[linha-1][0] == tabuleiro[linha-1][1] && tabuleiro[linha-1][1] == tabuleiro[linha-1][2]) {
      ganhou = 1;
    }
   

     

      if (tabuleiro[0][coluna-1] == tabuleiro[1][coluna-1] && tabuleiro[1][coluna-1] == tabuleiro[2][coluna-1]) {
	ganhou = 1;
      }

      

	
	if (linha == coluna && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro [1][1] == tabuleiro[2][2]) {
	  ganhou = 1;
	}
	
	
	  if (linha + coluna == 4 && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
	    ganhou = 1;
	  }
	
  }

  
  if (ganhou == 0) {
  	system("color 04");
     printf("\nDeu velha!\n");

  }
 
  else {
    
	printf("\nO jogador '%c' ganhou!\n", jogador);
    printf("       _      \n");
		printf("      '.=====.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         .' '.        \n");
		printf("        '-------'       \n\n");
		 
		
}
  
}
  
  


int main(){
setlocale(LC_ALL, "portuques");
system("color 02");
bool rep=true;
	  
	  
	do{	

		cabecalho();
	   
		menu();
	    system("pause");
		system("cls");

		switch(op) {
				case 1: 
	//					
					regra();
				    printf("\n");
					printf("__________________________________________________________________________________________________\n" );
					printf("|1-Dois jogadores escolhem uma marcacao cada um, geralmente um circulo (O) e um xis (X).          |\n");
					printf("|2-Os jogadores jogam alternadamente, uma marcação por vez, numa lacuna que esteja vazia          |\n");
					printf("|3-Se os dois jogadores jogarem sempre da melhor forma, o jogo terminara sempre em empate.        |\n");
					printf("|4-O objectivo e conseguir tres circulos ou tres is em linha, quer horizontal, vertical ou diagona|\n");
					printf("__________________________________________________________________________________________________|");
					printf("\n");
					system("pause");
					system("cls");
					break;
					
				case 2:
					jogo();
					system("pause");
					system("cls");
					break;
				case 3:
					sair();
					printf("\n");
					printf("  sair do jogo\n");
					rep = false;
					break;
		}
	} while(rep == true);
	
	return 0;
}
