#include <stdio.h>
#include <string.h>


void reverseString(char* str) {
    int start = 0;
    int end = strlen(str) - 1;
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
    char frase[1024];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

   
    frase[strcspn(frase, "\n")] = '\0';

    reverseString(frase);

    printf("Frase invertida: %s\n", frase);

    return 0;
}
