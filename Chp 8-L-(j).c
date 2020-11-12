//Write a program that interchanges the odd and even components of an array.
#include<stdio.h>
#include<conio.h>
int main(){
    int n, i, temp;
    printf("Enter array length: ");
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++){         //getting array from user
        printf("Enter element number %d: ", i);
        scanf("%d", &a[i]);
    }
    int *p = a;
    for(i = 0; i < n; i += 2){      
        temp = *p;               //interchanging odd and even elements
        *p = *(p + 1);
        *(p + 1) = temp;
        p += 2;
    }
    for(i = 0; i < n; i++){
        printf("Element number %d is = %d\n", i, a[i]);
    }
}
