import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int r = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();

        int[] cost = {l,r,b};

        int[][] dp = new int[k + 1][4]; // 0 앞, 1 우, 2 뒤 3 좌]
        // dp[i][j] = i 에너지를 써서 j 상태에 도달하는데 최소값. -1은 못하는 거
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < 4; j++) {
                dp[i][j] = 10000000;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i <= k; i++) {
            dp[i][0] = function(dp, new int[]{i-cost[0],i-cost[1],i-cost[2]}, new int[]{1,3,2}, dp[i][0]);
            dp[i][1] = function(dp, new int[]{i-cost[0],i-cost[1],i-cost[2]}, new int[]{2,0,3}, dp[i][1]);
            dp[i][2] = function(dp, new int[]{i-cost[0],i-cost[1],i-cost[2]}, new int[]{3,1,0}, dp[i][2]);
            dp[i][3] = function(dp, new int[]{i-cost[0],i-cost[1],i-cost[2]}, new int[]{0,2,1}, dp[i][3]);
        }
        if (dp[k][0] == 10000000) {
            dp[k][0] = -1;
        }
        System.out.println(dp[k][0]);
    }

    private static int function(int[][] dp, int[] i, int[] j, int back) {
        List<Integer> list = new ArrayList<>();
        for (int k = 0; k < 3; k++) {
            if (i[k]<0)continue;
            if (dp[i[k]][j[k]]!=10000000) {
                list.add(dp[i[k]][j[k]]);
            }
        }
        if (list.isEmpty()) {
            return back;
        }
        list.sort(Comparator.naturalOrder());
        return list.get(0) + 1;
    }
}
