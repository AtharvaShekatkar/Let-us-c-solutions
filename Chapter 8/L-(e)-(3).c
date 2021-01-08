//Write a program to sort all the elements of a 4 x 4 matrix.
#include<stdio.h>
#include<conio.h>
int main(){
    int a[4][4] = {
        {1, 3, 4, 2},
        {8 , 7 , 6, 5},
        {11, 12, 9, 10},
        {200, 13, 15, 16}
    };
    int *p, *q;
    int i, j, key;
    for(i = 1; i < 16; i++){
        p = a[0] + i;
        q = p - 1;
        key = *p;       //using insertion sort
        for(j = 0; *q > temp && j < i; j++){
            *p = *q;
            q--;
            p--;
        }
        *(q + 1) = key;
    }
    p = a[0];
    for(i = 0; i < 16; i++){        //printing sorted array
        printf("%d\t", *p);
        p++;
        if(i % 4 == 3)
            printf("\n");
    }
}
