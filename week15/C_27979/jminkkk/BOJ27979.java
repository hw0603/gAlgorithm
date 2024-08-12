package week15.C_27979.jminkkk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ27979 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");

        // 지금까지의 max 값보다 작은 값이 나오면 ++
        // 2 7 6 7 10 4 -> max보다 작은 개수 (max 까지의 현재 인덱스)
        int n = Integer.parseInt(str[0]);
        str = br.readLine().split(" ");
        int[] arr = new int[n];

        int max = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(str[i]);
            if (arr[i] < max) {
                count++;
            } else if (arr[i] >= max) {
                max = arr[i];
                count = i;
            }
        }

        System.out.println(count);
    }
}
