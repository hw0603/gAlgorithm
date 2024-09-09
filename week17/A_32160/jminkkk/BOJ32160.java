package week17.A_32160.jminkkk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;

public class BOJ32160 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Deque<Integer> numbers = new LinkedList<>();
        StringBuilder sb = new StringBuilder();

        for (int i = 1; i <= n - 1; i++) {
            numbers.addLast(i);
        }

        while (numbers.size() > 1) {
            int n1 = numbers.removeLast();
            int n2 = numbers.removeLast();
            sb.append(n2).append(" ").append(n1).append(" ").append("\n");
            numbers.addLast(Math.abs(n1 - n2));
        }

        int last = numbers.removeLast();
        sb.append(n).append(" ").append(last).append(" ");
        System.out.println(n - last);
        System.out.println(sb);
    }
}
