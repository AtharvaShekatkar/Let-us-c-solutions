/*A record contains name of cricketer, his age, number of test matches that he has played and the average runs that he has scored in each test match.
Create an array of structure to hold records of 20 such cricketer and then write a program to read these records and arrange them in ascending order by average runs. 
Use the qusort( ) standard library function.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20      

//structure definition
struct cricket{
    char *name;
    int age, test;
    float avg;
};

int comparator(const void *, const void *);
void print(struct cricket *);

int main(){
    struct cricket c1[MAX];
  
    //getting the information about cricketers
    for(int i = 0; i < MAX; i++){
        char n[25];
        printf("Enter Name of cricketer: ");
        fgets(n, 25, stdin);
        n[strlen(n) - 1] = 0;
        c1[i].name = (char *) malloc(sizeof(char) * strlen(n));
        strcpy(c1[i].name, n);

        printf("Enter age of cricketer: ");
        scanf("%d", &c1[i].age);

        printf("Enter number of test matches played by the player: ");
        scanf("%d", &c1[i].test);

        printf("Enter the avg score for test matches: ");
        scanf("%f", &c1[i].avg);
        getchar();
    }

    qsort((void *)c1, MAX, sizeof(struct cricket), comparator);   //function call

    //printing the sorted average runs
    for(int i = 0; i < MAX; i++){         
        printf("%0.2f\n", c1[i].avg);
    }

    return 0;
}

//comparison function for qsort()
int comparator(const void *p, const void *q){
    const struct cricket *elem1 = (struct cricket *)p;
    const struct cricket *elem2 = (struct cricket *)q;
    return((elem1 -> avg > elem2 -> avg) - (elem1 -> avg < elem2 -> avg));
}
