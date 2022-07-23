#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_GUERREIRO 5
#define MAX_DRAGAO 6
#define MAX_LOCACAO 6

char NomeGuerreiro[MAX_GUERREIRO][20] = {'\0'};
char Reino[MAX_GUERREIRO][20] = {'\0'};
char Titulo[MAX_GUERREIRO][20] = {'\0'};
char dataEntrega[MAX_GUERREIRO][20] = {'\0'};
char buscaGuerreiro[100] = {'\0'};
int CodigoDoGuerreiroLocador =-1;
int idGuerreiro = - 1;
int qtdGuerreiros;
char elementoDragao[MAX_DRAGAO][20] = {'\0'};
char buscaDragao[100] = {'\0'};
char tituloDragao[MAX_DRAGAO][20] = {'\0'};
char nomeDragao[MAX_DRAGAO][20] = {'\0'};
int IdadeDragao[MAX_DRAGAO];
int DragaoLocado[MAX_GUERREIRO];
int codigoDragao = -1;
int CodigoLocado = -1;
int codigo = -1;
int i;
int opcao;

int main(int argc, char *argv[]) {
	for (i = 0; i < MAX_GUERREIRO; i++)
	{
		DragaoLocado[i] = - 1;
	}
	do {
		printf("\n    MENU");
		printf("\n 0. Sair");
        printf("\n 1. Listar guerreiros");
        printf("\n 2. Cadastrar guerreiro pelo codigo");
        printf("\n 3. Pesquisar guerreiro pelo nome");
        printf("\n 4. Excluir guerreiro pelo codigo");
        printf("\n 5. Listar dragoes");
        printf("\n 6. Cadastrar dragao pelo codigo");
        printf("\n 7. Pesquisar dragao pelo nome");
        printf("\n 8. Excluir dragao pelo codigo");
        printf("\n 9. Listar dragoes locados");
        printf("\n 10. Locar dragao");
        printf("\n 11. Devolver dragao pelo codigo do guerreiro");
        printf("\n\n Digite o numero da opcao: ");
		scanf("%d", &opcao);
        
        switch(opcao){
        	case 1: 
        	        qtdGuerreiros = 0;
        	       for(i = 0; i < MAX_GUERREIRO; i++)
        	           if(NomeGuerreiro[i][0] != '\0'){
        	           	 printf("\n Codigo: %d \n Nome: %s\n Titulo: %s\n Reino: %s", i, NomeGuerreiro[i], Titulo[i], Reino[i]);
        	           	 qtdGuerreiros++;
					   }
				    if(qtdGuerreiros == 0){
				    	printf(" Nao tem guerreiros cadastrados!");
					}
                         
        	break;
        	
        	case 2: 
        	       printf(" Digita o codigo do guerreiro: ");
                   scanf("%d", &codigo);
                   if(codigo >= 0 && codigo < MAX_GUERREIRO){
				   
				      if(NomeGuerreiro[codigo][0] == '\0'){

		                   printf(" Digita o nome do guerreiro: ");
			               scanf("%s", NomeGuerreiro[codigo]);
			                 
			               printf(" Digite o titulo do guerreiro: ");
			               scanf("%s", Titulo[codigo]);
			                 
			               printf(" Digite o reino do guerreiro: ");
			               scanf("%s", Reino[codigo]);
	                   }
	               }
        	break;
        	
        	case 3: 
                   printf(" Nome do Guerreiro: ");
				   scanf("%s", buscaGuerreiro);
                   for(i = 0; i < MAX_GUERREIRO; i++){
	                   if (strcmp(buscaGuerreiro, NomeGuerreiro[i])==0){
						   printf(" Codigo	");
						   printf(" Nome		");
						   printf(" Reino		");
						   printf(" Titulo		\n");
						   printf(" %d", i);	
						   printf("	%s", NomeGuerreiro[i]);
						   printf("		%s", Reino[i]);
						   printf("		%s\n", Titulo[i]);	
						}	
				    }
        	break;
        	
        	case 4: 
                   printf(" Digite o codigo do guerreiro: ");            
                   scanf("%d", &idGuerreiro);
                   
                   if(idGuerreiro >= 0 && idGuerreiro < MAX_GUERREIRO){
	                   if(DragaoLocado[idGuerreiro] == -1){
		                   if (idGuerreiro < MAX_GUERREIRO && idGuerreiro >= 0){
		                         strcpy(NomeGuerreiro[idGuerreiro], "");
		                         printf(" Guerreiro excluido!");
		                    }else{
		                          printf(" Guerreiro nao cadastrado!\n");
		                        }
	                    } else{
	                    	   printf(" O Guerreiro tem dragao locado devolva o dragao!");
						    }
				    } else{
	                       printf(" Digite um codigo valido!");
						}
        	break;
        	
        	case 5:
				   printf("               Dragoes\n");
				   printf(" i	");
				   printf("Nome		");
				   printf("Idade		");
				   printf("Elemento		\n");
				
				   for(i = 0; i < MAX_DRAGAO; i++){
					   if(nomeDragao[i][0]!= '\0'){
						  printf(" %d", i);
						  printf("	%s", nomeDragao[i]);
						  printf("		%d", IdadeDragao[i]);
						  printf("		%s\n", elementoDragao[i]);	
					    }					
				    }   
        	break;
        	
        	case 6: 
        	      printf(" Digite o codigo do dragao: ");
                  scanf("%d", &codigoDragao);
                  
        	      printf(" Digite o nome do dragao: ");
                  scanf("%s", nomeDragao[codigoDragao]);
                  
                  printf(" Digite o elemento do dragao: ");
                  scanf("%s", elementoDragao[codigoDragao]);
                  
                  printf(" Digite a idade do dragao: ");
                  scanf("%d", &IdadeDragao[codigoDragao]);   
        	break;
        	
        	case 7:   
                   printf(" Digite o nome do Dragao: ");
				   scanf("%s", buscaDragao);

				   for(i = 0; i < MAX_DRAGAO; i++){
					   if (strcmp(buscaDragao, nomeDragao[i]) == 0){
						   printf("Codigo	");
						   printf("Nome		");
						   printf("Idade		");
						   printf("Elemento		\n");
						
						   printf(" %d", i);
						   printf("	%s", nomeDragao[i]);
						   printf("		%d", IdadeDragao[i]);
						   printf("		%s\n", elementoDragao[i]);
						   codigoDragao = 1;
					    }	
				    }
        	break;
        	
        	case 8:
			      printf(" Codigo do dragao: ");
                  scanf("%d", &codigoDragao);
                  
                  if(DragaoLocado[codigoDragao] == -1){
	                  if (MAX_DRAGAO > codigoDragao && codigoDragao >= 0){
	                           strcpy(nomeDragao[codigoDragao], "");
	                           printf(" Dragao excluido!");    
	                    }
	                    else{
	                        printf(" Dragao nao cadastrado!\n");
	                    }
                    } else{
                    	   printf(" O dragao esta locado devolva o dragao!");
					    }
        	break;
        	
        	case 9: 
        	      for (i = 0; i < MAX_GUERREIRO; i++){
                       if (DragaoLocado[i] != -1){
                           printf(" Codigo: %d \nNome: %s \nGuerreiro: %s\n", i, nomeDragao[DragaoLocado[i]], NomeGuerreiro[i]);
                        }
                    }
        	break;
        	case 10: 
					printf("         Dragoes disponiveis:\n");
					printf(" Codigo	");
					printf(" Nome		");
					printf(" Idade		");
					printf(" Elemento		\n");
					
					for(i = 0; i < MAX_DRAGAO; i++){
						if(nomeDragao[i][0] != '\0'){					
						   printf(" %d", i);
						   printf("	%s", nomeDragao[i]);
						   printf("		%d", IdadeDragao[i]);
						   printf("		%s\n", elementoDragao[i]);
						}
					}
				
				    printf(" Digite o codigo do Dragao: ");
				    scanf("%d", &CodigoLocado);
				    fflush(stdin);
				
				    if(CodigoLocado < MAX_DRAGAO && CodigoLocado >= 0 && nomeDragao[CodigoLocado][0]!='\0'){
					   printf(" Codigo	");
					   printf("Nome		");
					   printf("Reino		");
				       printf("Titulo		\n");
					
					for(i = 0; i < MAX_GUERREIRO; i++){
						if (NomeGuerreiro[i][0!= '\0']){				
						    printf(" %d", i);
						    printf("	%s", NomeGuerreiro[i]);
						    printf("		%s", Reino[i]);
						    printf("		%s\n", Titulo[i]);
						}					
					}
				
					printf(" Digite o seu codigo de Guerreiro: ");
					scanf("%d", &CodigoDoGuerreiroLocador);
					fflush(stdin);
					
					if( DragaoLocado [CodigoDoGuerreiroLocador] == -1){
					   DragaoLocado[CodigoDoGuerreiroLocador] = CodigoLocado;
					   printf("\n Informe da data da devolucao: ");
					   scanf("%s", dataEntrega[CodigoDoGuerreiroLocador]);
					   printf("\n Dragao locado com Sucesso!\n\n");
						break;
					} else{
						      printf("\n Esse Guerreiro ja tem um dragao locado.\n");	
					    }
				    } else{
						  printf("\n Codigo invalido. \n");	
			            }
        	break;
        	
        	case 11: 
					printf(" Codigo	");
					printf(" Nome		");
					printf("Reino		");
					printf("Titulo		");
					printf("Dragao		\n");	
					
					for(i = 0; i < MAX_GUERREIRO; i++){
						if (NomeGuerreiro[i][0!= '\0']){				
						    printf(" %d", i);
						    printf("	%s", NomeGuerreiro[i]);
						    printf("		%s", Reino[i]);
						    printf("		%s", Titulo[i]);
						    printf("		%s\n", nomeDragao[DragaoLocado[i]]);
						}				
					}
				
				    printf(" Digite o codigo do Guerreiro: ");
				    scanf("%d", &CodigoDoGuerreiroLocador);
				    fflush(stdin);
				
				
				    if(CodigoDoGuerreiroLocador >= 0 && CodigoDoGuerreiroLocador < MAX_GUERREIRO && DragaoLocado[CodigoDoGuerreiroLocador]!= -1){			
					   printf("\n Dragao devolvido com sucesso.\n\n");
					   DragaoLocado[CodigoDoGuerreiroLocador] = -1;
					   strcpy (dataEntrega[CodigoDoGuerreiroLocador], "");
					break;
				    }
				    else if(CodigoDoGuerreiroLocador > MAX_GUERREIRO){	
					printf("\n Codigo Invalido.\n\n");	
				    }
				    else{	
					     printf("\n Esse guerreiro nao tem dragao locado.\n\n");
				    }
            break;
        }
        printf("\n");
		system("pause"); 
		system("cls");         
	} while(opcao != 0);
	return 0;
}
    
	


    
