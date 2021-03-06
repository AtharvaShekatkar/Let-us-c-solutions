/*
Write a program to encrypt/decrypt a file using:
An offset cipher: In an offset cipher each character from the source file is offset with a fixed value and then written to the target file.
For example, if character read from the source file is ‘A’, then convert this into a new character by offsetting ‘A’ by a fixed value,
say 128, and then writing the new character to the target file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OFF 32

int main(){
    
    FILE *fs, *ft;
    fs = fopen("new.c", "r");

    if(fs == NULL){
        printf("Cannot open source file");
        exit(0);
    }

    ft = fopen("structs_prac.c", "w");

    if(ft == NULL){
        printf("Cannot open target file");
        exit(0);
    }

    char ch;
    while(!feof(fs)){
        ch = fgetc(fs);
        ch += OFF;
        fputc(ch, ft);
    }
    
    fclose(fs);
    fclose(ft);
    return 0;
}
