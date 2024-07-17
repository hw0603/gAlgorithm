package week11.B_14411.jminkkk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Map;
import java.util.Map.Entry;
import java.util.TreeMap;

public class BOJ1441 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long n = Long.parseLong(br.readLine());
        long count = 0;

        Map<Long, Long> xAndYs = new TreeMap<>(Collections.reverseOrder());
        for (int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");
            long x = Integer.parseInt(str[0]) / 2;
            long y = Integer.parseInt(str[1]) / 2;

            if (xAndYs.containsKey(y)) {
                xAndYs.put(y, Math.max(xAndYs.get(y), x));
            } else {
                xAndYs.put(y, x);
            }
        }


        long maxX = 0;
        for (Entry<Long, Long> entry : xAndYs.entrySet()) {
            long y = entry.getKey();
            long x = entry.getValue();
            if (x > maxX) {
                count += (x - maxX) * y;
                maxX = x;
            }
        }

        System.out.println(count * 4);
    }
}
