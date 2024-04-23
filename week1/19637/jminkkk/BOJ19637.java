import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class BOJ19637 {
    public static void main(String[] args) throws IOException {
        // 칭호의 개수 N, 칭호를 출력해야 하는 캐릭터들의 개수 M
        // 칭호의 이름 + 전투력 상한값
        // 캐릭터의 전투력에 맞는 칭호 출력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] NM = br.readLine().split(" ");
        int N = Integer.parseInt(NM[0]);
        int M = Integer.parseInt(NM[1]);

        List<Integer> maxRange = new ArrayList<>();
        List<String> chingho = new ArrayList<>();
        // 1. 값 범위별 칭호 저장
        for (int i = 0; i < N; i++) {
            NM = br.readLine().split(" ");
            maxRange.add(Integer.parseInt(NM[1]));
            chingho.add(NM[0]);
        }

        // 2. 캐릭터 전투력에 맞는 칭호 구하기
        // 2-1. 이진탐색 활용
        for (int i = 0; i < M; i++) {
            int power = Integer.parseInt(br.readLine());
            int start = 0;
            int last = chingho.size() - 1;

            while (start <= last) {
                int mid = (start + last) / 2; // 0

                if (maxRange.get(mid) < power) {
                    start = mid + 1;
                } else {
                    last = mid - 1;
                }
            }
            bw.write(chingho.get(start) + "\n");
        }
        bw.flush();
    }
}
