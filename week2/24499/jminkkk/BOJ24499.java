package week02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ24499 {
    public static void main(String[] args) throws IOException {
        // N개의 애플파이
        // 원형으로 배치, 맛있는 정도 수
        // 먹을 수 있는 최대값

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int k = Integer.parseInt(str[1]);

        int[] a = new int[n];
        str = br.readLine().split(" ");
        int max = 0;

        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(str[i]);
            max = Math.max(a[i], max);
        }

        // 시작 index
        // dp[i] = i부터 k를 먹었을 때 최대값
        // dp[i] = dp[i-1] + a[i+1 % n] - a[i-1]

        int[] dp = new int[n];
        for (int i = 0; i < k; i++) {
            dp[0] += a[i];
        }

        if (k == 1) {
            System.out.println(max);
            return;
        }

        int preHap = dp[0];
        for (int i = 1; i < n; i++) {
            int next = (i + k - 1) % n;
            int previous = (i - 1) % n;
            int newNum = preHap + a[next] - a[previous];

            dp[i] = Math.max(dp[i - 1], newNum);
            preHap = newNum;
        }
        System.out.println(dp[n - 1]);
    }
}
// 3 3
// 1 2 3
