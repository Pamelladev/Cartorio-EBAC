#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
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
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
    printf("\nEssas s�o as informa��es do Usu�rio: \n\n");
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
	
		printf("%s", conteudo);

	}
	
	system("pause");
	
}

int deletar()
{ 
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
		
		
	
	FILE *file;	
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
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
			printf("Usu�rio deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
}
		

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("___Cart�rio da EBAC____\n\n");
	printf("Login de administrador!\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao ==0)
	{	
	
		system("cls");
  		for(laco=1;laco=1;)
		{
		
		
	
        	setlocale(LC_ALL,"portuguese");// Definindo a linguagem 
	
    		printf("___Cart�rio da EBAC____\n\n");
	    	printf("Escolha a op��o desejada no menu:\n\n");
    		printf("\t1- Registrar Nomes\n");
    		printf("\t2- Consultar Nomes\n");
    		printf("\t3- Deletar Nomes\n");
    		printf("\t4- Sair do Sistema\n\n");
    		printf("op��o: ");//fim do menu
    	
	
    		scanf("%d", &opcao);//pausa o programa at� decis�o do usu�rio
	
    		system("cls");//Deleta as informa��es anteriores(para tela ficar mais limpa)
    	
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
	  	        printf("Essa op��o n�o est� dispon�vel!\n");
	   		    system("pause");
	  	  	    break;
	        	
	     		
    		}
		}
	
	}
	
	else
		printf("Senha incorreta!");
}

