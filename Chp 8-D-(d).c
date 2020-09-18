//Implement sieve of Eratothenes for first 100 numbers
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int arr[100], i, key, j;
    for(i = 0; i <= 99; i++){
        arr[i] = i + 1;
    }
    for(i = 1; i <= 99;i++){
        key = arr[i];
        for(j = i + key; (j <= 99) && (key != 0); j += key){              //iterations only occur if the element isn't 0
            arr[j] = 0;           //making all multiples of prime numbers 0
        }
    }
    for (i = 1; i < 100; i++)
        printf("%d\n", arr[i]);
}
