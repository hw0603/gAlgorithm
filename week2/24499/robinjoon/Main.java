import java.util.*;
import java.util.function.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        List<Integer> list = new ArrayList<>();
        list.add(0);
        for(int i = 0;i < n;i++) {
            list.add(sc.nextInt());
        }
        for(int i = 1;i <= n;i++) {
            list.add(list.get(i));
        }
        List<Integer> sum = new ArrayList<>();
        sum.add(0);
        for(int i = 1;i < list.size();i++) {
            sum.add(sum.get(i-1) + list.get(i));
        }
        int max = 0;
        for(int start = 1; start <=n; start++) {
            max = Math.max(max, sum.get(start + k) - sum.get(start));
        }
        System.out.println(max);
    }
}