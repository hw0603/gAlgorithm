import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class BOJ12865 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int k = Integer.parseInt(str[1]);

        List<Point> points = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            str = br.readLine().split(" "); // x -> n, y ->
            int x = Integer.parseInt(str[0]);
            int y = Integer.parseInt(str[1]);
            points.add(new Point(x, y));
        }

        int[][] dp = new int[n + 1][k + 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                Point now = points.get(i - 1);
                if (j - now.x < 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - now.x] + now.y);
                }
            }
        }

        System.out.println(dp[n][k]);
    }
}
