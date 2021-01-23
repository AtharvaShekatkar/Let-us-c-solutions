//Write a program to sort a set of names stored in an array in alphabetical order.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void alphabetical(char **, int);
int main(){
    
    char c;
    char *p, n[21];
    int i = 0;
    char **names = (char **)malloc(sizeof(char**));         //allocating memory to create an array of pointers to strings
    do{
        if(i >= 1){
            realloc(names, sizeof(char**) * (i + 1));           //reallocates memory if another name must be stored
        }
        printf("Enter a name: ");
        fgets(n, 21, stdin);
        n[strlen(n) - 1] = '\0';                //deletes the newline character
    
        p = (char *) malloc(strlen(n) + 1);       
        strcpy(p, n);
        names[i] = p;                   //stores address to string (name) in array

        i++;
        
        printf("Do you want to enter another name(y/n): ");       //checks if user wants to enter another name
        scanf("%c", &c);
        getchar();
    
    }while(c == 'y');
    
    int num = i;
    
    alphabetical(names, num);
    
    printf("\n\n");
    printf("The alphabetically sorted list of names is:\n");
    
    for(int i = 0; i < num; i++)                //prints the sorted list of names 
        printf("%s\n", names[i]);
    
    free(names);
    free(p);
}

void alphabetical(char **names, int num){
    for(int i = 1; i < num; i++){
        
        char *key = names[i];
        int j = i - 1;
        int k = 0;
       
        while(j >= 0 && names[j][k] >= key[k]){     //insertion sort
            if(names[j][k] == key[k]){          //if current letter is same, it points to next letter
                k++;
                continue;
            }
            
            names[j + 1] = names[j];
            j--;
            k = 0;                      //goes back to pointing to first letter after comparison of two names upto n same letters is done
        }
        
        names[j + 1] = key;
    }
}
