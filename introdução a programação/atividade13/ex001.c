#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char phrase[100];
    int j, count = 0;

    printf("Digite uma frase: ");
    fgets(phrase, sizeof(phrase), stdin);

    phrase[strcspn(phrase, "\n")] = '\0';

    for (int i = 0; phrase[i]; i++){
        phrase[i] = tolower((unsigned char) phrase[i]);
    }

    for (int i = 0; i <= strlen(phrase) - 4; i++){
        for( j = 0; j < 4; j++){
            if(phrase[i + j] != "aula"[j]) break;

        }
        if (j == 4) count++;
    }

    printf("A palavra 'AULA' aparece %d vez(es) na frase. \n", count);


    return 0;
}