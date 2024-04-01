#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <math.h>


typedef struct{
	char username[20];
	char email[40];
	char phoneNumber[12];
	char password[20];
	
} Data;

typedef struct{
	int money_dollars;
    int money_reils;
	int user_money_dollars;
	int user_money_reils; 
	
} money;

float readBalance(){
	FILE *file = fopen("User Money_dollars.txt", "r");
	float balance ; 
	fscanf(file , "%f", &balance); 
	fclose(file);
	return balance;
}


void writeBalance(float new_balance) {
	FILE *file = fopen("User Money_dollars.txt", "w");
    fprintf(file, "%.2f", new_balance); // Assuming balance is a float, "%.2f" is used to write only two decimal places
    fclose(file);
}

void deposits(float amount) {
    float balance = readBalance();
    balance += amount; // Add the deposited amount to the balance
    writeBalance(balance);
    printf("Deposit of %.2f $ completed.\nNew balance: %.2f $\n", amount, balance);
}

void withdraw(float amount) {
    float balance = readBalance();
    if (amount <= balance) {
        balance -= amount; // Subtract the withdrawn amount from the balance
        writeBalance(balance);
        printf("Withdrawal of %.2f $ completed. New balance: %.2f $\n", amount, balance);
    } else {
        printf("Insufficient funds!\n");
    }
}

void bankLoan() {
    float loanAmount, monthlyPayment, interestRate , totalPayment;
    int loanTerm;

    // Prompt user for loan details
    printf("Loan interest rate details : \n\n");
    printf("%-30s%-20s\n", "Loan Amount", "Interest rate");
	printf("--------------------------------------------\n");
    printf("%-30s%-20s\n", "Loans up to $10,000", "5%");
    printf("%-30s%-20s\n", "Loans up to $50,000", "4%");
    printf("%-30s%-20s\n", "Loans up to $100,000", "3.5%");
    printf("%-30s%-20s\n", "Loans up to $500,000", "3%");
    printf("%-30s%-20s\n", "Loans greater than $500,000", "2%");
	printf("--------------------------------------------\n");


    printf("Loan amount: $");
    scanf("%f", &loanAmount);

	if (loanAmount <= 10000) {
        interestRate = 0.05; // 5% interest rate for loans up to $10,000
    } else if (loanAmount <= 50000) {
        interestRate = 0.04; // 4% interest rate for loans up to $50,000
    } else if (loanAmount <= 100000) {
        interestRate = 0.035; // 3.5% interest rate for loans up to $100,000
    } else if (loanAmount <= 500000){
		interestRate = 0.03; //3% interest rate for loans up to $500000
	}else {
        interestRate = 0.02; // 3% interest rate for loans greater than $500000
    }

    printf("Loan term (months): ");
    scanf("%d", &loanTerm);

    // Convert annual interest rate to monthly
    float monthlyInterestRate = interestRate / 12.0;

    // Calculate monthly payment
    monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -loanTerm));

	totalPayment = monthlyPayment * loanTerm;

    // Display loan details
    printf("\nLoan Details:\n");
    printf("Loan Amount: $%.2f\n", loanAmount);
    printf("Interest Rate: %.2f%%\n", interestRate);
    printf("Loan Term: %d months\n", loanTerm);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
	printf("Loan amount including interest rate : $ %.2f\n\n" , totalPayment);

    // Simulate loan repayment
    float remainingLoanAmount = loanAmount;
    printf("\nLoan Repayment Schedule:\n");
    printf("Month\tRemaining Amount\n");
    for (int month = 1; month <= loanTerm; month++) {
        float interestPayment = remainingLoanAmount * monthlyInterestRate;
        float principalPayment = monthlyPayment - interestPayment;
        remainingLoanAmount -= principalPayment;
        printf("%d\t$%.2f\n", month, remainingLoanAmount);
    }
}
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
	printf("Username    :%s\n",items.username);
	printf("Email       :%s\n",items.email);
	printf("Phone number:%s\n",items.phoneNumber);
}

void createAccount() {
    int n, i;
    FILE *create_acc; // Declare file pointer locally
    printf("Input user :");
    scanf("%d", &n);
    create_acc = fopen("createAccount.txt", "w"); // Open file for writing
    Data user[20];
    if (create_acc == NULL) {
        printf("Error!");
    }
    for (i = 0; i < n; i++) {
        printf("========== User[%d] ========== \n", i + 1);
        user[i] = inputData();
    }

    for (i = 0; i < n; i++) {
        fwrite(&user[i], sizeof(Data), 1, create_acc); // Write each object to file
    }
    fclose(create_acc);
}
void loginAccount(){
	bool logins=false;
	int op;
	char username[20];
	char email[40];
	char phoneNumber[12];
	char password[20];
	Data login;
	FILE *create_acc; // Declare file pointer locally
	create_acc=fopen("createAccount.txt","r");
	printf("Input username     :");
    fgets(username, sizeof(username), stdin); //input data by using fgets (name of struct data , size of data , input)
	printf("Input email        :");
	fgets(email, sizeof(email), stdin);
	printf("Input phone number :");
	fgets(phoneNumber, sizeof(phoneNumber), stdin);
	printf("Input password     :");
	fgets(password, sizeof(password), stdin);
	while (fread(&login, sizeof(login),1, create_acc)) {
		if(strcmp(username,login.username)==0){
		    if(strcmp(email,login.email)==0){
		        if(strcmp(phoneNumber,login.phoneNumber)==0){
		        	if(strcmp(password,login.password)==0){
		        		logins=true;
						system("clear");
					}
				}
			}
						
		} 
	}
	if(strcmp(username,login.username)!=0){
		printf("Incorrect username\n");
	}
	if(strcmp(email,login.email)!=0){
		printf("Incorrect email\n");
	}
	if(strcmp(phoneNumber,login.phoneNumber)!=0){
		printf("Incorrect phone number\n");
	}
	if(strcmp(password,login.password)!=0){
		printf("Incorrect password\n");
	}
	if(logins==true){
			
			do{
				printf("\n=============== MENU ===============\n\n");
				printf("1. Deposit money\n");
				printf("2. Withdraw money\n");
				printf("0. Exit\n");
				printf("\n====================================\n\n");
				printf("Option : ");
				scanf("%d",&op); 
				switch(op){
					
					case 1:{
						
						int op;
						do{
							
							printf("\n=============== Deposit menu =============\n");
							printf("1. Deposit dollars\n");
							printf("2. Deposit reils\n");
						    printf("3. Exit\n");
							printf("\n==========================================\n\n");
							printf("Option : ");
							scanf("%d",&op); 
							
							switch(op){
								
								case 1:{							
									float deposit ; 
									printf("Amount of money want to deposit : ");
									scanf("%f" , &deposit);
									deposits(deposit);
									readBalance();				
														
									break;
								}
								case 2:{
									float withdrawAmount ; 
									printf("Amount of money want to withdraw : ");
									scanf("%f" , &withdrawAmount);
									withdraw(withdrawAmount);
									readBalance();	
									
									break;
								}
								default :{
									printf("Invalid option");
									break;
								}
									
							}
							
						}while(op!=3);				
					}break;
					
					
					case 2:{
						
						int op_withDraw;
						do{
						
							printf("\n======= Withdraw option =======\n\n");
							printf("1. Withdraw USD currency\n");
							printf("2. Withdraw Reils currency \n");
							printf("3. Exit\n");
							printf("\n==============================\n");
							printf("Choose option :");
							scanf("%d",&op_withDraw);
							
							switch(op_withDraw){
								
								case 1:{
									
									FILE *money_d;
									money withdraw;
									money_d = fopen("User Money_dollars.txt","r+");
									fscanf(money_d, "%d",&withdraw.user_money_dollars);
								    printf("Amount of USD in your bank account : %d $\n",withdraw.user_money_dollars);
								    if((money_d = fopen("User Money_dollars.txt","r")) != NULL){
									    printf("===== Withdraw USD =====\n");
										money_d = fopen("User Money_dollars.txt","a+");
										printf("Input USD to withdraw : ");
                                        scanf("%d",&withdraw.money_dollars);
							            withdraw.user_money_dollars -= withdraw.money_dollars;							            
							            printf("After withdraw : %d $\n",withdraw.user_money_dollars);
									    money_d = fopen("User Money_dollars.txt","w");
							            fprintf(money_d,"%d",withdraw.user_money_dollars);
							            
								    } else {
								        printf("Null \n");
								    }
								    
									fclose(money_d);
													
									break;
								}
								
								case 2:{
									
									FILE *money_r;
									money withdraw;
									money_r = fopen("User Money_reils.txt","r+");
									fscanf(money_r, "%d",&withdraw.user_money_reils);					    
								    printf("Money reils account : %d\n",withdraw.user_money_reils);
									
								    if((money_r = fopen("User Money_reils.txt","r")) != NULL){
								    	printf("===== Withdraw riels =====\n");
								    	money_r=fopen("User Money_reils.txt","a+");
								    	printf("Input money reils to withdraw : ");
                                        scanf("%d", &withdraw.money_reils);
					                	withdraw.user_money_reils -= withdraw.money_reils;					            
					                	printf("Sucessfully withdraw : %d\n",withdraw.user_money_reils);
					                	fprintf(money_r,"%d",withdraw.user_money_reils);
								        
								    } else {
								        printf("Null reils\n");
								    }
								    
									fclose(money_r);
									
									break;
								}
								default :{
									printf("Invalid option");
									break;
								}
								
							}
							
						}while(op_withDraw!=3);
								
					}break;
					
					
					case 3:{
								
					}break;
				}	
			}while(op!=0);
		}
		fclose(create_acc);
}

int main(){
		int option;
	    printf("\n\n\n");
	    printf("\033[0;36m \t ########     ###    ##    ## ##    ##    ##     ##    ###    ##    ##    ###     ######   ######## ##     ## ######## ##    ## ######## \033[0m\n");
	    printf("\033[0;36m \t ##     ##   ## ##   ###   ## ##   ##     ###   ###   ## ##   ###   ##   ## ##   ##    ##  ##       ###   ### ##       ###   ##    ##    \033[0m\n");
	    printf("\033[0;36m \t ##     ##  ##   ##  ####  ## ##  ##      #### ####  ##   ##  ####  ##  ##   ##  ##        ##       #### #### ##       ####  ##    ##    \033[0m\n");
	    printf("\033[0;36m \t ########  ##     ## ## ## ## #####       ## ### ## ##     ## ## ## ## ##     ## ##   #### ######   ## ### ## ######   ## ## ##    ##    \033[0m\n");
	    printf("\033[0;36m \t ##     ## ######### ##  #### ##  ##      ##     ## ######### ##  #### ######### ##    ##  ##       ##     ## ##       ##  ####    ##    \033[0m\n");
	    printf("\033[0;36m \t ##     ## ##     ## ##   ### ##   ##     ##     ## ##     ## ##   ### ##     ## ##    ##  ##       ##     ## ##       ##   ###    ##    \033[0m\n");
	    printf("\033[0;36m \t ########  ##     ## ##    ## ##    ##    ##     ## ##     ## ##    ## ##     ##  ######   ######## ##     ## ######## ##    ##    ##    \033[0m\n");
	    printf("\n\n\n");
	do{
		printf("\n=============== MENU =============\n");
	    printf("\n1. Create Acoount \n");
	    printf("2. Login Account\n");
	    printf("3. Bank loan\n");
	    printf("\n====================================\n");
	    printf("Option : ");
	    scanf("%d" , &option); 
    	switch(option){
    		case 1:{
			   createAccount();
			   break;
			};
			case 2:{
				loginAccount();
				break;
			};
			case 3: {
				bankLoan();
				break;
			}
		}
	}while(option!=0);
	return 0;
}	