import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class BOJ28420 {
    static int sum = Integer.MAX_VALUE;
    static int[][] arr;

    public static void main(String[] args) throws IOException {
        // 차와 캠핑카가 차지하는 단위 구역의 흐림 정도 합
        // 가장 맑은 곳에서 캠핑
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int y = Integer.parseInt(str[0]);
        int x = Integer.parseInt(str[1]);

        str = br.readLine().split(" ");
        int a = Integer.parseInt(str[0]);
        int b = Integer.parseInt(str[1]);
        int c = Integer.parseInt(str[2]);

        arr = new int[y][x];
        for (int i = 0; i < y; i++) {
            str = br.readLine().split(" ");
            for (int j = 0; j < x; j++) {
                arr[i][j] = Integer.parseInt(str[j]);
            }
        }

        // 1번째
        List<Point> points1 = new ArrayList<>();
        for (int yN = 0; yN <= a - 1; yN++) {
            for (int xN = 0; xN <= b + c - 1; xN++) {
                points1.add(new Point(xN, yN));
            }
        }

        // 2번째
        List<Point> points2 = new ArrayList<>();
        for (int nY = 0; nY <= a - 1; nY++) {
            for (int nX = 0; nX <= c - 1; nX++) {
                points2.add(new Point(nX, nY));
            }
        }
        for (int nY = a; nY <= a + b - 1; nY++) {
            for (int nX = c; nX <= c + a - 1; nX++) {
                points2.add(new Point(nX, nY));
            }
        }

        // 3번째
        List<Point> points3 = new ArrayList<>();
        for (int nY = 0; nY <= a - 1; nY++) {
            for (int nX = 0; nX <= b - 1; nX++) {
                points3.add(new Point(nX, nY));
            }
        }
        for (int nY = a; nY <= a + c - 1; nY++) {
            for (int nX = b; nX <= b + a - 1; nX++) {
                points3.add(new Point(nX, nY));
            }
        }

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (j + b + c <= x && i + a <= y) { // 1번 가능
                    hap(points1, j, i);
                }
                if (j + c + a <= x && i + a + b <= y) { // 2번 가능
                    hap(points2, j, i);
                }
                if (j + a + b <= x && i + a + c <= y) { // 3번 가능
                    hap(points3, j, i);
                }

            }
        }
        System.out.println(sum);
    }

    private static void hap(List<Point> points, int x, int y) {
        int hap = points.stream()
                .mapToInt(point -> arr[point.y + y][point.x + x])
                .sum();
        sum = Math.min(hap, sum);
    }
}
