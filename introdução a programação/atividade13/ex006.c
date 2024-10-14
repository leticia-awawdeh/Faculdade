#include <stdio.h>
#include <string.h>

void inverterString(char* str) {
    int start = 0, end = strlen(str) - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char sentence[100]; 
    char* word;
    char encryptedSentence[100] = ""; 

    printf("Digite uma frase: ");
    fgets(sentence, sizeof(sentence), stdin); 
    sentence[strcspn(sentence, "\n")] = '\0'; 

    
    word = strtok(sentence, " ");
    while (word != NULL) {
        inverterString(word);
        strcat(encryptedSentence, word);
        strcat(encryptedSentence, " "); 
        word = strtok(NULL, " ");
    }

    
    encryptedSentence[strlen(encryptedSentence) - 1] = '\0';

    printf("frase criptografada: %s\n", encryptedSentence);

    return 0;
}
