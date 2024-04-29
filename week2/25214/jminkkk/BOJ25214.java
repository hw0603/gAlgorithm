package week02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ25214 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] AStr = br.readLine().split(" ");
        int[] A = new int[N];

        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(AStr[i]);
        }

        int[] dp = new int[N];
        if (N == 1) {
            System.out.println("0");
            return;
        }

        dp[0] = 0;
        System.out.print(dp[0] + " ");

        int min = Math.min(A[1], A[0]);
        int max = Math.max(A[1], A[0]);

        for (int i = 1; i < N; i++) {
            int now = A[i];
            dp[i] = Math.max(dp[i - 1], now - min);

            min = Math.min(now, min);
            max = Math.max(now, max);

            System.out.print(dp[i] + " ");
        }
    }
}
