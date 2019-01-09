import java.util.Scanner;
import java.text.DecimalFormat;

public class E1 {

    public static DecimalFormat d = new DecimalFormat(".##");

    public static void main(String[] args) {

        int i;
        int[] p = new p[3];
        boolean j = false;
        float media;
        float[] n = new n[3];
        String nota = "ª nota: ", peso = "º peso: ";
        Scanner dado = new Scanner(System.in);
        System.out.println("Cálculo de Média!");
        for(i = 0; i < 3; i++) {
            System.out.print("Insira " + (j)?"o ":"a " + i + (j)?peso:nota);
            if(!j) {
                p[i] = dado.nextInt();
            } else {
                n[i] = dado.nextFloat();
            }
            if(!j) {
                j = true;
                i = -1;
            }
        }
        media = ((n[0] * p[0]) + (n[1] * p[1]) + (n[2] * p[2])) / (p[0] + p[1] + p[2]);
        System.out.println("Média: " + media);

    }

}