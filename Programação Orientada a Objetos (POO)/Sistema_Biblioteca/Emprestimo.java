import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Emprestimo {
    private Livro livro;
    private Usuario usuario;
    private LocalDate dataEmprestimo;
    private LocalDate dataDevolucao;

    public Emprestimo(Livro livro, Usuario usuario) {
        this.livro = livro;
        this.usuario = usuario;
        this.dataEmprestimo = LocalDate.now();
        this.dataDevolucao = dataEmprestimo.plusDays(7); // Prazo de 7 dias
    }

    // Getters
    public Livro getLivro() {
        return livro;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public LocalDate getDataEmprestimo() {
        return dataEmprestimo;
    }

    public LocalDate getDataDevolucao() {
        return dataDevolucao;
    }

    public long calcularAtraso(LocalDate dataAtual) {
        if (dataAtual.isAfter(dataDevolucao)) {
            return ChronoUnit.DAYS.between(dataDevolucao, dataAtual);
        }
        return 0;
    }

    public double calcularMulta(LocalDate dataAtual) {
        long diasAtraso = calcularAtraso(dataAtual);
        if (diasAtraso > 0) {
            double multa = diasAtraso * 2.0;
            return Math.min(multa, 30.0); // Teto de R$30 por livro
        }
        return 0.0;
    }

    @Override
    public String toString() {
        return "Livro: " + livro.getTitulo() + ", Usuário: " + usuario.getNome() +
                ", Emprestado em: " + dataEmprestimo + ", Devolução prevista: " + dataDevolucao;
    }
}
