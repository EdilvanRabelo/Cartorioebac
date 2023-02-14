#include <stdio.h> //biblioteca de comunica��o com o us�ario
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()//Fun��o responsavel por cadastrar os usu�rios do sitema
{
	setlocale(LC_ALL, "Portuguese"); //Definido as linguagem.
	
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de vari�veis/string
	
	printf("Digite o CPF ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever.
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");// abrir o arquivo "a"  para atualizar.
	fprintf(file,", ");//salvar no arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");// abrir o arquivo "a" para atualizar.
	fprintf(file,nome);//salvar no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
		
	printf("Digite o cargo a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,".");
	fclose(file);	
	
    system("pause");//messagem fixa at� usu�rio decidir.
}

int consulta()//Fun��o responsavel por consultar os usu�rios do sitema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");//Consultando informa��o do usu�rio
	scanf("%s",cpf);//%s refere-se a string
  	
	FILE *file;// consultar o arquivo
	file = fopen(cpf,"r");//abrir o arquivo e "r" ler.
  	
	if(file == NULL)//verifica��o de arquivo.
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)//verifica��o de arquivos enquanto concluir ou n�o existir.
	{	
		printf("\nEssas s�o as informa��es dos usuarios: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
  	
	system ("pause");///messagem fixa at� usu�rio decidir.
	
}

int delatar()//Fun��o responsavel por deletar os usu�rios do sitema
{

	char cpf[40];
	
	printf("Digite o CPF do Usi�rio a ser deletado: ");//Consultando informa��o do usu�rio
	scanf("%s",cpf);//%s refere-se a string
	
	remove(cpf);
	
	FILE *file;// consultar o arquivo
	file = fopen(cpf,"r");//abrir o arquivo e "r" ler.
	
	if(file == NULL)//verifica��o de arquivo.
	{
		printf("O usu�rio foi deletado com sucesso ou encontrado no sistema!\n");
		system ("pause");//messagem fixa at� usu�rio decidir.
	}
}


int main()
{
	int opcao=0; //Definindo as variaveis.
	int laco=1;
	
	for(laco=1;laco=1;)//instru��es de repeti��es
	{
		system("cls");//responsavel por limpar a tela.
		
		setlocale(LC_ALL, "Portuguese"); //Definido as linguagem.
	
		printf( "##### Cart�rio da EBAC #####\n\n"); // inico do menu.
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("opcao: "); // Final do menu.
	
		scanf ("%d", &opcao); //Armazenando a escolha do usu�rio.
	
		system ("cls");//responsavel por limpar a tela.
		
		switch(opcao)//inicio da sele��o no menu
		{
			case 1:// iniciar se for essa op��o.
			registro();//chamada de fun��es 
			break;//n�o prossegue se n�o for essa op��o.
			
			case 2:
			consulta();
			break;
			
			case 3:
		 	delatar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default://se n�o for nenhuma das op��es.
			printf("Essa op��o n�o est� disponivel!\n");
			system ("pause");//messagem fixa at� usu�rio decidir.
			break;//n�o prossegue se n�o for essa op��o.
			//fim da sele��o do menu.
		}
	
	}  		
	
}
