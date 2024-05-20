import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ30804 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");

        if (N == 1) {
            System.out.println(N);
            return;
        }

        int a = Integer.parseInt(str[0]);
        int aIndex = 0;
        int b = Integer.parseInt(str[1]);
        int bIndex = 1;

        int max = 2;

        while (a == b) {
            bIndex++;
            if (bIndex == N) {
                System.out.println(N);
                return;
            }
            b = Integer.parseInt(str[bIndex]);
        }

        int sum = 2;
        for (int i = 2; i < N; i++) {
            int now = Integer.parseInt(str[i]);
            if (now == a || now == b) {
                sum++;
            } else {
                bIndex = i;
                a = Integer.parseInt(str[bIndex - 1]);
                b = Integer.parseInt(str[bIndex]);

                aIndex = bIndex;
                while (a == Integer.parseInt(str[aIndex])
                        || b == Integer.parseInt(str[aIndex])) {
                    aIndex--;
                }
                aIndex++;
                sum = bIndex - aIndex + 1;
            }
            max = Math.max(max, sum);
        }

        System.out.println(max);
    }
}
// 10
// 5 5 5 2 4 2 2 5 5 7
// 7 5 5 2 2 4 2 5 5 5 -> 4
// 7 5 5 2 4 2 2 5 5 5 -> 5
