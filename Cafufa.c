#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int ate,num1,num2,i,ultimoDigito;
	do{
		printf("At� qual n�mero? ");
		scanf("%i",&ate);
	}while((ate<0)||(ate>1000));
	do{
		printf("Primeiro valor: ");
		scanf("%i",&num1);
	}while((num1<1)||(num1>9));
	do{
		printf("Segundo Valor: ");
		scanf("%i",&num2);
	}while((num2<1)||(num2>9)||(num1==num2));
	system("cls");
	for(i=1;i<=ate;i++){
		if(i%num1==0)
			printf(" Cafufa ");
		else{
			if(i%num2==0)
				printf(" Cafufa ");
			else{
				ultimoDigito=i/10,ultimoDigito=i*10,ultimoDigito=i-ultimoDigito;
				if((ultimoDigito==num1)||(ultimoDigito==num2))
					printf(" Cafufa ");
				else
					printf(" %i ",i);
			}
		}
		if(i!=ate)
			printf(",");
		else
			printf(".\n");
	}
	system("Pause");
	return 0;
}
