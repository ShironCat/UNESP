public class Peixe extends Animal {

    private String tipoHabitat;

    public Peixe(String nome, double peso, String tipoHabitat) {
        super(nome, peso);
        this.tipoHabitat = tipoHabitat;
    }

    private void privateSetTipoHabitat(String tipoHabitat) {
        this.tipoHabitat = tipoHabitat;
    }

    private String privateGetTipoHabitat() {
        return tipoHabitat;
    }

    public void setTipoHabitat(String tipoHabitat) {
        privateSetTipoHabitat(tipoHabitat);
    }

    public String getTipoHabitat() {
        return privateGetTipoHabitat();
    }
    
}