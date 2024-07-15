import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class P14411 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<long[]> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            String[] split = line.split(" ");
            list.add(new long[]{Long.parseLong(split[0])/2,Long.parseLong(split[1])/2});
        }
        list.sort((o1, o2) -> {
            int compare = Long.compare(o1[1], o2[1]);
            if (compare == 0) {
                return -Long.compare(o1[0],o2[0]);
            }
            return -compare;
        });
        long sum = list.get(0)[0] * list.get(0)[1];
        long beforeH = list.get(0)[1];
        long beforeW = list.get(0)[0];
        if (n == 1){
            System.out.println(sum);
            return;
        }
        for (int i = 1; i < n; i++) {
            long[] next = list.get(i);
            if (next[0] <= beforeW)continue;
            if (next[1] == beforeH)continue;
            sum += next[1] * (next[0] - beforeW);
            beforeH = next[1];
            beforeW = next[0];
        }
        System.out.println(sum * 4);
    }
}