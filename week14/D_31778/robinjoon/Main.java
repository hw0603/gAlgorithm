import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        String str = sc.next();
        char[] chars = str.toCharArray();

        int left = Math.max(str.indexOf('C'),0);
        int right = Math.max(str.lastIndexOf('P'),n-1);

        int moveCount = 0;
        while (left < right && moveCount < k) {
            if (chars[left] == 'C') {
                if (chars[right] == 'P') {
                    char tmp = chars[left];
                    chars[left] = chars[right];
                    chars[right] = tmp;
                    left++;
                    right--;
                    moveCount++;
                }else {
                    right--;
                }
            }else {
                left++;
            }
        }
        long pccCount = 0;
        char[] chars1 = new char[n+1];
        for (int i = 0; i < n; i++) {
            chars1[i+1] = chars[i];
        }
        long[] pSum = new long[n+1];
        long[] cSum = new long[n+1];
        long pMax = 0;
        long cMax = 0;
        for (int i = 1; i <= n; i++) {
            if (chars1[i] == 'P') {
                pSum[i] = Math.max(pSum[i-1] + 1, pMax + 1);
                pMax = Math.max(pMax, pSum[i]);
                cSum[i] = cMax;
            }else {
                cSum[i] = Math.max(cSum[i-1] + 1, cMax + 1);
                cMax = Math.max(cMax, cSum[i]);
                pSum[i] = pMax;
            }
        }
        // 처음 C 가 나오는 인덱스 기준으로 그 이전의 P, 그 이후의 C 계산, 그 뒤에 C가 나오는 기준으로
        long lastPCount = 0;
        for (int i = 1; i <= n; i++) {
            if (chars1[i] == 'P')continue;
            long p = pSum[i] - pSum[0];
            long c = cSum[n] - cSum[i-1];
            pccCount += (p * (p-1) / 2L - lastPCount) * c;
            lastPCount = p * (p-1) / 2L;
        }
        System.out.println(pccCount);
    }
}
