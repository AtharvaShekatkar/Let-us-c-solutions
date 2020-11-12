//Write a program to find if a square matrix is symmetric.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
    int n, i, j, temp;
    printf("Enter array length: ");
    scanf("%d", &n);
    int a[n][n];
    for(i = 0; i < n; i++){       //getting array from user
        for(j = 0; j < n; j++){
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j)
                continue;
            if(a[i][j] != a[j][i]){         //checking if array is symmetric
                printf("Not symmetric\n");
                exit(0);
            }
        }
    }
    printf("Symmetric\n");
    return 0;
}
