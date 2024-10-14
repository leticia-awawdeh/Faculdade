#include <stdio.h>
#include <limits.h>

int main() {
    int array[10];
    int higherNumber = INT_MIN;
    int lowestNumber = INT_MAX;

    printf("Digite 10 números inteiros: \n");

    for(int i; i < 10; i++){
    scanf("%d", &array[i]);
        if(array[i] > higherNumber){
            higherNumber = array[i];
        }
        if (array[i] < lowestNumber){
           lowestNumber = array[i]; 
        }
        
    }
    
    printf("%d é o maior número\n", higherNumber);
    printf("%d é o menor número\n", lowestNumber);

}