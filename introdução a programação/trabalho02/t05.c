#include <stdio.h>
#include <string.h>

// Define constantes para limites de cargos e funcionários.
#define NUM_CARGOS 5
#define NUM_FUNCIONARIOS 15

// Definição da estrutura Funcionario para armazenar informações básicas de um funcionário.
typedef struct {
    int codigo;          // Identificador único para cada funcionário.
    char nome[100];      // Armazena o nome completo do funcionário.
    int codigo_cargo;    // Indica qual cargo o funcionário ocupa.
} Funcionario;

// Array para armazenar os salários associados a cada cargo.
float salarios[NUM_CARGOS];

// Array para armazenar os objetos Funcionario, permitindo acessar informações de múltiplos funcionários.
Funcionario funcionarios[NUM_FUNCIONARIOS];

// Variável para rastrear quantos funcionários foram efetivamente cadastrados.
int num_funcionarios = 0;

// Função para validar se um código de funcionário já existe.
int validarNumeroFuncionario(int codigo) {
    // Verifica se o código do funcionário já está presente nos funcionários cadastrados.
    for (int i = 0; i < num_funcionarios; i++) {
        if (funcionarios[i].codigo == codigo) {
            return 0; // Retorna 0 se o código já existir.
        }
    }
    return 1; // Retorna 1 se o código não existir.
}

// Função para validar se o nome do funcionário é válido (contém pelo menos uma palavra).
int validarNome(char nome[]) {
    int palavras = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == ' ') {
            palavras++;
        }
    }
    return (palavras >= 1); // Retorna 1 se o nome tiver pelo menos uma palavra.
}

// Função para validar se o código do cargo é válido e se há salário associado a ele.
int validarCodigoCargo(int codigo_cargo) {
    return (codigo_cargo >= 1 && codigo_cargo <= NUM_CARGOS && salarios[codigo_cargo - 1] > 0);
}

// Função para cadastrar os salários dos cargos.
void cadastrarCargos() {
    for (int i = 0; i < NUM_CARGOS; i++) {
        printf("Digite o salário para o cargo %d: ", i + 1);
        scanf("%f", &salarios[i]);
    }
}

// Função para cadastrar um novo funcionário.
void cadastrarFuncionario() {
    // Verifica se o limite de funcionários foi alcançado.
    if (num_funcionarios >= NUM_FUNCIONARIOS) {
        printf("Limite de funcionários atingido.\n");
        return;
    }

    Funcionario novo;
    printf("Digite o código do funcionário: ");
    scanf("%d", &novo.codigo);
    if (!validarNumeroFuncionario(novo.codigo)) {
        printf("Código de funcionário já existente.\n");
        return;
    }

    printf("Digite o nome do funcionário: ");
    scanf(" %[^\n]", novo.nome);
    if (!validarNome(novo.nome)) {
        printf("Nome inválido. Insira nome e sobrenome.\n");
        return;
    }

    printf("Digite o código do cargo: ");
    scanf("%d", &novo.codigo_cargo);
    if (!validarCodigoCargo(novo.codigo_cargo)) {
        printf("Código de cargo inválido.\n");
        return;
    }

    funcionarios[num_funcionarios++] = novo;
}

// Função para exibir um relatório com informações de todos os funcionários.
void mostrarRelatorio() {
    for (int i = 0; i < num_funcionarios; i++) {
        printf("Código: %d, Nome: %s, Salário: R$ %.2f\n",
               funcionarios[i].codigo,
               funcionarios[i].nome,
               salarios[funcionarios[i].codigo_cargo - 1]);
    }
}

// Função para calcular e exibir o total pago a um cargo específico.
void mostrarTotalCargo(int codigo_cargo) {
    float total = 0;
    for (int i = 0; i < num_funcionarios; i++) {
        if (funcionarios[i].codigo_cargo == codigo_cargo) {
            total += salarios[codigo_cargo - 1];
        }
    }
    printf("Total pago ao cargo %d: R$ %.2f\n", codigo_cargo, total);
}

int main() {
    int opcao, cargo;
    do {
        printf("\n----------MENU---------\n");
        printf("\n-----------------------\n");
        printf("1. Cadastrar cargos\n");
        printf("2. Cadastrar funcionários\n");
        printf("3. Mostrar relatório\n");
        printf("4. Mostrar total por cargo\n");
        printf("5. Finalizar\n");
        printf("\n-----------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                cadastrarCargos();
                break;
            case 2:
                cadastrarFuncionario();
                break;
            case 3:
                mostrarRelatorio();
                break;
            case 4:
                printf("Digite o código do cargo (1 a 5): ");
                scanf("%d", &cargo);
                mostrarTotalCargo(cargo);
                break;
            case 5:
                printf("Finalizando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);
    return 0;
}
