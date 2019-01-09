public class Partida {

    private String local;
    private Time timeCasa;
    private Time timeVisitante;
    private int golTimeCasa;
    private int golTimeVisitante;

    public Partida(String local, Time timeCasa, Time timeVisitante, int golTimeCasa, int golTimeVisitante) {
        this.local = local;
        this.timeCasa = timeCasa;
        this.timeVisitante = timeVisitante;
        if(golTimeCasa < 0) golTimeCasa *= -1;
        this.golTimeCasa = golTimeCasa;
        if(golTimeVisitante < 0) golTimeVisitante *= -1;
        this.golTimeVisitante = golTimeVisitante;
        setGolTime(timeCasa, golTimeCasa, golTimeVisitante);
        setGolTime(timeVisitante, golTimeVisitante, golTimeCasa);
    }

    public void setLocal(String local) {
        this.local = local;
    }

    public String getLocal() {
        return local;
    }

    public void setTimeCasa(Time timeCasa) {
        this.timeCasa = timeCasa;
    }

    public String getTimeCasa() {
        return timeCasa;
    }

    public void setTimeVisitante(Time timeVisitante) {
        this.timeVisitante = timeVisitante;
    }

    public String getTimeVisitante() {
        return timeVisitante;
    }

    public void setGolTimeCasa(int golTimeCasa) {
        if(golTimeCasa < 0) golTimeCasa *= -1;
        this.golTimeCasa = golTimeCasa;
    }

    public String getGolTimeCasa() {
        return golTimeCasa;
    }

    public void setGolTimeVisitante(int golTimeVisitante) {
        if(golTimeVisitante < 0) golTimeVisitante *= -1;
        this.golTimeVisitante = golTimeVisitante;
    }

    public String getGolTimeVisitante() {
        return golTimeVisitante;
    }

    private void setGolTime(Time time, int golTime, int golTimeAdversario) {
        time.setGolMarcado(golTime);
        time.setGolSofrido(golTimeAdversario);
        time.setSaldoGol();
    }

}