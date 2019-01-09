import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        
        String nome, sexo, modalidade;
        int idade, id = 0, opcao = 1, i, j;
        double estatura, peso;
        Scanner scanner = new Scanner(System.in);
        List<Atleta> atletas = new ArrayList<>();
        while(opcao != 0){
            System.out.println("Escolha uma opção abaixo");
            System.out.println("1 - Adicionar um atleta");;
            System.out.println("2 - Estatura média de uma modalidade");
            System.out.println("3 - Peso médio dos atletas femininos");
            System.out.println("4 - Nome dos atletas masculinos com mais de 25 anos");
            System.out.println("0 - Sair");
            System.out.print("> ");
            opcao = Integer.parseInt(scanner.nextLine().trim());
            switch(opcao) {
                case 1:
                    System.out.print("Insira o nome do " + (id + 1) + "º atleta: ");
                    nome = scanner.nextLine().trim();
                    System.out.print("Insira a idade do " + (id + 1) + "º atleta: ");
                    idade = Integer.parseInt(scanner.nextLine().trim());
                    System.out.print("Insira o sexo do " + (id + 1) + "º atleta(F/M): ");
                    sexo = scanner.nextLine().trim();
                    System.out.print("Insira a modalidade do " + (id + 1) + "º atleta: ");
                    modalidade = scanner.nextLine().trim();
                    System.out.print("Insira a estatura do " + (id + 1) + "º atleta: ");
                    estatura = Double.parseDouble(scanner.nextLine().trim());
                    System.out.print("Insira o peso do " + (id + 1) + "º atleta: ");
                    peso = Double.parseDouble(scanner.nextLine().trim());
                    Atleta atleta = new Atleta(nome, idade, sexo, modalidade, estatura, peso);
                    atletas.add(id++, atleta);
                    break;
                case 2:
                    System.out.print("Insira a modalidade a ser checada: ");
                    modalidade = scanner.nextLine().trim();
                    estatura = j = 0;
                    for(i = 0; i < id; i++) {
                        if(atletas.get(i).getModalidade().equalsIgnoreCase(modalidade)) {
                            estatura += atletas.get(i).getEstatura();
                            j++;
                        }
                    }
                    System.out.println("A estatura média da modalidade " + modalidade + " é " + (estatura / j));
                    break;
                case 3:
                    peso = j = 0;
                    for(i = 0; i < id; i++) {
                        if(atletas.get(i).getSexo().equalsIgnoreCase("f")) {
                            peso += atletas.get(i).getPeso();
                            j++;
                        }
                        System.out.println("O peso médio dos atletas femininos é " + (peso / j));
                    }
                    break;
                case 4:
                    j = 0;
                    System.out.println("Atletas masculinos com mais de 25 anos");
                    for(i = 0; i < id; i++) {
                        if(atletas.get(i).getSexo().equalsIgnoreCase("m") && atletas.get(i).getIdade() > 25) {
                            System.out.println("Atleta: " + atletas.get(i).getNome() + "\tIdade: " + atletas.get(i).getIdade());
                            j = 1;
                        }
                    }
                    if(j == 0) System.out.println("Nenhum atleta masculino com mais de 25 anos!");
                    break;
                case 0: break;
                default:
                    System.out.println("Opção inválida!");
            }
        }
        scanner.close();

    }

}