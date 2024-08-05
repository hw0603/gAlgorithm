package week14.B_1885.jminkkk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class BOJ1885 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int k = Integer.parseInt(str[1]);

        Map<Integer, List<Integer>> numAndIndex = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            List<Integer> value = new ArrayList<>();
            value.add(num);
            numAndIndex.put(num, numAndIndex.getOrDefault(num, value));
        }

    }
}
