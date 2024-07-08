package org.example.p23830;

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

    private static long p;
    private static long q;
    private static long r;
    private static long s;

    /*
    K + r 초과하는 학생의 수 * p 보다 K 미만인 학생인 수 * q 가 크면 유리

    이 수를 짧은 시간에 알 수 있으면 될거 같아!
    일단 오름차순 정렬 해놓고

    a b c d e f g h i j k l
            ^       ^
    k 가 늘어나면 자연스럽게 유리해진다.
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] points = new long[n];
        for (int i = 0; i < n; i++) {
            points[i] = sc.nextLong();
        }
        p = sc.nextLong();
        q = sc.nextLong();
        r = sc.nextLong();
        s = sc.nextLong();
        Arrays.sort(points);
        long search = search(points, 0, 10000000);
        System.out.println(search);
    }
    private static boolean ok(long[] points, long k) {
        long sum = 0;
        for (long point : points) {
            if (point < k) {
                sum += q;
            }
            if (point > k + r) {
                sum -= p;
            }
            sum += point;
        }
        return sum >= s;
    }
    private static long search(long[] points, long left, long right) {
        long result = -1;
        while (left + 1 < right) {
            long mid = (left + right) / 2;
            if(ok(points,mid)) {
                result = mid;
                right = mid;
            }else {
                left = mid;
            }
        }
        return result;
    }
}
