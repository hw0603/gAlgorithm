import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
    private static int[] dx = {0,1,0,-1};
    private static int[] dy = {-1,0,1,0};
    private static int max = 0;
    private static Map<Integer, Integer> counts = new HashMap<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] map = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        int color = 3;
        for (int i = 0; i< n;i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] ==2) {
                    dfs(map, new boolean[n][m],i,j,color);
                    color++;
                }
            }
        }
        for (int x1 = 0; x1 < n; x1++) {
            for (int y1 = 0; y1 < m; y1++) {
                if (map[x1][y1] !=0) continue;
                map[x1][y1] = 1; // 1로
                for (int x2 = 0; x2 < n; x2++) {
                    for (int y2 = 0; y2 < m; y2++) {
                        if (map[x2][y2] !=0) continue;
                        map[x2][y2] = 1; // 1로
                        //잡히는 2 개수 새기
                        countAndMax(map,n,m,color);
                        map[x2][y2] = 0; // 0으로
                    }
                }
                map[x1][y1] = 0; // 다시 0으로
            }
        }
        System.out.println(max);
    }

    private static void countAndMax(int[][] map, int n, int m, int maxColor) {
        Set<Integer> isCaughtColor = new HashSet<>();
        for (int color = 3; color < maxColor; color++) {
            boolean isNotCaught = false;
            checkCaught: for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (map[x][y]==color){
                        for (int i = 0; i < 4; i++) {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            if (nx>=0 && nx <n && ny>=0 && ny < m) {
                                if (map[nx][ny]==0){
                                    isNotCaught = true;
                                    break checkCaught;
                                }
                            }
                        }
                    }
                }
            }
            if (!isNotCaught) {
                isCaughtColor.add(color);
            }
        }
        int caughtCount = isCaughtColor.stream().mapToInt(counts::get)
                .sum();
        max = Math.max(max,caughtCount);
    }

    private static void dfs(int[][] map, boolean[][] visited, int x,int y, int color) {
        visited[x][y] = true;
        map[x][y] = color;
        counts.put(color, counts.getOrDefault(color,0)+1);
        for (int i = 0; i < 4; i++) {
            int nx = x+dx[i];
            int ny = y +dy[i];
            if (nx>=0 && nx <map.length && ny>=0 && ny < map[0].length) {
                if (map[nx][ny] == 2) {
                    dfs(map, visited, nx,ny,color);
                }
            }
        }
    }
}
