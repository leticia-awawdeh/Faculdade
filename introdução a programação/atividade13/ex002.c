#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_SIZE 100

char* splitIntoWords(char* sentence, char words[MAX_WORDS][MAX_SIZE], int* numWords) {
    char* token = strtok(sentence, " ");
    *numWords = 0;

    while (token != NULL && *numWords < MAX_WORDS) {
        strcpy(words[*numWords], token);
        (*numWords)++;
        token = strtok(NULL, " ");
    }

    return sentence;
}

int main() {
    char sentence1[MAX_SIZE], sentence2[MAX_SIZE];
    char words1[MAX_WORDS][MAX_SIZE], words2[MAX_WORDS][MAX_SIZE];
    int numWords1 = 0, numWords2 = 0;
    int i;

    printf("Digite a primeira frase: ");
    fgets(sentence1, sizeof(sentence1), stdin);
    sentence1[strcspn(sentence1, "\n")] = '\0'; 

    printf("Digite a segunda frase: ");
    fgets(sentence2, sizeof(sentence2), stdin);
    sentence2[strcspn(sentence2, "\n")] = '\0'; 

    splitIntoWords(sentence1, words1, &numWords1);
    splitIntoWords(sentence2, words2, &numWords2);

    printf("Frase combinada: ");

    for (i = 0; i < numWords1 || i < numWords2; i++) {
        if (i < numWords1) {
            printf("%s ", words1[i]);
        }
        if (i < numWords2) {
            printf("%s ", words2[i]);
        }
    }

    printf("\n");

    return 0;
}
