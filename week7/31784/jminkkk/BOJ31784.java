import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ31784 {
    static int K;
    static char arr[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);
        K = Integer.parseInt(str[1]);
        String s = br.readLine();
        arr = s.toCharArray();

        if (K == 0) {
            System.out.println(s);
            return;
        }
        // 자물쇠, A ~ Z
        // 가장 작은 문자열
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < N - 1; i++) {
            if (K == 0) {
                answer.append(arr[i]);
            } else {
                answer.append(change(arr[i]));
            }
        }

        if (arr[N - 1] + K % 26 > 'Z') {
            answer.append((char) (arr[N - 1] + (K % 26) - ('Z' - 'A' + 1)));
        } else {
            answer.append((char) ((arr[N - 1] + K % 26)));
        }

        System.out.println(answer);
    }

    private static char change(char now) {
        int aGap = ('Z' - now + 1) % 26;
        if (aGap <= K) {
            K -= aGap;
            return 'A';
        }
        return now;
    }
}
