import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class BOJ31861 {
    static int m;
    static int n;
    static Set<String> set = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);

        for (char i = 'A'; i <= 'Z'; i++) {
            String newP = String.valueOf(i);
            dfs(newP, i, 1);
        }

        int answer = set.size() % 1_000_000_007;
        System.out.println(answer);
    }

    public static void dfs(String full, char pre, int depth) {
        if (depth == m) {
            set.add(full);
            return;
        }

        // i + n부터 24, i - n 부터 1까지 dfs
        for (char i = (char) (pre + n); i <= 'Z'; i++) {
            String newFull = full + i;
            dfs(newFull, i, depth + 1);
        }

        for (char i = (char) (pre - n); i >= 'A'; --i) {
            String newFull = full + i;
            dfs(newFull, i, depth + 1);
        }
    }
}
