package week03;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ25215 {
    private static boolean onNemo;
    private static boolean isBeforeOnStart;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] str = br.readLine().toCharArray();

        if (str.length == 1) {
            if ((int) str[0] < 97) {
                System.out.println(2);
                return;
            }
            System.out.println(1);
            return;
        }

        // 처음 대문자가 들어오는데 다음 것이 처음과 같다면 마름모 (+=2, !flag)
        // 다음 것이 처음과 다르다면 별 (+= 2)
        onNemo = false;
        isBeforeOnStart = false;
        int count = 0; // index 0은 무시
        if ((int) str[0] < 97 && (int) str[1] < 97) {
            count += 2;
            onNemo = true;
        } else if ((int) str[0] < 97) {
            count += 2;
            isBeforeOnStart = true;
        } else {
            count++;
        }

        for (int i = 1; i < str.length - 1; i++) {
            count = getCount((int) str[i] >= 97, (int) str[i + 1] >= 97, count);
        }

        // 다르더라도 직전 것이 별이였으면 1만
        if ((int) str[str.length - 2] >= 97 != (int) str[str.length - 1] >= 97 && !isBeforeOnStart) {
            count += 2;
        } else {
            count++;
        }
        //   정답, 지금
// jarDDasCs 12, 13
// jarDDasCS 12, 12
// jarDDaCCs 12, 12
// jarDDaCCS 11, 12

        System.out.println(count);
    }

    public static int getCount(boolean now, boolean next, int count) {
        if (now == onNemo && next == onNemo) {
            isBeforeOnStart = false;
            onNemo = !onNemo;
            return count + 2;
        } else if (now == onNemo) {
            isBeforeOnStart = true;
            return count + 2;
        }

        isBeforeOnStart = false;
        return count + 1;
    }
}
// AaA
// 3 3 3 2 1
// jar DD asCs // 12
