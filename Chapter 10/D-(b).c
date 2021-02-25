/*
Create a structure to specify data of customers in a bank. The data to be stored is: Account number, Name, Balance in account. Assume maximum of 200 customers in the bank.
(a) Write a function to print the Account number and name of each customer with balance below Rs. 100.
(b) If a customer request for withdrawal or deposit, it is given in the form:
Acct. no, amount, code (1 for deposit, 0 for withdrawal)
Write a program to give a message, “The balance is insufficient for the specified withdrawal”.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 200

struct account{
    long long int acno;
    char *name;
    long int bal;
};

void printinfo(struct account *);
void with_or_dep(struct account *);

int main(){
    struct account a[MAX];
    char n[25];
    for(int i = 0; i < MAX; i++){
        printf("Enter Account No.: ");
        scanf("%lld", &a[i].acno);
        getchar();

        printf("Enter Name of Account Holder: ");
        fgets(n, 25, stdin);
        n[strlen(n) - 1] = 0;
        a[i].name = (char*) malloc(sizeof(char) * strlen(n));     //dynamically allocates memory to save space
        strcpy(a[i].name, n);

        printf("Enter Account Balance: ");
        scanf("%ld", &a[i].bal);
    }
    printinfo(a);         //function calls
    with_or_dep(a);
    return 0;
}

void printinfo(struct account *a){
    int thresh;
    printf("Enter the threshold amount: ");
    scanf("%d", &thresh);
    int count = 0;
    for(int i = 0; i < MAX; i++){
      
        //checks if the given balance is below the threshold amount and if it is, then it prints the account number and name of account holder
        if(a[i].bal < thresh){                          
            printf("%lld\t%s\n", a[i].acno, a[i].name);
            count++;
        }
    }
    
    //checks if atleast one person's details were printed
    if(!count)
        printf("No users found with balance below %d!\n", thresh);
}

void with_or_dep(struct account *a){
    short int choice;
    long long int anum;
    long int amt;
    printf("Enter the Account number: ");
    scanf("%lld", &anum);
    printf("Enter the amount to be deposited or withdrawn: ");
    scanf("%ld", &amt);
    printf("Do you wish to withdraw or deposit amount?\n");
    printf("Enter 1 for deposit, 0 for withdrawal: ");
    scanf("%hi", &choice);
    
    int i;
    for(i = 0; i < MAX; i++){
        //gets the required account's position in the array
        if(a[i].acno == anum)
            break;
    }

    //checks if account was found
    if(i == MAX){
        printf("Account not found!\n");
        return;
    }
    else{
        
        //checks for withdrawal or deposit 
        if(choice){
            a[i].bal += amt;
            printf("New amount in your balance is: %ld\n", a[i].bal);
        }
        else{
             
            //checks if there is enough amount to be withdrawn in the account
            if(a[i].bal < amt){
                printf("Not enough money in account to withdraw given amount!\n");
            }
            else{
                a[i].bal -= amt;
                printf("New amount in your balance is: %ld\n", a[i].bal);
            }
        }
    }
} 
