import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ20165 {
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static int[][] domino;
    static boolean[][] visited;
    static int n;
    static int m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]); // 게임판의 행 개수
        m = Integer.parseInt(str[1]); // 열 개수
        int r = Integer.parseInt(str[2]); // 라운드 횟수
        domino = new int[n][m];
        visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            str = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                domino[i][j] = Integer.parseInt(str[j]);
            }
        }

        int sum = 0;
        for (int i = 0; i < r * 2; i++) {
            str = br.readLine().split(" ");
            int nowN = Integer.parseInt(str[0]) - 1;
            int nowM = Integer.parseInt(str[1]) - 1;

            if (i % 2 == 0) { // 공격
                if (str[2].equals("E")) {
                    sum += attack(nowN, nowM, 0);
                } else if (str[2].equals("W")) {
                    sum += attack(nowN, nowM, 1);
                } else if (str[2].equals("S")) {
                    sum += attack(nowN, nowM, 2);
                } else {
                    sum += attack(nowN, nowM, 3);
                }
            } else { // 수비
                visited[nowN][nowM] = false;
            }
            print();
            System.out.println("====================");
        }

        System.out.println(sum);
        print();
    }

    private static void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j]) {
                    System.out.print("F ");
                } else {
                    System.out.print("S ");
                }
            }
            System.out.println();
        }
    }

    private static int attack(int y, int x, int direction) {
        if (visited[y][x]) {
            return 0;
        }

        int sum = 1;
        visited[y][x] = true;
        int count = domino[y][x] - 1;
        int newN = y + dy[direction];
        int newM = x + dx[direction];
        while (true) {
            if (newN < 0 || newN >= n || newM < 0 || newM >= m
                    || count < 0) {
                break;
            }

            if (!visited[newN][newM]) { // 쓰러지지 않았다면
                sum++;
                if (count == 1) { // 연쇄 작용 체크
                    count += domino[newN][newM] - 1;
                }
            }

//            if (visited[newN][newM] && count == 0) {
//                break;
//            }
//
            visited[newN][newM] = true;
            count--;
            newN += dy[direction];
            newM += dx[direction];
        }

        return sum;
    }
}

//1 1 1 1 1
//1 2 2 1 1
//3 1 2 2 2
//1 3 2 1 1
//1 3 3 1 1
