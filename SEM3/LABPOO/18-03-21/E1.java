import javax.swing.JOptionPane;

public class E1 {

    public static void main(String[] args) {
        
        String []produto = new String[10];
        String relatorio = "";
        float []valorUnitario = new float[10];
        float lucroMes = 0, lucroMesTotal = 0;
        int []vendaMes = new int[10];
        int i;
        JOptionPane.showMessageDialog(null, "Controle de vendas");
        for(i = 0; i < 10; i++) {
            try {
                produto[i] = JOptionPane.showInputDialog(null, "Insira o nome do " + (i + 1) + "º produto");
                valorUnitario[i] = Float.parseFloat(JOptionPane.showInputDialog(null, "Insira o valor do produto \"" + produto[i] + "\" (R$)"));
                vendaMes[i] = Integer.parseInt(JOptionPane.showInputDialog(null, "Insira quantas unidados do produto \"" + produto[i] + "\" foram vendidas"));
                lucroMesTotal += lucroMes = valorUnitario[i] * vendaMes[i];
            } catch(NullPointerException e) {
                JOptionPane.showMessageDialog(null, "ERRO: nome do produto inválido!");
                System.exit(0);
            } catch(NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "ERRO: valor ou unidades do produto inválido!");
                System.exit(0);
            } catch(Exception e) {
                System.out.println(e);
                System.exit(0);
            }
            relatorio = relatorio + "Produto: \"" + produto[i] + "\" - Valor unitario: R$" + valorUnitario[i] + " - Valor vendido no mês: R$" + lucroMes + "\n";
        }
        JOptionPane.showMessageDialog(null, relatorio);
        JOptionPane.showMessageDialog(null, "Valor total vendido no mes: R$" + lucroMesTotal);

    }

}