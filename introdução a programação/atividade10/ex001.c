#include <stdio.h>

int main() {
    int array[10];
    int countPairs = 0; 
   
    printf("Digite 10 números inteiros:\n");
    for(int i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
        
        
        if(array[i] % 2 == 0) {
            countPairs++;
        }
    }

    
    printf("Você digitou %d números pares", countPairs);

    return 0;
}
