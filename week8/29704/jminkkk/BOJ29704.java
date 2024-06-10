import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class BOJ29704 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int t = Integer.parseInt(str[1]);

        List<Node> nodes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            str = br.readLine().split(" ");
            int a = Integer.parseInt(str[0]);
            int b = Integer.parseInt(str[1]);
            nodes.add(new Node(a, b));
        }

        int[][] dp = new int[t + 1][n + 1];
        int sum = nodes.stream()
                .mapToInt(node -> node.money)
                .sum();

        for (int i = 1; i <= n; i++) {
            Node node = nodes.get(i - 1);
            for (int j = 1; j <= t; j++) {
                if (j - node.day < 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - node.day] + node.money);
                }
            }
        }

        System.out.println(sum - dp[t][n]);
        //            for (int j = 1; j < nodes.size(); j++) {
//                Node node = nodes.stream()
//                        .filter(node1 -> node1.day == j)
//                        .findFirst();
////                dp[i - j] + arr[j]
//            }
//        }

        // dp[i] = Math.min(dp[i - a] + arr[a])
    }
}

class Node implements Comparable<Node> {
    int day;
    int money;

    public Node(int a, int b) {
        this.day = a;
        this.money = b;
    }

    public int compareTo(final Node o) {
        if (o.day == this.day) { // day가 같으면 money가 큰 게 앞으로
            return this.money - o.money;
        } // day가 작은게 앞으로
        return o.day - this.day;
    }
}
