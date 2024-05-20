import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ28017 {
    static int n = 0;
    static int m = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);
        int[][] dp = new int[n + 1][m];

        for (int i = 1; i <= n; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }

        // dp[i][j]는 i번째 회차에서 j번째 무기를 골랐을 때 최소 시간
        // dp[i][j] = Math.min(Min(dp[i - 1]) + sum[i][j], dp[i][j - 1])
        for (int i = 1; i <= n; i++) {
            str = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                int time = Integer.parseInt(str[j]);
                for (int k = 0; k < m; k++) {
                    if (j != k) {
                        dp[i][j] = Math.min(dp[i - 1][k] + time, dp[i][j]);
                    }
                }
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < m; i++) {
            ans = Math.min(dp[n][i], ans);
        }
        System.out.println(ans);
    }
}

