import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {

        int duracaoFilme, opcao;
        double valorLocacaoFilme;
        String tituloFilme, generoFilme, classificacaoEtaria;
        List<Filme> filme = new ArrayList<Filme>();
        Scanner scanner = new Scanner(System.in);
        do {
            System.out.print("Insira o titulo do filme: ");
            tituloFilme = scanner.nextLine().trim();
            System.out.print("Insira o gênero do filme: ");
            generoFilme = scanner.nextLine().trim();
            System.out.print("Insira a duração do filme(em minutos): ");
            duracaoFilme = Integer.parseInt(scanner.nextLine().trim());
            System.out.print("Insira a classificação etária do filme: ");
            classificacaoEtaria = scanner.nextLine().trim();
            System.out.print("Insira o valor de locação do filme: R$");
            valorLocacaoFilme = Double.parseDouble(scanner.nextLine().trim());
            System.out.print("Insira 1 se deseja cadastrar outro filme: ");
            opcao = Integer.parseInt(scanner.nextLine().trim());
        } while(opcao);
    }
}