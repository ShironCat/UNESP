import java.util.List;
import java.util.ArrayList;

public class CompanhiaAerea {

    private String nomeCompanhiaAerea;
    private String paisMatrizCompanhiaAerea;
    private List<Voo> listaVooCompanhiaAerea;

    public CompanhiaAerea(String nomeCompanhiaAerea, String paisMatrizCompanhiaAerea, List<Voo> listaVooCompanhiaAerea) {
        this.nomeCompanhiaAerea = nomeCompanhiaAerea;
        this.paisMatrizCompanhiaAerea = paisMatrizCompanhiaAerea;
        this.listaVooCompanhiaAerea = listaVooCompanhiaAerea;
    }

    public void setNomeCompanhiaAerea(String nomeCompanhiaAerea) {
        this.nomeCompanhiaAerea = nomeCompanhiaAerea;
    }

    public String getNomeCompanhiaAerea() {
        return nomeCompanhiaAerea;
    }

    public void setPaisMatrizCompanhiaAerea(String paisMatrizCompanhiaAerea) {
        this.paisMatrizCompanhiaAerea = paisMatrizCompanhiaAerea;
    }

    public String getPaisMatrizCompanhiaAerea() {
        return paisMatrizCompanhiaAerea;
    }

    public void setListaVooCompanhiaAerea(List<Voo> listaVooCompanhiaAerea) {
        this.listaVooCompanhiaAerea = listaVooCompanhiaAerea;
    }

    public List<Voo> getListaVooCompanhiaAerea() {
        return listaVooCompanhiaAerea;
    }

    public String getStringListaVooCompanhiaAerea() {
        int i;
        String mensagem = "Selecione um voo:\n";
        List<Voo> listaVooCompanhiaAerea = getListaVooCompanhiaAerea();
        for(i = 0; i < 2; i++) {
            mensagem += (i + 1) + " - " + listaVooCompanhiaAerea.get(i).getCidadeOrigemVoo() + " -> " + listaVooCompanhiaAerea.get(i).getCidadeDestinoVoo() + " (" + listaVooCompanhiaAerea.get(i).getHorarioPartidaVoo() + ")\n";
        }
        mensagem += "-1 - Voltar\n";
        mensagem += "0 - Sair\n";
        mensagem += "> ";
        return mensagem;
    }
    
}