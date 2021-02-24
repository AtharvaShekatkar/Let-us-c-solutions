//Circular Queue

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 10

//function prototype declaration
void qinsert(void);         
int qdel(void);
void qpeek(void);
void qprint(void);


int queue[MAX];
int front = -1, rear = -1;

int main(){
    int op, val;

    //infinite loop until user chooses to exit
    while(1){               
        printf("\n\n\n");    
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. View latest element\n");
        printf("4. View queue\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &op);
        printf("\n\n\n");

        switch(op){
            case 1:
                qinsert();
                break;
            case 2:
                val = qdel();
                if(val)
                    printf("The deleted element is: %d\n", val);
                break;
            case 3:
                qpeek();
                break;
            case 4:
                qprint();
                break;
            case 5:
                exit(0);
        }
    }
}

void qinsert(void){         
    int val;
    printf("\t\tElement Insertion\n\n");
    printf("Enter value to be inserted: ");
    scanf("%d", &val);

    //checks if queue is empty
    if(rear == -1 && front == -1){
        rear = front = 0;
        queue[rear] = val;
    }
    
    //checks for overflow
    else if((rear == MAX - 1 && front == 0) || (rear == front - 1)){
        printf("\nOverflow! Delete some elements first!\n");
    }
    
    else{
        //checks if rear has reached end of the queue
        if(rear == MAX - 1)
            rear = -1;
        rear++;
        queue[rear] = val;
    }
}

int qdel(void){
    int val;

    //checks if queue is empty
    if(front == -1 && rear == -1){
        printf("\nUnderflow! Enter some elements first!\n");
        return 0;
    }
    
    val = queue[front];     //deleted element
    
    //checks if front has reached end of the queue
    if(front == MAX - 1)
        front = 0;

    //checks if the last element is to be deleted
    else if(front == rear)
        front = rear = -1;

    else
        front++;
    
    return val;
}

void qpeek(void){

    //checks if queue is empty
    if(rear == -1 && front == -1){
        printf("Queue is empty!\n");
    }
    else
        printf("The latest element is: %d", queue[front]);
}

void qprint(void){

    //checks if queue is empty
    if(front == -1 && rear == -1){
        printf("Queue is empty!\n");
    }

    else{
        printf("From first to last positions the queue is:\n");
        if(front <= rear){
            for(int i = front; i <= rear; i++){
                printf("%d  ", queue[i]);
            }
        }
        
        else{
            for(int i = front; i < MAX; i++){
                printf("%d  ", queue[i]);
            }
            for(int i = 0; i <= rear; i++){
                printf("%d  ", queue[i]);
            }
        }
        
    }
}
