import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Arrays;

public class BOJ30459 {
    static int m;
    static int n;
    static int r;
    static int[] a;
    static int[] b;
    static double hap = -1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);
        r = Integer.parseInt(str[2]);

        str = br.readLine().split(" ");
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(str[i]);
        }

        str = br.readLine().split(" ");
        b = new int[m];
        for (int i = 0; i < m; i++) {
            b[i] = Integer.parseInt(str[i]);
        }

        Arrays.sort(a);
        Arrays.sort(b);

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int height = Math.abs(a[i] - a[j]);
                two(height);
            }
        }

        NumberFormat formatter = new DecimalFormat("#0.0");
        if (hap == -1) {
            System.out.println(-1);
        } else {
            System.out.println(formatter.format(new BigDecimal(hap)));
        }
    }

    private static void two(int height) {
        int start = 0;
        int end = m - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            double sum = (height * b[mid]) / (double) 2;
            if (sum <= r) {
                hap = Math.max(sum, hap);
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
}
