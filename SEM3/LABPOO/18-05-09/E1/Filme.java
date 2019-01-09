public class Filme {

    private String tituloFilme;
    private String generoFilme;
    private int duracaoFilme;
    private String classificacaoEtariaFilme;
    private double valorLocacaoFilme;

    public Filme(String tituloFilme, String generoFilme, int duracaoFilme, String classificacaoEtariaFilme, double valorLocacaoFilme) {
        this.tituloFilme = tituloFilme;
        this.generoFilme = generoFilme;
        this.duracaoFilme = duracaoFilme;
        this.classificacaoEtariaFilme = classificacaoEtariaFilme;
        this.valorLocacaoFilme = valorLocacaoFilme;
    }

    public String getTituloFilme() {
        return tituloFilme;
    }

    public double getValorLocacaoFilme() {
        return valorLocacaoFilme;
    }
    
}