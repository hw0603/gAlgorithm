import java.util.*;
import java.util.function.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        List<Long> list = new ArrayList<>(n + 1);
        list.add(0L);
        for(int i = 1; i<=n; i++) {
            list.add(sc.nextLong());
        }
        List<Long> sum = new ArrayList<>(n + 1);
        sum.add(0L);
        for(int i = 1; i<=n; i++) {
            sum.add(sum.get(i-1) + list.get(i));
        }
        long max = 0;
        int l = 0;
        int e = 1;
        while(true) {
            long subSum = sum.get(e) - sum.get(l);
            if (subSum > m) {
                l++;
            } else if(subSum == m) {
                System.out.println(m);
                return;
            }else {
                max = Math.max(max, subSum);
                e++;
                if (e > n) {
                    break;
                }
            }
            if (e == n && l==n) {
                break;
            }
        }
        System.out.println(max);
    }
}
