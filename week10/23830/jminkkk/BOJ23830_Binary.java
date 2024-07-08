//package week9;
//
//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//
//public class BOJ23830_Binary {
//    static int p;
//    static int q;
//    static int r;
//    static long s;
//    static int[] a;
//
//    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//
//        int n = Integer.parseInt(br.readLine());
//        String[] str = br.readLine().split(" ");
//        a = new int[str.length];
//
//        long pureSum = 0;
//        for (int i = 0; i < n; i++) {
//            a[i] = Integer.parseInt(str[i]);
//            pureSum += a[i];
//        }
//
//        str = br.readLine().split(" ");
//        p = Integer.parseInt(str[0]);
//        q = Integer.parseInt(str[1]);
//        r = Integer.parseInt(str[2]);
//        s = Long.parseLong(str[3]);
//
//        // =================입력 끝==================
//        // k가 어떤 수이면 청소를 해야 한다
//        // k가 어떤 수이면 청소를 해야 하지 않는다
//        for (int k = 0; k <= 100_001; k++) {
//            if (notClean(k)) {
//                System.out.println(k);
//                return;
//            }
//        }
//
//        System.out.println(-1);
//    }
//
//    public static boolean notClean(int k) {
//        int low = 0;
//        int high = 100_000;
//
//        while (low + 1 < high) {
//            int mid = (high + low) / 2;
//            if (mustChunhso(k, mid)) {
//                high = mid;
//            } else {
//                mid =
//            }
//        }
//
//    }
//
//    public static boolean mustChunhso(int mid) {
//        long calSum = 0;
//        for (int i = 0; i < index; i++) {
//            calSum += a[i] + q;
//        }
//
//        for (int i = index; i < a.length; i++) {
//            if (a[i] > tempK + r) {
//                calSum += a[i] - p;
//            } else {
//                calSum += a[i];
//            }
//        }
//
//        return calSum;
//    }
//}
