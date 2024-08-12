package week15.A_20438.jminkkk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class BOJ20438 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");

        int n = Integer.parseInt(str[0]);
        int k = Integer.parseInt(str[1]);
        int q = Integer.parseInt(str[2]);
        int m = Integer.parseInt(str[3]);

        Set<Integer> sleep = new HashSet<>();
        Set<Integer> attendance = new HashSet<>();

        str = br.readLine().split(" ");
        for (int i = 0; i < k; i++) {
            sleep.add(Integer.parseInt(str[i]));
        }

        str = br.readLine().split(" ");
        for (int i = 0; i < q; i++) {
            int num = Integer.parseInt(str[i]);
            if (!sleep.contains(num)) {
                attendance.add(num);

                int index = 2;
                while (num * index <= n + 2) {
                    if (!sleep.contains(num * index)) {
                        attendance.add(num * index);
                    }
                    index++;
                }
            }
        }

        int[] count = new int[n + 3];
        count[0] = 0;
        count[1] = 0;
        count[2] = 0;
        for (int i = 3; i <= n + 2; i++) {
            count[i] = !attendance.contains(i) ? count[i - 1] + 1 : count[i - 1];
        }

        for (int i = 0; i < m; i++) {
            str = br.readLine().split(" ");
            System.out.println(count[Integer.parseInt(str[1])] - count[Integer.parseInt(str[0]) - 1]);
        }
    }
}
// 3 4 6 8 9 12 16 18 20 21 25 28 30 32 33 36 39 40 42 44 45 48 50 51 52
