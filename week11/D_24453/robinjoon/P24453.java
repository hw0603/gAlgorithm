package week11.D_24453.robinjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class P24453 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        String[] split = line.split(" ");
        int n = Integer.parseInt(split[0]);
        int m = Integer.parseInt(split[1]);

        boolean[] arr = new boolean[n];
        Arrays.fill(arr, true);
        line = br.readLine();
        split = line.split(" ");
        for (int i = 0; i < m; i++) {
            arr[Integer.parseInt(split[i]) - 1] = false;
        }
        line = br.readLine();
        split = line.split(" ");
        int x = Integer.parseInt(split[0]);
        int y = Integer.parseInt(split[1]);

        if (m == y) {
            System.out.println(0);
            return;
        }

        int bugCount = 0;
        int start = 0;
        int end = x-1;
        for (int i = start; i <= end; i++) {
            if (!arr[i])bugCount++;
        }
        int answer = Integer.MAX_VALUE;
        while (end < n) {
            if (bugCount==y) {
                System.out.println(m-y);
                return;
            }
            if (bugCount < y) {
                end++;
                if (!arr[end])bugCount++;
            }
            if (bugCount > y) {
                answer = Math.min(bugCount,answer);
                if (!arr[start])bugCount--;
                start++;
                end++;
                if (end == n)break;
                if (!arr[end])bugCount++;
            }
        }
        while (end - start + 1 > x) { // end가 끝까지 도달했을 때, 여전히 윈도우 크기가 x 보다 큰 경우
            if (bugCount < y)break;
            if (bugCount==y) {
                System.out.println(m-y);
                return;
            }
            answer = Math.min(bugCount, answer);
            if (!arr[start])bugCount--;
            start++;
        }
        System.out.println(m - answer);
    }
}
