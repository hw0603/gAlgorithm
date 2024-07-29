import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ23815 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        long noSkipVer = 1; // 광고 아직까지 안쓴거
        long skipVer = 1; // 광고 이미 쓴거
        boolean mustUseMinusBefore = false; // 이전에 썼었어야했음 -> 이전에 이미 안쓴것이 없어
        for (int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");
            char c = str[0].charAt(0);
            char b = str[1].charAt(0);

            if (mustUseMinusBefore) {
                skipVer = Math.max(operate(skipVer, str[0]), operate(skipVer, str[1]));
                noSkipVer = skipVer;
            } else if (isMinusOrDiv(c) && isMinusOrDiv(b)) {
                // 안 쓴거에 광고 써서 쓴 것보다 작다면 쓴 거 갱신 -> 쓴거
                // 쓴거에 광고 못 쓰고 skipVer 당하기
                skipVer = Math.max(noSkipVer, Math.max(operate(skipVer, str[0]), operate(skipVer, str[1])));
                noSkipVer = Math.max(operate(noSkipVer, str[0]), operate(noSkipVer, str[1]));
                // 안쓰면 - 되면 무조건 써야함
                if (noSkipVer <= 0) {
                    noSkipVer = skipVer;
                    mustUseMinusBefore = true;
                }
            } else {
                noSkipVer = Math.max(operate(noSkipVer, str[0]), operate(noSkipVer, str[1]));
                skipVer = Math.max(operate(skipVer, str[0]), operate(skipVer, str[1]));
            }

            if (skipVer <= 0) {
                System.out.println("ddong game");
                return;
            }
        }
        long answer = Math.max(noSkipVer, skipVer);
        System.out.println(answer);
    }

    public static boolean isMinusOrDiv(char c) {
        return c == '-' || c == '/';
    }

    public static long operate(long sum, String operAndValue) {
        char operation = operAndValue.charAt(0);
        int value = Integer.parseInt(operAndValue.substring(1));
        if (operation == '+') {
            return sum += value;
        }
        if (operation == '-') {
            return sum -= value;
        }
        if (operation == '/') {
            return sum /= value;
        }
        return sum *= value;
    }
}

