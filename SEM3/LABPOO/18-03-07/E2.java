import java.util.Scanner;

public class E2 {

    public static void main(String[] args) {

        float d, j, r;
        Scanner dado = new Scanner(System.in);
        System.out.println("Cálculo de Rendimento!");
        System.out.print("Insira o valor do depósito(R$): ");
        d = dado.nextFloat();
        System.out.print("Insira o valor da taxa de juros(%): ");
        j = dado.nextFloat() / 100;
        r = d * j;
        System.out.println("Rendimento: " + r);
        System.out.println("Total: " + (d + r));

    }

}