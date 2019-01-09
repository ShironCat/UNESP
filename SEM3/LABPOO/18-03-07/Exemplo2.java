import javax.swing.JOptionPane;

public class Exemplo2 {

    public static void main(String[] args) {

        int n1;
        n1 = Integer.parseInt(JOptionPane.showInputDialog(null, "Insira um valor"));
        JOptionPane.showMessageDialog(null, "Este é o seu valor: " + n1);
        
    }

}