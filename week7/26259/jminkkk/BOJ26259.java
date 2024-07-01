//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//
//public class BOJ26259 {
//    static int x1;
//    static int y1;
//    static int x2;
//    static int y2;
//    static boolean garoByeok;
//
//    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        String[] str = br.readLine().split(" ");
//        int n = Integer.parseInt(str[0]);
//        int m = Integer.parseInt(str[1]);
//        int dp[][] = new int[n + 1][m + 1];
//        int arr[][] = new int[n + 1][m + 1];
//
//        for (int i = 1; i <= n; i++) {
//            str = br.readLine().split(" ");
//            for (int j = 0; j < m; j++) {
//                arr[i][j + 1] = Integer.parseInt(str[j]);
//            }
//        }
//
//        garoByeok = false;
//        boolean noByeok = false;
//        str = br.readLine().split(" ");
//        x1 = Integer.parseInt(str[0]);
//        y1 = Integer.parseInt(str[1]);
//        x2 = Integer.parseInt(str[2]);
//        y2 = Integer.parseInt(str[3]);
//        if (y2 - y1 == m || x2 - x1 == n) {
//            System.out.println("Entity");
//            return;
//        }
//
//        if (x1 == x2 && y1 != y2) { // --- 가로벽
//            garoByeok = true;
//            if (y1 > y2) {
//                int tmp = y1;
//                y1 = y2;
//                y2 = tmp;
//            }
//        } else if (x1 == x2) { // 벽업음
//            noByeok = true;
//        } else {
//            if (x1 > x2) {
//                int tmp = x1;
//                x1 = x2;
//                x2 = tmp;
//            }
//        }
//
//        dp[1][1] = arr[1][1];
//        if (noByeok) {
//            for (int i = 1; i <= n; i++) {
//                for (int j = 1; j <= m; j++) {
//                    if (i == 1) {
//                        dp[i][j] = dp[i][j - 1] + arr[i][j];
//                    } else if (j == 1) {
//                        dp[i][j] = dp[i - 1][j] + arr[i][j];
//                    } else {
//                        dp[i][j] = Math.max(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);
//                    }
//                }
//            }
//        } else {
//            if (garoByeok) { // 가로벽있음
//                for (int i = 1; i <= n; i++) {
//                    for (int j = 1; j <= m; j++) {
//                        if (cantGo(i, j)) { // 벽에 막힘
//                            if (j <= 1) { // 세로 옆을 봐야되는디 막혀있으면 그냥 0
//                                dp[i][j] = -40000000;
//                            } else {
//                                dp[i][j] = dp[i][j - 1] + arr[i][j];
//                            }
//                        } else { // 막히진 않았는데
//                            if (i == 1) {
//                                dp[i][j] = dp[i][j - 1] + arr[i][j];
//                            } else if (j == 1) {
//                                dp[i][j] = dp[i - 1][j] + arr[i][j];
//                            } else {
//                                dp[i][j] = Math.max(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);
//                            }
//                        }
//
//                        System.out.println("dp[" + i + "][" + j + "] " + dp[i][j]);
//
//                    }
//                }
//            } else { // 세로벽있음
//                for (int i = 1; i <= n; i++) {
//                    for (int j = 1; j <= m; j++) {
//                        if (cantGo(i, j)) { // 벽에 막힘
//                            if (i <= 1) { // 세로 옆을 봐야되는디 막혀있으면 그냥 0
//                                dp[i][j] = -40000000;
//                            } else {
//                                dp[i][j] = dp[i - 1][j] + arr[i][j];
//                            }
//                        } else { // 막히진 않았는데
//                            if (i == 1) {
//                                dp[i][j] = dp[i][j - 1] + arr[i][j];
//                            } else if (j == 1) {
//                                dp[i][j] = dp[i - 1][j] + arr[i][j];
//                            } else {
//                                dp[i][j] = Math.max(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);
//                            }
//                        }
//                        System.out.println("dp[" + i + "][" + j + "] " + dp[i][j]);
//                    }
//                }
//            }
//        }
//
//        System.out.println(dp[n][m]);
//    }
////2 2
////1 -10
////-100 10
////0 1 1 1
//
//    private static boolean cantGo(int i, int j) {
//        if (garoByeok) {
//            return j >= y1 && j < y2 && i == x1;
//        }
//        return i >= x1 && i < x2 && j == y1;
//    }
//}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ26259 {
    static int x1;
    static int y1;
    static int x2;
    static int y2;
    static boolean garoByeok;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);
        int[][] dp = new int[n + 1][m + 1];
        int[][] arr = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            str = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                arr[i][j + 1] = Integer.parseInt(str[j]);
                dp[i][j] = -1000000000;
            }
        }

        garoByeok = false;
        boolean noByeok = false;
        str = br.readLine().split(" ");
        x1 = Integer.parseInt(str[0]);
        y1 = Integer.parseInt(str[1]);
        x2 = Integer.parseInt(str[2]);
        y2 = Integer.parseInt(str[3]);
//        if (y2 - y1 == m || x2 - x1 == n) {
//            System.out.println("Entity");
//            return;
//        }
        if (x1 == x2 && y1 != y2) { // --- 가로벽
            garoByeok = true;
            if (y1 > y2) {
                int tmp = y1;
                y1 = y2;
                y2 = tmp;
            }
        } else if (y1 == y2 && x1 != x2) { // 세로벽
            if (x1 > x2) {
                int tmp = x1;
                x1 = x2;
                x2 = tmp;
            }
        } else {
            noByeok = true;
        }

        dp[1][1] = arr[1][1];
        if (noByeok) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (i == 1) {
                        dp[i][j] = dp[i][j - 1] + arr[i][j];
                    } else if (j == 1) {
                        dp[i][j] = dp[i - 1][j] + arr[i][j];
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);
                    }
                }
            }
        } else {
            if (garoByeok) { // 가로벽있음
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        if (cantGo(i - 1, j)) { // 벽에 막힘
                            if (j <= 1) { // 세로 옆을 봐야되는디 막혀있으면 그냥 0
                                dp[i][j] = -1000000000;
                            } else {
                                dp[i][j] = dp[i][j - 1] + arr[i][j];
                                System.out.println("dp[i][j - 1] " + dp[i][j - 1]);
                            }
                        } else { // 막히진 않았는데
                            if (i == 1 && j == 1) {
                                dp[i][j] = arr[i][j];
                            } else if (i == 1) {
                                dp[i][j] = dp[i][j - 1] + arr[i][j];
                            } else if (j == 1) {
                                dp[i][j] = dp[i - 1][j] + arr[i][j];
                            } else {
                                dp[i][j] = Math.max(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);
                            }
                        }
                        System.out.println("dp[" + i + "][" + j + "] " + dp[i][j]);
                    }
                }
            } else { // 세로벽있음
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        if (cantGo(i - 1, j - 1)) { // 벽에 막힘
                            if (i <= 1) { // 세로 옆을 봐야되는디 막혀있으면 그냥 0
                                dp[i][j] = -1000000000;
                            } else {
                                dp[i][j] = dp[i - 1][j] + arr[i][j];
                            }
                        } else { // 막히진 않았는데
                            if (i == 1 && j == 1) {
                                dp[i][j] = arr[i][j];
                            } else if (i == 1) {
                                dp[i][j] = dp[i][j - 1] + arr[i][j];
                            } else if (j == 1) {
                                dp[i][j] = dp[i - 1][j] + arr[i][j];
                            } else {
                                dp[i][j] = Math.max(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);
                            }
                        }
                    }
                }
            }
        }

        System.out.println(dp[n][m]);
    }
//2 2
//1 -10
//-100 10
//0 1 1 1

    private static boolean cantGo(int i, int j) {
        if (garoByeok) {
            return j >= y1 && j < y2 && i == x1;
        }
        return i >= x1 && i < x2 && j == y1;
    }
}
