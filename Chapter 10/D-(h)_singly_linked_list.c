/*Linked list is a very common data structure often used to store similar data in memory. 
While the elements of an array occupy contiguous memory locations, those of a linked list are not constrained to be stored in adjacent location.
The individual elements are stored “somewhere” in memory, rather like a family dispersed, but still bound together.
The order of the elements is maintained by explicit links between them.
Thus, a linked list is a collection of elements called nodes, each of which stores two item of information—an element of the list, and a link,
i.e., a pointer or an address that indicates explicitly the location of the node containing the successor of this list element.
Write a program to build a linked list by adding new nodes at the beginning, at the end or in the middle of the linked list.
Also write a function display( ) which display all the nodes present in the linked list.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *start = NULL;

node* createll(node *);
void display(node *);
void add_end(node *);
node* add_beg(node *);
node* add_before(node *);
node* add_after(node *);
node* del_beg(node *);
node* del_end(node *);
node* del_given(node *);
node* del_after(node *);
node* del_ll(node *);
void sortll(node *);


int main(){
    int choice;
    while(1){
        
        printf("1. Create a list and enter data\n");
        printf("2. Add a node at the end\n");
        printf("3. Add a node at the beginning\n");
        printf("4. Add a node before a given node\n");
        printf("5. Add a node after a given node\n");
        printf("6. Delete a node from the beginning\n");
        printf("7. Delete a node from the end\n");
        printf("8. Delete a given node\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire list\n");
        printf("11. Sort the list\n");
        printf("12. Display the list\n");
        printf("13. Exit\n\n");
        
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                start = createll(start);
                printf("Linked List Created!\n");
                break;
            case 2:
                add_end(start);
                break;

            case 3:
                start = add_beg(start);
                break;
            case 4:
                start = add_before(start);
                break;
            case 5:
                start = add_after(start);
                break;
            case 6:
                start = del_beg(start);
                break;
            case 7:
                start = del_end(start);
                break;
            case 8:
                start = del_given(start);
                break;
            case 9:
                start = del_after(start);
                break;
            case 10:
                start = del_ll(start);
                break;
            case 11:
                sortll(start);
                break;
            case 12:
                display(start);
                break;
            case 13:
                exit(0);
                
        }
    }
}

node* createll(node *start){
    node *new_node;
    int num;
    printf("Enter data: ");
    scanf("%d", &num);
    getchar();

    new_node = (node *) malloc(sizeof(node));
    new_node -> data = num;
    start = new_node;
    new_node -> next = NULL;
    
    char c;
    printf("Add another element?(y/n): ");
    scanf("%c", &c);
    getchar();
    while(c == 'y' || c == 'Y'){
        add_end(start);
        getchar();
        printf("Add another element?(y/n): ");
        scanf("%c", &c);
    }
    return start;
}

void add_end(node *start){
    if(start != NULL){    
        node *ptr, *new_node;
        ptr = start;

        int num;
        printf("Enter data: ");
        scanf("%d", &num);

        new_node = (node *) malloc(sizeof(node));
        new_node -> data = num;
        new_node -> next = NULL;

        while(ptr -> next != NULL){
            ptr = ptr -> next;
        } 

        ptr -> next = new_node;
    }

    else
        printf("List is empty! Create a list first!\n\n");

}

void display(node *start){
    if(start != NULL){    
        node *ptr;
        ptr = start;
        while(ptr != NULL){
            printf("%d\t", ptr -> data);
            ptr = ptr -> next;
        }

        printf("\n");
    }
    
    else
        printf("List is empty!\n\n");
}

node* add_beg(node *start){
    if(start != NULL){    
        node *new_node;
        int num;
        printf("Enter data: ");
        scanf("%d", &num);
        new_node = (node *) malloc(sizeof(node));
        new_node -> data = num;
        new_node -> next = start;
        start = new_node;
    }

    else
        printf("List is empty! Create a list first!\n\n");
    
    return start;
}

node* add_before(node *start){

    if(start != NULL){    
        node *new_node, *ptr, *preptr;
        int num, val;

        printf("Enter the value before which you want to add another node: ");
        scanf("%d", &val);

        ptr = start;
        if(ptr -> data == val){
            start = add_beg(start);
            return start;
        }
        
        printf("Enter data: ");
        scanf("%d", &num);
        new_node = (node *) malloc(sizeof(node));
        new_node -> data = num;


        while(ptr -> data != val){
            preptr = ptr;
            ptr = ptr -> next;
        }

        preptr -> next = new_node;
        new_node -> next = ptr;
    }
    else
        printf("List is empty! Create a list first!\n\n");
    
    return start;
}

node *add_after(node *start){
    if(start != NULL){    
        node *new_node, *ptr;
        ptr = start;
        int num, val;

        printf("Enter value after which given data is to be added: ");
        scanf("%d", &val);

        printf("Enter data: ");
        scanf("%d", &num);

        new_node = (node *) malloc(sizeof(node));
        new_node -> data = num;

        while(ptr -> data != val && ptr != NULL){
            ptr = ptr -> next;
        }

        if(ptr != NULL){
            node *temp = ptr -> next;
            ptr -> next = new_node;
            new_node -> next = temp;
        }

        else
            printf("Value not found!\n\n");
    }
    else
        printf("List is empty! Create a list first!\n\n");

    return start;
}

node *del_beg(node *start){
    if(start != NULL){
        node *ptr;
        ptr = start;
        start = start -> next;

        printf("The deleted element is: %d\n\n", ptr -> data);
        free(ptr);
    }
    else
        printf("List is empty!\n");

    return start;
}

node* del_end(node *start){
    
    if(start != NULL){   
        node *ptr;
        ptr = start;

        if(ptr -> next == NULL){
            start = del_beg(start);
            return start;
        }
        
        node *preptr;
        preptr = ptr;
        while(ptr -> next != NULL){
            preptr = ptr;
            ptr = ptr -> next;
        }

        preptr -> next = NULL;
        printf("The deleted element is: %d\n\n", ptr -> data);
        free(ptr);
    }

    else
        printf("List is empty!\n\n");
        
    return start;
}

node *del_given(node *start){
    if(start != NULL){
        
        int val;
        printf("Enter the value has to be deleted: ");
        scanf("%d", &val);

        if(start -> data == val)
            start = del_beg(start);
        
        else{
            node *ptr, *preptr;
            ptr = start;
            preptr = ptr;
            while(ptr -> data != val && ptr != NULL){
                preptr = ptr;
                ptr = ptr -> next;
            }
            if(ptr != NULL){    
                preptr -> next = ptr -> next;
                printf("The deleted element is: %d\n\n", ptr -> data);
                free(ptr);
            }
            else
                printf("No such value found!\n\n");
        }
    }
    else
        printf("List is empty!\n\n");
    
    return start;
} 

node *del_after(node *start){
    
    if(start != NULL){    
        node *ptr, *preptr;
        
        int val;
        printf("Enter value after which node has to be deleted: ");
        scanf("%d", &val);
        
        ptr = start;
        while(ptr -> data != val && ptr -> next != NULL)
            ptr = ptr -> next;

        if(ptr -> next != NULL && ptr -> data == val){
            preptr = ptr;
            ptr = ptr -> next;
            preptr -> next = ptr -> next;
            printf("The deleted element is: %d\n\n", ptr -> data);
            free(ptr);
        }
        else if(ptr -> next == NULL && ptr -> data == val)
            printf("No node present after given value!\n\n");
        else
            printf("No value found!\n\n");
    }

    else
        printf("List is empty!\n\n");

    return start;
}

node *del_ll(node *start){
    if(start != NULL){
        node *ptr;
        ptr = start -> next;
        start = NULL;
        while(ptr != NULL){
            node *temp;
            temp = ptr -> next;
            free(ptr);
            ptr = temp;
        }
    }

    else
        printf("List is already empty!\n\n");
    
    return start;
}

void sortll(node *start){
    if(start != NULL){    
        node *ptr1, *ptr2;
        ptr1 = start;
        while(ptr1 -> next != NULL){
            ptr2 = ptr1 -> next;
            while(ptr2 != NULL){
                if(ptr1 -> data > ptr2 -> data){
                    int temp = ptr1 -> data;
                    ptr1 -> data = ptr2 -> data;
                    ptr2 -> data = temp;
                }
                ptr2 = ptr2 -> next;
            }
            ptr1 = ptr1 -> next;
        }
    }

    else
        printf("List is empty!\n\n");
}
