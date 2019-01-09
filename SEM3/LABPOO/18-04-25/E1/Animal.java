public class Animal {

    private String nome;
    private double peso;

    public Animal(String nome, double peso) {
        this.nome = nome;
        this.peso = peso;
    }

    private void privateSetNome(String nome) {
        this.nome = nome;
    }

    private String privateGetNome() {
        return nome;
    }

    private void privateSetPeso(double peso) {
        this.peso = peso;
    }

    private double privateGetPeso() {
        return peso;
    }

    public void setNome(String nome) {
        privateSetNome(nome);
    }

    public String getNome() {
        return privateGetNome();
    }

    public void setPeso(double peso) {
        privateSetPeso(peso);
    }

    public double getPeso() {
        return privateGetPeso();
    }
    
}