#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*Exerc�cio de lista encadeada -
	Crie uma lista que armazena caracteres, e na qual os n�s s�o inseridos sempre no in�cio da lista.
	 O usu�rio deve ser perguntado a cada n� inserido se deseja inserir um novo n�.
	 Ao t�rmino da cria��o da lista:
	 	 a) Mostre os elementos da lista criada;
		 b) Conte e informe quantos n�s possuem uma vogal mai�scula armazenada.*/

	struct no{
		   char letra;
		   struct no *prox;	
	};
	
	typedef struct no LISTA;

	LISTA * InserirInicio(LISTA *p, char caracter){
		LISTA *novo; // Cria um ponteiro auxiliar
		novo = (LISTA*) malloc (sizeof(LISTA)); //Aloca espa�o dinamicamente para 1 caractere e 1 ponteiro para a pr�xima posi��o (struct no)
		novo->letra = caracter; // Atribui o valor de "caracter" ao campo novo-> letra
		
		if(p == NULL){
			p = novo; // Se p apontar para null, logo, a lista est� vazia. Como adicionaremos o novo, p apontar� para "novo" pois aponta para o in�cio da lista. 
			novo -> prox = NULL; // Novo -> prox apontar� para null, pois como ele � o novo da lista, ele aponta para null e p aponta para ele
		}
		else{
			novo->prox = p; // Se a lista n�o est� vazia, novo->prox aponta para p pois, que aponta para o ponteiro do in�cio
			p = novo; // p = novo, pois o p apontar� para o caractere inserido em novo, e para o endere�o do ponteiro passado, que era apontado por p
		}
		return p;
	}
	
	char ColetarCaracter(char caracter){
		printf("Digite o caracter que deseja inserir na lista: ");
		fflush(stdin);
		scanf("%c", &caracter);
		fflush(stdin);
		return caracter;
	}
	
	void MostraLista(LISTA *p){
		LISTA *percorrer;
		percorrer = p;
		printf("Vogais: ");
		while(percorrer != NULL){
			printf("%c", percorrer->letra);
			percorrer = percorrer->prox;
		}
	}
	
	void ContadorVogal(LISTA *p, int contadorVogalM, char caracter){
		LISTA *percorrer;
		percorrer = p;
		while(percorrer != NULL){
			if(percorrer->letra == 'A' || percorrer->letra == 'E' || percorrer->letra == 'I' || percorrer->letra == 'O' || percorrer->letra == 'U'){
			contadorVogalM++;
		}
			percorrer = percorrer->prox;
		}
		printf("\nO programa tem %d vogais mai�sculas", contadorVogalM);
		
	}
	
	
	
int main (){
	setlocale(LC_ALL,"Portuguese");
	LISTA *p;
	p = NULL; // Lista vazia
	char caracter;
	int contadorVogalM = 0, op;
	
	do{
	caracter = ColetarCaracter(caracter);
	p = InserirInicio(p, caracter);
	system("cls");
	printf("Deseja inserir mais caracteres?\n\n1 - SIM\n0 - SAIR\n\n-> ");
	scanf("%d", &op);
	system("cls");
	}while(op!=0);
	MostraLista(p);
	ContadorVogal(p, contadorVogalM, caracter);
}