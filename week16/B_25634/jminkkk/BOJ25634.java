package week16.B_25634.jminkkk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ25634 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        String[] str = br.readLine().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(str[i]);
        }

        int[] b = new int[n];
        str = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            b[i] = Integer.parseInt(str[i]);
        }

        int sum = 0;
        int[] bright = new int[n];
        for (int i = 0; i < n; i++) {
            if (b[i] == 1) {
                sum += a[i];
                bright[i] = -a[i];
            } else {
                bright[i] = a[i];
            }
        }

        int now = bright[0]; // 무조건
        int max = bright[0];
        for (int i = 1; i < n; i++) {
            now = Math.max(bright[i], now + bright[i]);
            max = Math.max(max, now);
        }

        System.out.println(sum + max);
    }
}
