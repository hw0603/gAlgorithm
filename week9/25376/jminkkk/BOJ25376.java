
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class BOJ25376 {
    static int count;
    static boolean[] on;
    static boolean[] visited;
    static int N;
    static List<List<Integer>> list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");

        on = new boolean[N];
        for (int i = 0; i < N; i++) {
            on[i] = str[i].equals("1");
        }

        list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            str = br.readLine().split(" ");

            List<Integer> linked = new ArrayList<>();
            for (int j = 1; j < str.length; j++) {
                linked.add(Integer.parseInt(str[j]) - 1);
            }

            list.add(linked);
        }

        for (count = 0; count <= N; count++) {
            visited = new boolean[N];
            if (dfs(0)) {
                System.out.println(count);
                return;
            }
        }

        System.out.println(-1);
    }

    private static boolean dfs(int depth) {
        if (depth == count) {
            for (boolean b : on) {
                if (!b) {
                    return false;
                }
            }
            return true;
        }

        for (int i = 0; i < N; i++) {
            if (!visited[i] && !on[i]) {
                visited[i] = true;
                turn(i);
                if (dfs(depth + 1)) {
                    return true;
                }
                turn(i);
                visited[i] = false;
            }
        }

        return false;
    }

    private static void turn(int index) {
        on[index] = !on[index];
        List<Integer> linkedS = list.get(index);
        for (int changIdx : linkedS) {
            on[changIdx] = !on[changIdx];
        }
    }
}
