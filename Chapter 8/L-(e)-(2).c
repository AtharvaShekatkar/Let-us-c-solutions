//multiplication of a 3x3 matrix
#include<stdio.h>
#include<conio.h>
int main(){
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int b[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int c[3][3];
    int i, j, k, sum = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            sum = 0;
            for(k = 0; k < 3; k++){
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
    int *p = c[0];
    for(i = 0; i < 9; i++){
        printf("%d\t", *p);
        p++;
        if(i % 3 == 2)
            printf("\n");
    }
}
