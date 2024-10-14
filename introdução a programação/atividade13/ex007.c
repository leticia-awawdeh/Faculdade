#include <stdio.h>
#include <ctype.h> 
#include <string.h>

int main() {
    char sentence[100]; 
    int i;

    printf("Digite uma frase: ");
    fgets(sentence, sizeof(sentence), stdin); 
    sentence[strcspn(sentence, "\n")] = '\0'; 

   
    if (sentence[0] >= 'a' && sentence[0] <= 'z') {
        sentence[0] = toupper(sentence[0]);
    }

    for (i = 1; sentence[i]; i++) {
        if (sentence[i-1] == ' ' && sentence[i] >= 'a' && sentence[i] <= 'z') {
            sentence[i] = toupper(sentence[i]);
        }
    }

    printf("sentence modificada: %s\n", sentence);

    return 0;
}
