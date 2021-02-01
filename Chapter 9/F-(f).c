/*A factory has 3 division and stocks 4 categories of products. An inventory table is updated for each division and for each product as they are received. There are three independent suppliers of products to the factory:
(a) Design a data format to represent each transaction.
(b) Write a program to take a transaction and update the inventory.
(c) If the cost per item is also given write a program to calculate the total inventory values.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void print(char (*)[5][10]);
void record(char (*)[5][10]);
void findprice(char (*)[5][10]);

int main(void){
    system("cls");
    char table[][5][10] = {             //initializing the table
        {
            "",
            "Cat 1",
            "Cat 2",
            "Cat 3",
            "Cat 4"
        },
        {
            "Div 1",
            "0",
            "0",
            "0",
            "0"
        },
        {
            "Div 2",
            "0",
            "0",
            "0",
            "0"
        },
        {
            "Div 3",
            "0",
            "0",
            "0",
            "0"
        }
    };


    while(1){                           //infinite loop for menu driven program
        int choice;
        printf("1. View Supply Sheet\n");
        printf("2. Record New Shipment\n");
        printf("3. Total price of products of a category in a division\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){                               //switch case for a menu
            case 1:
                printf("\n\nPrinting Supply Table:\n\n");
                print(table);
                break;
            case 2:
                record(table);
                break;
            case 3:
                findprice(table);
                break;
            case 4:
                printf("\n\nFinal Supply Sheet for this session: \n\n");
                print(table);
                printf("\n\nThank you for using our system!!\n\n");
                exit(0);
        }
        
    }
    
    return 0;
}

void record(char (*table)[5][10]){                              //updates the values of products for given category and division
    int sup, prod, div, cat;

    printf("\n\nNew Record: ");
    
    printf("\n\nEnter supplier number: ");
    scanf("%d", &sup);
    printf("Enter number of products supplied in current transaction: ");
    scanf("%d", &prod);
    printf("Enter category of products: ");
    scanf("%d", &cat);
    printf("Enter division to be stored in: ");
    scanf("%d", &div);
    
    if(cat >=1 && cat <=4 && div >= 1 && div <= 3){               //checks if correct category and division number are entered
        int total = atoi(table[div][cat]);                    //converts string to int
        total += prod;
        itoa(total, table[div][cat], 10);                   //converts int back to string

        printf("\n\nInformation Recorded Successfully!\n\n");
        printf("Log:\n\n");
        printf("Supplier %d supplied %d products of Category %d in Division %d.\n\n", sup, prod, cat, div);
    }

    else{                                                                 //displays error if category or division number is not correct
        printf("Invalid Category/Division Number entered! Entry not successful!\n");
        printf("Please try again!");
        
    }
    
    printf("Press enter to continue\n");
    getchar();
    getchar();
    system("cls");
}

void print(char (*table)[5][10]){             //prints the supply sheet
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            printf("%s\t\t", table[i][j]);
        }
        printf("\n\n");
    }

    printf("Press enter to continue\n");
    getchar();
    getchar();
    system("cls");
}

void findprice(char (*table)[5][10]){                   //finds the total cost of products for a given category and division when price per item is given
    int cat, div, cost;
    printf("Enter the Category of products: ");
    scanf("%d", &cat);
    printf("Enter the Division of products: ");
    scanf("%d", &div);
    printf("Enter cost per item: ");
    scanf("%d", &cost);

    cost *= atoi(table[div][cat]);
    printf("\n\nThe total cost of products of Category %d in Division %d is: %d\n\n", cat, div, cost);
    printf("Press enter to continue\n");
    getchar();
    getchar();
    system("cls");
}
