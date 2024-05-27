import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ31863 {
    static int N, M, count;
    static char[][] arr;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, -1, 0, 1};

    public static void main(String[] args) throws IOException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);
        arr = new char[N][M];

        for (int i = 0; i < N; i++) {
            arr[i] = br.readLine().toCharArray();
        }

        count = 0;
        int total = 0;

        int r = -1, col = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == '@') {
                    r = i;
                    col = j;
                } else if (arr[i][j] == '*' || arr[i][j] == '#') {
                    total++;
                }
            }
        }

        for (int k = 0; k < 4; k++) {
            for (int d = 1; d <= 2; d++) {
                int newRow = r + dy[k] * d;
                int newCol = col + dx[k] * d;
                if (newRow < 0 || newCol < 0 || newRow >= N || newCol >= M) {
                    break;
                }
                if (arr[newRow][newCol] == '|') {
                    break;
                }
                if (arr[newRow][newCol] == '#') {
                    arr[newRow][newCol] = '*';
                } else if (arr[newRow][newCol] == '*') {
                    arr[newRow][newCol] = '.';
                    count++;
                    yeojin(newRow, newCol);
                }
            }
        }
        System.out.print(count + " " + (total - count));
    }

    private static void yeojin(int row, int col) {
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if (newRow < 0 || newCol < 0 || newRow >= N || newCol >= M) {
                continue;
            }
            if (arr[newRow][newCol] == '|') {
                continue;
            }
            if (arr[newRow][newCol] == '#') {
                arr[newRow][newCol] = '*';
            } else if (arr[newRow][newCol] == '*') {
                arr[newRow][newCol] = '.';
                count++;
                yeojin(newRow, newCol);
            }
        }
    }
}
