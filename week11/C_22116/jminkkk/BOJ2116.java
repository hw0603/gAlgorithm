package week11.C_22116.jminkkk;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

import javax.swing.Popup;

public class BOJ2116 {
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static long max = 0;
    static long[][] arr;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");

        // 경사가 N일 때 한번도 내리지 않고 갈 수 있음?
        // 경사: 인접한 격자 사이의 높이 차이의 절대값
        arr = new long[n][n];
        long first = Long.parseLong(str[0]);
        for (int i = 1; i < n; i++) {
            arr[0][i] = Math.max(Long.parseLong(str[i]) - first, 0);
        }

        for (int i = 1; i < n; i++) {
            str = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Math.max(Long.parseLong(str[j]) - first, 0);
            }
        }

        // 돌아서 가도 되는데 경로는 최대한 낮게 가야함
        Queue<Point> queue = new LinkedList<>();
        queue.add(new Point(0, 0));
        Point de = new Point(n - 1, n - 1);

        boolean[][] visited = new boolean[n][n];
        visited[0][0] = true;

        while (!queue.isEmpty()) {
            Point point = queue.poll();
            max = Math.max(arr[point.x][point.y], max);

            if (de.x == n - 1 && de.y == n - 1) {

                break;
            }

            int index = 0;
            long min = Integer.MAX_VALUE;
            int minX = 0;
            int minY = 0;

            for (int i = 0; i < 4; i++) {
                int newX = point.x + dx[i];
                int newY = point.y + dy[i];
                if (newX >= 0 && newX < n && newY >= 0 && newY < n
                        && !visited[newX][newY]) {
                    if (max < arr[newX][newY] && min > arr[newX][newY]) {
                        visited[newX][newY] = true;
                        minX = newX;
                        minY = newY;
                        min = arr[newX][newY];
                    } else {
                        visited[newX][newY] = true;
                    }
                }
            }

            // 같은데 다 막히면 max를 min으로 갱신하고 다시 ㄱㄱ
//            if () {
//                max = min;
//                visited[minX][minY] = false;
//            }

            queue.add(new Point(point.x + dx[index], point.y + dy[index]));
            visited[point.x + dx[index]][point.y + dy[index]] = true;
        }

        System.out.println(max);
    }
}

//3
//3 4 3
//2 5 2
//5 2 2

/**
 *  0 0 0 0 1
 *  1 1 1 0 1
 *  0 0 0 0 1
 *  0 1 1 1 1
 *  0 0 0 0 0
 */


//0 1 0
//0 2 0
//2 0 0
// 일단 자기랑 똑같거나 작은 곳으로 가려는데 막힘
// -> 다 막힘
// -> 막히는 곳들 중 제일 작은 곳으로
