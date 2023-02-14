#include <stdio.h> //biblioteca de comunicação com o usúario
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()//Função responsavel por cadastrar os usuários do sitema
{
	setlocale(LC_ALL, "Portuguese"); //Definido as linguagem.
	
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis/string
	
	printf("Digite o CPF ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever.
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");// abrir o arquivo "a"  para atualizar.
	fprintf(file,", ");//salvar no arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");// abrir o arquivo "a" para atualizar.
	fprintf(file,nome);//salvar no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
		
	printf("Digite o cargo a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,".");
	fclose(file);	
	
    system("pause");//messagem fixa até usuário decidir.
}

int consulta()//Função responsavel por consultar os usuários do sitema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");//Consultando informação do usuário
	scanf("%s",cpf);//%s refere-se a string
  	
	FILE *file;// consultar o arquivo
	file = fopen(cpf,"r");//abrir o arquivo e "r" ler.
  	
	if(file == NULL)//verificação de arquivo.
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)//verificação de arquivos enquanto concluir ou não existir.
	{	
		printf("\nEssas são as informações dos usuarios: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
  	
	system ("pause");///messagem fixa até usuário decidir.
	
}

int delatar()//Função responsavel por deletar os usuários do sitema
{

	char cpf[40];
	
	printf("Digite o CPF do Usiário a ser deletado: ");//Consultando informação do usuário
	scanf("%s",cpf);//%s refere-se a string
	
	remove(cpf);
	
	FILE *file;// consultar o arquivo
	file = fopen(cpf,"r");//abrir o arquivo e "r" ler.
	
	if(file == NULL)//verificação de arquivo.
	{
		printf("O usuário foi deletado com sucesso ou encontrado no sistema!\n");
		system ("pause");//messagem fixa até usuário decidir.
	}
}


int main()
{
	int opcao=0; //Definindo as variaveis.
	int laco=1;
	
	for(laco=1;laco=1;)//instruções de repetições
	{
		system("cls");//responsavel por limpar a tela.
		
		setlocale(LC_ALL, "Portuguese"); //Definido as linguagem.
	
		printf( "##### Cartório da EBAC #####\n\n"); // inico do menu.
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("opcao: "); // Final do menu.
	
		scanf ("%d", &opcao); //Armazenando a escolha do usuário.
	
		system ("cls");//responsavel por limpar a tela.
		
		switch(opcao)//inicio da seleção no menu
		{
			case 1:// iniciar se for essa opção.
			registro();//chamada de funções 
			break;//não prossegue se não for essa opção.
			
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
			
			default://se não for nenhuma das opções.
			printf("Essa opção não está disponivel!\n");
			system ("pause");//messagem fixa até usuário decidir.
			break;//não prossegue se não for essa opção.
			//fim da seleção do menu.
		}
	
	}  		
	
}
