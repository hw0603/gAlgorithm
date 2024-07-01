import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ27313 {
    static int[] list;
    static int n;
    static int m;
    static int k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]); // 봐야 하는 애니메이션의 개수
        m = Integer.parseInt(str[1]); // 사용할 수 있는 시간
        k = Integer.parseInt(str[2]); // 동시에 볼 수 있는 애니메이션의 개수

        str = br.readLine().split(" ");

        list = new int[n + 2];
        list[0] = 0;
        for (int i = 1; i <= n; i++) {
            list[i] = Integer.parseInt(str[i - 1]);
        }

        list[n + 1] = 100_000_0001;
        Arrays.sort(list);

        int low = 0;
        int high = n + 1;

        while (low + 1 < high) {
            int mid = (high + low) / 2;
            if (canSee(mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }

        if (low == 0) {
            System.out.println(0);
            return;
        }
        System.out.println(low);
    }

    private static boolean canSee(int index) {
        int nowRestTime = m;
        int now = index + 1;
        while (now > 1) {
            nowRestTime -= list[now - 1];

            if (nowRestTime < 0) {
                return false;
            }
            now -= k;
        }

        return true;
    }
}
