//Write a program to reverse the strings stored in an array of pointers to strings
//Hint: Write a function xstrrev ( string ) which should reverse the contents of one string. Call this function for reversing each string stored in s.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void xstrrev(char *);

int main(){
    char **lines = (char **) malloc(sizeof(char **));             //allocating memory to store pointer to one line in array of pointers to strings 
    int i = 0;
    char c;
    
    do{
        if(i >= 1)
            realloc(lines, sizeof(char **) * (i + 1));        //reallocating memory to store pointer for one more line in array of pointers to strings
        
        char n[50];
        
        printf("Enter a line: ");
        fgets(n, 50, stdin);                                        //getting line from user
        n[strlen(n) - 1] = '\0';
        
        char *p = (char *) malloc(strlen(n) + 1);                   //allocating memory to store the entered line in the array of pointers to strings
        strcpy(p, n);                                               //copying entered line in the character pointer

        xstrrev(p);                                                  //reverses entered line

        lines[i] = p;                                             //stores pointer to reversed line in array of pointer to strings 
        
        i++;
        
        printf("Do you want to enter another line? (y/n): ");
        scanf("%c", &c);                                                //checks if another line needs to be entered
        getchar();

    }while(c == 'y');

    int num = i;
 
    printf("\n\nThe reversed lines are: \n\n");                   
    
    for(i = 0; i < num; i++)                                      //prints reversed lines one by one
        printf("%s\n\n", lines[i]);
       
    return 0;
    
}

void xstrrev(char *str){
    char temp;
    
    for(int i = 0; i < strlen(str) / 2; i++){             //swaps each character till it reaches half of the length of the entered line 
        
        temp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp;
    }
}
