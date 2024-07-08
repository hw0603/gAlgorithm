import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class BOJ23352 {
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static int[][] arr;
    static List<Point> points;
    static int n;
    static int m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);

        arr = new int[n][m];
        points = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            str = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(str[j]);
                if (arr[i][j] != 0) {
                    points.add(new Point(j, i));
                }
            }
        }

        int maxDist = -1;
        int maxSum = 0;

        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i; j < points.size(); j++) {
                Point start = points.get(i);
                Point end = points.get(j);

                int dist = bfs(start, end);
                if (dist > maxDist) {
                    maxDist = dist;
                    maxSum = arr[start.y][start.x] + arr[end.y][end.x];
                } else if (dist == maxDist) {
                    maxSum = Math.max(maxSum, arr[start.y][start.x] + arr[end.y][end.x]);
                }
            }
        }
        System.out.println(maxSum);
    }

    public static int bfs(Point start, Point end) {
        int[][] dist = new int[n][m];
        for (int[] row : dist) {
            Arrays.fill(row, -1);
        }

        Queue<Point> queue = new LinkedList<>();
        queue.add(start);
        dist[start.y][start.x] = 0;

        while (!queue.isEmpty()) {
            Point point = queue.poll();
            int x = point.x;
            int y = point.y;

            if (x == end.x && y == end.y) {
                return dist[y][x];
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n
                        && arr[ny][nx] != 0 && dist[ny][nx] == -1) {
                    dist[ny][nx] = dist[y][x] + 1;
                    queue.add(new Point(nx, ny));
                }
            }
        }
        return -1;
    }
}
