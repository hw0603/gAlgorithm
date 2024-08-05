package week14.C_1464.jminkkk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1464 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int length = str.length() - 1;

        char max = 'Z';
        int index = length;
        while (index != 0) {
            if (str.charAt(index) <= str.charAt(0)
                    && str.charAt(index - 1) > str.charAt(0)) {
                String back = str.substring(index, str.length());
                str = reverse(str.substring(0, index)) + back;
                index = length;
                continue;
            }

            System.out.println(index);
            max = str.charAt(index) < max ? str.charAt(index) : max;
            index--;
        }

        max = str.charAt(index) < max ? str.charAt(index) : max;
        for (int i = length; i > 0; i--) {
            if (str.charAt(i) == max) {
                String back = str.substring(i + 1);
                str = reverse(str.substring(0, i + 1)) + back;
                break;
            }
        }

        System.out.println(str);
    }

    private static String reverse(String str) {
        StringBuilder sb = new StringBuilder();
        for (int i = str.length() - 1; i >= 0; i--) {
            sb.append(str.charAt(i));
        }
        return sb.toString();
    }
}
//EABCD
//DCBAE
//ABCDE
