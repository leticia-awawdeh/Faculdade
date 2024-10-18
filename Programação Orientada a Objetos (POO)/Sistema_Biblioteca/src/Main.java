import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Biblioteca biblioteca = new Biblioteca();
        Scanner scanner = new Scanner(System.in);
        int opcao = -1;

        while (opcao != 0) {
            exibirMenu();
            try {
                opcao = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                opcao = -1;
            }

            switch (opcao) {
                case 1:
                    cadastrarLivro(biblioteca, scanner);
                    break;
                case 2:
                    listarLivros(biblioteca);
                    break;
                case 3:
                    excluirLivro(biblioteca, scanner);
                    break;
                case 4:
                    cadastrarUsuario(biblioteca, scanner);
                    break;
                case 5:
                    listarUsuarios(biblioteca);
                    break;
                case 6:
                    editarUsuario(biblioteca, scanner);
                    break;
                case 7:
                    excluirUsuario(biblioteca, scanner);
                    break;
                case 8:
                    emprestarLivro(biblioteca, scanner);
                    break;
                case 9:
                    devolverLivro(biblioteca, scanner);
                    break;
                case 10:
                    listarEmprestimos(biblioteca);
                    break;
                case 11:
                    consultarPorUsuario(biblioteca, scanner);
                    break;
                case 12:
                    consultarPorLivro(biblioteca, scanner);
                    break;
                case 0:
                    System.out.println("Encerrando o sistema. Até mais!");
                    break;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }

        scanner.close();
    }

    private static void exibirMenu() {
        System.out.println("\n=== Sistema de Gestão de Biblioteca ===");
        System.out.println("1. Adicionar Livro");
        System.out.println("2. Listar Livros");
        System.out.println("3. Excluir Livro");
        System.out.println("4. Adicionar Usuário");
        System.out.println("5. Listar Usuários");
        System.out.println("6. Editar Usuário");
        System.out.println("7. Excluir Usuário");
        System.out.println("8. Emprestar Livro");
        System.out.println("9. Devolver Livro");
        System.out.println("10. Listar Empréstimos");
        System.out.println("11. Consultar Empréstimos por Usuário");
        System.out.println("12. Consultar Empréstimos por Livro");
        System.out.println("0. Sair");
        System.out.print("Escolha uma opção: ");
    }

    // Métodos Auxiliares para cada Opção do Menu
    private static void cadastrarLivro(Biblioteca biblioteca, Scanner scanner) {
        System.out.print("Título: ");
        String titulo = scanner.nextLine();
        System.out.print("Autor: ");
        String autor = scanner.nextLine();
        System.out.print("Ano de Publicação: ");
        int ano = Integer.parseInt(scanner.nextLine());
        System.out.print("ISBN: ");
        String isbn = scanner.nextLine();

        Livro livro = new Livro(titulo, autor, ano, isbn);
        biblioteca.adicionarLivro(livro);
    }

    private static void listarLivros(Biblioteca biblioteca) {
        System.out.println("\n--- Lista de Livros ---");
        biblioteca.listarLivros();
    }

    private static void excluirLivro(Biblioteca biblioteca, Scanner scanner) {
        System.out.print("ISBN do livro a ser excluído: ");
        String isbn = scanner.nextLine();
        biblioteca.excluirLivro(isbn);
    }

    private static void cadastrarUsuario(Biblioteca biblioteca, Scanner scanner) {
        System.out.print("Nome: ");
        String nome = scanner.nextLine();
        System.out.print("Matrícula: ");
        String matricula = scanner.nextLine();
        System.out.print("Telefone: ");
        String telefone = scanner.nextLine();

        Usuario usuario = new Usuario(nome, matricula, telefone);
        biblioteca.adicionarUsuario(usuario);
    }

    private static void listarUsuarios(Biblioteca biblioteca) {
        System.out.println("\n--- Lista de Usuários ---");
        biblioteca.listarUsuarios();
    }

    private static void editarUsuario(Biblioteca biblioteca, Scanner scanner) {
        System.out.print("Matrícula do usuário a ser editado: ");
        String matricula = scanner.nextLine();
        System.out.print("Novo Nome: ");
        String nome = scanner.nextLine();
        System.out.print("Novo Telefone: ");
        String telefone = scanner.nextLine();

        biblioteca.editarUsuario(matricula, nome, telefone);
    }

    private static void excluirUsuario(Biblioteca biblioteca, Scanner scanner) {
        System.out.print("Matrícula do usuário a ser excluído: ");
        String matricula = scanner.nextLine();
        biblioteca.excluirUsuario(matricula);
    }

    private static void emprestarLivro(Biblioteca biblioteca, Scanner scanner) {
        System.out.print("ISBN do livro a ser emprestado: ");
        String isbn = scanner.nextLine();
        System.out.print("Matrícula do usuário: ");
        String matricula = scanner.nextLine();
        biblioteca.emprestarLivro(isbn, matricula);
    }

    private static void devolverLivro(Biblioteca biblioteca, Scanner scanner) {
        System.out.print("ISBN do livro a ser devolvido: ");
        String isbn = scanner.nextLine();
        System.out.print("Matrícula do usuário: ");
        String matricula = scanner.nextLine();
        biblioteca.devolverLivro(isbn, matricula);
    }

    private static void listarEmprestimos(Biblioteca biblioteca) {
        System.out.println("\n--- Lista de Empréstimos ---");
        biblioteca.listarEmprestimos();
    }

    private static void consultarPorUsuario(Biblioteca biblioteca, Scanner scanner) {
        System.out.print("Matrícula do usuário: ");
        String matricula = scanner.nextLine();
        biblioteca.consultarPorUsuario(matricula);
    }

    private static void consultarPorLivro(Biblioteca biblioteca, Scanner scanner) {
        System.out.print("ISBN do livro: ");
        String isbn = scanner.nextLine();
        biblioteca.consultarPorLivro(isbn);
    }
}
