
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 15
void drawBoard(int matris[][MAX], int N);
void readFromFile(int matris[][MAX], char *fileName);
int menu();
void game(int arr[][MAX], int size, int *score);
int main(){
    int i,j,matris[MAX][MAX]={{0}}; 
    int N = 5;
    char fileName[20];
    char user[MAX][MAX];
    char newuser[MAX];
    int registry = 0;
    int cont;
    int contuser;
    int scores[MAX];
    int score;
    int tmp;
    
    
    do{
    	cont = menu();
        if(cont == 1){
            printf("Enter the User Name: ");
            scanf("%s", newuser);

            for(i = 0 ; i < registry ; i++){
                while (strcmp(user[i], newuser) == 0){
                    printf("This name already taken, please re-enter: ");
                    scanf("%s", newuser);
                }
            }
            strcpy(user[registry], newuser);
            registry++;
            printf("\n\n!Registration Successful!\n");
            scores[registry] = 0;
            
        }
        else if(cont == 2){
            printf("user name: ");
        	scanf("%s", newuser);
        	for (i = 0 ; i < registry ; i++){
                if (strcmp(user[i], newuser) == 0){
                    printf("\nyour score = %d\n", scores[i]);
                    contuser++;
                }
            }
            if(contuser == 0){
            	printf("\nPlease register the game!\n\n");
            	cont =1;
			}
        	
		}
        else if(cont == 3){
        	printf("user name: ");
        	scanf("%s", newuser);
        	for (i = 0 ; i < registry ; i++){
                if (strcmp(user[i], newuser) == 0){
                    printf("\nWelcome to Game %s\n\n", user[i]);
                    contuser++;
                    tmp = i;
                }
            }
            if(contuser == 0){
            	printf("\nPlease register the game!\n\n");
            	cont =1;
			}
            else{
			
	            printf("random playground formation: 1\nformation of playground by reading file: 2\nyour choice:");
	            scanf("%d", &cont);
	    		printf("Enter the size: ");
	    		scanf("%d", &N);
	            if(cont == 2){
	                printf("Dosya Adini Giriniz: ");
	  	            scanf("%s",fileName);
	                readFromFile(matris, fileName);
	                
	                game(matris, N, &score);
                    scores[tmp] += score;
	            }
	            else if(cont == 1){
	                printf("Enter the size: ");
	                scanf("%d", &N);
	            }
	            else{
	                printf("invalid number");
            	}
            
       		}
        }
        else if(cont == 4){
        	cont=0;
		}
		else{
		}
        
        contuser = 0;
        score = 0;
    }while(cont != 0);
	
	
	
  return 0;
}
void readFromFile(int matris[][MAX], char *fileName){
	int i,j, temp;
	FILE *data = fopen(fileName,"r");
	if(!data){
        printf("Dosya Acilamadi!");
		return;
    }
    while(!feof(data)){
        fscanf(data,"%d %d %d\n",&i,&j,&temp);  
		matris[i][j]=temp; 
    }  
  	fclose(data); 
}


void drawBoard(int matris[][MAX], int N){
    int i,j,k;
    for(i=0;i<N;i++){
        printf("\n");
        for (k=0;k<N;k++)
            printf("-------");
        printf("\n");
        for(j=0;j<N;j++)
            if (matris[i][j]!=0)
                printf("  %d   |",matris[i][j]);
            else
                 printf("      |",matris[i][j]);
    }
}
int menu(){
    int temp;
    printf("\t\t\t\t\t***********\n");
    printf("\t\t\t\t\t* Welcome *\n");
    printf("\t\t\t\t\t***********\n");
    printf("\t\t\t\t\t*   Menu  *\n\t\t\t\t\t***********\n");    
    printf("1) Register the Game: \n2) View User Scores: \n3) Start Game: \n4) Quit: \nYour Choice: ");
    scanf("%d", &temp);

    return temp;
}

void game(int arr[][MAX], int size, int *score){
    int base_x, base_y, dest_x, dest_y;
    int **tempMatrix;
    int main_matris[MAX][MAX];
    int i, j;
    int cont;
    int temp;
    int gamecontrol = 1;
    
    
    
    
    tempMatrix = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++) {
   		tempMatrix[i] = (int *)malloc(size * sizeof(int));
	}
	
	for(i = 0 ; i < size ; i++){
		for(j = 0 ; j < size ; j++){
			main_matris[i][j] = arr[i][j];
		}
	}

    
	
	drawBoard(arr, size);

		
    do{
    	for(i = 0 ; i < size ; i++){
            for(j = 0 ; j < size ; j++){
                tempMatrix[i][j]= arr[i][j];
            }
		}
		cont = 0;
        
        do{
            gamecontrol = 1;
            
            
            printf("\nEnter the start point row: ");
            scanf("%d", &base_x);
            printf("Enter the start point colm: ");
            scanf("%d", &base_y);

            printf("Enter the dest row: ");
            scanf("%d", &dest_x);
            printf("Enter the dest colm: ");
            scanf("%d", &dest_y);

            if(base_x - dest_x == 0){
                if(dest_y > base_y){
                    for(i = 1 ; i <= (dest_y-base_y) ; i++){
                        if(arr[base_x][base_y+i] != 0){
                            gamecontrol = 0;
                        }
                    }
                }
                else if(base_y > dest_y){
                    for(i = 1 ; i <= (base_y-dest_y) ; i++){
                        if(arr[base_x][base_y-i] != 0){
                            gamecontrol = 0;
                        }
                    }
                }
                else{

                }
            }
            if(dest_y-base_y == 0){
                if(dest_x > base_x){
                    for(i = 1 ; i <= (dest_x-base_x) ; i++){
                        if(arr[base_x+i][base_y] != 0){
                            gamecontrol = 0;
                        }
                    }
                }
                else if (base_x > dest_x)
                {
                    for(i = 1 ; i <= (base_x-dest_x); i++){
                        if(arr[base_x][base_y-i] != 0){
                            gamecontrol = 0;
                        }
                    }
                }
                else{

                }
            
            }
			if(gamecontrol == 0){
				printf("\nwrong move please re-enter!\n");
			}

            
        }while(gamecontrol == 0);

        

        if(base_x - dest_x == 0){
            if(dest_y > base_y){
                for(i = 1 ; i <= (dest_y-base_y) ; i++){
                    arr[base_x][base_y+i] = arr[base_x][base_y];
                }
                *score+=(dest_y-base_y);
            }
            else if(base_y > dest_y){
                for(i = 1 ; i <= (base_y-dest_y) ; i++){
                    arr[base_x][base_y-i] = arr[base_x][base_y];
                }
                *score+=(base_y-dest_y);
            }
            else{

            }
        }
        if(dest_y-base_y == 0){
            if(dest_x > base_x){
                for(i = 1 ; i <= (dest_x-base_x) ; i++){
                    arr[base_x+i][base_y] = arr[base_x][base_y];
                }
                *score+=(dest_x-base_x);
            }
            else if (base_x > dest_x)
            {
                for(i = 1 ; i <= (base_x-dest_x); i++){
                    arr[base_x][base_y-i] = arr[base_x][base_y];
                }
                *score+=(base_x-dest_x);
            }
            else{

            }
            
        }
        
        drawBoard(arr,size);

        for(i = 0 ; i < size ; i++){
            for(j = 0 ; j < size ; j++){
                if(arr[i][j] > 0 && arr[i][j] <= size){
                	cont++;
                }
            }
		}
		if(cont == size*size){
			cont = 0;
		}
		printf("\nContinue: 1\nUndo: 2\nExit: 3\nyour choice: ");
		scanf("%d", &temp);
		while(temp != 1 && temp != 2 && temp != 3){
			printf("wrong command please re-enter: ");
			scanf("%d", &temp);
		}
		if(temp == 2){
			for(i = 0 ; i < size ; i++){
				for(j = 0 ; j < size ; j++){
					arr[i][j] = tempMatrix[i][j];
				}
			}
			drawBoard(arr, size);
			
		}
		else if(temp == 1){
			
		}
		else if(temp ==3){
			break;
		}
        
    }while(cont != 0);
    
    
    for(i = 0 ; i < size ; i++){
		for(j = 0 ; j < size ; j++){
			arr[i][j] = main_matris[i][j];
		}
	}

}
