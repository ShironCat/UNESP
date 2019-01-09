public class Invoice {

    private String numeroItemFaturado;
    private String descricaoItem;
    private int quantidadeCompradaItem;
    private double precoUnitarioItem;
    private String nomeCliente;

    public Invoice(String numeroItemFaturado, String descricaoItem, int quantidadeCompradaItem, double precoUnitarioItem, Stirng nomeCliente) {
        this.numeroItemFaturado = numeroItemFaturado;
        this.descricaoItem = descricaoItem;
        this.quantidadeCompradaItem = quantidadeCompradaItem;
        this.precoUnitarioItem = precoUnitarioItem;
        this.nomeCliente = nomeCliente;
    }

    public void setNumeroItemFaturado(String numeroItemFaturado) {
        this.numeroItemFaturado = numeroItemFaturado;
    }

    public String getNumeroItemFaturado() {
        return numeroItemFaturado;
    }

    public void setDescricaoItem(String descricaoItem) {
        this.descricaoItem = descricaoItem;
    }

    public String getDescricaoItem() {
        return descricaoItem;
    }

    public void setQuantidadeCompradaItem(int quantidadeCompradaItem) {
        this.quantidadeCompradaItem = quantidadeCompradaItem;
    }

    public int getQuantidadeCompradaItem() {
        return quantidadeCompradaItem;
    }

    public void setPrecoUnitarioItem(double precoUnitarioItem) {
        this.precoUnitarioItem = precoUnitarioItem;
    }

    public double getPrecoUnitarioItem() {
        return precoUnitarioItem;
    }

    public void setNomeCliente(String nomeCliente) {
        this.nomeCliente = nomeCliente;
    }

    public double getNomeCliente() {
        return nomeCliente;
    }

    public double getInvoiceAmount() {
        return precoUnitarioItem * quantidadeCompradaItem;
    }
    
}