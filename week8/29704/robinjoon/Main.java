package org.example.p29704;

import java.awt.Point;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
/*
효율 순서대로 정렬 => 개같이 실패. 왜냐면 문제 하나당 효율이 남은 일수에 따라 계속 변하기 때문.
어떤 문제를 이미 골랐다는 가정 하에 나머지 것들 중 최대 값 => dp?

어떤 문제를 풀었다 vs 안풀었다 둘 중 하나

그 문제를 풀었다는 가정 하의 최대 값 => T - (그 문제의 소요 일수) 동안의 최대값 + 그 문제의 벌금

그 문제를 풀지 않았다는 가정 하의 최대 값 => 그 문제를 제외하고, T 동안의 최대값

위 두 값 중 뭐가 더 큰지가 그 문제를 풀지 안풀지 결정
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        List<Point> points = new ArrayList<>();
        points.add(null);
        for (int i = 0; i < n; i++) {
            points.add(new Point(sc.nextInt(),sc.nextInt()));
        }
        int[][] dp = new int[n+1][t+1]; // i 번째 까지 고려했을 때, t일 동안 최대값
        for (int i = 1; i <= n; i++) {
            Point p = points.get(i);
            for (int j = 1; j <= t; j++) {
                if(p.x > j) { // 풀 수 없음
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = Math.max(p.y + dp[i-1][j - p.x], dp[i-1][j]);
                }
            }
        }
        int all = points.stream().skip(1).mapToInt(p -> p.y).sum();
        System.out.println(all - dp[n][t]);
    }
}
