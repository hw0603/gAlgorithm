import java.util.*;
public class Main28471 {
    static int[] dx = new int[]{-1,-1,-1,0,1,1,0};
    static int[] dy = new int[]{-1,0,1,1,1,-1,-1};
    static int count = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[][] arr = new char[n][n];
        for (int i = 0; i < n; i++) {
            String input = sc.next();
            char[] chars = input.toCharArray();
            arr[i] = chars;
        }
        int[] end = new int[]{0,0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(arr[i][j] == 'F') {
                    end[0] = i;
                    end[1] = j;
                }
            }
        }
        bfs(arr, new boolean[n][n], end);
        System.out.println(count);
    }
    private static void bfs(char[][] arr, boolean[][] visited, int[] start) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(start);
        while (!queue.isEmpty()) {
            int[] now = queue.poll();
            visited[now[0]][now[1]] = true;
            for (int i = 0; i < 7; i++) {
                int nx = now[0] + dx[i];
                int ny = now[1] + dy[i];
                if(nx>=0 && nx < arr.length && ny>=0 && ny < arr.length && arr[nx][ny] != '#' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    count++;
                    queue.add(new int[]{nx,ny});
                }
            }
        }
    }
}
