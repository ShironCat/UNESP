public class Cachorro extends Animal {

    private String raca;

    public Cachorro(String nome, double peso, String raca) {
        super(nome, peso);
        this.raca = raca;
    }

    private void privateSetRaca(String raca) {
        this.raca = raca;
    }

    private String privateGetRaca() {
        return raca;
    }

    public void setRaca(String raca) {
        privateSetRaca(raca);
    }

    public String getRaca() {
        return privateGetRaca();
    }
    
}