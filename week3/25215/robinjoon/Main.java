import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        
        int result = str.length();
        
        char[] chars = str.toCharArray();
        /*
        바뀐게 유지가 되다가 다시 바뀌면 +1 추가
        바뀌고 다시 바로 바뀌면 그대로
        */
        boolean caps = false;
        for(int i =0 ; i<str.length();i++) {
            char c = chars[i];
            boolean cIsUpper = isUpper(c);
            if(cIsUpper && !caps) { // 현재 대문자고, 캡스락이 안눌린 경우
                caps = true;
                result++;
                if(i < str.length() - 1) {
                    // 다음 문자가 소문자인 경우 캡스락 말고 특수 키 이용
                    if(!isUpper(chars[i+1])){
                        caps = false;
                    }
                }
            }else if(caps && !cIsUpper) { // 현재 소문자고, 캡스락이 눌린 경우
                caps = false;
                result ++;
                if(i < str.length() - 1) {
                    // 다음 문자가 대문자인 경우 캡스락 말고 특수 키 이용
                    if(isUpper(chars[i+1])){
                        caps = true;
                    }
                }
            }
        }
        System.out.print(result);
    }
    private static boolean isUpper(char c) {
        return c >='A' && c <='Z';
    }
}