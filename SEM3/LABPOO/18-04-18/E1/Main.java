import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {

        int i, j, opcaoTimeCasa, opcaoTimeVisitante, golTimeCasa, golTimeVisitante;
        String nome, cidade, anoCriacao, local;
        Scanner scanner = new Scanner(System.in);
        Time[] time = new Time[5];
        Partida[] partida = new Partida[4];
        for(i = 0; i < 5; i++) {
            System.out.print("Insira o nome do " + i + "º time: ");
            nome = scanner.nextLine().trim();
            System.out.print("Insira a cidade do time \"" + nome + "\": ");
            cidade = scanner.nextLine().trim();
            System.out.print("Insira o ano de criação do time \"") + nome + "\": ");
            anoCriacao = scanner.nextLine().trim();
            Time novoTime = new Time(nome, cidade, anoCriacao);
            time[i] = novoTime;
        }
        for(i = 0; i < 4; i++) {
            System.out.print("Insira o local da " + i + "ª partida: ");
            local = scanner.nextLine().trim();
            System.out.println("Selecione o time da casa");
            for(j = 0; j < 5; j++) {
                System.out.println(j + " - " + time[j].getNome());
            }
            System.out.print("> ");
            opcaoTimeCasa = Integer.parseInt(scanner.nextLine().trim());
            System.out.println("Selecione o time visitante");
            for(j = 0; j < 5; j++) {
                System.out.println(j + " - " + time[j].getNome());
            }
            System.out.print("> ");
            opcaoTimeVisitante = Integer.parseInt(scanner.nextLine().trim());
            System.out.print("Insira o número de gols do time da casa: ");
            golTimeCasa = Integer.parseInt(scanner.nextLine().trim());
            System.out.print("Insira o número de gols do time visitante: ");
            golTimeVisitante = Integer.parseInt(scanner.nextLine().trim());
            Partida novoPartida = new Partida(local, time[opcaoTimeCasa], time[opcaoTimeVisitante], golTimeCasa, golTimeVisitante);
            partida[i] = novoPartida;
        }

    }

}