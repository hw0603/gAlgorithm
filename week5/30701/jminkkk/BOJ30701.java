import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BOJ30701 {
    public static void main(String[] args) throws IOException {
        // 전투력 D, N개의 방
        // 방의 전투력은 모두 다르다.
        // 돌파하지 않은 방 중 순서 자유
        // 방 입장
        // 몬스터
        // 근호  > 몬스터 승 & 근호 += 몬스터
        // 장비
        // 근호 *= 장비 & 얻고자하는 장비보다 전투력이 작은 모든 장비 Get
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]); // n개의 방
        long D = Integer.parseInt(str[1]);

        List<Integer> monster = new ArrayList<>();
        List<Integer> jangbi = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            str = br.readLine().split(" ");
            if (str[0].equals("1")) {
                monster.add(Integer.parseInt(str[1]));
            } else {
                jangbi.add(Integer.parseInt(str[1]));
            }
        }

        Collections.sort(monster);
        Collections.sort(jangbi);

        int count = 0;
        while ((!monster.isEmpty() && monster.get(0) < D)
                || (!jangbi.isEmpty())) {
                // 장비 또는 몬스터 중 하나라도 전투가능하다면

            while (!monster.isEmpty() && monster.get(0) < D) {
                D += monster.remove(0);
                count++;
            }

            if (!jangbi.isEmpty()) {
                D *= jangbi.remove(0);
                count++;
            }
        }
        System.out.println(count);
    }
}
