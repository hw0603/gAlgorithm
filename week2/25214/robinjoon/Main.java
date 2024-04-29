import java.util.*;
import java.util.function.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        list.add(0);

        for(int i=0; i<n ; i++) {
            list.add(sc.nextInt());
        }

        int min = list.get(1);
        List<Integer> result = new ArrayList<>();
        result.add(0);
        result.add(0);
        for(int i = 2; i<=n ;i++) {
            int max = result.get(i-1);
            max = Math.max(max, list.get(i) - min);
            result.add(max);
            min = Math.min(min, list.get(i));
        }
        String collect = result.stream().skip(1).map(String::valueOf).collect(Collectors.joining(" "));
        System.out.print(collect);
    }
}