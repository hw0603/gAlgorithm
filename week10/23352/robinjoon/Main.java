package org.example.p23352;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    private static int[] dx = {0,1,0,-1};
    private static int[] dy = {-1,0,1,0};

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
        Map<int[], int[]> results = new HashMap<>();
        int maxLength = 0;
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j]==0)continue;
                int[] bfs = bfs(i, j, map);
                if (maxLength < bfs[2]) {
                    maxLength = bfs[2];
                    max = map[i][j] + map[bfs[0]][bfs[1]];
                }else if (maxLength == bfs[2]) {
                    max = Math.max(max, map[i][j] + map[bfs[0]][bfs[1]]);
                }
            }
        }
        System.out.println(max);
    }
    static int[] bfs(int x, int y, int[][] map) {
        List<int[]> result = new ArrayList<>();
        boolean[][] visited = new boolean[map.length][map[0].length];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x,y,0});
        while (!queue.isEmpty()) {
            int[] poll = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = poll[0] +dx[i];
                int ny = poll[1] +dy[i];
                int nextLength = poll[2] + 1;
                if (nx>=0 && nx <map.length && ny>=0 && ny<map[0].length) {
                    if (!visited[nx][ny] && map[nx][ny]!=0) {
                        visited[nx][ny] = true;
                        queue.add(new int[]{nx,ny,nextLength});
                    }
                }
            }
            if (queue.isEmpty()) {
                result.add(poll);
            }
        }
        int[] max = result.stream().sorted((o1, o2) -> {
            int compare = Integer.compare(o2[2], o1[2]);
            if (compare == 0) {
                return Integer.compare(map[x][y] + map[o2[0]][o2[1]], map[x][y] + map[o1[0]][o1[1]]);
            }
            return compare;
        }).collect(Collectors.toList()).get(0);
        return max;
    }
}
