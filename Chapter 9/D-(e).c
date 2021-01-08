//Write a program that converts a string like "124" to an integer 124.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int xatoi(char *);
int main(void){
    char s[10];
    int a;
    printf("Enter a number: ");
    fgets(s, 10, stdin);        //getting the string of numbers from user
    a = xatoi(s);
    printf("%d", a);
    return 0;
}

int xatoi(char *s){
    int num = 0;
    int sign = 1;
    if(s[0] == '-'){        //checking if number entered is negative
        sign = -1;
        s++;
    }

    while(*s != '\n'){                  //converting string to integer
        num = (num * 10) + (*s - '0');      
        s++;
    }
    return (sign * num);
}
