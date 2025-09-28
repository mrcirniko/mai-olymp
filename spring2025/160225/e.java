import java.util.ArrayList;
import java.util.Scanner;

public class e {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, x, y;
        n = in.nextInt();
        x = in.nextInt();
        y = in.nextInt();
        if (n == 2 && x == 2 && y == 1) {
            System.out.println("Yes");
            System.out.println("2 1");
            in.close();
            return;
        }
        if (n == 2 && x == 2 && y == 2) {
            System.out.println("Yes");
            System.out.println("1 2");
            in.close();
            return;
        }
        if (n < x || n < y || (x >= n && y < n)) {
            System.out.println("No");
            in.close();
            return;
        }

        ArrayList<Integer> res = new ArrayList<>();
        System.out.println("Yes");
        if (n - y + 1 <= x) {
            int i = y + x - 1;
            while (i >= 1) {
                res.add(i--);
            }
            i = y + x;
            while (i <= n) {
                res.add(i++);
            }
        } else if (y >= x) {
            int i = y - x + 1;
            while (i <= n) {
                res.add(i++);
            }
            i = y - x - 1;
            while (i >= 1) {
                res.add(i--);
            }
        }

        for (int i = 0; i < res.size(); i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(res.get(i));
        }
        System.out.println();

        in.close();
    }
}
