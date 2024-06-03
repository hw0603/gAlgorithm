import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ28471 {
    static int N;
    static boolean[][] canGo;
    static int count;
    static int[] dx = {1, -1, 0, 1, 0, -1, -1}; // {-1, 0}
    static int[] dy = {1, 0, 1, -1, -1, 1, -1}; // {-1, 0}

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        canGo = new boolean[N][N];
        Point destination = null;

        for (int i = 0; i < N; i++) {
            str = br.readLine().split("");
            for (int j = 0; j < N; j++) {
                if (str[j].equals(".")) {
                    canGo[i][j] = true;
                } else if (str[j].equals("#")) {
                    canGo[i][j] = false;
                } else if (str[j].equals("F")) {
                    canGo[i][j] = true;
                    destination = new Point(i, j);
                }
            }
        }

        bfs(destination);
        System.out.println(count);
    }

    private static void bfs(Point point) {
        Queue<Point> queue = new LinkedList<>();
        queue.add(point);

        boolean[][] visited = new boolean[N][N];
        visited[point.x][point.y] = true;
        while (!queue.isEmpty()) {
            Point now = queue.poll();

            for (int i = 0; i < 7; i++) {
                int newX = now.x + dx[i];
                int newY = now.y + dy[i];

                if (newX >= 0 && newX < N && newY >= 0 && newY < N
                        && !visited[newX][newY] && canGo[newX][newY]) {
                    visited[newX][newY] = true;
                    count++;
                    queue.add(new Point(newX, newY));
                }
            }
        }
    }
}
