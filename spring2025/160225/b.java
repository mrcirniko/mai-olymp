import java.util.Scanner;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        byte[] c = new byte [5];
        byte count = 0;
        byte max = 0;
        for (byte i = 0; i < 5; ++i) {
            c[i] = in.nextByte();
            if (c[i] == 0) {
                ++count;
            }
            max = (c[i] > max) ? c[i] : max;
        }
        if (max == 3 || count == 2) {
            System.out.println("op");
        } else if (max == 2 || count == 3) {
            System.out.println("add oil");
        } else {
            System.out.println("gg");
        }
        in.close();
    }
}
