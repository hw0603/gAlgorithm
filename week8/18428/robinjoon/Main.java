import java.awt.Point;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
    static int[] dx = {0,1,0,-1};
    static int[] dy = {-1,0,1,0};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[][] arr = new String[n][n];
        List<Point> teachers = new ArrayList<>();
        List<Point> students = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = sc.next();
                if (arr[i][j].equals("S")){
                    students.add(new Point(i,j));
                }
                if (arr[i][j].equals("T")){
                    teachers.add(new Point(i,j));
                }
            }
        }
        Set<Point> objects = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(arr[i][j].equals("X")) {
                    objects.add(new Point(i,j));
                }
            }
        }
        for (Point p1 : objects) {
            for (Point p2 : objects) {
                if (p1.equals(p2))continue;
                for (Point p3 : objects) {
                    if (p1.equals(p3) || p2.equals(p3))continue;
                    arr[p1.x][p1.y] = "O";
                    arr[p2.x][p2.y] = "O";
                    arr[p3.x][p3.y] = "O";
                    boolean can = true;
                    check:for (Point teacher : teachers) {
                        for (int i = 0; i < 4; i++) {
                            for (int j = 1; j <= n; j++) {
                                int nx = teacher.x + j*dx[i];
                                int ny = teacher.y + j*dy[i];
                                if (nx>=0 && nx < n && ny >=0 && ny < n) {
                                    if (arr[nx][ny].equals("S")) { // 학생이면 이 조합은 실패한 것
                                        can = false;
                                        break check;
                                    }
                                    if (arr[nx][ny].equals("O")) { // 장애물이면 이 뒤는 보면 안됨.
                                        break;
                                    }
                                }else { // 한쪽 방향으로 범위 밖으로 감
                                    break;
                                }
                            }
                        }
                    }
                    arr[p1.x][p1.y] = "X";
                    arr[p2.x][p2.y] = "X";
                    arr[p3.x][p3.y] = "X";
                    if (can) {
                        System.out.println("YES");
                        return;
                    }
                }
            }
        }
        System.out.println("NO");
    }
}
