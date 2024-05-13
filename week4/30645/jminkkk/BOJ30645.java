package week04;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ30645 {
    public static void main(String[] args) throws IOException {
        // R C N
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int hang = Integer.parseInt(str[0]);
        int yeol = Integer.parseInt(str[1]);
        int n = Integer.parseInt(br.readLine());

        str = br.readLine().split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(str[i]);
        }
        Arrays.sort(arr);

        int[] past = new int[yeol];
        int yeolIndex = 0; // 인형
        int score = 0;

        // past[i] 랑 비교
        // 현재값이 더 크면 ++
        // past[i] = 현재값
        for (int i = 0; i < n; i++) {
            yeolIndex %= yeol;
            if (past[yeolIndex] < arr[i]) {
                score++;
                past[yeolIndex] = arr[i];
            }
            yeolIndex++;

            if (score >= yeol * hang) {
                break;
            }
        }
        System.out.println(score);
    }
}
// 3 2
// 8
// 1 2 3 4 66 7 8 9 9
// 가장 작은 아이들을 앞에서부터


// 2 2
// 5
// 2 2 2 4 4
