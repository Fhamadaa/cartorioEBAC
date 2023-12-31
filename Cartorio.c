#include <stdio.h> //biblioteca de comunica��o
#include <stdlib.h> //biblioteca de aloca��o de memt�ria
#include <locale.h> //bibliteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos strings

int registro() // Fun�ao respons�vel por cadastrar o usu�rio no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:\n"); //coleta das informa��es do usu�rio
	scanf("%s", cpf); // %s refere-se a sting

	strcpy(arquivo, cpf); //Copia os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo (w = escrever)  
	fprintf(file,cpf); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:\n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:\n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo. Arquivo n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do cadastro: \n");
	scanf("%s",cpf);
	
	remove(cpf);
			
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	else	
	{
		printf("Usu�rio removido com sucesso! \n");
		system("pause");
	}
			
}
int main()
	{
		int opcao=0; //Definindo vari�veis
		int x=1;
	
		for(x=1;x=1;)
		{
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("###Cartorio da EBAC### \n\n"); //In�cio do menu
			printf("Escolha a op��o desejada do menu \n\n");
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o:\n\n");	//Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
			system("cls"); //respons�vel por limpar a tela
		
			switch(opcao) // in�cio da sele��o do menu
			{
				case 1:
				registro(); // chamada de fun��es
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa op��o n�o est� dispon�vel\n");
				system("pause");
				break;
			}//Fim da sele��o
	
		}
	}


