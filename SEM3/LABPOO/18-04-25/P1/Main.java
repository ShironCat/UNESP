import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {

        int i, j, opcao;
        String nomeCompanhiaAerea, paisMatrizCompanhiaAerea, cidadeOrigemVoo, cidadeDestinoVoo, horarioPartidaVoo;
        List<CompanhiaAerea> listaCompanhiaAerea = new ArrayList<CompanhiaAerea>();
        List<Voo> listaVoo1 = new ArrayList<Voo>(), listaVoo2 = new ArrayList<Voo>();
        Scanner scanner = new Scanner(System.in);
        for(i = 0; i < 2; i++) {
            System.out.print("Insira o nome da " + (i + 1) + "ª companhia aérea: ");
            nomeCompanhiaAerea = scanner.nextLine().trim();
            System.out.print("Insira o país matriz da " + (i + 1) + "ª companhia aérea: ");
            paisMatrizCompanhiaAerea = scanner.nextLine().trim();
            for(j = 0; j < 2; j++) {
                System.out.print("Insira a cidade de origem do " + (j + 1) + "º vôo: ");
                cidadeOrigemVoo = scanner.nextLine().trim();
                System.out.print("Insira a cidade de destino do " + (j + 1) + "º vôo: ");
                cidadeDestinoVoo = scanner.nextLine().trim();
                System.out.print("Insira o horário de partida do " + (j + 1) + "º vôo: ");
                horarioPartidaVoo = scanner.nextLine().trim();
                Voo voo = new Voo(cidadeOrigemVoo, cidadeDestinoVoo, horarioPartidaVoo);
                if(i == 1) {
                    listaVoo2.add(voo);
                } else if(i == 0) {
                    listaVoo1.add(voo);
                }
            }
            if(i == 1) {
                CompanhiaAerea companhiaAerea = new CompanhiaAerea(nomeCompanhiaAerea, paisMatrizCompanhiaAerea, listaVoo2);
                listaCompanhiaAerea.add(companhiaAerea);
            } else if(i == 0) {
                CompanhiaAerea companhiaAerea = new CompanhiaAerea(nomeCompanhiaAerea, paisMatrizCompanhiaAerea, listaVoo1);
                listaCompanhiaAerea.add(companhiaAerea);
            }
        }
        do {
            System.out.println("Insira sua opção:");
            System.out.println("1 - Comprar uma passagem");
            System.out.println("0 - Sair");
            System.out.print("> ");
            opcao = Integer.parseInt(scanner.nextLine().trim());
            switch(opcao) {
                case 1:
                    do {
                        System.out.println("Selecione uma companhia aérea:");
                        for(i = 0; i < 2; i++) {
                            System.out.println((i + 1) + " - " + listaCompanhiaAerea.get(i).getNomeCompanhiaAerea());
                        }
                        System.out.println("-1 - Voltar");
                        System.out.println("0 - Sair");
                        System.out.print("> ");
                        opcao = Integer.parseInt(scanner.nextLine().trim());
                        switch(opcao) {
                            case 1:
                            case 2:
                                CompanhiaAerea companhiaAerea = listaCompanhiaAerea.get(opcao - 1);
                                do {
                                    System.out.print(companhiaAerea.getStringListaVooCompanhiaAerea());
                                    opcao = Integer.parseInt(scanner.nextLine().trim());
                                    switch(opcao) {
                                        case 1:
                                        case 2:
                                            Voo voo = companhiaAerea.getListaVooCompanhiaAerea().get(opcao - 1);
                                            do {
                                                System.out.print(voo.getStringAssentoDisponivelVoo());
                                                opcao = Integer.parseInt(scanner.nextLine().trim());
                                                switch(opcao) {
                                                    case 1:
                                                    case 2:
                                                    case 3:
                                                    case 4:
                                                    case 5:
                                                    case 6:
                                                    case 7:
                                                    case 8:
                                                    case 9:
                                                    case 10:
                                                        System.out.println(voo.setAssentoVoo(opcao - 1));
                                                        break;
                                                    case -1:
                                                        opcao -= 2;
                                                        break;
                                                    case 0: break;
                                                    default:
                                                        System.out.println("Opção inválida!");
                                                }
                                            } while(opcao != -3 && opcao != 0);
                                            break;
                                        case -1:
                                            opcao -= 1;
                                            break;
                                        case 0: break;
                                        default:
                                            System.out.println("Opção inválida!");
                                    }
                                } while(opcao != -2 && opcao != 0);
                                break;
                            case -1: break;
                            case 0: break;
                            default:
                                System.out.println("Opção inválida!");
                        }
                    } while(opcao != -1 && opcao != 0);
                    break;
                case 0: break;
                default:
                    System.out.println("Opção inválida!");
            }
        } while(opcao != 0);
        scanner.close();

    }

}