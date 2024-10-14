#include <stdio.h>

int main(){
    int options;

    printf("========================================\n");
    printf("================TRADUTOR================\n");
    printf("========================================\n");
    printf("selecione o idioma que deseja traduzir: \n");
    printf("1. Inglês\n");
    printf("2. Espanhol\n");
    printf("3. Alemão\n");
    printf("4. Francês\n");
    printf("5. Italiano\n");
    printf("6. Português\n");
    printf("7. Russo\n");
    printf("0. Sair\n");
    printf("========================================\n");
    printf(": ");
    scanf ("%d", &options);

    switch (options)
    {
    case 1:
        printf("Hello");
        break;
    case 2:
        printf("Hola");
        break;
    case 3:
        printf("Hallo");
        break;
    case 4:
        printf("Bonjour");
        break;
    case 5:
        printf("Ciao");
        break;
    case 6:
        printf("Olá");
        break;
    case 7:
        printf("привет");
        printf("privet");
        break;
    case 0:
        printf("Saindo...");
        break;
    
    default:
        printf("número inválido");
        break;
    }

    
    return 0;
}