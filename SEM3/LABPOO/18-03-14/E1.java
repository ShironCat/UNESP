import javax.swing.JOptionPane;

public class E1 {

    public static void main(String[] args) {
        
        float salario = 0, imposto = 0, aumento = 0;
        int opcao = 0;
        try {
            salario = Float.parseFloat(JOptionPane.showInputDialog(null, "Insira seu salario"));
            opcao = Integer.parseInt(JOptionPane.showInputDialog(null, "Escolha uma das opções:\n1 - Imposto\n2 - Novo salário"));
        } catch (Exception e) {
            System.out.println("ERRO: " + e);
        }
        switch(opcao) {
            case 1:
                if(salario < 500) {
                    imposto = salario * (float)0.05;
                } else if(salario >= 500 && salario <= 850) {
                    imposto = salario * (float)0.10;
                } else if(salario > 850) {
                    imposto = salario * (float)0.15;
                }
                JOptionPane.showMessageDialog(null, "Imposto = " + imposto);
                break;
            case 2:
                if(salario > 1500) {
                    aumento = (float)25.00;
                } else if(salario >= 750 && salario <= 1500) {
                    aumento = (float)50.00;
                } else if(salario >= 450 && salario < 750) {
                    aumento = (float)75.00;
                } else if(salario < 450) {
                    aumento = (float)100.00;
                }
                JOptionPane.showMessageDialog(null, "Aumento = " + aumento);
                break;
        }

    }

}