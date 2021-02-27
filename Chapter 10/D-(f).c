/*
Write a menu driven program that depicts the working of a library. The menu options should be:
1. Add book information
2. Display book information
3. List all books of given author
4. List the title of specified book
5. List the count of books in the library
6. List the books in the order of accession number
7. Exit
Create a structure called library to hold accession number, title of the book, author name, price of the book, and flag indicating whether book is issued or not.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct library{
    int access;
    char *title, *auth;
    float price;
    int issued;
};

void add_book(struct library *);
void display_book(struct library *);
void list_auth(struct library *);
void list_title(struct library *);
int comparator(const void *, const void *);
int binarysearch(struct library *, int, int, int);

int count = 0;

int main(){
    int choice;
  
    //allocating space for 1 book first
    struct library *l = (struct library *) malloc(sizeof(struct library));
    
    //infinite loop until user decides to exit
    while(1){
        printf("\n\t\tMain Menu\n\n\n");
        printf("1. Add book information\n");
        printf("2. Display book information\n");
        printf("3. List all books of given author\n");
        printf("4. List the title of specified book\n");
        printf("5. List the count of books in the library\n");
        printf("6. List the books in the order of accession number\n");
        printf("7. Exit\n");
        printf("\nYour choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                count++;
                add_book(l);
                break;
            case 2:
                display_book(l);
                break;
            case 3:
                list_auth(l);
                break;
            case 4:
                list_title(l);
                break;
            case 5:
                printf("The number of books in the library is: %d\n", count);
                break;
            case 6:
                display_book(l);
                break;
            case 7: 
                exit(0);
        }
    }
}

void add_book(struct library *l){
    //checking if allocated space needs to be increased to hold another book
    if(count > 1)
        l = (struct library *) realloc(l, sizeof(struct library) * count);
    
  
    //getting the details of the book
    char n[50];
    printf("Enter title of book: ");
    fgets(n, 50, stdin);
    n[strlen(n) - 1] = 0;
    l[count - 1].title = (char *) malloc(strlen(n) * sizeof(char));
    strcpy(l[count - 1].title, n);

    printf("Enter accession number of the book: ");
    scanf("%d", &l[count - 1].access);
    getchar();

    printf("Enter name of the author: ");
    fgets(n, 50, stdin);
    n[strlen(n) - 1] = 0;
    l[count - 1].auth = (char *) malloc(strlen(n) * sizeof(char));
    strcpy(l[count - 1].auth, n);

    printf("Enter the price of the book: ");
    scanf("%f", &l[count - 1].price);

    printf("Is the book issued?(1 for yes, 0 for no): ");
    scanf("%d", &l[count - 1].issued);

    printf("\n\nThe book record has been updated!\n");
    
    //sorting the array of structures based on the accession number
    if(count > 1)
        qsort((void*) l, count, sizeof(struct library), comparator);
}


//displays all books in the library
void display_book(struct library *l){
    for(int i = 0; i < count; i++){
        printf("%d. Accession number: %d\n", i + 1, l[i].access);
        printf("Title: %s\n", l[i].title);
        printf("Author: %s\n", l[i].auth);
        printf("Price: %0.2f\n", l[i].price);
        if(l[i].issued)
            printf("Issued\n\n");
        else
            printf("Available\n\n");
    }
}

//displays all books in the library belonging to a given author
void list_auth(struct library *l){
    char searchauth[50];
    printf("Enter author name to be searched: ");
    fgets(searchauth, 50, stdin);
    searchauth[strlen(searchauth) - 1] = 0;

    for(int i = 0; i < count; i++){
        //checking if the entered author name and the author name of nth book is same
        if(strcmp(l[i].auth, searchauth) == 0){
            printf("%d. Accession number: %d\n", i + 1, l[i].access);
            printf("Title: %s\n", l[i].title);
            printf("Author: %s\n", l[i].auth);
            printf("Price: %0.2f\n", l[i].price);
            if(l[i].issued)
                printf("Issued\n\n");
            else
                printf("Available\n\n"); 
        }
    }
}



void list_title(struct library *l){
    //searching the array using the accession number
    int search_acc;
    printf("Enter accession number of book to be searched: ");
    scanf("%d", &search_acc);
    int pos = binarysearch(l, search_acc, 0, count - 1);
    if(pos == -1)
        printf("No book found!\n");
    else
        printf("Title of the required book is: %s\n", l[pos].title);
}


//comparison function for sorting using accession number
int comparator(const void *p, const void *q){
    struct library *elem1 = (struct library *)p;
    struct library *elem2 = (struct library *)q;
    return((elem1 -> access > elem2 -> access) - (elem1 -> access < elem2 -> access));
}

//binary search algorithm for searching using accession number
int binarysearch(struct library *l, int search_acc, int l1, int r){
    if(r >= l1){
        int mid = (l1 + r) / 2;
        if(l[mid].access == search_acc)
            return mid;
        
        if(l[mid].access > search_acc)
            return binarysearch(l, search_acc, l1, mid - 1);

        return binarysearch(l, search_acc, mid + 1, r);
    }
    
    return -1;
}
