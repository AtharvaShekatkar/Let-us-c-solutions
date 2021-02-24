//Write a program that takes a set of names of individuals and abbreviates the first, middle and other names except the last name by their first letter.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void abbreviate(const char *,const char *,const char *, char *);

int main(){
    char n[25];

    printf("Enter first name: ");
    fgets(n, 25, stdin);
    n[strlen(n) - 1] = 0;

    char *first = (char *) malloc(strlen(n) * sizeof(char));
    strcpy(first, n);

    printf("Enter middle name: ");
    fgets(n, 25, stdin);
    n[strlen(n) - 1] = 0;

    char *mid = (char *) malloc(strlen(n) * sizeof(char));
    strcpy(mid, n);
    
    printf("Enter last name: ");
    fgets(n, 25, stdin);

    char *last = (char *) malloc(strlen(n) * sizeof(char));
    strcpy(last, n);

    char *abbreviation = (char *) malloc(strlen(last) + 6);

    abbreviate(first, mid, last, abbreviation);

    printf("Abbreviated name is: %s", abbreviation);
    return 0;
}

void abbreviate(const char *first,const char *mid,const char *last,char *ab){
    *ab = *first;
    *(++ab) = '.';
    *(++ab) = ' ';

    *(++ab) = *mid;
    *(++ab) = '.';
    *(++ab) = ' ';
    ab++;

    strcpy(ab, last);
}
