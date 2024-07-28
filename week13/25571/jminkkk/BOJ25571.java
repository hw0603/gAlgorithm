import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ25571 {
    static String[] str;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            str = br.readLine().split(" ");
            if (str.length == 1) {
                System.out.println(0);
                return;
            }

            long sum = 0;
            boolean pastIsSuccess = true; // 이전이 지그재그였는지

            int start = 0;
            int end = 0;
            // 인덱스 0,1에 대한 처리 해주기
            if (str[0].equals(str[1])) {
                pastIsSuccess = false;
            } else {
                end++;
            }

            for (int j = 1; j < n - 1; j++) {
                if (str[j].equals(str[j + 1])) { // 이번 두 수는 지그재그 불가
                    if (pastIsSuccess) { // 이전 것은 성공이였다면 이전 range에 대한 부분 수열 계산
                        sum += calGroupCount(start, end);
                    }
                    pastIsSuccess = false;
                } else {
                    if (!pastIsSuccess) { // 저번이 실패였으면 이번 두 수가 지그재그 가능하니, 이번 것을 시작으로 만들기
                        pastIsSuccess = true;
                        start = j + 1;
                        end = j + 2;
                    } else {
                        if (isZigZagSuccess(j)) { // 저번이 성공, 이번도 성공이면 range 늘리기
                            end++;
                        } else { // 저번이 성공, 이번은 실패이면 이전 range에 대한 부분 수열 계산
                            sum += calGroupCount(start, end);
                            pastIsSuccess = false;
                            if (!str[j].equals(str[j + 1])) { // 이번 것이 이전이랑 비교하면 실패지만, 새로 시작가능하다면 range 다시 잡아주기
                                pastIsSuccess = true;
                                start = end;
                                end++;
                            }
                        }
                    }
                }
            }

            if (pastIsSuccess) { /// 성공한채로 끝난다면 계산되지 않은 마지막 range의 부분 수열 갯수 계산
                sum += calGroupCount(start, end);
            }

            System.out.println(sum);
        }
    }

    public static boolean isZigZagSuccess(int aIdx) {
        long a_1 = Integer.parseInt(str[aIdx - 1]);
        long a1 = Integer.parseInt(str[aIdx]);
        long a2 = Integer.parseInt(str[aIdx + 1]);
        return (a_1 - a1 > 0 && a1 - a2 < 0) || (a_1 - a1 < 0 && a1 - a2 > 0);
    }

    // 안 깨지는 구간에서 나올 수 있는 부분 배열 갯수
    public static long calGroupCount(long start, long end) {
        if (start >= end) {
            return 0;
        }
        long n = end - start + 1;
        return (n * (n - 1)) / 2;
    }
}
