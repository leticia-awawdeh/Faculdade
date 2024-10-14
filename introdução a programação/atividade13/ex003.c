#include <stdio.h>
#include <string.h>

void reverseAndReplace(char* str) {
    int start = 0, end = strlen(str) - 1;
    char temp;

    
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    for (int i = 0; str[i]; i++) {
        if (str[i] == 'A' || str[i] == 'a') {
            str[i] = '*';
        }
    }
}

int main() {
    char sentence1[100], sentence2[100];

    printf("Digite a primeira frase: ");
    fgets(sentence1, sizeof(sentence1), stdin);
    sentence1[strcspn(sentence1, "\n")] = '\0'; 

    printf("Digite a segunda frase: ");
    fgets(sentence2, sizeof(sentence2), stdin);
    sentence2[strcspn(sentence2, "\n")] = '\0';

    inverteEsubstitui(sentence1);
    inverteEsubstitui(sentence2);

    printf("Saída da frase 1: ", sentence1);
    printf("Saída da frase 2: %s\n", sentence2);

    return 0;
}
