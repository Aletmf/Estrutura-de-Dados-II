#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*Faça um programa em que o usuário digite uma sequência de números, sem limite de qtidade. Os números deverão
ser digitados um a um, sendo que deve ser digitado 0 para encerrar a entrada. Os dados devem ser armazenados
desse modo:

	*Inicie com um vetor de tamanho 5, alocado dinamicamente;
	*Caso o vetor alocado esteja cheio, aloque um novo vetor do tamanho do vetor anterior adicionado espaço
	para mais 5 valores (tamanho n + 5)*/
	
	
	
	int main(){
		setlocale(LC_ALL,"Portuguese");
		int *numeros, tam = 5, numero, quantidade = 0;
		
		numeros = (int *) malloc (tam * sizeof(int));
		printf("Digite um número para ser colocado no vetor (0 sai): ");
		scanf("%d", &numero);
		while(numero != 0){
		if(quantidade<tam){
			numeros[quantidade] = numero;
			quantidade++;
		}
		else{
			numeros = (int *) realloc(numeros, (tam+5)*sizeof(int));
			tam = tam + 5; // Atualiza o número do TAM para que o if do while aja corretamente
			numeros[quantidade] = numero;
			quantidade++;
		}
		printf("Digite um número para ser colocado no vetor (0 sai): ");
		scanf("%d", &numero);
		}
		printf("Vetor resultante: ");
		for(int i = 0; i < quantidade; i++){
			printf("%d ", numeros[i]);
		}
		free(numeros);
		
	}