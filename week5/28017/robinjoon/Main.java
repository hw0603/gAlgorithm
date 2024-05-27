import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int n;
    static int m;
    static int[][] min;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        min = new int[n+1][m+1];
        int[][] input = new int[n+1][m+1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                input[i][j] = sc.nextInt();
            }
        }
        for (int i = 1; i < m+1; i++) {
            min[1][i] = input[1][i];
        }
        for (int i = 1; i < m + 1; i++) {
            dp(min,input,n,i);
        }
        int answer = min[n][m];
        for (int i = 1; i < m+1; i++) {
            if(answer > min[n][i]){
                answer = min[n][i];
            }
        }
        System.out.println(answer);
    }
    public static int dp(int[][] min,int[][] input, int x, int y) {
        if (min[x][y] == 0) {
            List<Integer> before = new ArrayList<>();
            for (int i = 1; i < min[0].length; i++) {
                if (i == y)
                    continue;
                before.add(dp(min,input, x - 1, i));
            }
            int asInt = before.stream().mapToInt(i -> i).min().getAsInt();
            min[x][y] = asInt + input[x][y];
        }
        return min[x][y];
    }
}

