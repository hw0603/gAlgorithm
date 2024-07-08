package week9;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ23830 {
    static int p;
    static int q;
    static int r;
    static long s;
    static int[] a;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        a = new int[str.length];

        long pureSum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(str[i]);
            pureSum += a[i];
        }

        str = br.readLine().split(" ");
        p = Integer.parseInt(str[0]);
        q = Integer.parseInt(str[1]);
        r = Integer.parseInt(str[2]);
        s = Long.parseLong(str[3]);

        // =================입력 끝==================
        // 무조건 -1인 경우
        if (pureSum + q * n < s) {
            System.out.println(-1);
            return;
        }

        // "+ 연산을 시켜야 하는 점수가 몇 개이냐" 찾기
        // 작을 수록 k도 작음
        Arrays.sort(a);
        int index = n + 1;

        if (calSum(a[0], 0) >= s) {
            if (a[0] != 0) {
                System.out.println(a[0]);
                return;
            }
            System.out.println(1);
            return;
        }

        for (int i = 1; i <= n; i++) {
            int tempK = a[i - 1] + 1;
            if (calSum(tempK, i) >= s) {
                index = i;
                break;
            }
        }

        if (index == n + 1) {
            System.out.println(-1);
            return;
        }

        System.out.println(a[index - 1] + 1);
    }

    public static long calSum(int tempK, int index) {
        long calSum = 0;
        for (int i = 0; i < index; i++) {
            calSum += a[i] + q;
        }

        for (int i = index; i < a.length; i++) {
            if (a[i] > tempK + r) {
                calSum += a[i] - p;
            } else {
                calSum += a[i];
            }
        }

        return calSum;
    }
}
