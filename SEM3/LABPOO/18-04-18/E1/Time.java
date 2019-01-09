public class Time {

    private String nome;
    private String cidade;
    private String anoCriacao;
    private int golMarcado;
    private int golSofrido;
    private int saldoGol;

    public Time(String nome, Stirng cidade, String anoCriacao) {
        this.nome = nome;
        this.cidade = cidade;
        this.anoCriacao = anoCriacao;
        golMarcado = golSofrido = saldoGol = 0;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public String getCidade() {
        return cidade;
    }

    public void setAnoCriacao(String anoCriacao) {
        this.anoCriacao = anoCriacao;
    }

    public String getAnoCriacao() {
        return anoCriacao;
    }

    public void setGolMarcado(int golMarcado) {
        this.golMarcado = golMarcado;
    }

    public int getGolMarcado() {
        return golMarcado;
    }

    public void setGolSofrido(int golSofrido) {
        this.golSofrido = golSofrido;
    }

    public int getGolSofrido() {
        return golSofrido;
    }

    public void setSaldoGol() {
        saldoGol = golMarcado - golSofrido;
    }

    public int getSaldoGol() {
        return saldoGol;
    }

}