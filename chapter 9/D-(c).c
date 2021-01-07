#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<strings.h>
void xlowercase(char *, const char *);
int main(void){
    char s[30], t[30] = {'\0'};
    printf("Enter a string in lowercase: ");
    fgets(s, 30, stdin);
    xlowercase(t, s);
    printf("The uppercase string is: %s\n", t);
}
void xlowercase(char *target, const char *source){
    while(*source != '\n'){
        if(*source == 32)
            *target = *source;
        
        else
            *target = *source - ('a' - 'A');

        source++;
        target++; 
    }
}
