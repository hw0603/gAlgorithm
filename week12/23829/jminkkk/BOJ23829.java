import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ23829 {
    static long[] p;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // n개의 나무
        // 사진 = |사진을 찍은 위치 - 나무까지의 거리 합|
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        int q = Integer.parseInt(str[1]);

        // 1. 누적합으로 p들을 저장
        p = new long[n + 1];
        str = br.readLine().split(" ");
        for (int i = 1; i < n + 1; i++) {
            p[i] = Long.parseLong(str[i - 1]);
        }

        Arrays.sort(p);
        long[] sum = new long[n + 1];
        for (int i = 1; i < n + 1; i++) {
            sum[i] = sum[i - 1] + p[i];
        }

        for (int i = 0; i < q; i++) {
            long x = Long.parseLong(br.readLine());
            if (x < p[1]) {
                System.out.println(sum[n] - x * n);
                continue;
            }

            if (x > p[n]) {
                System.out.println(x * n - sum[n]);
                continue;
            }

            int c = getC(x);
            //3. sum[n] - 2 * sum[c] + x * (2c - n) 출력
            long answer = sum[n] - 2 * sum[c] + x * (2L * c - n);
            System.out.println(answer);
        }
    }

    // 2. 이분탐색으로 x보다 작은 수 중 가장 큰 pi의 인덱스 c를 구함
    public static int getC(long x) {
        int start = 1;
        int end = n;

        while (start + 1 < end) {
            int mid = (start + end) / 2;
            if (isSmallThan(mid, x)) {
                start = mid;
            } else {
                end = mid;
            }
        }

        return start;
    }

    private static boolean isSmallThan(int mid, long x) {
        return p[mid] <= x;
    }
}
