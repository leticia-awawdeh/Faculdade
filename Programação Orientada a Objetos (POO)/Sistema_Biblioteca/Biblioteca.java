import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class Biblioteca {
    private List<Livro> livros;
    private List<Usuario> usuarios;
    private List<Emprestimo> emprestimos;

    public Biblioteca() {
        livros = new ArrayList<>();
        usuarios = new ArrayList<>();
        emprestimos = new ArrayList<>();
    }

    // Métodos para Gerenciar Livros
    public void adicionarLivro(Livro livro) {
        livros.add(livro);
        System.out.println("Livro adicionado com sucesso.");
    }

    public void listarLivros() {
        if (livros.isEmpty()) {
            System.out.println("Nenhum livro cadastrado.");
            return;
        }
        livros.forEach(System.out::println);
    }

    public void excluirLivro(String isbn) {
        Optional<Livro> livroOpt = livros.stream()
                .filter(l -> l.getIsbn().equals(isbn))
                .findFirst();
        if (livroOpt.isPresent()) {
            Livro livro = livroOpt.get();
            if (livro.isDisponivel()) {
                livros.remove(livro);
                System.out.println("Livro excluído com sucesso.");
            } else {
                System.out.println("Não é possível excluir um livro emprestado.");
            }
        } else {
            System.out.println("Livro não encontrado.");
        }
    }

    // Métodos para Gerenciar Usuários
    public void adicionarUsuario(Usuario usuario) {
        usuarios.add(usuario);
        System.out.println("Usuário adicionado com sucesso.");
    }

    public void listarUsuarios() {
        if (usuarios.isEmpty()) {
            System.out.println("Nenhum usuário cadastrado.");
            return;
        }
        usuarios.forEach(System.out::println);
    }

    public void editarUsuario(String matricula, String novoNome, String novoTelefone) {
        Optional<Usuario> usuarioOpt = usuarios.stream()
                .filter(u -> u.getMatricula().equals(matricula))
                .findFirst();
        if (usuarioOpt.isPresent()) {
            Usuario usuario = usuarioOpt.get();
            usuario.setNome(novoNome);
            usuario.setTelefone(novoTelefone);
            System.out.println("Dados do usuário atualizados.");
        } else {
            System.out.println("Usuário não encontrado.");
        }
    }

    public void excluirUsuario(String matricula) {
        Optional<Usuario> usuarioOpt = usuarios.stream()
                .filter(u -> u.getMatricula().equals(matricula))
                .findFirst();
        if (usuarioOpt.isPresent()) {
            Usuario usuario = usuarioOpt.get();
            if (usuario.getEmprestimos().isEmpty()) {
                usuarios.remove(usuario);
                System.out.println("Usuário excluído com sucesso.");
            } else {
                System.out.println("Não é possível excluir um usuário com empréstimos pendentes.");
            }
        } else {
            System.out.println("Usuário não encontrado.");
        }
    }

    // Métodos para Gerenciar Empréstimos
    public void emprestarLivro(String isbn, String matricula) {
        Optional<Livro> livroOpt = livros.stream()
                .filter(l -> l.getIsbn().equals(isbn))
                .findFirst();
        Optional<Usuario> usuarioOpt = usuarios.stream()
                .filter(u -> u.getMatricula().equals(matricula))
                .findFirst();

        if (!livroOpt.isPresent()) {
            System.out.println("Livro não encontrado.");
            return;
        }

        if (!usuarioOpt.isPresent()) {
            System.out.println("Usuário não encontrado.");
            return;
        }

        Livro livro = livroOpt.get();
        Usuario usuario = usuarioOpt.get();

        // Verificar disponibilidade do livro
        if (!livro.isDisponivel()) {
            System.out.println("Livro não está disponível para empréstimo.");
            return;
        }

        // Verificar se o usuário pode emprestar mais livros
        long countEmprestimosAtivos = emprestimos.stream()
                .filter(e -> e.getUsuario().equals(usuario))
                .count();
        if (countEmprestimosAtivos >= 3) {
            System.out.println("Usuário já possui 3 empréstimos ativos.");
            return;
        }

        // Verificar multas e atrasos
        double multas = calcularMultasUsuario(usuario, LocalDate.now());
        boolean possuiAtrasos = possuiAtrasos(usuario, LocalDate.now());

        if (multas > 50.0 || possuiAtrasos) {
            System.out.println("Usuário bloqueado para novos empréstimos devido a multas ou atrasos.");
            return;
        }

        // Realizar empréstimo
        Emprestimo emprestimo = new Emprestimo(livro, usuario);
        emprestimos.add(emprestimo);
        usuario.adicionarEmprestimo(emprestimo);
        livro.setDisponivel(false);
        System.out.println("Empréstimo realizado com sucesso.");
    }

    public void devolverLivro(String isbn, String matricula) {
        Optional<Emprestimo> emprestimoOpt = emprestimos.stream()
                .filter(e -> e.getLivro().getIsbn().equals(isbn) &&
                        e.getUsuario().getMatricula().equals(matricula))
                .findFirst();
        if (emprestimoOpt.isPresent()) {
            Emprestimo emprestimo = emprestimoOpt.get();
            emprestimos.remove(emprestimo);
            emprestimo.getUsuario().removerEmprestimo(emprestimo);
            emprestimo.getLivro().setDisponivel(true);

            // Calcular multa, se houver
            double multa = emprestimo.calcularMulta(LocalDate.now());
            if (multa > 0) {
                System.out.println("Livro devolvido com atraso. Multa: R$ " + multa);
            } else {
                System.out.println("Livro devolvido no prazo.");
            }
        } else {
            System.out.println("Empréstimo não encontrado.");
        }
    }

    // Métodos para Listar Empréstimos e Consultas
    public void listarEmprestimos() {
        if (emprestimos.isEmpty()) {
            System.out.println("Nenhum empréstimo registrado.");
            return;
        }
        emprestimos.forEach(System.out::println);
    }

    public void consultarPorUsuario(String matricula) {
        Optional<Usuario> usuarioOpt = usuarios.stream()
                .filter(u -> u.getMatricula().equals(matricula))
                .findFirst();
        if (usuarioOpt.isPresent()) {
            Usuario usuario = usuarioOpt.get();
            List<Emprestimo> lista = emprestimos.stream()
                    .filter(e -> e.getUsuario().equals(usuario))
                    .toList();
            if (lista.isEmpty()) {
                System.out.println("Usuário não possui empréstimos.");
            } else {
                lista.forEach(System.out::println);
            }
        } else {
            System.out.println("Usuário não encontrado.");
        }
    }

    public void consultarPorLivro(String isbn) {
        Optional<Livro> livroOpt = livros.stream()
                .filter(l -> l.getIsbn().equals(isbn))
                .findFirst();
        if (livroOpt.isPresent()) {
            Livro livro = livroOpt.get();
            if (livro.isDisponivel()) {
                System.out.println("Livro está disponível para empréstimo.");
            } else {
                Optional<Emprestimo> emprestimoOpt = emprestimos.stream()
                        .filter(e -> e.getLivro().equals(livro))
                        .findFirst();
                emprestimoOpt.ifPresent(e -> {
                    System.out.println("Livro emprestado para: " + e.getUsuario().getNome());
                    System.out.println("Data de devolução prevista: " + e.getDataDevolucao());
                });
            }
        } else {
            System.out.println("Livro não encontrado.");
        }
    }

    // Métodos Auxiliares para Multas e Atrasos
    private double calcularMultasUsuario(Usuario usuario, LocalDate dataAtual) {
        return usuario.getEmprestimos().stream()
                .mapToDouble(e -> e.calcularMulta(dataAtual))
                .sum();
    }

    private boolean possuiAtrasos(Usuario usuario, LocalDate dataAtual) {
        return usuario.getEmprestimos().stream()
                .anyMatch(e -> e.calcularAtraso(dataAtual) > 0);
    }
}
