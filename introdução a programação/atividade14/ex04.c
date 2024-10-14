#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    char sexo;
    char cpf[14];
    char dataNascimento[11]; 
    int codigoSetor;
    char cargo[31]; // String de até 30 caracteres + '\0'
    float salary;
} Funcionario;

void lerDados(Funcionario *func) {
    printf("Digite o nome do funcionario: ");
    fgets(func->nome, sizeof(func->nome), stdin);
    
    printf("Digite a idade do funcionario: ");
    scanf("%d", &func->idade);
    getchar(); // Limpa o buffer do teclado
    
    printf("Digite o sexo do funcionario (M/F): ");
    scanf("%c", &func->sexo);
    getchar(); // Limpa o buffer do teclado
    
    printf("Digite o CPF do funcionario: ");
    fgets(func->cpf, sizeof(func->cpf), stdin);
    
    printf("Digite a data de nascimento do funcionario (DD/MM/AAAA): ");
    fgets(func->dataNascimento, sizeof(func->dataNascimento), stdin);
    
    printf("Digite o codigo do setor onde o funcionario trabalha: ");
    scanf("%d", &func->codigoSetor);
    getchar(); // Limpa o buffer do teclado
    
    printf("Digite o cargo do funcionario: ");
    fgets(func->cargo, sizeof(func->cargo), stdin);
    
    printf("Digite o salary do funcionario: ");
    scanf("%f", &func->salary);
}

void exibirDados(const Funcionario *func) {
    printf("\nNome: %s", func->nome);
    printf("Idade: %d\n", func->idade);
    printf("Sexo: %c\n", func->sexo);
    printf("CPF: %s", func->cpf);
    printf("Data de Nascimento: %s", func->dataNascimento);
    printf("Codigo do Setor: %d\n", func->codigoSetor);
    printf("Cargo: %s", func->cargo);
    printf("Salário: %.2f\n", func->salary);
}

int main() {
    Funcionario func;
    
    lerDados(&func);
    exibirDados(&func);
    
    return 0;
}
