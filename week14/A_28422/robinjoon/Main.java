import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String input = br.readLine();
        String[] split = input.split(" ");
        int[] arr = new int[n+1];
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(split[i-1]);
        }
        int[] dp = new int[n+1]; // dp[n] = 총 n 장을 가져갔을 때 최대값
        /*
        dp[n] = Max(dp[n-2] + score, dp[n-3] + score);
         */
        dp[0] = 0;
        dp[1] = 0;
        if (n >= 2) {
            dp[2] = calculateScore(arr[2],arr[1]);
        }
        if (n >= 3) {
            dp[3] = calculateScore(arr[3]^arr[2], arr[1]);
        }
        if (n >= 4) {
            dp[4] = calculateScore(arr[4],arr[3]) + dp[2];
        }
        for (int i = 5; i<=n; i++) {
            if (i - 2 >= 0) { // 두장 뽑는 경우
                dp[i] = Math.max(dp[i-2] + calculateScore(arr[i],arr[i-1]), dp[i]);
            }
            if (i - 3 >= 0) { // 세장 뽑는 경우
                dp[i] = Math.max(dp[i-3] + calculateScore(arr[i]^arr[i-1],arr[i-2]), dp[i]);
            }
        }
        System.out.println(dp[n]);
    }

    private static int calculateScore(int a, int b) {
        return Integer.bitCount(a^b);
    }
}
