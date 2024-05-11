package week03;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class BOJ17264 {
    public static void main(String[] args) throws IOException {
        // 1. 두 플레이어가 같이 게임
        // 2. 해킹을 통하여 알아내지 못한 플레이어와 같이 게임을 하는 경우 형동이가 매우 못하기 때문에 같은 팀원이 아무리 잘해도 반드시 진다.
        // 못알아거나 알아내도 지면 -15
        // 알아서 내서 이기면 +20
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]); // 게임 횟수
        int p = Integer.parseInt(str[1]); // 알게된 플레이어 수

        str = br.readLine().split(" ");
        int w = Integer.parseInt(str[0]); // 이길 경우 점수
        int l = Integer.parseInt(str[1]); // 질 경우 점수
        int g = Integer.parseInt(str[2]); // 티어 점수

        HashSet<String> winners = new HashSet<>();

        for (int i = 0; i < p; i++) {
            str = br.readLine().split(" ");
            if (str[1].equals("W")) {
                winners.add(str[0]);
            }
        }

        boolean isNotIron = false;
        int score = 0;
        for (int i = 0; i < n; i++) {
            String playerName = br.readLine();
            if (winners.contains(playerName)) {
                score += w;
                if (score >= g) {
                    isNotIron = true;
                }
            } else {
                score = Math.max(0, score - l);
            }
        }

        String answer = isNotIron ? "I AM NOT IRONMAN!!" : "I AM IRONMAN!!";
        System.out.println(answer);
    }
}
