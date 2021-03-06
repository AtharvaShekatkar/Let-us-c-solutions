/*
Write a program that merges lines alternately from two files and writes the results to new file. 
If one file has less number of lines than the other, the remaining lines from the larger file should be simply copied into the target file.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    char name[50];
    int age;
}student;

int main(){

    
    FILE *fs1, *fs2, *ft;

    fs1 = fopen("new.c", "r");
    if(fs1 == NULL){
        printf("Can't open source file1");
        exit(0);
    }

    fs2 = fopen("fileio.c", "r");
    if(fs2 == NULL){
        printf("Can't open source file2");
        exit(0);
    }

    ft = fopen("structs_prac.c", "w");
    if(ft == NULL){
        printf("Can't open target file");
        exit(0);
    }

    char text1[100], text2[100];
    int count = 0;
    while(!feof(fs1) || !feof(fs2)){
        if(!feof(fs1)){
            fgets(text1, 100, fs1);
            fputs(text1, ft);
        }
        if(!feof(fs2)){
            fgets(text2, 100, fs2);
            fputs(text2, ft);
        }
    }
    
    fclose(fs1);
    fclose(fs2);
    fclose(ft);
    return 0;
}
