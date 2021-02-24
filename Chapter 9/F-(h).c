//Write a program to delete all vowels from a sentence. Assume that the sentence is not more than 80 characters long.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 80

void remove_vowels(const char *, char *, char *);
int main(){
    char sentence[MAX] = {0};
    char vowels[] = "aeiouAEIOU";   //for both capital and small letters
    printf("Enter a sentence: ");
    fgets(sentence, 80, stdin);
    
    char *new_sentence = (char *) malloc(strlen(sentence) * sizeof(char));
    
    remove_vowels(sentence, vowels, new_sentence);

    printf("Sentence with vowels: \n%s\n", sentence);
    printf("Sentence without vowewls: \n%s", new_sentence);
    return 0;
}

void remove_vowels(const char *sentence, char *vowels, char *new_sentence){
    //checks each character until the end of sentence
    while(*sentence != 0){
        int j = 0;
      
        //checks if the character is a vowel
        while(vowels[j] != 0){
            if(*sentence == vowels[j]){
                break;
            }
            j++;
        }
        
        if(vowels[j] != 0){
            sentence++;
            continue;
        }
        else{
            *new_sentence = *sentence;
            new_sentence++;
            sentence++;            
        }       
    }
}
