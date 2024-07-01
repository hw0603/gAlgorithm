import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ27114 {
    public static void main(String[] args) throws IOException {
        // 좌 * 1, 우 * 1
        // 뒤 * 2

        // 좌 * 2, 뒤 * 1
        // 우 * 2, 뒤 * 1

        // 좌 * 4
        // 우 * 4
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int right = Integer.parseInt(str[0]);
        int left = Integer.parseInt(str[1]);
        int back = Integer.parseInt(str[2]);
        int energy = Integer.parseInt(str[3]);
        int[] arr1 = new int[2];
        int[] arr2 = new int[2];
        int[] arr3 = new int[2];

        arr1[0] = right + left;
        arr1[1] = back * 2;

        arr2[0] = right * 2 + back;
        arr2[1] = left * 2 + back;

        arr3[0] = right * 4;
        arr3[1] = left * 4;

        // dp[i]: i만큼의 에너지를 소비할 경우 최소 횟수
        int[] dp = new int[energy + 1];
        dp[0] = 0;

        for (int i = 1; i <= energy; i++) {
            dp[i] = 10_000_001;
        }

        for (int i = 2; i <= energy; i++) {
            for (int j = 0; j < 2; j++) {
                if (i - arr1[j] >= 0) {
                    dp[i] = dp[i] != 0 ? Math.min(dp[i - arr1[j]] + 2, dp[i]) : dp[i - arr1[j]] + 2;
                }
            }

            for (int j = 0; j < 2; j++) {
                if (i - arr2[j] >= 0) {
                    dp[i] = dp[i] != 0 ? Math.min(dp[i - arr2[j]] + 3, dp[i]) : dp[i - arr2[j]] + 3;
                }
            }

            for (int j = 0; j < 2; j++) {
                if (i - arr3[j] >= 0) {
                    dp[i] = dp[i] != 0 ? Math.min(dp[i - arr3[j]] + 4, dp[i]) : dp[i - arr3[j]] + 4;
                }
            }
        }

        if (dp[energy] > 10_000_000 || dp[energy] < 1) {
            System.out.println(-1);
            return;
        }
        System.out.println(dp[energy]);
    }
}
// 1 3 2 4
