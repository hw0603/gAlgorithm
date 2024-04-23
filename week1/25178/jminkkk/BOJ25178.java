import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ25178 {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int length = Integer.parseInt(bufferedReader.readLine());
        String original = bufferedReader.readLine();
        String strange = bufferedReader.readLine();

        // 1. 첫, 끝 글자 같은지 확인
        if (original.charAt(0) != strange.charAt(0)
                || original.charAt(length - 1) != strange.charAt(length - 1)) {
            System.out.println("NO");
            return;
        }

        // 2. 두 단어로부터 모음 모두 제거
        // 2 -1 . 제거한 단어가 동일한지 체크
        if (!original.replaceAll("a|e|i|o|u", "").equals(strange.replaceAll("a|e|i|o|u", ""))) {
            System.out.println("NO");
            return;
        }

        // 3. 같은 문자들로만 이루어져있는지 체크
        // 특정 문자의 갯수가 서로 다르다면 NO
        for (int i = 0; i < 24; i++) {
            String replace = String.valueOf((char) (i + 'a'));
            if (getCount(original, replace) != getCount(strange, replace)) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
    }

    public static int getCount(String word, String re) {
        String replace = word.replace(re, "");
        return word.length() - replace.length();
    }
}

