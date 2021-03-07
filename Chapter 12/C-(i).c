/*
In the file ‘CUSTOMER.DAT’ there are 100 records with the following structure:

struct customer
{
int accno ;
char name[30] ;
float balance ;
} ;

In another file ‘TRANSACTIONS.DAT’ there are several records with the following structure:

struct trans
{
int accno ,
char trans_type ;float amount ;
} ;

The parameter trans_type contains D/W indicating deposit or withdrawal of amount. Write a program to update ‘CUSTOMER.DAT’ file, i.e.
if the trans_type is ‘D’ then update the balance of ‘CUSTOMER.DAT’ by adding amount to balance for the corresponding accno.
Similarly, if trans_type is ‘W’ then subtract the amount from balance.
However, while subtracting the amount make sure that the amount should not get overdrawn, i.e. at least 100 Rs. Should remain in the account.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct customers{
    int accno;
    char name[30];
    float balance;
}customers;

typedef struct transaction{
    int accno;
    char t_type;
    float amount;
}transaction;


int main(){
    customers c;
    transaction t;

    FILE *fcustomer, *ftransaction;
    ftransaction = fopen("transactions.dat", "rb");

    if(ftransaction == NULL){
        printf("Cannot open source file");
        exit(0);
    }

    fcustomer = fopen("customers.dat", "rb+");

    if(fcustomer == NULL){
        printf("Cannot open target file");
        exit(0);
    }

    int t_size = sizeof(t);
    int c_size = sizeof(c);

    while(fread(&t, t_size, 1, ftransaction)){
        
        fread(&c, c_size, 1, fcustomer);
        while(t.accno != c.accno && !feof(fcustomer))
            fread(&c.accno, sizeof(c), 1, fcustomer);
        
        if(feof(fcustomer) && t.accno != c.accno)
            printf("The account number %d is not found in record\n", c.accno);
        
        else if(t.t_type == 'w'){
            if(c.balance - t.amount > 100){
                c.balance -= t.amount;
                printf("%d updated successfully!\n", c.accno);
            }
            else
                printf("%d Not enough amount to be withdrawn\n");
        }
        else{
            c.balance += t.amount;
            printf("%d updated successfully!\n", c.accno);
        }

        fseek(fcustomer, -c_size, SEEK_CUR);
        fwrite(&c, c_size, 1, fcustomer);
        fseek(fcustomer, 0, SEEK_SET);
    }
    
    fclose(fcustomer);
    fclose(ftransaction);
    return 0;
}
