/*
Write a program that uses an array of pointers to strings str[ ]. 
Receive two strings str1 and str2 and check if str1 is embedded in any of the strings in str[ ]. 
If str1 is found, then replace it with str2.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void shiftforward(char *, int);
void shiftback(char *, int, int);
void change(char *, char *);


int main(){
    int i;
    char *str[] = {                   //initializing array of pointers to strings
        "We will teach you how to...",
        "Move a mountain",
        "Level a building",
        "Erase the past",
        "Make a million",
        "...all through C!"
    };
    char find[20], replace[20];
    char *p, *hay, *q;
    
    printf("Enter the phrase to find: ");       //getting phrase to find in str[]
    fgets(find, 20, stdin);
    find[strlen(find) - 1] = '\0';              //removing '\n'
    printf("Enter the phrase which is the replacement: ");      //getting replacement phase 
    fgets(replace, 20, stdin);
    replace[strlen(replace) - 1] = '\0';        //removing '\n'

    for(i = 0; i < 6; i++){
        hay = (char *) malloc(strlen(str[i]) + 1);        
        strcpy(hay, str[i]);              //copying each line to hay since string constants cannot be modified
        
        p = strstr(hay, find);          //searching for the phrase in a line
        if(p != NULL){
            int diff = strlen(replace) - strlen(find);      //checking if find and replacement phrases are of different lengths

            if(diff > 0){                               //if length of replacement phrase is greater, shift the string by the difference to right 
                realloc(hay, strlen(str[i]) + diff);
                
                shiftforward(p, diff);
            }
            
            else if(diff < 0){
                shiftback(p, strlen(replace), diff);      //if length of replacement phrase is greater, shift the string by the difference to left

                realloc(hay, strlen(hay));
            }
            
            change(replace, p);               //replace the found phrase with the replacement phrase

            str[i] = hay;
            
        }
        else
            free(hay);

    }

    for(i = 0; i < 6; i++)          //print the lines after the change
        printf("%s\n", str[i]);

}

void shiftforward(char *p, int diff){
    while(*p != ' ' && *p != '\0')          //find the point at which the word ends
        p++;
    p -= 1; 
    for(int i = diff; i > 0; i--){            //shift each element of string to the right n times where n = diff 
        char *q = p;
        q += strlen(p);
        for(;q != p; q--){
            *(q + 1) = *q;
        }
    }
}

void shiftback(char *p, int length, int diff){          
    int i = length;
    while(i > 0){           //find the point where the replacement length ends
        p++;
        i--;
    }
    for(i = (-diff); i > 0; i--){           //shift each element to left n times where n = -diff (since in this case difference is negative)
        char *q = p;
        while(*(q + 1) != '\0'){
            *q = *(q + 1);
            q++;
        }
        *q = '\0';                  
    }
}

void change(char *replace, char *p){
    while(*replace != 0){         //replace the found phrase with replacement phrase until replacement phrase ends
        *p = *replace;
        replace++;
        p++;
    }
}
