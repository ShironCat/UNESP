import javax.swing.JOptionPane;
import java.util.List;
import java.util.ArrayList;

public class E2 {

    public static void main(String[] args) {
        
        List<String> produto = new ArrayList<>();
        List<Float> valorUnitario = new ArrayList<>();
        List<Integer> vendaMes = new ArrayList<>();
        String relatorio = "";
        float lucroMes = 0, lucroMesTotal = 0;
        int i = 0, opcao;
        JOptionPane.showMessageDialog(null, "Controle de vendas");
        do {
            try {
                produto.add(JOptionPane.showInputDialog(null, "Insira o nome do produto"));
                valorUnitario.add(Float.parseFloat(JOptionPane.showInputDialog(null, "Insira o valor do produto \"" + produto.get(i) + "\" (R$)")));
                vendaMes.add(Integer.parseInt(JOptionPane.showInputDialog(null, "Insira quantas unidados do produto \"" + produto.get(i) + "\" foram vendidas")));
                lucroMesTotal += lucroMes = valorUnitario.get(i) * vendaMes.get(i);
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
            relatorio = relatorio + "Produto: \"" + produto.get(i) + "\" - Valor unitario: R$" + valorUnitario.get(i) + " - Valor vendido no mês: R$" + lucroMes + "\n";
            i += 1;
            opcao = JOptionPane.showConfirmDialog(null, "Deseja adicionar outro produto?", "?", JOptionPane.YES_NO_OPTION);
        } while(opcao == JOptionPane.YES_OPTION);
        JOptionPane.showMessageDialog(null, relatorio);
        JOptionPane.showMessageDialog(null, "Valor total vendido no mes: R$" + lucroMesTotal);

    }

}