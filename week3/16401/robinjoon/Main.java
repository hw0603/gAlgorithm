import java.util.*;
import java.util.stream.*;
import java.util.function.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();//조카 수
        int m = sc.nextInt(); // 과자 수

        List<Integer> snack = IntStream.range(0,m)
                .mapToObj(i -> sc.nextInt())
                .collect(Collectors.toList());

        Collections.sort(snack);
        int max = snack.get(snack.size() - 1);

        int answer = 0;
        int left= 1;
        int right = max;
        while(left <= right) {
            int now = (right - left) / 2 + left;
            boolean canGive = canGive(now, n, snack);
            if(canGive) { // 오른쪽으로
                answer = Math.max(answer, now);
                left = now + 1;
            }else { // 왼쪽으로
                right = now - 1;
            }
        }
        System.out.print(answer);
    }
    private static boolean canGive(int size, int count, List<Integer> list) {
        int c = 0;
        for(int l : list) {
            c+= l / size;
        }
        return count <= c;
    }
}
