#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void replaceWord(char* sentence, const char* oldWord, const char* newWord) {
    char buffer[1024];
    char lowerSentence[1024]; 
    char lowerOldWord[1024];  


    strcpy(lowerSentence, sentence);
    toLowerCase(lowerSentence);
    strcpy(lowerOldWord, oldWord);
    toLowerCase(lowerOldWord);

    char *position = strstr(lowerSentence, lowerOldWord);
    while (position != NULL) {
        
        int offset = position - lowerSentence;
        
        memmove(sentence + offset, newWord, strlen(newWord));
        
        int newSentenceLength = strlen(sentence) - strlen(lowerOldWord) + strlen(newWord);
        sentence[newSentenceLength] = '\0'; 

        strcpy(lowerSentence, sentence);
        toLowerCase(lowerSentence);
        position = strstr(lowerSentence, lowerOldWord);
    }
}

int main() {
    char sentence[1024];

    printf("Digie uma frase: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    replaceWord(sentence, "ALUNO", "ESTUDANTE");
    replaceWord(sentence, "ESCOLA", "UNIVERSIDADE");

    printf("Frase alterada: %s\n", sentence);

    return 0;
}
