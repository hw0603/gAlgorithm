import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ15926 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split("");

        int max = 0;
        int sum = 0;
        Queue<String> queue = new LinkedList<>();
        // ( 만 저장

        for (int i = 0; i < str.length; i++) {
            if (str[i].equals(")")) {
                if (queue.isEmpty()) {
                    sum = 0;
                } else {
                    sum += 2;
                    queue.poll();
                    max = Math.max(max, sum);
                    System.out.println("max " + max);
                }
            } else {
                queue.add(str[i]);
            }
            System.out.println("sum " + sum);
            System.out.println("================");
        }

        System.out.println(max);
    }
}

// 12
// (()(()()(()(
