package week11.A_27210.robinjoon;

import java.util.Arrays;
import java.util.Scanner;

public class P27210 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            int v = sc.nextInt();
            if (v == 2){
                arr[i] = -1;
            }else {
                arr[i] = 1;
            }
        }
        int[] dp = new int[n+1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = Math.max(dp[i-1] + arr[i], arr[i]);
        }
        int left = Arrays.stream(dp).skip(1).max().getAsInt();
        for (int i = 1; i <= n; i++) {
            arr[i] = -1 * arr[i];
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = Math.max(dp[i-1] + arr[i], arr[i]);
        }
        int right = Arrays.stream(dp).skip(1).max().getAsInt();
        System.out.println(Math.max(left,right));
    }
}
