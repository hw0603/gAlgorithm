import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            long[] arr = new long[n];
            String input = br.readLine();
            String[] split = input.split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Long.parseLong(split[i]);
            }
            List<Long> answers = new ArrayList<>();
            int start = 0;
            int end = 1;
            while (start < end) {
                if (end == n) {
                    answers.add((long)end - start);
                    break;
                }
                if (arr[end] - arr[end-1] == 0) { // 같아서 지그재그 아님 => start = end
                    answers.add((long)end - start);
                    start = end;
                    end++;
                    continue;
                }
                if (start + 2 <= end) {
                    boolean left = arr[end-1] > arr[end-2];
                    boolean right = arr[end] > arr[end-1];
                    if (left != right) { // 지그재그
                        end++;
                    }else { // 증감 방향이 같아서 지그재그 아님
                        answers.add((long)end - start);
                        start = end -1;
                    }
                }else { // 시작점과 끝 점의 차이가 1임
                    if (arr[start] != arr[end]) { // 지그재그임
                        end++;
                    }else { // 둘이 같아서 지그재그 아님
                        start = end;
                        end++;
                    }
                }
            }
            long a = 0L;
            for (Long answer : answers) {
                a = a + (answer * (answer-1) /2);
            }
            System.out.println(a);
        }
    }
}
