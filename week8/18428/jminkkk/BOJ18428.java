//import java.awt.Point;
//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//
//public class BOJ18428 {
//    static int[] dx = {0, -1, 0, 1};
//    static int[] dy = {-1, 0, 1, 0};
//    static boolean flag;
//    static List<Point> teachers;
//    static List<Point> students;
//    static char[][] map;
//    static int n;
//
//    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        String[] str = br.readLine().split(" ");
//
//        n = Integer.parseInt(str[0]);
//        map = new char[n][n];
//
//        students = new ArrayList<>();
//        teachers = new ArrayList<>();
//
//        for (int i = 0; i < n; i++) {
//            map[i] = br.readLine().toCharArray();
//            for (int j = 0; j < n; j++) {
//                if (map[i][j] == 'S') {
//                    students.add(new Point(i, j));
//                } else if (map[i][j] == 'T') {
//                    teachers.add(new Point(i, j));
//                }
//            }
//        }
//
//        dfs(0);
//        System.out.println(flag);
//    }
//
//    private static void dfs(int depth) {
//        if (depth == 3) {
//            findStudent();
//            return;
//        }
//
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                if (map[i][j] == 'X') {
//                    map[i][j] = 'O'; // 장애물 등록
//                    dfs(depth + 1);
//                    map[i][j] = 'X';
//                }
//            }
//        }
//    }
//
//    public static void findStudent() {
//        Queue<Point> q = new LinkedList<>();
//        boolean[][] check = new boolean[n][n];
//        char[][] copyMap = new char[n][n];
//
//
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                copyMap[i][j] = map[i][j];
//            }
//        }
//
//        teachers.forEach(point -> {
//            check[point.y][point.x] = true;
//            q.add(point);
//        });
//
//        while (!q.isEmpty()) {
//            Point now = q.poll();
//            int x = now.x;
//            int y = now.y;
//
//            for (int k = 0; k < 4; k++) {
//                int nx = x + dx[k];
//                int ny = y + dy[k];
//
//                while (0 <= nx && nx < n && 0 <= ny && ny < n) {
//                    if (copyMap[nx][ny] != 'O') {
//                        check[nx][ny] = true;
//                        nx += dx[k];
//                        ny += dy[k];
//                    } else {
//                        break;
//                    }
//                }
//            }
//        }
//        if (catchStudent(check)) {
//            System.out.println("YES");
//            System.exit(0);
//        }
//    }
//
//    private static boolean catchStudent(boolean[][] check) {
//        for (Point point : students) {
//            if (check[point.x][point.y]) {
//                return false;
//            }
//        }
//        return true;
//    }
//}
