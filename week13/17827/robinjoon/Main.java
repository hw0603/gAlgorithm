import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String[] sp = s.split(" ");
        int n = Integer.parseInt(sp[0]);
        int m = Integer.parseInt(sp[1]);
        int v = Integer.parseInt(sp[2]);

        int[] arr = new int[n];
        s = br.readLine();
        sp = s.split(" ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(sp[i]);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            int a = Integer.parseInt(br.readLine());
            if (a < n) {
                sb.append(arr[a]).append("\n");
                continue;
            }
            int index = (a-n) % (n-v+1) + v-1;
            sb.append(arr[index]).append("\n");
        }
        System.out.println(sb);
    }
}
