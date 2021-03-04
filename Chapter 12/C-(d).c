//Suppose a file contains student’s records with each record containing name and age of a student. 
//Write a program to read these records and display them in sorted order by name.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    char name[50];
    int age;
}student;

int main(){
    
  
    //creating structure pointer and dynamically allocating memory as required
    student *s = (student *) malloc(sizeof(student));
    int count = 0;
    FILE *fs, *ft;

    //opening students.dat file as binary. if not available, it creates the file
    fs = fopen("students.dat", "wb+");
    if(fs == NULL){
        printf("Can't open source file");
        exit(0);
    }
  
    //getting all the name records
    char c;
    do{
        //reallocating memory as required
        if(count >= 1)
            s = (student*)realloc(s, sizeof(student) * (count + 1));
        
        printf("Enter name: ");
        fgets(s[count].name, 50, stdin);
        s[count].name[strlen(s[count].name) - 1] = 0;

        printf("Enter age: ");
        scanf("%d", &s[count].age);

        getchar();
        printf("\nEnter another record?(y/n): ");
        scanf("%c", &c);
        if(c == 'y' || c == 'Y')
            count++;
        getchar();
        
    }while(c == 'y' || c == 'Y');

    //sorting structure array by name
    for(int i = 0; i <= count; i++){
        int j = i + 1;
        int k = 0;
        while(j <= count){
            if(s[i].name[k] > s[j].name[k]){
                student temp;
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                k = 0;
            }

            else if(s[i].name[k] == s[j].name[k] && k < strlen(s[i].name) && k < strlen(s[j].name)){
                k++;
                continue;
            }
            j++;
        }
    }

  
    //writing the elements to the file
    for(int i = 0; i <= count; i++){
        fwrite(&s[i], sizeof(s[i]), 1, fs);
    }
   
    //closing the file
    fclose(fs);
    return 0;
}
