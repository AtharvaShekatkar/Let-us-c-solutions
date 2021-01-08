//Write a program that replaces two or more consecutive blanks in a string by a single blank. For example, if the input is
//Grim      return    to   the   planet   of    apes!!
//the output should be
//Grim return to the planet of apes!!

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void remove_wspace(char *, const char *);
int main(void){
    char source[100], target[100] = {0};
    printf("Enter a string: ");
    fgets(source, 100, stdin);          //getting string from user
    remove_wspace(target, source);      //calling the function
    printf("Given string after removing extra white spaces is: %s", target);          //printing string after removing extra whitespaces
    return 0;
}

void remove_wspace(char *t, const char *s){
    while(*s != '\0'){
        if((*(s + 1) == ' ') && (*s == ' ')){       //checking if current as well as next character in the string is a whitespace
            s++;            
            continue;
        }
        *t = *s;
        s++;
        t++;
    }
}
