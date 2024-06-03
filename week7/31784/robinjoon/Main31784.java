import java.util.Scanner;

public class Main31784 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        String str = sc.next();
        char[] chars = str.toCharArray();
        for (int i = 0; i < n; i++) {
            boolean canA = canA(chars[i], k);
            if (canA) {
                k -= consumeCount(chars[i]);
                chars[i] = 'A';
            }
        }
        if(k != 0) {
            chars[n-1] = moveN(chars[n-1], k);
        }
        String result = new String(chars);
        System.out.print(result);
    }
    static boolean canA(char c, int t) {
        if (c == 'A') return true;
        char limit = 'Z';
        // c = z t 1 c = y t 2
        return limit - c < t;
    }
    static int consumeCount(char c) {
        if (c == 'A') return 0;
        char limit = 'Z';
        return limit - c + 1;
    }
    static char moveN(char ch, int n) {
        for (int i = 0; i < n; i++) {
            if(ch == 'Z') {
                ch = 'A';
            }else {
                ch++;
            }
        }
        return ch;
    }
}
