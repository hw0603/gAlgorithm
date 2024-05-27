import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int tmp = Math.max(b,c);
        b = Math.min(b,c); // 짧은 걸 자동차로
        c = tmp; // 긴걸 캠핑카로

        int[][] map = new int[n+1][m+1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        int[][] sum = new int[n+1][m+1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = map[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        // a b ~ c d 까지의 합 = sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a][b]
        // 가로로 길게
        int min = Integer.MAX_VALUE;
        for (int i = 0; i <=n-a ; i++) {
            for (int j = 0; j <= m-b-c; j++) {
                min = Math.min(min, sum[i+a][j+b+c] - sum[i+a][j] - sum[i][j+b+c] + sum[i][j]);
            }
        }
        // 캠핑 가로 오른쪽 세로 자동
        for (int i = 0; i <=n-a-b ; i++) {
            for (int j = 0; j <= m-a-c; j++) {
                // i,j ~ i+a,j+c + i+a,j+c ~ i + a + b, j + c + a
                int s1 = sum[i + a][j + c] - sum[i + a][j] - sum[i][j + c] + sum[i][j];
                int s2 = sum[i + a+b][j + c+a] - sum[i + a+b][j+c] - sum[i+a][j + c+a] + sum[i+a][j+c];
                min = Math.min(min, s1 + s2);
            }
        }
        // 가로 자동 오른쪽 세로 캠핑
        for (int i = 0; i <=n-a-c ; i++) {
            for (int j = 0; j <= m-b-a; j++) {
                // i,j ~ i+a,j+b + (i+a,j+b ~ i+a+c,j+b+a)
                int s1 = sum[i + a][j + b] - sum[i + a][j] - sum[i][j + b] + sum[i][j];
                int s2 = sum[i + a+c][j + b+a] - sum[i + a+c][j+b] - sum[i+a][j + b+a] + sum[i+a][j+b];
                min = Math.min(min, s1 + s2);
            }
        }
        System.out.println(min);
    }
}
