#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char username[20];
	char email[40];
	char phoneNumber[12];
	char password[20];
	
} Data;
    Data inputData(void){
	Data items;
	printf("Input username     :");
    fgets(items.username, sizeof(items.username), stdin);
	printf("Input email        :");
    fgets(items.email, sizeof(items.email), stdin);
	printf("Input phone number :");
    fgets(items.phoneNumber, sizeof(items.phoneNumber), stdin);
	printf("Input password     :");
    fgets(items.password, sizeof(items.password), stdin);
	return items;
}
void output(Data items){
	printf("username    :%s\n",items.username);
	printf("email       :%s\n",items.email);
	printf("phone number:%s\n",items.phoneNumber);
	// printf("password    :%s\n",items.password);
}
int main(){
	int option;
	FILE *account_data;
	int n,i;
	do{
	    printf("\n\n\n");
	    printf("\033[0;36m \t ########     ###    ##    ## ##    ##    ##     ##    ###    ##    ##    ###     ######   ######## ##     ## ######## ##    ## ######## \033[0m\n");
	    printf("\033[0;36m \t ##     ##   ## ##   ###   ## ##   ##     ###   ###   ## ##   ###   ##   ## ##   ##    ##  ##       ###   ### ##       ###   ##    ##    \033[0m\n");
	    printf("\033[0;36m \t ##     ##  ##   ##  ####  ## ##  ##      #### ####  ##   ##  ####  ##  ##   ##  ##        ##       #### #### ##       ####  ##    ##    \033[0m\n");
	    printf("\033[0;36m \t ########  ##     ## ## ## ## #####       ## ### ## ##     ## ## ## ## ##     ## ##   #### ######   ## ### ## ######   ## ## ##    ##    \033[0m\n");
	    printf("\033[0;36m \t ##     ## ######### ##  #### ##  ##      ##     ## ######### ##  #### ######### ##    ##  ##       ##     ## ##       ##  ####    ##    \033[0m\n");
	    printf("\033[0;36m \t ##     ## ##     ## ##   ### ##   ##     ##     ## ##     ## ##   ### ##     ## ##    ##  ##       ##     ## ##       ##   ###    ##    \033[0m\n");
	    printf("\033[0;36m \t ########  ##     ## ##    ## ##    ##    ##     ## ##     ## ##    ## ##     ##  ######   ######## ##     ## ######## ##    ##    ##    \033[0m\n");
	    printf("\n\n\n");
	    printf("1. Create Acoount \n");
	    printf("2. Login Account\n");
	    printf("Option [0] to exits : ");
	    scanf("%d" , &option); 

        while (getchar() != '\n'); //Clear input buffer

    	switch(option){
    		case 1:{
			   	printf("Input user :");
                scanf("%d",&n);
                
                while (getchar() != '\n');  // Clear input buffer
                
				account_data=fopen("account_data.txt","w");
				Data user[20];
				if(account_data==NULL){
					printf("Error!");
					return 0;
				}
				for(i=0;i<n;i++){
					printf("========>User[%d]<===========\n",i+1);
					user[i]=inputData();
				}
			
				for (i = 0; i < n; i++) {
			        fwrite(&user[i], sizeof(Data), 1, account_data); // Write each object to file
			    }
				fclose(account_data);
				account_data=fopen("account_data.txt","r");
                
				Data temp;
			    while (fread(&temp, sizeof(temp), 1, account_data)) {
			        output(temp);
			    }
			
			}break;
			case 2:{
				
				
			}break;
		}
	}while(option != 0);
	return 0;
}
