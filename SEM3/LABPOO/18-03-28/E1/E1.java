import javax.swing.JOptionPane;
import java.util.List;
import java.util.Arraylist;

public class E1 {

    public static void main(String[] args) {
        
        int i;
        String name, ra;
        List alunos = new Arraylist();
        for(i = 1; i <= 5; i++) {
            name = JOptionPane.showInputDialog(null, "Insira o nome do " + i + "º aluno:");
            ra = JOptionPane.showInputDialog(null, "Insira o RA do " + i + "º aluno:");
            Aluno aluno = new Aluno(String.parseInt(i), name, ra);
            alunos.add(aluno);
        }
        ra = JOptionPane.showInputDialog(null, "Insira o RA para busca:");
        i = 0;
        while(ra != alunos.get(i).getRa() && i <= 5) i++;
        if(i <= 5) JOptionPane.showMessageDialog(null, "Aluno: " + alunos.get(i).getName() + "\nRA: " + alunos.get(i).getRa());

    }

}