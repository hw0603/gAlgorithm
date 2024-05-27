import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int[] dx = {-1,-2,0,0,1,2,0,0}; // 행
    static int[] dy = {0,0,1,2,0,0,-1,-2}; // 열
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] arr = new int[n][m];

        int x=0,y=0;
        for (int i = 0; i < n; i++) {
            String line = sc.next();
            String[] split = line.split("");
            for (int j = 0; j < split.length; j++) {
                if(split[j].equals("*")){
                    arr[i][j] = 1;
                }
                if(split[j].equals(".")){
                    arr[i][j] = 4;
                }
                if(split[j].equals("|")){
                    arr[i][j] = 1000;
                }
                if(split[j].equals("#")){
                    arr[i][j] = 2;
                }
                if(split[j].equals("@")){
                    arr[i][j] = 3;
                    x = i;
                    y = j;
                }
            }
        }
        bfs(arr,x,y);
        int count = 0;
        int count2 = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                if(arr[i][j] <= 0) {
                    count++;
                }
                if(arr[i][j] == 1 || arr[i][j] == 2) {
                    count2++;
                }
            }
        }
        System.out.println(count +" " + count2);
    }
    static void bfs(int[][] arr, int x, int y) {
        boolean[][] visited = new boolean[arr.length][arr[0].length];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x,y});
        while (!queue.isEmpty()) {
            int[] now = queue.poll();
            for (int i = 0; i < 8; i++) {
                if(arr[now[0]][now[1]] == 0) { // 부서진 건물이면 한칸만 이동
                    if(i % 2 == 1) {
                        continue;
                    }
                }
                int nx = now[0] + dx[i];
                int ny = now[1] + dy[i];
                if (nx>=0 && nx < arr.length && ny>=0 && ny <arr[0].length) {
                    if(arr[nx][ny] == 1000) {
                        if(i%2==0 && arr[now[0]][now[1]] != 0) {
                            i++;
                        }
                        continue;
                    }
                    if (arr[nx][ny] == 2 || arr[nx][ny] == 1) {
                        arr[nx][ny]--;
                    }
                    if (arr[nx][ny] == 0 && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        queue.add(new int[]{nx,ny});
                    }
                }
            }
        }
    }
}
