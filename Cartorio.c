#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vek por cuidar das sting

int registro() //Fun��o para cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];	 
	char cpf[40]; 		//char significa que estamos criando um banco de dados
	char nome[40];		//[40]quantidade maxima de caracteres da variavel (String) "%s"
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");	//Coletando informa��o do usu�rio
	scanf("%s", cpf);	//armazena o CPF %s dentro da Strings
	
	strcpy(arquivo, cpf);	//Responsavel por copiar os valores das string
	
	FILE *file;	//cria o arquivo 
	file = fopen(arquivo, "w");	//abre o arquivo e "w" write para escrever a informa��o
	fprintf(file,cpf);	//salvo o valor da variavel cpf
	fclose(file);	//fecha o arquivo
	
	file = fopen(arquivo, "a"); //acessar o arquivo e 'a' para atualizar a informa��o
	fprintf(file,","); //salva o espa�a para separar a variavel
	fclose(file); //fechar o arquivo att
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",nome); //armazena o nome dentro da string
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" atualiza a informa��o 
	fprintf(file,nome); //salva o valor da variavel nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" para atualizar informa��o
	fprintf(file,","); //salva o espa�o para serparar a variavel
	fclose(file); //fechar arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es
	scanf("%s",sobrenome); //salva o valor da variavel sobrenome
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file,sobrenome); //salva o valor da variavel sobrenome
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file,","); //salva o espa�o para separar a variavel
	fclose(file); //fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��es sobre o cargo
	scanf("%s",cargo); //armazena o cargo dentro das string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,cargo); //salva o valor da variavel cargo
	fclose(file); //fecha arquivo
	
	system("pause");
	
}

int consulta() //Fun��o para consultar um registo
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //armazenado a variavel cpf utilizando a fun��o string "%s"
	
	FILE *file; //criar arquivo
	file = fopen(cpf,"r"); //abrir o arquivo CPF e "r" de Read (ler) a informa��o 
	
	
	if(file == NULL) //Se a informa��o n�o existir traz a frase a baixo
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //While (enquanto) tiver informa��es, armazene informa��es em conteudo se n�o for diferente de NULL (nulo)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n"); 
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
		
}

int deletar() //Fun��o para deletar um registo
{
	 char cpf[40]; //string CPF
	 
	 printf("Digite o CPF do usu�rio a ser deletado: ");
	 scanf("%s",cpf); //string "s" s�o conjuntos de variaveis
	 
	 remove(cpf);
	 
	 FILE *file; 
	 file = fopen(cpf,"r"); //"r" read 'ler' o cpf na pasta file
		 
	 if(file == NULL) //Se for igual a NULL vai aparecer a mensagem abaixo	 
	 {
		printf("O usu�rio n�o se encontra no sistema!\n\n");
	 	system("pause");
	 }
	 
	 fclose(file);
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("\tCart�rio de registro EBAC\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio 
	
		system("cls"); //responsavel por limpar a tela
		
		
		switch(opcao) //inicio da sele��o do menu 
		{
			case 1:	
			registro();	//chamada de fun��es 
			break;
			
			case 2:
			consulta();		 
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o esta disponivel!\n");
			system("pause");
			break;
		} //fim da sele��o
		
	
	} 
}

//string -> CONJUNTO DE VARIAVEIS  
