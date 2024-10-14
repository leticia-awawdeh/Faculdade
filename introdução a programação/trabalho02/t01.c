#include <stdio.h>

//Define constante do número de salários
#define NUM_EMPLOYEES 5

/*carrega dados dos funcionários a partir da entrada. 
Solicita ao usuário que insira o código, salário e anos de serviço para cada funcionário 
armazena os valores nos arrays correspondentes.*/
void loadVectors(int codes[], float salaries[], int years[]) {

        //Um loop é usado para iterar sobre cada posição dos vetores, correspondendo a cada funcionário.
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
       
        /*O número do funcionário é indicado por (i + 1), pois os índices dos vetores começam em 0,
        mas queremos mostrar ao usuário uma contagem começando em 1 para facilitar o entendimento.*/
        printf("Digite o código do funcionário n°%d: ", i + 1);
        scanf("%d", &codes[i]);

        printf("Digite o salário do funcionário n°%d: ", i + 1);
        scanf("%f", &salaries[i]);

        printf("Digite o anos de serviço do funcionário n°%d: ", i + 1);
        scanf("%d", &years[i]);
    }
}


//A função recebe três parâmetros: um vetor de salários, um vetor de códigos de funcionários e um valor de referência
void reportBySalary(float salaries[], int codes[], float amount) {
    int found = 0;

    //Imprime o cabeçalho para os funcionários com salário até o valor especificado.
    printf("Funcionários com salário até %.2f:\n", amount);

    //Loop para percorrer todos os funcionários.
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        //Verifica se o salário do funcionário atual é menor ou igual ao valor de referência.
        if (salaries[i] <= amount) {
            //Se verdadeiro, imprime o código e o salário do funcionário.
            printf("Código: %d, Salário: %.2f\n", codes[i], salaries[i]);
            //Atualiza a variável
            found = 1;
        }
    }

    //Se nenhum funcionário foi encontrado na primeira busca
    if (!found) {
        printf("Não foi encontrado nenhum funcionário.\n");
    }

    //Reinicia a variável
    found = 0;

    //Imprime o cabeçalho para os funcionários com salário acima do valor especificado.
    printf("Funcionários com salário superior a %.2f:\n", amount);

    //Novo loop para percorrer todos os funcionários novamente.
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        //Verifica se o salário do funcionário atual é maior que o valor de referência.
        if (salaries[i] > amount) {
            //Se verdadeiro, imprime o código e o salário do funcionário.
            printf("Código: %d, Salário: %.2f\n", codes[i], salaries[i]);
            //Atualiza a variável 'found' para indicar que pelo menos um funcionário foi encontrado.
            found = 1;
        }
    }

    //Se nenhum funcionário foi encontrado na segunda busca
    if (!found) {
        printf("Nenhum funcionário encontrado.\n");
    }
}


/*Encontra o salário mais baixo entre todos os funcionários 
mostra os códigos dos funcionários que têm o salário mínimo
informa quantos funcionários têm esse salário mínimo.*/
void findLowestSalary(float salaries[], int codes[]) {
    // Inicializa a variável lowestSalary com o primeiro salário da lista.
    float lowestSalary = salaries[0];

    /*Loop para percorrer todos os salários, começando do segundo elemento (índice 1),
    pois o primeiro já foi utilizado para inicializar lowestSalary.*/
    for (int i = 1; i < NUM_EMPLOYEES; i++) {
        //Compara o salário atual com o salário mais baixo encontrado
        if (salaries[i] < lowestSalary) {
            //Se o salário atual for menor, atualiza o valor de lowestSalary.
            lowestSalary = salaries[i];
        }
    }

    //Inicializa uma contagem para os funcionários que têm o salário mais baixo.
    int count = 0;

    //Imprime o salário mais baixo encontrado.
    printf("Funcionários com salário mais baixo (%.2f):\n", lowestSalary);

    //Novo loop para percorrer todos os funcionários novamente.
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        //Verifica se o salário do funcionário atual corresponde ao salário mais baixo encontrado.
        if (salaries[i] == lowestSalary) {
            //Se sim, imprime o código do funcionário.
            printf("Código: %d\n", codes[i]);
            //Incrementa a contagem de funcionários com o salário mais baixo.
            count++;
        }
    }

    //Imprime o número total de funcionários que têm o salário mais baixo.
    printf("Número de funcionários com o salário mais baixo: %d\n", count);
}



//um vetor para armazenar os códigos dos funcionários isentos e um ponteiro para contar quantos funcionários são isentos.
void generateExemptVector(int codes[], float salaries[], int years[], int exemptCodes[], int *exemptCount) {
    //Inicializa a contagem de funcionários isentos como 0.
    *exemptCount = 0;

    //Loop para percorrer todos os funcionários.
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        //Verifica se o funcionário atual atende aos critérios de isenção:
        if (years[i] >= 2 && years[i] <= 4 && salaries[i] < 1500.0) {
            //Se o funcionário atender aos critérios, seu código é adicionado ao vetor de isentos.
            exemptCodes[*exemptCount] = codes[i];
            //Incrementa a contagem de funcionários isentos.
            (*exemptCount)++;
        }
    }

    //Verifica se algum funcionário foi encontrado como isento.
    if (*exemptCount == 0) {
        //Se nenhum funcionário atender aos critérios, imprime uma mensagem informando isso.
        printf("Nenhum funcionário atende aos critérios de isenção.\n");
    } else {
        // Se houver funcionários isentos, imprime os códigos desses funcionários.
        printf("Códigos de funcionários isentos:\n");
        for (int i = 0; i < *exemptCount; i++) {
            printf("Código: %d\n", exemptCodes[i]);
        }
    }
}

int main() {
    /* Declaração dos vetores para armazenar os códigos, salários e anos de serviço dos funcionários e
    um vetor para armazenar os códigos dos funcionários que atendem aos critérios de isenção.*/
    int codes[NUM_EMPLOYEES];
    float salaries[NUM_EMPLOYEES];
    int years[NUM_EMPLOYEES];
    int exemptCodes[NUM_EMPLOYEES];

    //Variável para contar quantos funcionários são isentos.
    int exemptCount;

    //Chama a função loadVectors para preencher os vetores com os dados dos funcionários inseridos pelo usuário.
    loadVectors(codes, salaries, years);

    //Declaração de uma variável para armazenar o valor do salário que será consultado.
    float amount;

    //Solicita ao usuário que insira o valor do salário a ser consultado.
    printf("Informe o valor do salário a ser consultado: ");
    scanf("%f", &amount);

    //Chama a função reportBySalary para gerar um relatório dos funcionários com base no valor do salário inserido.
    reportBySalary(salaries, codes, amount);

    //Chama a função findLowestSalary para identificar e listar os funcionários com o salário mais baixo.
    findLowestSalary(salaries, codes);

    /*Chama a função generateExemptVector para identificar os funcionários que atendem aos critérios de isenção,
    armazenando seus códigos no vetor exemptCodes e atualizando a contagem de funcionários isentos em exemptCount.*/
    generateExemptVector(codes, salaries, years, exemptCodes, &exemptCount);

    return 0;
}
