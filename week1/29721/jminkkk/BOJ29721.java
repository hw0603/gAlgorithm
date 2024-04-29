package week01;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

// 다바바 -> 2칸씩 이동하며 뛰어넘을 수 있음, 단 이동 자리에 있으면 못감
// 체스 크기 N, 다바바 개수 K

// 각 포인트 순회하면서 포인트에서 이동할 수 있는 포인트들 구하기
// Set에 저장 ->  Set의 갯수
public class BOJ29721 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] NK = br.readLine().split(" ");
        int N = Integer.parseInt(NK[0]);
        int K = Integer.parseInt(NK[1]);

        List<Point> points = new ArrayList<>();
        Set<Point> canMovePoint = new HashSet<>();
        for (int i = 0; i < K; i++) {
            NK = br.readLine().split(" ");
            Point point = new Point(Integer.parseInt(NK[0]), Integer.parseInt(NK[1]));
            points.add(point);
            canMovePoint.addAll(getCanMovePoint(point, N));
        }

        points.forEach(canMovePoint::remove);
//        canMovePoint.removeIf(points::contains);
        System.out.println(canMovePoint.size());
    }

    private static Set<Point> getCanMovePoint(Point point, int n) {
        int[] dx = {0, 2, 0, -2};
        int[] dy = {2, 0, -2, 0};

        Set<Point> movablePosition = new HashSet<>();
        for (int i = 0; i < 4; i++) {
            Point newPoint = new Point(point.x + dx[i], point.y + dy[i]);
            if (canMove(newPoint, n)) {
                movablePosition.add(newPoint);
            }
        }
        return movablePosition;
    }

    private static boolean canMove(Point point, int n) {
        return point.x <= n && point.x > 0 &&
                point.y <= n && point.y > 0;
    }
}
