/*
Unlike a stack, in a queue the addition of new element takes place at the end (called ‘rear’ of queue) whereas deletion takes place at the other end (called ‘front’ of queue). 
Write a program to implement a queue using a linked list.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *rear = NULL;
node *front = NULL;

void create_queue();
void display();
void del_queue();
void del_elem();
void add();
void isEmpty();

int main(){
    int choice;
    while(1){
        printf("\n\nMain Menu\n\n");
        printf("1. Create queue\n");
        printf("2. Add an element\n");
        printf("3. Remove an element\n");
        printf("4. Display queue\n");
        printf("5. Delete queue\n");
        printf("6. Check if queue is empty\n");
        printf("7. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create_queue();
                break;
            case 2:
                add();
                break;
            case 3:
                del_elem();
                break;
            case 4:
                display();
                break;
            case 5:
                del_queue();
                break;
            case 6:
                isEmpty();
                break;
            case 7:
                exit(0);
            default:
                printf("Enter a valid option!\n");
        }
    }
}

void create_queue(){
    char c;
    do{
        add();
        printf("Enter another element? (y/n): ");
        getchar();
        scanf("%c", &c);
    }while(c == 'y' || c == 'Y');
}

void add(){
    node *new_node;
    int num;
    printf("Enter data: ");
    scanf("%d", &num);

    new_node = (node*) malloc(sizeof(node));
    new_node -> data = num;
    if(rear == NULL){
        rear = new_node;
        front = new_node;
    }
    else{
        rear -> next = new_node;
        rear = new_node;
    }

    new_node -> next = NULL;
}

void del_elem(){
    if(front != NULL){    
        node *ptr;
        ptr = front;
        front = ptr -> next;
        printf("The deleted element is: %d\n", ptr -> data);
        free(ptr);
        if(front == NULL)
            rear = NULL;
    }
    else
        printf("Queue is empty!\n");
}

void del_queue(){
    if(front != NULL){    
        while(front != NULL)
            del_elem();
        rear = NULL;
    }

    else
        printf("Queue is already empty!\n");
}

void isEmpty(){
    if(front == NULL)
        printf("Queue is empty!\n\n");
    else
        printf("Queue is not empty!\n\n");
}

void display(){
    if(front != NULL){    
        node *ptr;
        ptr = front;
        while(ptr != NULL){
            printf("%d\t", ptr -> data);
            ptr = ptr -> next;
        }
    }

    else
        printf("Queue is empty!\n");
}
