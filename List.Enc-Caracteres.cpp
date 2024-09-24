#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*Exercício de lista encadeada -
	Crie uma lista que armazena caracteres, e na qual os nós são inseridos sempre no início da lista.
	 O usuário deve ser perguntado a cada nó inserido se deseja inserir um novo nó.
	 Ao término da criação da lista:
	 	 a) Mostre os elementos da lista criada;
		 b) Conte e informe quantos nós possuem uma vogal maiúscula armazenada.*/

	struct no{
		   char letra;
		   struct no *prox;	
	};
	
	typedef struct no LISTA;

	LISTA * InserirInicio(LISTA *p, char caracter){
		LISTA *novo; // Cria um ponteiro auxiliar
		novo = (LISTA*) malloc (sizeof(LISTA)); //Aloca espaço dinamicamente para 1 caractere e 1 ponteiro para a próxima posição (struct no)
		novo->letra = caracter; // Atribui o valor de "caracter" ao campo novo-> letra
		
		if(p == NULL){
			p = novo; // Se p apontar para null, logo, a lista está vazia. Como adicionaremos o novo, p apontará para "novo" pois aponta para o início da lista. 
			novo -> prox = NULL; // Novo -> prox apontará para null, pois como ele é o novo da lista, ele aponta para null e p aponta para ele
		}
		else{
			novo->prox = p; // Se a lista não está vazia, novo->prox aponta para p pois, que aponta para o ponteiro do início
			p = novo; // p = novo, pois o p apontará para o caractere inserido em novo, e para o endereço do ponteiro passado, que era apontado por p
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
		printf("\nO programa tem %d vogais maiúsculas", contadorVogalM);
		
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