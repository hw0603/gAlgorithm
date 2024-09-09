import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        if (n == 2) {
            System.out.println("1\n2 1");
            return;
        }
        StringBuilder sb = new StringBuilder();
        Queue<Integer> queue = new LinkedList<>();
        boolean oneRemain = false;
        for (int i = n - 1; i >= 1; i -= 2) {
            if (i == 1) {
                oneRemain = true;
                break;
            }
            queue.add(i);
            queue.add(i-1);
        }
        while (queue.size() >=2) {
            int a = queue.poll();
            int b = queue.poll();
            sb.append(a).append(" ").append(b).append("\n");
            queue.add(Math.abs(a - b));
            if (queue.size() == 1 && oneRemain) {
                queue.add(1);
                oneRemain = false;
            }
        }

        int last = queue.poll();
        sb.append(n).append(" ").append(last).append("\n");
        System.out.println(n - last);
        System.out.println(sb);
    }
}
