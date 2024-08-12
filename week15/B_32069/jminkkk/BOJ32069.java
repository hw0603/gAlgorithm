package week15.B_32069.jminkkk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class BOJ32069 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");

        int L = Integer.parseInt(str[0]);
        int N = Integer.parseInt(str[1]);
        int K = Integer.parseInt(str[2]);

        str = br.readLine().split(" ");
        Set<Integer> lamps = new HashSet<>();
        for (int i = 0; i < N; i++) {
            lamps.add(Integer.parseInt(str[i]));
        }

        List<Integer> already = new ArrayList<>();
        int distance = 0;
        int count = 0;

        while (count != K) {
            for (Integer lamp : lamps) {
                int right = lamp + distance;
                int left = lamp - distance;
                if (right > L && left < 0) {
                    continue;
                }

                if (right <= L && !already.contains(right)) {
                    already.add(right);
                    count++;
                    System.out.println(distance);
                }

                if (count == K) {
                    break;
                }

                if (left >=  0 && !already.contains(left)) {
                    already.add(left);
                    count++;
                    System.out.println(distance);
                }
            }
            distance++;
        }

    }

}
