#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>

int MudaDirecao(int dist[],int mudancaDirecao);

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int trocouDirecao,distancia[100],i,totalPercorrido=0,TeclaPressionada;
	do{
		printf("***Valores entre 0 e 100***\n\n");
		do{
			printf("Quantas vezes Jo�ozinho trocou de posi��o? ");
			scanf("%i",&trocouDirecao);
			system("cls");
		}while((trocouDirecao<0)||(trocouDirecao>100));
		if(trocouDirecao>0){
			//trocouDirecao-=1;
			for(i=0;i<=trocouDirecao;i++){
				distancia[i]=MudaDirecao(distancia,i);
				totalPercorrido+=distancia[i];
			}
			system("cls");
			if(totalPercorrido>=0)
				printf("Foi percorrido um total de %i metros para a Direita.",totalPercorrido);
			else
				printf("Foi percorrido um total de %i metros para a Esquerda.",-totalPercorrido);
			printf("\n\n\nSe deseja executar o programa novamente aperte 'Enter'\nCaso contr�rio pressione qualquer tecla.");
			TeclaPressionada=getch();
			system("cls");
		}else
			printf("Programa encerrado.");
		
	}while(TeclaPressionada==13);
	return 0;
	
}

int MudaDirecao(int dist[],int mudancaDirecao){
	if(mudancaDirecao%2==0){
		printf("%i� dist�ncia pecorrida (Direita): ",mudancaDirecao+1);
		scanf("%i",&dist[mudancaDirecao]);
	}else{
		printf("%i� dist�ncia pecorrida (Esquerda): ",mudancaDirecao+1);
		scanf("%i",&dist[mudancaDirecao]);
		dist[mudancaDirecao]*=-1;
	}
	return dist[mudancaDirecao];
}
