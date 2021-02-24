
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 80

int occurances(const char *, const char *);

int main(){
    char sentence[MAX];
    char vowels[] = "aeiouAEIOU";
    
    printf("Enter a sentence: ");
    fgets(sentence, MAX, stdin);

    printf("Number of occurances of two vowels in a succession is: %d", occurances(sentence, vowels));
    return 0;
}

int occurances(const char *s, const char *v){
    int count = 0, i = 0;
    int len = strlen(s) - 1;
    while(i != len){
        int count1 = 0, count2 = 0;
        int j = 0;
        while(v[j] != 0){
            if(*s == v[j] && count1 == 0){
                count1 = 1;
            }
            if(*(s + 1) == v[j] && count2 == 0){
                count2 = 1;
            }
            j++;
        }
        if(count1 == 1 && count2 == 1){
            count++;           
        }

        s++;
        i++;
    }
    return count;
}
