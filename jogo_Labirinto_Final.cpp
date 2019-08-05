#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include "colors.h"

/*
* Um jogo é basicamente um laço infinito, ate onde aquela condição seja estabelecida
por isso temos que definir a condição de vitória e derrota. O laço sera repetido até que
umas das condições sejam realizadas, ou você ganhou, ou você perdeu;

* No caso do labirinto, vai ser ate onde a pessoa vai querer ir, por isso tem que determinar 
uma chave para saida;;

* Também seria bom definir as dificuldades, qual ele ira escolher, em um menu inicial

* Seria bom definir parede, chao, obstaculos, com define para ficar melhor a manipulação
e player tbm

*/


/*
DEFINIÇÕES DO MAPA DO JOGO
*/
#define PAREDE 7

#define SAIDA 4
#define PLAYER 5

#define CHAO 0
#define OBSTACULO 1
#define VAZIO 2
#define GRAMA 3

#define TAM_LINHAS 20
#define TAM_COLUNAS 15

/*
DEFINIÇÕES DE JOGABILIDADE
*/

#define CIMA 119
#define BAIXO 115
#define DIREITA 100
#define ESQUERDA 97
#define SAIR 113

int linha = 1, coluna = 1;


//int dificuldade, sair=0;


int mapa[TAM_LINHAS][TAM_COLUNAS] = {};

void gerando_mapa( ){
		
		int contObstaculos = 0;
		int contVazio =0;
		
		for(int i =0; i<TAM_LINHAS; i++){
				
				for(int j =0; j<TAM_COLUNAS; j++){
					
					if((i == 0 || i == TAM_LINHAS-1) || (j ==0 || j == TAM_COLUNAS-1)){
						
						mapa[i][j] = PAREDE;
					
					}
					 else{
						
						mapa[i][j] = CHAO;
					
					}
						if(mapa[i][j] == CHAO){
						
							mapa[i][j] = rand()%4;
						}
						
							if(mapa[i][j] == SAIDA)
								mapa[i][j] == CHAO;
								
						if(mapa[i][j] == OBSTACULO)
							contObstaculos ++;
							
						if(mapa[i][j] == VAZIO)
							contVazio ++;
							
						if(contObstaculos > 4){
							if(mapa[i][j] == OBSTACULO)
								mapa[i][j] = CHAO;
						}
						
						if(contVazio > 3){
							if(mapa[i][j] == VAZIO)
								mapa[i][j] = CHAO;
						}
				}
				
				contObstaculos =0;
				contVazio =0;
			}
			
	mapa[1][1+1] = CHAO;
	mapa[1+1][1] = CHAO;
	mapa[1+1][1+1] = CHAO;
	
	mapa[TAM_LINHAS-2][TAM_COLUNAS-2] = SAIDA;
	
}

void desenhando_mapa( ){
	
	for(int i =0; i<TAM_LINHAS; i++){
		
		for(int j =0; j<TAM_COLUNAS; j++){
			
			if((i == linha) && (j == coluna)){
				printf(CIANO"&"CINZA);
				continue;
			}
				
			if(mapa[i][j] ==  PAREDE)
				printf("%c", 219);
			
			if(mapa[i][j] == CHAO)
				printf("%c", 176);
			
			if(mapa[i][j] == VAZIO)
				printf(" ");
			
			if(mapa[i][j] == OBSTACULO)
				printf("%c", 220);
				
			if(mapa[i][j] == SAIDA)
				printf(AMARELO"O"CINZA);
				
			if(mapa[i][j] == GRAMA)
				printf(VERDE"%c"CINZA, 178);
		}
		
	
		putchar('\n');
	}

}

void sumario(){
	
	printf("SUMARIO:\n");
	printf("JOGADOR--->"CIANO"&\n"CINZA);
	printf("CHAO---> %c\n", 176);
	printf("VAZIO--->   \n");
	printf("OBSTACULO---> %c\n", 220);
	printf("GRAMA---> "VERDE"%c\n"CINZA,178);
	printf("SAIDA---> "AMARELO"O\n"CINZA);
}

int main(){
	
	srand(time(NULL));
	
	int nivel = 1;
	
	int tecla, pontos=0;
	
	int contTentativas = 0;
		
	int opcao;
	
	printf("\n\tJOGO DO LABIRINTO V.1.0\n");
	printf("\t\t[1] - Inicio\n\t\t[2] - Creditos\n\t\t[3] - Sair\n");
	scanf("%d", &opcao);
	
	switch(opcao){
		
		case 1:
				do{
					int flag =0;
					
					system("cls");
					
					gerando_mapa();
					
					sumario();
						desenhando_mapa();
							printf("Pontos: %d\nFase: %d", pontos, nivel);
					
					do{
						
						tecla = getch();
						
						if(tecla == CIMA){
							
							linha --;
							
							pontos ++;
							
								if(mapa[linha][coluna] == PAREDE){
									
									linha ++;
									
									pontos --;
								}
								
								if(mapa[linha][coluna] == VAZIO){
									system("cls");
									
									flag =1;
									
									break;
									
								}
								
								if(mapa[linha][coluna] == OBSTACULO){
									
									linha ++;
									
									pontos --;
									
									contTentativas++;
									
									if(contTentativas > 2){
										
										linha --;
										
										pontos ++;
										
										contTentativas =0;							
									}
								}
							
							system("cls");
							
							sumario();
								desenhando_mapa();
									printf("Pontos: %d\nFase: %d", pontos, nivel);
						}
						
						if(tecla == BAIXO){
							
							linha ++;
							
							pontos ++;
							
								if(mapa[linha][coluna] == PAREDE){
									
									linha --;
									
									pontos --;
								}
								
								if(mapa[linha][coluna] == VAZIO){
									system("cls");
									
									flag =1;
									
									break;
									
								}
								
								if(mapa[linha][coluna] == OBSTACULO){
									
									linha --;
									
									pontos --;
									
									contTentativas++;
									
									if(contTentativas > 2){
										
										linha ++;
										
										pontos ++;
										
										contTentativas =0;							
									}
								}
								
							system("cls");
							
							sumario();
								desenhando_mapa();
									printf("Pontos: %d\nFase: %d", pontos, nivel);
						}
						
						if(tecla == ESQUERDA){
							
							coluna --;
							
							pontos ++;
							
								if(mapa[linha][coluna] == PAREDE){
									
									coluna ++;
									
									pontos --;
								}
								
								if(mapa[linha][coluna] == VAZIO){
									system("cls");
									
									flag =1;
									
									break;
									
								}
								
								if(mapa[linha][coluna] == OBSTACULO){
									
									coluna ++;
									
									pontos --;
									
									contTentativas++;
									
									if(contTentativas > 2){
										
										coluna --;
										
										pontos ++;
										
										contTentativas =0;							
									}
								}
							
							system("cls");
							
							sumario();
								desenhando_mapa();
									printf("Pontos: %d\nFase: %d", pontos, nivel);
						}
						
						if(tecla == DIREITA){
							
							coluna ++;
							
							pontos ++;
							
							
								if(mapa[linha][coluna] == PAREDE){
								
									coluna --;
								
									pontos --;
								}
								
							
								if(mapa[linha][coluna] == VAZIO){
									system("cls");
									
									flag =1;
									
									break;
									
								}
							
								if(mapa[linha][coluna] == OBSTACULO){
									
									coluna --;
									
									pontos --;
									
									contTentativas++;
									
									if(contTentativas > 2){
										
										coluna ++;
										
										pontos ++;
										
										contTentativas =0;							
									}
								}
								
							system("cls");
							
							sumario();
								desenhando_mapa();
									printf("Pontos: %d\nFase: %d", pontos, nivel);
						}
						
						if(tecla == SAIR){
						
							system("cls");
							
							printf("Fase incompleta.");
							
							system("pause");
							
							exit(0);
						}
						
					}while(mapa[linha][coluna] != SAIDA);
					
					linha = rand()%6+1;
					coluna = rand()%4+1;
					
					nivel ++;
					
					system("cls");
					
					if(flag != 1){
						printf("FASE COMPLETA\nTOTAL DE PONTOS ATE AQUI: %d\n", pontos);
					}
					if(flag == 1){
						printf("\nGame over, voce cometeu suicidio :'(\nTente novamente! :D\n");
						pontos =0;
						nivel --;
					}
			
					printf("Para continuar, %c Enter, Para sair Q", 217);
					
					tecla = getch();
					
					system("cls");
						
				}while(tecla != SAIR);
				
				break;
				
		case 2:
			
			system("cls");
			printf("\n\t\t\tJOGO DO LABIRINTO V.1.0\n");
			printf("\t\tDesenvolvido por Luan de Souza Nascimento\n\t\tAuxiliado pela professora Laura Emmanuella.");
		
			break;
			
		case 3:
			exit(0);
		}
	exit(0);
}
