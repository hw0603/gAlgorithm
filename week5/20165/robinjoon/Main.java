package org.example.p20165;

import java.awt.Point;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int r = sc.nextInt();
        Point[][] board = new Point[n+1][m+1]; // Point 의 y = 1 => 안넘어짐, 0 = 넘어짐
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                board[i][j] = new Point(sc.nextInt(),1);
            }
        }
        int dropCount = 0;
        for (int i = 0; i < r; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            String direction = sc.next();
            dropCount += drop(board, x, y, direction);
            int reX = sc.nextInt();
            int reY = sc.nextInt();
            board[reX][reY].y = 1;
        }
        System.out.println(dropCount);
        print(n, m, board);
    }

    private static void print(int n, int m, Point[][] board) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (board[i][j].y == 0) {
                    System.out.print("F ");
                } else {
                    System.out.print("S ");
                }
            }
            System.out.println();
        }
    }

    public static int drop(Point[][] board, int x, int y, String direction) {
        int dropCount = 0;
        if(board[x][y].y == 0) {
            return 0;
        }
        if(direction.equals("E")) {
            int end = board[x][y].x + y;
            for (int i = y; i < end; i++) {
                if(i >= board[1].length) {
                    break;
                }
                int x1 = board[x][i].x;
                if(board[x][i].y != 0)
                    end = Math.max(end, x1 + i);
                if (board[x][i].y == 1) {
                    board[x][i].y = 0;
                    dropCount++;
                }
            }
        }
        if(direction.equals("W")) {
            int end = y - board[x][y].x;
            for (int i = y; i > end; i--) {
                if(i < 1) {
                    break;
                }
                int x1 = board[x][i].x;
                if(board[x][i].y != 0)
                    end = Math.min(end, i - x1);
                if (board[x][i].y == 1) {
                    board[x][i].y = 0;
                    dropCount++;
                }
            }
        }
        if(direction.equals("S")) {
            int end = board[x][y].x + x;
            for (int i = x; i < end; i++) {
                if(i >= board.length) {
                    break;
                }
                int x1 = board[i][y].x;
                if(board[i][y].y != 0)
                    end = Math.max(end, x1 + i);
                if(board[i][y].y == 1 ) {
                    board[i][y].y = 0;
                    dropCount++;
                }
            }
        }
        if(direction.equals("N")) {
            int end = x - board[x][y].x;
            for (int i = x; i > end; i--) {
                if(i < 1) {
                    break;
                }
                int x1 = board[i][y].x;
                if(board[i][y].y != 0)
                    end = Math.min(end, i - x1);
                if (board[i][y].y == 1) {
                    board[i][y].y = 0;
                    dropCount++;
                }
            }
        }
        return dropCount;
    }
}
