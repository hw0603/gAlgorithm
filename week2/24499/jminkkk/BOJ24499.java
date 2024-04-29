package week02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ24499 {
    public static void main(String[] args) throws IOException {
        // N개의 애플파이
        // 원형으로 배치, 맛있는 정도 수
        // 먹을 수 있는 최대값
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int k = Integer.parseInt(str[1]);

        int[] a = new int[n];
        str = br.readLine().split(" ");
        int max = 0;

        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(str[i]);
            max = Math.max(a[i], max);
        }

    }
}
