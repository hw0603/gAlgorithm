import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ27210 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        if (str.length == 1) {
            System.out.println(1);
            return;
        }

        int max = 0;
        int sum1 = str[0].equals("1") ? 1 : 0;
        int sum2 = str[0].equals("2") ? 1 : 0;
        String past = str[0];
        for (int i = 1; i < n; i++) {
            if (str[i].equals(past)) {
                if (past.equals("1")) {
                    if (sum2 > 0) {
                        sum2--;
                    } else {
                        sum1++;
                    }
                } else {
                    if (sum1 > 0) {
                        sum1--;
                    } else {
                        sum2++;
                    }
                }
            } else {
                if (str[i].equals("1")) {
                    sum1++;
                    if (sum1 >= sum2) {
                        sum2 = 0;
                        past = "1";
                    }
                } else {
                    sum2++;
                    if (sum1 <= sum2) {
                        sum1 = 0;
                        past = "2";
                    }
                }
            }
            max = Math.max(max, Math.abs(sum2 - sum1));
        }
        System.out.println(max);
    }
}
