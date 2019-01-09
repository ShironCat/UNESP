import java.util.List;
import java.util.ArrayList;

public class Carrinho {

    private List<Filme> listaCarrinho;

    public Carrinho() {
        listaCarrinho = new ArrayList<Filme>();
    }

    public int setCarrinho(Filme filme) {
        listaCarrinho.add(filme);
        return listaCarrinho.size();
    }

    public String getTotalCarrinho(int i) {
        int j;
        double total = 0;
        String msg = "Lista de Filmes Alugados:\n";
        for(j = 0; j < i; j++) {
            msg = msg + listaCarrinho.get(j).getTituloFilme() + "\tR$" + listaCarrinho.get(j).getValorLocacaoFilme() + "\n";
            total += listaCarrinho.get(j).getValorLocacaoFilme();
        }
        msg = msg + "Total: R$" + total + "\n";
        return msg;
    }
}