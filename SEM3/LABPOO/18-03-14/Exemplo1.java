import javax.swing.JOptionPane;

public class Exemplo1 {

    public static void main(String[] args) {
        
        String aux1, aux2;
        int n1, n2;
        aux1 = JOptionPane.showInputDialog(null, "Entre com n1");
        aux2 = JOptionPane.showInputDialog(null, "Entre com n2");
        try {
            n1 = Integer.parseInt(aux1);
            n2 = Integer.parseInt(aux2);
            JOptionPane.showMessageDialog(null, "Soma = " + (n1 + n2));
            JOptionPane.showMessageDialog(null, "Divisão = " + (n1 / n2));
        } catch(ArithmeticException erro) {
            JOptionPane.showMessageDialog(null, "Erro de divisão por zero!", "ERRO", JOptionPane.ERROR_MESSAGE);
        } catch(NumberFormatException erro) {
            JOptionPane.showMessageDialog(null, "Digite apenas números inteiros", "ERRO", JOptionPane.ERROR_MESSAGE);
        }

    }

}