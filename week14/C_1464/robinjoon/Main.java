import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        char[] charArray = str.toCharArray();
        for (int i = 0; i < charArray.length-1; i++) {
            if (charArray[i] < charArray[i+1]) {
                reverse(charArray, i);
                reverse(charArray, i+1);
            }
        }
        System.out.println(new StringBuilder(new String(charArray)).reverse());

    }
    private static void reverse(char[] arr, int endIndex) {
        char[] tmp = new char[endIndex+1];
        for (int i = 0; i <= endIndex; i++) {
            tmp[i] = arr[i];
        }
        for (int i = 0; i <= endIndex; i++) {
            arr[i] = tmp[endIndex-i];
        }
    }
}
