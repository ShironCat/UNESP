public class Atleta{

    private String nome;
    private int idade;
    private String sexo;
    private String modalidade;
    private double estatura;
    private double peso;

    public Atleta(String nome, int idade, String sexo, String modalidade, double estatura, double peso) {
        this.nome = nome;
        this.idade = idade;
        this.sexo = sexo;
        this.modalidade = modalidade;
        this.estatura = estatura;
        this.peso = peso;
    }

    public String getNome() {
        return nome;
    }

    public int getIdade() {
        return idade;
    }

    public String getSexo() {
        return sexo;
    }

    public String getModalidade() {
        return modalidade;
    }

    public double getEstatura() {
        return estatura;
    }

    public double getPeso() {
        return peso;
    }

}