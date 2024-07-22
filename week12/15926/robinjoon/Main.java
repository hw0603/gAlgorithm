import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String str = sc.next();
        Deque<Character> deque = new LinkedList<>();
        int length = 0;
        int max = 0;
        for (char c : str.toCharArray()) {
            length++;
            if (c == '('){ // 이전까지를 모두 포함한다면, 앞으로 괄호 문자열이 될 가능성이 충분함.
                deque.addLast(c);
            }
            if (c == ')') {
                if (deque.isEmpty()) { // 이전까지를 모두 포함한다면, 앞으로 절대 괄호 문자열이 될 수 없음. 다음 위치부터 파악해야 함.
                    length = 0;
                    continue;
                }
                deque.removeLast();
                if (deque.isEmpty()) { // 스택이 비워지면 괄호 문자열임
                    max = Math.max(max, length);
                }
            }
        }
        length = 0;
        str = new StringBuffer(str).reverse().toString();
        deque = new LinkedList<>();
        for (char c : str.toCharArray()) {
            length++;
            if (c == ')'){ // 이전까지를 모두 포함한다면, 앞으로 괄호 문자열이 될 가능성이 충분함.
                deque.addLast(c);
            }
            if (c == '(') {
                if (deque.isEmpty()) { // 이전까지를 모두 포함한다면, 앞으로 절대 괄호 문자열이 될 수 없음. 다음 위치부터 파악해야 함.
                    length = 0;
                    continue;
                }
                deque.removeLast();
                if (deque.isEmpty()) { // 스택이 비워지면 괄호 문자열임
                    max = Math.max(max, length);
                }
            }
        }
        System.out.println(max);
    }
}
