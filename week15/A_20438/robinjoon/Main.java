import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();

        String[] split = input.split(" ");
        int n = Integer.parseInt(split[0]);
        int k = Integer.parseInt(split[1]);
        int q = Integer.parseInt(split[2]);
        int m = Integer.parseInt(split[3]);

        Set<Integer> sleep = new HashSet<>();
        input = br.readLine();
        split = input.split(" ");

        for (int i = 0; i < k; i++) {
            sleep.add(Integer.parseInt(split[i]));
        }

        int[] check = new int[n+3];
        input = br.readLine();
        split = input.split(" ");
        for (int i = 0; i < q; i++) {
            int qr = Integer.parseInt(split[i]);
            for (int j = 1; j <= n+2; j++) {
                if (qr * j > n+2)break;
                if (sleep.contains(qr*j)) {
                    if (j==1) break;
                    continue;
                }
                check[qr*j] = 1;
            }
        }
        int[] sum = new int[n+3];
        sum[3] = check[3];
        for (int i = 4; i < n+3; i++) {
            sum[i] = sum[i-1] + check[i];
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            input = br.readLine();
            split = input.split(" ");
            int s = Integer.parseInt(split[0]);
            int e = Integer.parseInt(split[1]);

            sb.append(e-s+1 - (sum[e]-sum[s-1])).append("\n");
        }

        System.out.print(sb);
    }
}
