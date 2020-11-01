//Write a program to obtain transpose of a 4 x 4 matrix. The transpose of a matrix is obtained by exchanging the elements of each row with the elements of the corresponding column.
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
void findtranspose(int (*)[5], int(*)[5]);
int main(){
    int a[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 32, 185, 25}
    };
    int trans[5][5];
    findtranspose(a, trans);
    int i, *p;
    p = trans[0];
    for(i = 0; i < 25; i++){
        printf("%d\t", *p);
        p++;
        if(i % 5 == 4)
            printf("\n");
    }
}
void findtranspose(int (*a)[5], int (*trans)[5]){
    int i, j;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            trans[j][i] = a[i][j];
        }
    }
}
