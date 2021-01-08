//Write a program to add two 6 x 6 matrices.
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

void add(int (*)[6], int(*)[6], int(*)[6]);
int main(){
    int a[6][6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };
    int b[6][6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };
    int c[6][6];
    add(a, b, c);
    int i, *p;
    p = c[0];
    for(i = 0; i < 25; i++){
        printf("%d\t", *p);
        p++;
        if(i % 5 == 4)
            printf("\n");
    }
}
void add(int (*a)[6], int (*b)[6], int (*c)[6]){
    int *p, *q, *r, i;
    p = a[0];
    q = b[0];
    r = c[0];
    for(i = 0; i < 36; i++){
        *r = *p + *q;
        r++;
        p++;
        q++;
    }
}
