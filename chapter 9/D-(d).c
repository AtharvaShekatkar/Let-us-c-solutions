#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void xcpy(char *, const char *, int, int);
int main(void){
    char s[100], t[100] = {0};
    int num, pos;
    printf("Enter a string: ");
    fgets(s, 100, stdin);
    printf("Enter the position from which the string is to be extracted: ");
    scanf("%d", &pos);
    printf("Enter the number of characters to be extracted(0 for all characters from specified position): ");
    scanf("%d", &num);
    xcpy(t, s, num, pos - 1);               //passing (pos - 1) because positions would start from 1 for the user
    printf("The target is: %s\n", t);
}
void xcpy(char *target, const char *source, int num, int pos){
    char *end;
    source = source + pos;        //setting the address to the position from which string is to be copied
    if(num == 0)              //checking if entire string is to be copied
        end = (char*) source + strlen(source) - 1;          //storing address of second last character of string as last would be '\n'
    else
        end = (char*) source + num;               //storing address of last character to be copied
    while(source != end){
        *target = *source;
        source++;
        target++;
    }
}
