#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsávek por cuidar das sting

int registro() //Função para cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];	 
	char cpf[40]; 		//char significa que estamos criando um banco de dados
	char nome[40];		//[40]quantidade maxima de caracteres da variavel (String) "%s"
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");	//Coletando informação do usuário
	scanf("%s", cpf);	//armazena o CPF %s dentro da Strings
	
	strcpy(arquivo, cpf);	//Responsavel por copiar os valores das string
	
	FILE *file;	//cria o arquivo 
	file = fopen(arquivo, "w");	//abre o arquivo e "w" write para escrever a informação
	fprintf(file,cpf);	//salvo o valor da variavel cpf
	fclose(file);	//fecha o arquivo
	
	file = fopen(arquivo, "a"); //acessar o arquivo e 'a' para atualizar a informação
	fprintf(file,","); //salva o espaça para separar a variavel
	fclose(file); //fechar o arquivo att
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",nome); //armazena o nome dentro da string
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" atualiza a informação 
	fprintf(file,nome); //salva o valor da variavel nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" para atualizar informação
	fprintf(file,","); //salva o espaço para serparar a variavel
	fclose(file); //fechar arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informações
	scanf("%s",sobrenome); //salva o valor da variavel sobrenome
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file,sobrenome); //salva o valor da variavel sobrenome
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file,","); //salva o espaço para separar a variavel
	fclose(file); //fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informações sobre o cargo
	scanf("%s",cargo); //armazena o cargo dentro das string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,cargo); //salva o valor da variavel cargo
	fclose(file); //fecha arquivo
	
	system("pause");
	
}

int consulta() //Função para consultar um registo
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //armazenado a variavel cpf utilizando a função string "%s"
	
	FILE *file; //criar arquivo
	file = fopen(cpf,"r"); //abrir o arquivo CPF e "r" de Read (ler) a informação 
	
	
	if(file == NULL) //Se a informação não existir traz a frase a baixo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //While (enquanto) tiver informações, armazene informações em conteudo se não for diferente de NULL (nulo)
	{
		printf("\nEssas são as informações do usuário: \n\n"); 
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
		
}

int deletar() //Função para deletar um registo
{
	 char cpf[40]; //string CPF
	 
	 printf("Digite o CPF do usuário a ser deletado: ");
	 scanf("%s",cpf); //string "s" são conjuntos de variaveis
	 
	 remove(cpf);
	 
	 FILE *file; 
	 file = fopen(cpf,"r"); //"r" read 'ler' o cpf na pasta file
		 
	 if(file == NULL) //Se for igual a NULL vai aparecer a mensagem abaixo	 
	 {
		printf("O usuário não se encontra no sistema!\n\n");
	 	system("pause");
	 }
	 
	 fclose(file);
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("\tCartório de registro EBAC\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário 
	
		system("cls"); //responsavel por limpar a tela
		
		
		switch(opcao) //inicio da seleção do menu 
		{
			case 1:	
			registro();	//chamada de funções 
			break;
			
			case 2:
			consulta();		 
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não esta disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
		
	
	} 
}

//string -> CONJUNTO DE VARIAVEIS  
