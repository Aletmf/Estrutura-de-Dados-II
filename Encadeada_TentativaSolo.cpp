#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*Exercicio de lista encadeada -
	Crie uma lista que armazena caracteres, e na qual os nos sao inseridos sempre no inicio da lista. ok
	 O usuario deve ser perguntado a cada no inserido se deseja inserir um novo no. ok
	 Ao termino da criacao da lista:
	 	 a) Mostre os elementos da lista criada;
		 b) Conte e informe quantos nos possuem uma vogal maiuscula armazenada.*/
		 
		 struct no{
			 char letra;
			 struct no *prox;
		 };
	typedef struct no LISTA; // Chamaremos struct no de "LISTA" o resto do programa inteiro a partir daqui.
		 
 	char Coletar_Caractere(char caracter){
		 printf("Digite o caractere a ser inserido: ");
		 scanf("%c", &caracter);
		 
		 return caracter;
	 }
	 
	 LISTA * Inserir_Inicio(LISTA *inicio, char caracter){ // Criacaoo da funcao com retorno de ponteiro LISTA. Futuramente retornar "inicio"
		 LISTA *aux; // Criacaoo de ponteiro auxiliar para manusear "p" indiretamente.
		 aux = (LISTA*) malloc(sizeof(LISTA)); // Malloc para alocar dinamicamente UM espaco com o tamanho de LISTA, contendo um caracter e um ponteiro -> prox.
		 aux->letra = caracter; // Coloca o caractere inserido pelo usuario na posicao "letra" do ponteiro auxiliar.
		 
		 if(inicio==NULL){ // Condicao para verificar se a lista esta vazia. Caso sim...
			 aux->prox = NULL; // Caso sim, aux-> prox apontar para NULL, pois ele sera o primeiro elemento da lista, e como nao temos segundo, apontar? para NULL.
		 	 inicio = aux; // Inicio apontar? para AUX, pois ele ser? o primeiro item da lista.
		 }
		 else{ // Se n?o...
			 aux->prox = inicio; // Aux->prox apontar? para in?cio, pois j? temos algo sendo apontado por in?cio, que ? um n?, num endere?o aleat?rio.
			 inicio = aux; // Inicio = aux pois ser? o primeiro termo da lista, j? que inserimos no in?cio. Inicio apontar? para o endere?o que aux-prox apontou acima.
		 }
		 
		 return inicio; // Retorna o ponteiro inicio com o valor apontado atualizado
	 }
	 
	 void Mostrar_Lista(LISTA *inicio){
	 	LISTA *percorrer; // Cria um ponteiro auxiliar para percorrer a lista
	 	percorrer = inicio; // Percorrer aponta para inicio, pois inicio possui um caracter, ? o come?o do encadeamento e aponta para o pr?ximo do encadeamento.
	 	while(percorrer != NULL){ // Enquanto "percorrer" n?o apontar para "NULL" vai percorrer a lista
			 printf("%c", percorrer->letra);
			 percorrer = percorrer->prox; // Percorrer = percorrer->prox pois "percorrer->prox" apontar? o pr?ximo n?, que apontar? seu valor, e apontar? o pr?ximo at? NULL.
		 }
		 
	 }
	 void Contar_Vogal(LISTA *inicio, int contadorVogalM){
	 	LISTA *percorrer; // Cria um ponteiro auxiliar para percorrer a lista
	 	percorrer = inicio; // Pois aponta para o primeiro n?, que futuramente apontar? para os outros n?s
	 	while(percorrer != NULL){
			 if(percorrer->letra == 'A' || percorrer->letra == 'E' || percorrer->letra == 'I' || percorrer->letra == 'O' || percorrer->letra == 'U'){
			 	contadorVogalM++; // Incremento quando a condicaoo "if percorrer->letra cont?m vogal ma?scula" ? verdadeira.
			} //Fechamento if
			percorrer = percorrer->prox; // Torna "percorrer" igual o percorrer->prox, que aponta para o pr?ximo n?. Logo, na pr?xima repeti??o, percorrer ter? o novo n?.
		 } // Fechamento while
		 printf("\n\nO programa possui %d vogais mai?sculas.", contadorVogalM);
	 } // Fechamento funcaoo
	 
		 int main (){
	setlocale(LC_ALL,"Portuguese");
	LISTA *inicio;
	char caracter;
	int op, contadorVogalM = 0;
	inicio = NULL;
	
	
	do{
		caracter = Coletar_Caractere(caracter); // Coleta o caracter digitado pelo usu?rio.
		inicio = Inserir_Inicio(inicio, caracter); // Atualiza o valor do ponteiro "inicio", sem perder o que estava anteriormente, e agora com um ponteiro para o n? antigo.
		system("cls");
		printf("Deseja inserir outro caractere?\n\n1- SIM\n0- SAIR\n\n-> ");
		scanf("%d", &op);
		system("cls");
	}while(op != 0);
	Mostrar_Lista(inicio);
	Contar_Vogal(inicio, contadorVogalM);
	
	}