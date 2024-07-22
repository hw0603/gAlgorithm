import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();

        long[] arr = new long[n + 1];
        arr[0] = 0;
        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        long[] sum = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i-1] + arr[i];
        }
        for (int i = 0; i < q; i++) {
            long x = sc.nextInt();
            int search = search(arr, x);
            if (search > n+1) {
                search = n+1;
            }
            long before = sum[search-1] - sum[0];
            long after = sum[sum.length-1] - sum[search-1];
            long answer = x * (long)(search-1) - before;
            answer += after - x * (long)(n-search + 1);
            System.out.println(answer);
        }
    }
    static int search(long[] arr, long target) {
        int left = 0;
        int right = arr.length;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (arr[mid] < target) {
                left = mid;
            }else {
                right = mid;
            }
        }
        return right;
    }
}
