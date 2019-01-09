import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {

        int numeroPeixe = 0, numeroCachorro = 0, opcaoGeral, opcaoEspecie;
        String nome, tipoHabitat, raca;
        double peso;
        List<Peixe> listaPeixe = new ArrayList<Peixe>();
        List<Cachorro> listaCachorro = new ArrayList<Cachorro>();
        Peixe peixe;
        Cachorro cachorro;
        Scanner scanner = new Scanner(System.in);
        do {
            System.out.println("Escolha uma das opções abaixo:");
            System.out.println("1 - Cadastrar um animal");
            if(numeroPeixe > 0) System.out.println("2 - Exibir os peixes");
            if(numeroCachorro > 0) System.out.println("3 - Exibir os cachorros");
            System.out.println("0 - Sair");
            System.out.print("> ");
            opcaoGeral = Integer.parseInt(scanner.getLine().trim());
            switch(opcaoGeral) {
                case 1:
                    System.out.print("Insira o nome do animal: ");
                    nome = scanner.getLine().trim();
                    System.out.print("Insira o peso do animal: ");
                    peso = Double.parseDouble(scanner.getLine().trim());
                    do {
                        System.out.println("Escolha a espécie do seu animal:");
                        System.out.println("1 - Peixe");
                        System.out.println("2 - Cachorro");
                        System.out.print("> ");
                        opcaoEspecie = Integer.parseInt(scanner.getLine().trim());
                        switch(opcaoEspecie) {
                            case 1:
                                System.out.print("Insira o tipo de habitat do peixe: ");
                                tipoHabitat = scanner.getLine().trim();
                                peixe = new Peixe(nome, peso, tipoHabitat);
                                listaPeixe.add(peixe);
                                numeroPeixe++;
                                break;
                            case 2:
                                System.out.print("Insira a raça do cachorro: ");
                                raca = scanner.getLine().trim();
                                cachorro = new Cachorro(nome, peso, raca);
                                listaCachorro.add(cachorro);
                                numeroCachorro++;
                                break;
                        }
                    } while(opcaoEspecie < 1 || opcaoEspecie > 2);
                    break;
                    if(numeroPeixe > 0) {
                        case 2:
                            System.out.println("Peixes:");
                            for(i = 0; i < numeroPeixe; i++) {
                                peixe = listaPeixe.get(i);
                                System.out.println("Nome: " + peixe.getNome() + "\tPeso: " + peixe.getPeso() + " kg\tTipo do Habitat: " + peixe.getTipoHabitat());
                            }
                            break;
                    }
                    if(numeroCachorro > 0) {
                        case 3:
                            System.out.println("Cachorros:");
                            for(i = 0; i < numeroCachorro; i++) {
                                System.out.println("")
                            }
                    }
            }
        }
    }
}