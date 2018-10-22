#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int zeroEsquerda(int vetor[]);
int verifPrimo(int num);
void ConcPrimo (int vetor[],int tamanho);

int main(){
	setlocale(LC_ALL,"Portuguese");
	int i,j=1,numeros[5]={0},novamente=0,condicaoEsquerda,tamanhoNumero,primo,vezes;
	char nome[5];
	printf("Quantos n�meros voc�s deseja checar a concatena��o de primos? ");
	scanf("%i",&vezes);
	while(j<=vezes){
		do{
			system("cls");
			printf("***N�o � aceit�vel n�meros com mais de 5 d�gitos, caracteres que sejam valores fora do intervalo de 1 a 9 e zeros a esquerda!***\n\n");
			novamente=0,tamanhoNumero=0;
			printf("\n%i� n�mero: ",j);
			gets(nome);
			printf("Resultado: ");
			for(i=0;nome[i]!='\0';i++){
				numeros[i]=nome[i]-'0'; //transforma string em inteiro
				if((numeros[i]<0)||(numeros[i]>9))
					novamente+=1;
			}
			tamanhoNumero=i-1;
			condicaoEsquerda=zeroEsquerda(numeros);
			novamente+=condicaoEsquerda;
			if(tamanhoNumero>4){
				printf(" N�mero com mais de 5 d�gitos. Digite novamente.");	
				system("Pause");							
			}
		}while((novamente>0)||(tamanhoNumero>4));
		ConcPrimo(numeros,tamanhoNumero);	
		printf("\n-----------------------\n");
		system("Pause");
		j++;
	}
	return 0;

}

int zeroEsquerda(int vetor[]){ //verifica se o n�mero possui zero a esquerda
	int i;
	
		if (vetor[0]==0)
			return 1;
		else
			return 0;	
}

void ConcPrimo (int vetor[],int tamanho){
	int i,primos=0,soma=0,j,soma2=0;
	for(i=0;i<=tamanho;i++){
		if(verifPrimo(vetor[i])==1)
			primos+=1;
	} //Quando todos os d�gitos s�o primos
	if((primos==tamanho+1)&&(tamanho!=0)){ //"Tamanho+1" pois o tamanho no caso utilizado come�a do 0
		printf("Sim:");
		for(i=0;i<=tamanho;i++)
			printf(" '%i' ",vetor[i]);
	}else{
		switch(tamanho){
			case 0: //se o n�mero digitado tiver apenas um d�gito
				printf("N�o.\n");
				break;
			case 1: //se o n�mero digitado tiver dois d�gitos
				printf("N�o");
				break;
			case 2: //se o n�mero digitado tiver tr�s d�gitos
				
				if(vetor[1]==0)
					printf("N�o.");
				else{
					soma=((vetor[0]*10)+(vetor[1]*1));
					if((verifPrimo(soma)==1)&&(verifPrimo(vetor[2])==1))
						printf("Sim: '%i' '%i'",soma,vetor[2]);
					else{
						soma=((vetor[1]*10)+(vetor[2]*1));
						if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1))
							printf("Sim: '%i' '%i'",vetor[0],soma);
						else{
							printf("N�o.\n");
						}
					}
				}
				break;
			case 3: //se o n�mero digitado tiver quatro d�gitos
				if((vetor[1]==0)&&(vetor[2]==0))
					printf("N�o.");
				else{
					if(vetor[1]==0){
						soma=(vetor[0]*100)+(vetor[1]*10)+(vetor[2]*1);
						if((verifPrimo(soma)==1)&&(verifPrimo(vetor[3])==1))
							printf("Sim: '%i' '%i'",soma,vetor[3]);
						else
							printf("N�o.");
					}else{
						if(vetor[2]==0){
							soma=(vetor[1]*100)+(vetor[2]*10)+(vetor[3]*1);
							if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1))
								printf("Sim: '%i' '%i'",vetor[0],soma);
							else
								printf("N�o.");
						}else{
							soma=((vetor[0]*10)+(vetor[1]*1));
							if((verifPrimo(soma)==1)&&(verifPrimo(vetor[2])==1)&&(verifPrimo(vetor[3])==1))
								printf("Sim: '%i' '%i' '%i'",soma,vetor[2],vetor[3]);
							else{
								soma=((vetor[1]*10)+(vetor[2]*1));
								if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1)&&(verifPrimo(vetor[3])==1))
									printf("Sim: '%i' '%i' '%i'",vetor[0],soma,vetor[3]);
								else{
									soma=((vetor[2]*10)+(vetor[3]*1));
									if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1)&&(verifPrimo(vetor[1])==1))
										printf("Sim: '%i' '%i' '%i'",vetor[0],vetor[1],soma);
									else{
										soma=((vetor[0]*10)+(vetor[1]*1));
										soma2=((vetor[2]*10)+(vetor[3]*1));
										if((verifPrimo(soma)==1)&&(verifPrimo(soma2)==1))
											printf("Sim: '%i' '%i' ",soma,soma2);
										else{
											soma=((vetor[0]*100)+(vetor[1]*10)+(vetor[2]*1));
											if((verifPrimo(soma)==1)&&(verifPrimo(vetor[3])==1))
												printf("Sim: '%i' '%i' ",soma,vetor[3]);
											else{
												soma=((vetor[1]*100)+(vetor[2]*10)+(vetor[3]*1));
												if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1))
													printf("Sim: '%i' '%i' ",vetor[0],soma);
												else{
													printf("N�o.");
												}
											}
										}
									}
								}
							}
						}
					}
				}
				break;
			case 4:
				if((vetor[1]==0)&&(vetor[2]==0)&&(vetor[3]==0))
					printf("N�o.");
				else{
					if((vetor[1]==0)&&(vetor[2]==0)){
						soma=(vetor[0]*1000)+(vetor[1]*100)+(vetor[2]*10)+(vetor[3]*1);
						if((verifPrimo(soma)==1)&&(verifPrimo(vetor[4])==1))
							printf("Sim: '%i' '%i'",soma,vetor[4]);
						else
							printf("N�o.");
					}else{
						if((vetor[2]==0)&&(vetor[3]==0)){
							soma=(vetor[1]*1000)+(vetor[2]*100)+(vetor[3]*10)+(vetor[4]*1);
							if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1))
								printf("Sim: '%i' '%i'",vetor[0],soma);
							else
								printf("N�o.");
						}else{
							if((vetor[1]==0)&&(vetor[3]==0))
								printf("N�o.");
							else{
								if(vetor[1]==0){
									soma=(vetor[0]*100)+(vetor[1]*10)+(vetor[2]*1);
									if((verifPrimo(soma)==1)&&(verifPrimo(vetor[3])==1)&&(verifPrimo(vetor[4])==1))
										printf("Sim: '%i' '%i' '%i'",soma,vetor[3],vetor[4]);
									else{
										soma=(vetor[0]*1000)+(vetor[1]*100)+(vetor[2]*10)+(vetor[3]*1);
										if((verifPrimo(soma)==1)&&(verifPrimo(vetor[4])==1))
											printf("Sim: '%i' '%i'",soma,vetor[4]);
										else
											printf("N�o.");
									}
								}else{
									if(vetor[2]==0){
										soma=(vetor[1]*100)+(vetor[2]*10)+(vetor[3]*1);
										if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1)&&(verifPrimo(vetor[4])==1))
											printf("Sim: '%i' '%i' '%i'",vetor[0],soma,vetor[4]);
										else{
											soma=(vetor[1]*1000)+(vetor[2]*100)+(vetor[3]*10)+(vetor[4]*1);
											if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1))
												printf("Sim: '%i' '%i'",vetor[0],soma);
											else
												printf("N�o.");
										}
									}else{
										if(vetor[3]==0){
											soma=(vetor[2]*100)+(vetor[3]*10)+(vetor[4]*1);
											if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1)&&(verifPrimo(vetor[1])==1))
												printf("Sim: '%i' '%i' '%i'",vetor[0],vetor[1],soma);
											else
												printf("N�o.");
										}else{
											soma=((vetor[0]*10)+(vetor[1]*1));
											if((verifPrimo(soma)==1)&&(verifPrimo(vetor[2])==1)&&(verifPrimo(vetor[3])==1)&&(verifPrimo(vetor[4])==1))
												printf("Sim: '%i' '%i' '%i' '%i'",soma,vetor[2],vetor[3],vetor[4]);
											else{
												soma=((vetor[1]*10)+(vetor[2]*1));
												if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1)&&(verifPrimo(vetor[3])==1)&&(verifPrimo(vetor[4])==1))
													printf("Sim: '%i' '%i' '%i' '%i'",vetor[0],soma,vetor[3],vetor[4]);
												else{
													soma=(vetor[2]*10+(vetor[3]*1));
													if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1)&&(verifPrimo(vetor[1])==1)&&(verifPrimo(vetor[4])==1))
														printf("Sim: '%i' '%i' '%i' '%i'",vetor[0],vetor[1],soma,vetor[4]);
													else{
														soma=((vetor[3]*10)+(vetor[4]*1));
														if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1)&&(verifPrimo(vetor[1])==1)&&(verifPrimo(vetor[2])==1))
															printf("Sim: '%i' '%i' '%i' '%i'",vetor[0],vetor[1],vetor[2],soma);	
														else{
															soma=((vetor[0]*10)+(vetor[1]*1));
															soma2=((vetor[2]*10)+(vetor[3]*1));
															if((verifPrimo(soma)==1)&&(verifPrimo(soma2)==1)&&(verifPrimo(vetor[4])==1))
																printf("Sim: '%i' '%i' '%i' ",soma,soma2,vetor[4]);
															else{
																soma=((vetor[0]*10)+(vetor[1]*1));
																soma2=((vetor[3]*10)+(vetor[4]*1));
																if((verifPrimo(soma)==1)&&(verifPrimo(soma2)==1)&&(verifPrimo(vetor[2])==1))
																	printf("Sim: '%i' '%i' '%i' ",soma,vetor[2],soma2);
																else{
																	soma=((vetor[1]*10)+(vetor[2]*1));
																	soma2=((vetor[3]*10)+(vetor[4]*1));
																	if((verifPrimo(soma)==1)&&(verifPrimo(soma2)==1)&&(verifPrimo(vetor[0])==1))
																		printf("Sim: '%i' '%i' '%i' ",vetor[0],soma,soma2);
																	else{
																		soma=((vetor[0]*100)+(vetor[1]*10)+(vetor[2]*1));
																		if((verifPrimo(soma)==1)&&(verifPrimo(vetor[3])==1)&&(verifPrimo(vetor[4])==1))
																			printf("Sim: '%i' '%i' '%i' ",soma,vetor[3],vetor[4]);
																		else{
																			soma=((vetor[1]*100)+(vetor[2]*10)+(vetor[3]*1));
																			if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1)&&(verifPrimo(vetor[4])==1))
																				printf("Sim: '%i' '%i' '%i' ",vetor[0],soma,vetor[4]);
																			else{
																				soma=((vetor[2]*100)+(vetor[3]*10)+(vetor[4]*1));
																				if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1)&&(verifPrimo(vetor[1])==1))
																					printf("Sim: '%i' '%i' '%i' ",vetor[0],vetor[1],soma);
																				else{
																					soma=((vetor[0]*100)+(vetor[1]*10)+(vetor[2]*1));
																					soma2=((vetor[3]*10)+(vetor[4]*1));
																					if((verifPrimo(soma)==1)&&(verifPrimo(soma2)==1))
																						printf("Sim: '%i' '%i' ",soma,soma2);
																					else{
																						soma=((vetor[2]*100)+(vetor[3]*10)+(vetor[4]*1));
																						soma2=((vetor[0]*10)+(vetor[1]*1));
																						if((verifPrimo(soma)==1)&&(verifPrimo(soma2)==1))
																							printf("Sim: '%i' '%i' ",soma2,soma);
																						else{
																							soma=((vetor[0]*1000)+(vetor[1]*100)+(vetor[2]*10)+(vetor[3]*1));
																							if((verifPrimo(soma)==1)&&(verifPrimo(vetor[4])==1))
																								printf("Sim: '%i' '%i' ",soma2,vetor[4]);
																							else{
																								soma=((vetor[1]*1000)+(vetor[2]*100)+(vetor[3]*10)+(vetor[4]*1));
																								if((verifPrimo(soma)==1)&&(verifPrimo(vetor[0])==1))
																									printf("Sim: '%i' '%i' ",vetor[0],soma2);
																								else{
																									printf("N�o.");
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}						
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			break;	
		}
	}
}


int verifPrimo(int num){ //verifica se o n�mero � primo {se ele retornar 1 quer dizer que o n�mero primo}
	int i,divisores=0;
	if((num==1||(num==0)))
		return 0;
	else{
		for(i=2;i<num;i++){
			if(num%i==0)
				divisores+=1;
		}
	}
	return (divisores>0)?0:1;
}
