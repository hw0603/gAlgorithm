package week14.D_31778.jminkkk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BOJ31778 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int s = Integer.parseInt(str[0]);
        int k = Integer.parseInt(str[1]);

        List<Integer> pList = new ArrayList<>();
        List<Integer> cList = new ArrayList<>();
        str = br.readLine().split("");
        for (int i = 0; i < s; i++) {
            if (str[i].equals("P")) {
                pList.add(i);
            } else {
                cList.add(i);
            }
        }

        k = Math.min(k, pList.size());
        for (int i = 0; i < k; i++) {
            cList.add(pList.remove(pList.size() - 1));
        }

        Collections.sort(cList);
        long sum = 0;
        for (int i = k; i < cList.size(); i++) {
            sum += getC(cList.get(i) - i + k);
        }

        System.out.println(sum);
    }

    private static long getC(long count) {
        return count * (count - 1) / 2;
    }
}
