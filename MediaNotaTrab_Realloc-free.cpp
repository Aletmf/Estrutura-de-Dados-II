#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//CORRIGIR
#define peso1 2
#define peso2 3
#define pesotrab 2

/* Escreva um programa que faça a alocação dinâmica de um vetor que contenha o nome do aluno, notas das provas 
1 (com peso 2) e 2 (com peso 3) e de trabalho (com peso 2). Escreva uma função que calcule a média de cada
aluno de uma turma com n alunos, sendo n digitado pelo usuário, e que mostre se o aluno foi aprovado
(com média >= 7) ou reprovado. Escreva uma função que permita alterar o número de alunos na turma. Calcule a
a média da turma antes e após a alteração do número de alunos.*/

struct alunos{
	   char nome[50];
	   float p1;
	   float p2;
	   float trabalho;
	   float media;
	   char situacao[20];
	   	
};

	void cadastrar_alunos(struct alunos *Aluno, int n){
		for(int i = 0; i < n; i++){
		printf("Digite o nome do aluno %d: ", i+1);
		fflush(stdin);
		gets(Aluno[i].nome);
		printf("Digite a nota da p1 do aluno: ");
		scanf("%f", &Aluno[i].p1);
		printf("Digite a nota da p2 do aluno: ");
		scanf("%f", &Aluno[i].p2);
		printf("Digite a nota do trabalho do aluno: ");
		scanf("%f", &Aluno[i].trabalho);
		system("cls");
		}
	}
	
	float calcular_mediaG(struct alunos *Aluno, int n){
		float soma_media = 0;
		float media_geral;
		for(int i = 0; i < n; i++){
			Aluno[i].media = ((Aluno[i].p1 * peso1) + (Aluno[i].p2 * peso2) + (Aluno[i].trabalho*pesotrab))/(peso1+peso2+pesotrab);
			soma_media = soma_media + Aluno[i].media;
			if(Aluno[i].media >= 7){
				strcpy(Aluno[i].situacao, "APROVADO");
			}
			else{
				strcpy(Aluno[i].situacao, "REPROVADO");
			}
		}
		media_geral = soma_media/n;
		return media_geral;
		
	}
	void visualizar_situacao(struct alunos *Aluno, int n){
		for(int i = 0; i < n; i++){
			printf("Aluno %d- NOME: %c\nMEDIA:%2.f\nSITUAÇÃO:%c", i+1, Aluno[i].nome, Aluno[i].media, Aluno[i].situacao);
		}
	}

int main (){
	   setlocale(LC_ALL,"Portuguese");
	   struct alunos *Aluno;
	   int n, op, tam;
	   float media_geral;
	   printf("Digite o número de alunos na turma\n-> ");
	   scanf("%d", &n);
	   Aluno = (struct alunos*)malloc(n*sizeof(struct alunos));
	   cadastrar_alunos(Aluno, n);
	   media_geral = calcular_mediaG(Aluno, n);
	   printf("Média geral: %.2f\n\n", media_geral);
	   system("pause");
	   printf("Deseja alterar a quantidade de alunos da turma?\n1- AUMENTAR\n2- DIMINUIR\n3- NÃO\n\n-> ");
	   scanf("%d", &op);
	   
	   if(op != 3){
		   if (op==1){
			   printf("Quantos novos alunos entrarão na turma?");
			   scanf("%d", &tam);
			   cadastrar_alunos(Aluno, n + tam);
		   }
		   else{
			   printf("Quantos alunos sairão da turma?");
			   scanf("%d", &tam);
			   tam = tam*-1;
			   cadastrar_alunos(Aluno, n + tam);
		   }
		   if(n + tam == 0){
			   free(Aluno);
		   }
		   else if(n + tam < 0){
			   printf("Erro de alocação");
			   free(Aluno);
		   }
		   else{
			   Aluno =(struct alunos*)realloc(Aluno, (n+tam)*sizeof(struct alunos));
			   if(Aluno==NULL){
				   printf("ERRO");
				   exit(1);
			   }
		   }
	   }
	   /*for(int i = 0; i < (n + tam); i++){
		   cadastrar_alunos(Aluno, n + tam);
	   }*/

	   calcular_mediaG(Aluno, n+tam);
	   system("cls");
	   visualizar_situacao(Aluno, n);
	   system("pause");
	   free(Aluno);
	   
	   
	   
}