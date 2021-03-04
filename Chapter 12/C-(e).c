//Write a program to copy one file to another. While doing so replace all lowercase characters to their equivalent uppercase characters.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    char name[50];
    int age;
}student;

int main(){

    //declaring file pointers
    FILE *fs, *ft;

    fs = fopen("new.c", "r");
    //checking if source file was opened successfully
    if(fs == NULL){
        printf("Can't open source file");
        exit(0);
    }

    
    ft = fopen("structs_prac.c", "w");
    //checking if target file was opened successfully
    if(ft == NULL){
        printf("Can't open target file");
        exit(0);
    }

    
    char text[40];
  
    //copying content to target file from source file
    while(!feof(fs)){
        fgets(text, 40, fs);
        
        //loop for converting all lower case characters to upper case characters
        for(int i = 0; i < strlen(text); i++){
            if(text[i] >= 97 && text[i] <= 122)
                text[i] -= 32;
        }
            
        //copying all contents to target file
        fputs(text, ft);
    }
   
    //closing opened files
    fclose(fs);
    fclose(ft);
    return 0;
}
