import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");

        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);

        str = br.readLine().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(str[i]);
        }

        int firstIndex = 0;
        int lastIndex = 0;
        int newSum = 0;
        int maxSum = 0;
        for (int i = 0; i < n; i++) {
            if (newSum + a[i] > m) {
                lastIndex = i - 1;
                break;
            }
            newSum += a[i];
        }

        maxSum = newSum;
        // first ---- lastIndex
        while (firstIndex < n) {
            // 현재 더하기만 계속해도 괜찮다면
            while (lastIndex + 1 < n && newSum + a[lastIndex + 1] <= m) {
                lastIndex++;
                newSum += a[lastIndex];
                maxSum = Math.max(maxSum, newSum);
            }

            // 현재를 제거해야한다면
            firstIndex++;
            lastIndex = firstIndex;
            newSum = 0;
        }

        System.out.println(maxSum);
    }
}
// 햄스터의 부피 M
// 독에 구멍 N개, 각 구멍 크기 Ai
// 부피안에서 연속으로 가릴 수 있는 최대값
// dp[i] = dp[i -1] or dp[i - 1] + new - first
//---
// 3 100
// 99 99 100
