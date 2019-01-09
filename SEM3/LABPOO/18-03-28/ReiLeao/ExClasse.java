public class ExClasse {

    public static void main(String[] args) {
        
        Item milk = new Item("011", "1 Galão de Leite", 2, 2.50);
        Item yogurt = new Item("032", "Iogurte de Pêssego", 4, 0.68);
        Item bread = new Item("023", "Pão de Forma", 1, 2.55);
        Item soap = new Item("021", "Pacote de Sabão", 1, 4.51);

        milk.setDiscount(0.15);

        double milk_price = milk.getAdjustedTotal();
        double yogurt_price = yogurt.getAdjustedTotal();
        double bread_price = bread.getAdjustedTotal();
        double soap_price = soap.getAdjustedTotal();

        System.out.println("Obrigado pela compra!");
        System.out.println(milk.getDescription() + "\tR$" + milk_price);
        System.out.println(yogurt.getDescription() + "\tR$" + yogurt_price);
        System.out.println(bread.getDescription() + "\tR$" + bread_price);
        System.out.println(soap.getDescription() + "\tR$" + soap_price);
        double total = milk_price + yogurt_price + bread_price + soap_price;
        System.out.println("Valor total \t R$" + total);

    }

}