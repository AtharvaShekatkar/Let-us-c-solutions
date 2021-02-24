/*
A dequeue is an ordered set of elements in which elements may be inserted or retrieved from either end.
Using an array simulate a dequeue of characters and the operations retrieve left, retrieve right, insert left, insert right. 
Exceptional conditions such as dequeue full or empty should be indicated. 
Two pointers (namely, left and right) are needed in this simulation.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 50

void insert_left(void);
void insert_right(void);
int del_left(void);
int del_right(void);
void display(void);

char dequeue[MAX];
int left = -1, right = -1;

int main(){
    int op;
    char val;

    //infinite loop until user decides to quit
    while(1){
        printf("\n\n\n\t\t* Main Menu *\n\n\n");
        printf("1. Insert from left\n");
        printf("2. Insert from right\n");
        printf("3. Delete from left\n");
        printf("4. Delete from right\n");
        printf("5. Display Dequeue\n");
        printf("6. Exit\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &op);
        getchar();
      
        switch(op){
            case 1:
                insert_left();
                break;
            case 2:
                insert_right();
                break;
            case 3:
                val = del_left();
                if(val)
                    printf("The deleted character is: %c", val);
                break;
            case 4:
                val = del_right();
                if(val)
                    printf("The deleted character is: %c", val);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0); 
        }
    }
}

void insert_left(void){
    printf("\n\n\n\t\tInsertion from Left End\n\n");
    
    //Checks if dequeue is full
    if((left == 0 && right == MAX - 1) || left == right + 1){
        printf("Overflow! Delete some elements first!\n");
        return;
    }
    else{
        char val;
        printf("Enter element to be inserted: ");
        scanf("%c", &val);
        getchar();

        if(left == -1)
            left = right = 0;


        else if(left == 0)
            left = MAX - 1;
        
        else
            left--;
        
        dequeue[left] = val;
    }
}

void insert_right(void){
    printf("\n\n\t\tInsertion from Right End\n\n");
    
    //checks if dequeue is full
    if((right == left - 1) || (right == MAX - 1 && left == 0)){
        printf("Overflow! Delete some elements first!\n");
        return;
    }
    
    else{
        char val;
        printf("Enter element to be inserted: ");
        scanf("%c", &val);
        getchar();

        if(left == -1){
            left = right = 0;
        }
        else if(right == MAX - 1)
            right = 0;
        else
            right++;

        dequeue[right] = val;
    }
}

int del_left(void){

    //checks if dequeue is empty
    if(left == -1){
        printf("Underflow! Insert some elements first!\n");
        return 0;
    }
    
    char val = dequeue[left];
    
    //checks if last element is to be deleted
    if(left == right)
        left = right = -1;

    else if(left == MAX - 1)
        left = 0;
    else
        left++;

    return val;
}

int del_right(void){

    //checks if dequeue is empty
    if(left == - 1){
        printf("Underflow! Insert some elements first!\n");
        return 0;
    }
    
    char val = dequeue[right];

    //checks if last element is to be deleted
    if(left == right)
        left = right = -1;
    else if(right == 0)
        right = MAX - 1;
    else
        right--;
    
    return val;
}

void display(void){

    //checks if dequeue is empty
    if(left == -1){
        printf("Dequeue is empty!\n");
        return;
    }
    else if(left <= right){
        printf("The elements of the dequeue are:\n");
        for(int i = left; i <= right; i++){
            printf("%c  ", dequeue[i]);
        }
    }
    else{
        printf("The elements of the dequeue are:\n");
        for(int i = left; i < MAX ; i++){
            printf("%c  ", dequeue[i]);
        }
        for(int i = 0; i <= right; i++){
            printf("%c  ", dequeue[i]);
        }
    }
}
