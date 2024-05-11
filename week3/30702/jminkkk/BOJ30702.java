package week03;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class BOJ30702 {
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        // 1. 색만 다르고 모양 같은 국기
        // 2. N-M 모든 구간의 색(A~Z)이 동일하다면 같은 국기
        // 3. 주어진 다른 2개의 국기를 같은 국기로 만들기 위해 색을 칠할 거임
        // 3-1. 같은 구역 -> 같은 색이면서 인접한 곳
        // 3-2. 구역을 원하는 색으로 변경 가능

        // A, B 각각 bfs로 인접한 곳들을 다 담아서 리스트로 만들기
        // 담은 곳들이 동일한지 체크
        // 어케 체크할거임?

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);
        int M = Integer.parseInt(str[1]);

        char[][] a = new char[N][M];
        char[][] b = new char[N][M];

        for (int i = 0; i < N; i++) {
            a[i] = br.readLine().toCharArray();
        }

        for (int i = 0; i < N; i++) {
            b[i] = br.readLine().toCharArray();
        }

        List<List<Point>> bfsA = getBfs(a);
        List<List<Point>> bfsB = getBfs(b);

        for (List<Point> small : bfsA) {
            // 모든 list에 대해 bfsB가 가지고 있으면 됌
            boolean isContains = false;
            for (List<Point> big : bfsB) {
                if (big.containsAll(small)) {
                    isContains = true;
                }
            }
            if (!isContains) {
                System.out.println("NO");
                return;
            }
        }

        // 합치기를 해야함... 어케하누...
//        String answer = bfsB.containsAll(bfsA) ? "YES" : "NO";
        System.out.println("YES");
    }

    public static List<List<Point>> getBfs(char[][] arr) {
        List<List<Point>> lists = new ArrayList<>();
        boolean[][] visited = new boolean[arr.length][arr[0].length];

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                if (visited[i][j]) {
                    continue;
                }

                List<Point> points = new ArrayList<>();
                Stack<Point> stack = new Stack<>();

                stack.add(new Point(i, j));
                visited[i][j] = true;

                while (!stack.isEmpty()) {
                    Point now = stack.pop();

                    for (int k = 0; k < 4; k++) {
                        int newX = now.x + dx[k];
                        int newY = now.y + dy[k];

                        if (newX < arr.length && newX >= 0 && newY < arr[0].length && newY >= 0
                                && !visited[newX][newY]
                                && arr[now.x][now.y] == arr[newX][newY]) {
                            stack.add(new Point(newX, newY));
                            visited[newX][newY] = true;
                        }
                    }
                    points.add(now);
                }

                lists.add(points);
            }
        }

        return lists;
    }
}

// 틀린 이유 아래 테케 안돼뮤
// 2 4
// AAAA
// BBBB
// AAAA
// AAAA
