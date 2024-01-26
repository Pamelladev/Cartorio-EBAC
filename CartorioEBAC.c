#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()
{ 
 	char arquivo[40];
 	char cpf [40];
 	char nome [40];
 	char sobrenome [40];
 	char cargo [40];
 	
 	printf("Digite o CPF a ser cadastrado: ");
 	scanf("%s", cpf); //salvar na string

	strcpy(arquivo, cpf); //responsvel por copiar o valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen (arquivo,"w"); //abre o arquivo para escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",\nNome: ");
	fclose(file);  // fecha arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");//salvar/atualizar
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",\nSobrenome: "); // salvar separacao com a virgula(,)
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen (arquivo,"a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);
	
    system("pause");	
		
}

int consulta()
{ 
 	setlocale(LC_ALL,"portuguese");// Definindo a linguagem 
 	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
    printf("\nEssas são as informações do Usuário: \n\n");
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
	
		printf("%s", conteudo);

	}
	
	system("pause");
	
}

int deletar()
{ 
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
		
		
	
	FILE *file;	
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usuário deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
}
		

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("___Cartório da EBAC____\n\n");
	printf("Login de administrador!\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao ==0)
	{	
	
		system("cls");
  		for(laco=1;laco=1;)
		{
		
		
	
        	setlocale(LC_ALL,"portuguese");// Definindo a linguagem 
	
    		printf("___Cartório da EBAC____\n\n");
	    	printf("Escolha a opção desejada no menu:\n\n");
    		printf("\t1- Registrar Nomes\n");
    		printf("\t2- Consultar Nomes\n");
    		printf("\t3- Deletar Nomes\n");
    		printf("\t4- Sair do Sistema\n\n");
    		printf("opção: ");//fim do menu
    	
	
    		scanf("%d", &opcao);//pausa o programa até decisão do usuário
	
    		system("cls");//Deleta as informações anteriores(para tela ficar mais limpa)
    	
    		switch(opcao)
    		{
    			case 1:
    		    registro();
			    break;
		    
			    case 2:
			    consulta();
	   		  	break;
	     	
	   		  	case 3:
				deletar();
	  	        break;
	        
	  	        case 4:
	  	        printf("Obrigada por utilizar o sistema!\n");
			    return 0;
		   	    break;	
	        
	  	        default:
	  	        printf("Essa opção não está disponível!\n");
	   		    system("pause");
	  	  	    break;
	        	
	     		
    		}
		}
	
	}
	
	else
		printf("Senha incorreta!");
}

