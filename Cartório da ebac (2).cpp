#include <stdio.h>
#include <stdlib.h> //
#include <locale.h> // biblioteca de alocação de texto
#include <string.h>

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//cpf
	
	printf("digite o cpf a ser cadastrado:");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);  //copia os valores da string
	
	FILE *file; // cria o arquivo
	file= fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	//nome
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file= fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	//sobrenome
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file= fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	// cargo
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file= fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
	
	
}


int consultar()
{

setlocale (LC_ALL, "Portuguese"); // definindo a linguagem

    char cpf [40];
    char conteudo [200];
    
    printf ("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("Arquivo não localizado! \n\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário ");
		
		// teste
		
		char *token = strtok(conteudo, ",");
		while(token != NULL){
			printf("%s\n", token);
			token = strtok(NULL, ",");
		}
		
		// fin teste
		
		
		printf("\n\n");
	}

    system("pause");

}

int deletar()
{
	
char cpf[40];

setlocale(LC_ALL,"portuguese");

printf("Digite o CPF a ser deletado: ");

scanf("%s",cpf);

FILE *file;

  file = fopen(cpf, "r"); // Tenta abrir o arquivo para leitura

if (file == NULL) 

  {

    printf("O usuário não existe!\n");

    system("pause");

  } 

else 

  {

    fclose(file); // Fecha o arquivo, pois ele existe

    remove(cpf); // Agora você pode remover o arquivo

    printf("Usuário deletado!\n");

    system("pause");

  }
	
	
	
	
	
	
}


int main()
{
	
	int opcao=0; // definindo variáveis
	int laco=1;
	
	
    for (laco=1;laco=1;)
    {
	
	 system("cls");
	 
     setlocale (LC_ALL, "Portuguese"); // definindo a linguagem
    
     printf ("#~# Cartório de Minas #~#\n\n"); // inicio do menu
     printf ("Escolha a opção desejada do menu:\n\n");
     printf ("\t1 - Registrar nomes\n");
     printf ("\t2 - Consultar nomes\n");
     printf ("\t3 - Deletar nomes\n\n\n"); //fim do menu
     printf ("Opção:  ");
     scanf("%d", &opcao); // armazenando as escolhas do user
    
     system("cls");
     
     switch(opcao)
     {
     	case 1:
     		registro();
            break;
        
        case 2:
        	consultar();
            break;
        
        case 3:
        	deletar();
            break;
        
        default:
        	printf("Desculpe, essa opção não esta disponivel.\n\n");
        	system("pause");
        break;
        	
	 }
     
    }
}
