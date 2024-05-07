package week03;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ16401 {
    static int m;
    static int[] snacks;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        m = Integer.parseInt(str[0]); // 조카의 수
        int n = Integer.parseInt(str[1]); // 과자의 수

        // 길이와 상관없이 여러 조각으로 나눠질 수 있지만, 과자를 하나로 합칠 수는 없다.
        snacks = new int[n];
        str = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            snacks[i] = Integer.parseInt(str[i]);
        }
        Arrays.sort(snacks);

        if (m == 1) {
            System.out.println(snacks[snacks.length - 1]);
            return;
        }

        // 0 ~ last
        int start = 1;
        int end = snacks[n - 1];
        int mid = (start + end) / 2;

        if (mid <= 0 || !canEat(1)) {
            System.out.println(0);
            return;
        }

        while (start != end) {
            if (canEat(mid)) {
                if (mid < end && !canEat(mid + 1)) {
                    break;
                } else {
                    start = mid + 1;
                }
            } else { // 7 7
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }

        System.out.println(mid);
    }

    private static boolean canEat(int length) {
        int count = 0;
        for (int i = 0; i < snacks.length; i++) {
            count += snacks[i] / length;
        }
        return m <= count;
    }
}
