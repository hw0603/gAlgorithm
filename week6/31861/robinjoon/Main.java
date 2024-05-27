import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
/*
YA              ZA              ZB      AY      AZ              BZ
YAY     YAZ     ZAY     ZAZ     ZBZ     AYA     AZA     AZB     BZA     BZB
AYAY    AYAZ    AZAY    AZAZ    AZBZ    ZAYA    ZAZA    ZAZB    ZBZA    ZBZB
                BZAY    BZAZ    BZBZ    YAYA    YAZA    YAZB

특정 문자로 끝나는 m-1 길이의 문자열 개수 * cash.get().size = 길이가 m인 특정 문자로 끝나는 문자열 개수

a 로 끝나는 2 길이 문자열 개수 => a 이전에 올 수 있는 모든 문자로 끝나는 1 길이의 문자열 개수

a 로 끝나는 3 길이 문자열 개수 => Z로 끝나는 길이 2의 문자열 개수 + Y로 끝나는 길이 2의 문자열 개수

dp[i][m] = cash.get(i).sum(v -> dp[v][m-1])

sum(특정 문자로 끝나는 m-1 길이의 문자열 개수 * cash.get().size) = 길이가 m 인 문자열 개수
 */
public class Main {
    static Map<Integer,List<Integer>> cash = new HashMap<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] dp = new int[27][m+1];
        for (int now = 1; now <=26; now++) {
            List<Integer> next = new ArrayList<>();
            for (int i = 1; i <=26; i++) { //1 = A, 26 =Z
                if(Math.abs(i - now) >= n) {
                    next.add(i);
                }
            }
            cash.put(now,next);
        }
        for (int i = 1; i < 27; i++) {
            dp[i][1] = 1; // i 로 끝나는 길이가 1인 문자의 개수 = 1
        }
        for (int i = 2; i <=m ; i++) { // 길이가 i인
            for (int j = 1; j < 27; j++) { // 각 문자로 끝나는
                int sum = 0;
                List<Integer> list = cash.get(j);
                for (Integer integer : list) {
                    sum = (sum + dp[integer][i-1])% 1_000_000_007;
                }
                dp[j][i] = sum % 1_000_000_007;
            }
        }
        int sum = 0;
        for (int i = 1; i < 27; i++) {
            sum = (sum + dp[i][m])%1_000_000_007;
        }
        System.out.println(sum);
    }
}
//94665207
