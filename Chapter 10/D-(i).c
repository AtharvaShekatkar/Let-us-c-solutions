/*
A stack is a data structure in which addition of new element or deletion of existing element always takes place at the same end. 
This end is often known as ‘top’ of stack. 
This situation can be compared to a stack of plates in a cafeteria where every new plate taken off the stack is also from the ‘top’ of the stack.
There are several application where stack can be put to use.
For example, recursion, keeping track of function calls, evaluation of expressions, etc.
Write a program to implement a stack using a linked list.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* create_stack(node *);
node* push(node *);
node* pop(node *);
void display(node *);
void isEmpty(node *);
node* delete_stack(node *);

node *top = NULL;
int main(){
    int choice;
    while(1){
        printf("\nMain Menu\n\n\n");
        printf("1. Create a stack\n");
        printf("2. Display stack\n");
        printf("3. Push an element on the stack\n");
        printf("4. Pop an element from the stack\n");
        printf("5. Check if stack is empty\n");
        printf("6. Delete Stack\n");
        printf("7. Exit\n\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                top = create_stack(top);
                printf("Stack created!!\n");
                break;
            case 2:
                display(top);
                break;
            case 3:
                top = push(top);
                if(top != NULL)
                    printf("Push operation successful!\n");
                break;
            case 4:
                top = pop(top);
                break;
            case 5:
                isEmpty(top);
                break;
            case 6:
                top = delete_stack(top);
                break;
            case 7:
                exit(0);

            default:
                printf("Enter a valid option!\n");

        }
    }
    return 0;
}

node* create_stack(node *top){
    node *new_node;
    int num;
    printf("Enter data: ");
    scanf("%d", &num);
    new_node = (node *) malloc(sizeof(node));
    new_node -> data = num;
    new_node -> next = NULL;
    top = new_node;

    char c;
    getchar();
    printf("Enter another element?(y/n): ");
    scanf("%c", &c);
    while(c == 'y' || c == 'Y'){
        top = push(top);
        getchar();
        printf("Enter another element?(y/n): ");
        scanf("%c", &c);
    }

    return top;
}

node* push(node *top){
    if(top != NULL){    
        node *new_node;
        int num;
        printf("Enter data: ");
        scanf("%d", &num);

        new_node = (node*) malloc(sizeof(node));
        new_node -> data = num;
        new_node -> next = top;
        top = new_node;
        
    }
    else
        printf("Stack is empty! Create stack first!\n");
    return top;
}

node* pop(node *top){
    if(top != NULL){    
        node *ptr;
        ptr = top;
        top = ptr -> next;
        printf("The popped element is: %d", ptr -> data);

        free(ptr);
    }

    else
        printf("Stack is empty!\n");
    
    return top;
}

void display(node *top){
    if(top != NULL){    
        node *ptr;
        ptr = top;
        while(ptr != NULL){
            printf("%d\t", ptr -> data);
            ptr = ptr -> next;
        }
    }

    else
        printf("Stack is empty!\n");
}

void isEmpty(node *top){
    if(top == NULL)
        printf("Stack is empty!\n");
    else
        printf("Stack is not empty!\n");
}

node* delete_stack(node *top){
    if(top != NULL){    
        node *ptr;
        ptr = top;
        while(ptr != NULL){
            node *temp;
            temp = ptr -> next;
            free(ptr);
            ptr = temp;
        }
    }

    else
        printf("Stack is already empty!\n");

    return NULL;
}
