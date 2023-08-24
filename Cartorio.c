#include <stdio.h> //biblioteca de comunicação
#include <stdlib.h> //biblioteca de alocação de memtória
#include <locale.h> //bibliteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar dos strings

int registro() // Funçao responsável por cadastrar o usuário no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:\n"); //coleta das informações do usuário
	scanf("%s", cpf); // %s refere-se a sting

	strcpy(arquivo, cpf); //Copia os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo (w = escrever)  
	fprintf(file,cpf); //Salvo o valor da variável
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
		printf("Não foi possível abrir o arquivo. Arquivo não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\n Essas são as informações do usuário: ");
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
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	else	
	{
		printf("Usuário removido com sucesso! \n");
		system("pause");
	}
			
}
int main()
	{
		int opcao=0; //Definindo variáveis
		int x=1;
	
		for(x=1;x=1;)
		{
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("###Cartorio da EBAC### \n\n"); //Início do menu
			printf("Escolha a opção desejada do menu \n\n");
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção:\n\n");	//Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usuário
	
			system("cls"); //responsável por limpar a tela
		
			switch(opcao) // início da seleção do menu
			{
				case 1:
				registro(); // chamada de funções
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
				printf("Essa opção não está disponível\n");
				system("pause");
				break;
			}//Fim da seleção
	
		}
	}


