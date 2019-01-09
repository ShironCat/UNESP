import java.util.Random;
import javax.swing.JOptionPane;

public class Trabalho1_Victor_AzadinhoMiranda {

    public static void main(String[] args) {
        
        Random r = new Random();
        int numero = r.nextInt(10) + 1, opcao = 5, tentativa = 1, limiteMaior = 10, limiteMenor = 1;
        while(opcao != numero) {
            if(opcao > numero) {
                limiteMaior = opcao;
            } else {
                limiteMenor = opcao;
            }
            opcao = (int)((limiteMaior + limiteMenor) / 2);
            tentativa++;
        }
        JOptionPane.showMessageDialog(null, "Número aleatório gerado: " + opcao + "\nNúmero de comparações: " + tentativa);

    }

}