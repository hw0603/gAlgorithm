import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] dp = new int[n][2]; // dp[n][0] = 한번도 스킵하지 않은 경우
        dp[0][1] = 1;
        String line = br.readLine();
        String[] split = line.split(" ");
        String first = split[0];
        String second = split[1];
        dp[0][0] = Math.max(calc(1, first), calc(1, second));
        for (int i = 1; i < n; i++) {
            line = br.readLine();
            split = line.split(" ");
            first = split[0];
            second = split[1];
            if (dp[i-1][0] <=0 && dp[i-1][1] <=0) {
                System.out.println("ddong game");
                return;
            }
            if (dp[i-1][0] <= 0) {
                dp[i][0] = 0;
            }else {
                //스킵 안한 경우 = 이전에 스킵하지 않은 경우 + 이번 선택지
                dp[i][0] = Math.max(calc(dp[i - 1][0], first), calc(dp[i - 1][0], second));
            }
            if (dp[i-1][1] <=0) {
                dp[i][1] = dp[i-1][0];
            }else if (dp[i-1][0] <=0){
                dp[i][1] = Math.max(calc(dp[i-1][1], first), calc(dp[i-1][1],second));
            }else {
                dp[i][1] = Math.max(Math.max(calc(dp[i - 1][1], first), calc(dp[i - 1][1], second)), dp[i - 1][0]);
            }
            //스킵 한 경우 = max(이전에 스킵하지 않은 경우 + 이번에 스킵한 경우 , 이전에 스킵한 경우 + 이번에 스킵하지 않은 경우)

        }
        int max = Math.max(dp[n-1][0], dp[n-1][1]);
        if (max <=0) {
            System.out.println("ddong game");
            return;
        }
        System.out.println(max);
    }
    private static int calc(int target, String str) {
        int num = Integer.parseInt(str.substring(1));
        char c = str.charAt(0);
        if (c == '+') return target + num;
        if (c == '-') return target - num;
        if (c == '*') return target * num;
        return target / num;
    }
}
