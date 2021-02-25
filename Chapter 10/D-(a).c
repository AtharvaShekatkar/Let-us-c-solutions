/*
Create a structure to specify data on students given below:
Roll number, Name, Department, Course, Year of joining
Assume that there are not more than 450 students in the collage.
(a) Write a function to print names of all students who joined in a particular year.
(b) Write a function to print the data of a student whose roll number is given.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 450

//structure declaration and definition
struct student{     
    int roll;
    char *name, *depart, *course;
    int year;
};

void print_same_year(struct student *);
void print_data(struct student *);

int main(){
    struct student s[MAX];
    char n[50];
    for(int i = 0; i < MAX; i++){
        printf("Enter name of student: ");
        fgets(n, 50, stdin);
        n[strlen(n) - 1] = 0;
        s[i].name = (char*) malloc(strlen(n) * sizeof(char));   //dynamically allocates memory for strings so that space is not wasted
        strcpy(s[i].name, n);
        
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll);
        getchar();

        printf("Enter Department name: ");
        fgets(n, 50, stdin);
        n[strlen(n) - 1] = 0;
        s[i].depart = (char*) malloc(strlen(n) * sizeof(char));       //dynamically allocates memory for strings so that space is not wasted
        strcpy(s[i].depart, n);

        printf("Enter Course name: ");
        fgets(n, 50, stdin);
        n[strlen(n) - 1] = 0;
        s[i].course = (char*) malloc(strlen(n) * sizeof(char));       //dynamically allocates memory for strings so that space is not wasted
        strcpy(s[i].course, n);

        printf("Enter Year of joining: ");
        scanf("%d", &s[i].year);
        getchar();
    }

    print_same_year(s);       //function calls
    print_data(s);
}

void print_same_year(struct student *s){
    int req_year;
    printf("Enter the year of admission: ");
    scanf("%d", &req_year);

    printf("The students admitted in year %d are: \n", req_year);
    int count;
    for(int i = 0; i < MAX; i++){
        if(s[i].year == req_year){        //checks if the student was admitted in the given year
            printf("%s\n", s[i].name);
            count++;
        }
    }
    
    //checks if atleast one student was admitted in the given year
    if(!count){       
        printf("Sorry! Record shows that no students were admitted in the year %d", req_year);
    }
}

void print_data(struct student *s){
    int req_roll;
    
    printf("Enter roll no. of student: ");
    scanf("%d", &req_roll);
    int flag = 0;
    for(int i = 0; i < MAX; i++){
        
        //checks if the given roll number matches with any student 
        if(req_roll == s[i].roll){
            flag = 1;
            printf("Recorded data of the student with roll no. %d: \n", req_roll);
            printf("Name: %s\n", s[i].name);
            printf("Department: %s\n", s[i].depart);
            printf("Course: %s\n", s[i].course);
            printf("Year of joining: %d\n", s[i].year);
            break;
        }
    }
    
    //checks if any student was found
    if(flag == 0){
        printf("No student havning roll no. %d", req_roll);
    }
}
    
