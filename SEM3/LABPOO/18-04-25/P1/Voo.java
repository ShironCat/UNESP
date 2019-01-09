public class Voo {

    private String cidadeOrigemVoo;
    private String cidadeDestinoVoo;
    private String horarioPartidaVoo;
    private Boolean[] assentoDisponivelVoo = new Boolean[10];

    public Voo(String cidadeOrigemVoo, String cidadeDestinoVoo, String horarioPartidaVoo) {
        int i;
        this.cidadeOrigemVoo = cidadeOrigemVoo;
        this.cidadeDestinoVoo = cidadeDestinoVoo;
        this.horarioPartidaVoo = horarioPartidaVoo;
        for(i = 0; i < 10; i++) assentoDisponivelVoo[i] = true;
    }

    public void setCidadeOrigemVoo(String cidadeOrigemVoo) {
        this.cidadeOrigemVoo = cidadeOrigemVoo;
    }

    public String getCidadeOrigemVoo() {
        return cidadeOrigemVoo;
    }

    public void setCidadeDestinoVoo(String cidadeDestinoVoo) {
        this.cidadeDestinoVoo = cidadeDestinoVoo;
    }

    public String getCidadeDestinoVoo() {
        return cidadeDestinoVoo;
    }

    public void setHorarioPartidaVoo(String horarioPartidaVoo) {
        this.horarioPartidaVoo = horarioPartidaVoo;
    }

    public String getHorarioPartidaVoo() {
        return horarioPartidaVoo;
    }

    public void setAssentoDisponivelVoo(Boolean[] assentoDisponivelVoo) {
        int i;
        for(i = 0; i < 10; i++) this.assentoDisponivelVoo[i] = assentoDisponivelVoo[i];
    }

    public Boolean[] getAssentoDisponivelVoo() {
        return assentoDisponivelVoo;
    }

    public String getStringAssentoDisponivelVoo() {
        int i;
        String mensagem = "Selecione uma poltrona:\n";
        Boolean[] assentoDisponivelVoo = getAssentoDisponivelVoo();
        for(i = 0; i < 10; i++) {
            if(i == 5) mensagem += "\n";
            if(assentoDisponivelVoo[i]) {
                mensagem += (i + 1) + " ";
            } else {
                mensagem += "X ";
            }
        }
        mensagem += "\n-1 - Voltar\n";
        mensagem += "0 - Sair\n";
        mensagem += "> ";
        return mensagem;
    }

    public String setAssentoVoo(int i) {
        Boolean[] assentoDisponivelVoo = getAssentoDisponivelVoo();
        if(assentoDisponivelVoo[i]) {
            assentoDisponivelVoo[i] = false;
            setAssentoDisponivelVoo(assentoDisponivelVoo);
            return "Assento comprado!";
        } else {
            return "Assento indisponível!";
        }
    }
    
}