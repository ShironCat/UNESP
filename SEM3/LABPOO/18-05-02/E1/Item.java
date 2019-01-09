public class Item {

    private String numeroItem;
    private String descricaoItem;
    private double precoUnitarioItem;

    public Item(String numeroItem, String descricaoItem, double precoUnitarioItem) {
        this.numeroItem = numeroItem;
        this.descricaoItem = descricaoItem;
        this.precoUnitarioItem = precoUnitarioItem;
    }

    public void setNumeroItem(String numeroItem) {
        this.numeroItem = numeroItem;
    }

    public String getNumeroItem() {
        return numeroItem;
    }

    public void setDescricaoItem(String descricaoItem) {
        this.descricaoItem = descricaoItem;
    }

    public String getDescricaoItem() {
        return descricaoItem;
    }

    public void setPrecoUnitarioItem(String precoUnitarioItem) {
        this.precoUnitarioItem = precoUnitarioItem;
    }

    public double getPrecoUnitarioItem() {
        return precoUnitarioItem;
    }
    
}