package week11.D_24453.jminkkk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ24453 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]); // 총 코드 수
        int m = Integer.parseInt(str[1]); // 오류의 갯수

        int[] errorLineArr = new int[m + 1];
        int[] gap = new int[m + 1];
        str = br.readLine().split(" ");
        for (int i = 1; i < m; i++) {
            errorLineArr[i] = Integer.parseInt(str[i]);
            gap[i] = errorLineArr[i] - errorLineArr[i - 1] - 1;
        }

        str = br.readLine().split(" ");
        long x = Long.parseLong(str[0]); // 연속 오류가 없어야 하는 코드 수
        int y = Integer.parseInt(str[1]); // 인규가 바꿀 코드 수

        if (x <= y) {
            System.out.println(m - y);
            return;
        }

        // m 중에 y개를 없앴을 때, 각 m의 차이 중 x보다 같거나 크냐
        // 1개를 없애면 그 양옆의 gap + 1 이 더해짐
        // 지워서 최대한 gap을 크게 만들기
        for (int i : errorLineArr) {

        }
        System.out.println(m - y);
        // 1 ()
        // 2
        // 3
        // 4 ()
        // 5
        // 6
        // 7 ()
        // 8
        // 9
        // 10 ()

        // 3 1

        // 1. x > y
        // ->
        // 2. x <= y
        // -> m - y
        // 3. x < y
        // -> m - y

    }
}
