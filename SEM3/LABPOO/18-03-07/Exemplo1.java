import java.util.Scanner;;

public class Exemplo1 {

    public static void main(String[] args) {

        int n1;
        Scanner dado = new Scanner(System.in);
        System.out.print("Insira um valor: ");
        try {
            n1 = dado.nextInt();
        } finally {
            in.close();
        }
        System.out.println("Este é o seu valor: " + n1);
        
    }

}