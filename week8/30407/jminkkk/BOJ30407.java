import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ30407 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]); // 냥냥펀치 수

        str = br.readLine().split(" ");
        int h = Integer.parseInt(str[0]); // 춘배의 체력
        int d = Integer.parseInt(str[1]); // 나비 사이의 거리
        int k = Integer.parseInt(str[2]); // 네발걷기 이동거리

        int[] r = new int[n];

        int max = Integer.MIN_VALUE;
        int maxIdx = 0;
        for (int i = 0; i < n - 1; i++) {
            r[i] = Integer.parseInt(br.readLine()); // i번째 냥냥펀치의 데미지
            if (r[i] > max) {
                maxIdx = i;
                max = r[i];
            }
        }

        int[][] dp = new int[n][3];
        // dp[i][j] = i번째 공격에서 j 스킬이 시전(적용된다면 춘배의 최대 채력
        // dp[i][j] = Math.max(dp[i - 1][
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < 3; j++) {
//                dp[i][j] = Math.max();
//            }
//        }

        System.out.println(h);
        // 냥냥펀치 : R(i)에서 춘배와 나비 사이의 거리를 뺀 값만큼 춘배의 체력이 깎인다. 체력이 깎이는 양은 음수가 될 수 없다.
        // 춘배의 3가지 기술
        // 1. 웅크리기: 나비가 공격할 시 데미지가 절반 감소한다. 데미지가 거리만큼 약해진 후 계산된다. 단, 감소 후 데미지의 소수점 아래는 버린다.
        // 2. 네발로 걷기: 문제에서 주어진 값 K 만큼 나비와 멀어지는 방향으로 이동
        // 3. 깜짝 놀라게 하기: 나비의 다음 행동을 1번 무시 (i번째 사용 할 시 R(i+1)를 무시)
        // 한 턴: 춘배의 기술 -> 냥냥펀치 -> 데미지 계산의 순서대로 실행
        // 나비가 모든 N개의 냥냥펀치를 하여 지칠 때까지 춘배가 유지할 수 있는 최대 체력
    }
}
// 깜짝 놀라기 다음은 거리 좁히기 쓰기

// 1번째 펀치, 깜짝 놀래기 -> 남은 hp: 100 - (20 - 3) = "83"
// 2번째 펀치, 깜짝 놀래기 영향 + 네발로 걷기 -> 남은 hp: "83" k = 6
// 3번째 펀치, 웅크리기 -> 남은 hp: 83 - ((20 - 6) / 2) = 83 - 7 = 76
// 4번째 펀치, 웅크리기 -> 남은 hp: 75 - ((20 - 6) / 2 ) = 76 - 7 = 69
