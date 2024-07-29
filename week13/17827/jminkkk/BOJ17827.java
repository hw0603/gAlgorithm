import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ17827 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);
        int v = Integer.parseInt(str[2]); // 사이클이 생긴 최초

        str = br.readLine().split(" ");
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = Integer.parseInt(str[i]);
        }

        for (int i = 0; i < m; i++) {
            int k = Integer.parseInt(br.readLine());
            if (k >= n) {
                k -= n;
                int c = k % (n - v + 1);
                System.out.println(values[c + v - 1]);
            } else {
                int c = k;
                System.out.println(values[c]);
            }
        }
    }
}
