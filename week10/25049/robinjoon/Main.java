import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] arr = new long[n+1];
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line);
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        long[] dp = new long[n+1];
        for (int i = 1; i <= n; i++) {
            dp[i] = Math.max(dp[i-1] + arr[i], arr[i]);
        }
        long max = Long.MIN_VALUE;
        long[] dp2 = new long[n+1];
        long[] dp3 = new long[n+1];
        for (int i = n-1; i >=0; i--) {
            dp2[i] = Math.max(dp2[i+1]+arr[i+1],arr[i+1]);
            dp3[i] = Math.max(dp3[i+1],dp2[i]);
        }
        for (int i = 1; i <= n; i++) {
            long lMax = dp[i];// 왼쪽 구간
            long rMax = dp3[i];
            max = Math.max(rMax + lMax, max);
        }
        max = Math.max(0,max);
        long sum = Arrays.stream(arr).sum();
        System.out.println(sum + max);
    }
}

