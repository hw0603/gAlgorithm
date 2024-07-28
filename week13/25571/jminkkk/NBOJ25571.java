import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class NBOJ25571 {
    static String[] str;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            str = br.readLine().split(" ");
            if (str.length == 1) {
                System.out.println(0);
                continue;
            }

            long sum = 0;
            long pastGap = Integer.parseInt(str[0]) - Integer.parseInt(str[1]);
            long count = pastGap != 0 ? 1 : 0;
            for (int j = 1; j < n - 1; j++) {
                long nowGap = Integer.parseInt(str[j]) - Integer.parseInt(str[j + 1]);
                if (nowGap * pastGap < 0) { // 음수면 지그재그 성공
                    count++;
                } else if (nowGap != 0 && pastGap == 0) { // 음수면 지그재그 성공
                    count = 1;
                } else { // 지그재그 실패
                    sum += calGroupCount(count);
                    count = 0;
                    if (nowGap != 0) { // 이번부터 새로 count
                        count++;
                    }
                }
                pastGap = nowGap;
            }
            sum += calGroupCount(count);
            System.out.println(sum);
        }
    }

    public static long calGroupCount(long count) {
        return (count * (count + 1)) / 2;
    }
}
