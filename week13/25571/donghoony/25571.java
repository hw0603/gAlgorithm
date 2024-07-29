import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int readInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    static long[] readLongs() throws IOException {
        return Arrays.stream(br.readLine().split(" "))
                .mapToLong(Long::parseLong)
                .toArray();
    }

    public static void main(String[] args) throws IOException {
        int T = readInt();
        for (int i = 0; i < T; i++) solve();
    }

    static void solve() throws IOException {
        int n = readInt();
        long[] arr = readLongs();
        long ans = 0;
        int l = 0, r = 1;
        while (l < n-1) {
            while (l < n-1 && arr[l] == arr[r]) { l++; r++; }
            while (r < n-1 && (arr[r] - arr[r-1]) * (arr[r+1] - arr[r]) < 0) r++;
            long len = r - l + 1;
            if (r < n) ans += len * (len-1) / 2;
            l = r; r++;
        }
        System.out.println(ans);
    }
}
