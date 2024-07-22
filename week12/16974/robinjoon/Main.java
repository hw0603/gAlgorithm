import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    static Map<Integer, Long> levelLength = new HashMap<>();
    static Map<Integer, Map<Long, Long>> cache = new HashMap<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long x = sc.nextLong();

        levelLength.put(1, 5L);
        for (int i = 1; i <= n; i++) {
            cache.put(i, new HashMap<>());
        }
        for (int i = 2; i <= n; i++) {
            levelLength.put(i, levelLength.get(i-1) * 2 + 3);
        }
        System.out.println(dq(n,x));
    }
    static long dq(int n, long x) {
        if (n == 1) {
            if (x == 1) return 0;
            if (x==2) return 1;
            if (x == 3) return 2;
            if (x == 4) return 3;
            if (x == 5) return 3;
        }
        if (x == 1) return 0;
        Long beforeLevelLength = levelLength.get(n - 1);
        if (x <= beforeLevelLength + 1) {
            if (cache.get(n-1).containsKey(x-1)){
                return cache.get(n-1).get(x-1);
            }else {
                long dq = dq(n - 1, x - 1);
                cache.get(n-1).put(x-1, dq);
                return dq;
            }
        }
        if (x == beforeLevelLength + 2) {
            if (cache.get(n-1).containsKey(beforeLevelLength)){
                return cache.get(n-1).get(beforeLevelLength);
            }else {
                long dq = dq(n - 1, beforeLevelLength) + 1;
                cache.get(n-1).put(x-1, dq);
                return dq;
            }
        }
        if (x <= levelLength.get(n-1) + 2L + levelLength.get(n-1)) {
            long l,r;
            if (cache.get(n-1).containsKey(levelLength.get(n-1))) {
                l = cache.get(n-1).get(levelLength.get(n-1));
            }else {
                l = dq(n-1, levelLength.get(n-1));
            }
            if (cache.get(n-1).containsKey(x - (levelLength.get(n-1)+2))) {
                r = cache.get(n-1).get(x - (levelLength.get(n-1)+2));
            }else {
                r = dq(n-1, x - (levelLength.get(n-1)+2));
            }
            return l + 1 + r;
        }
        if (cache.get(n-1).containsKey(levelLength.get(n-1))) {
            return cache.get(n-1).get(levelLength.get(n-1)) * 2 + 1;
        }
        return dq(n-1, levelLength.get(n-1)) * 2 + 1;
    }
}
