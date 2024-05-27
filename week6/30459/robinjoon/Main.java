import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int r = sc.nextInt() * 2;
        int[] ns = new int[n];
        for (int i = 0; i < n; i++) {
            ns[i] = sc.nextInt();
        }
        Arrays.sort(ns);
        int[] ms = new int[m];
        for (int i = 0; i < m; i++) {
            ms[i] = sc.nextInt();
        }
        Arrays.sort(ms);
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = ns[j] - ns[i];
                int index = upperBound(ms, r / d);
                if (index == 0) {
                    continue;
                }
                max = Math.max(max, ms[index-1] * d);
            }
        }
        if (max == 0) {
            System.out.println(-1);
        }else {
            System.out.printf("%.1f",max / 2.0);
        }
    }
    static int upperBound(int[] ms,int find) {
        int start = 0;
        int end = ms.length;
        while (start < end) {
            int mid = (end + start) /2;
            if(find > ms[mid]) { // 오른쪽
                start = mid + 1;
            } else if(find == ms[mid]) {
                start = mid + 1;
            }else { // 왼쪽
                end = mid;
            }
        }
        return end;
    }
}
