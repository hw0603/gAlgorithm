package week15.C_27979.robinjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Objects;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        List<Integer> list = new ArrayList<>(n);
        List<Integer> answer = new ArrayList<>(n);
        String[] split = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            list.add(Integer.parseInt(split[i]));
            answer.add(list.get(i));
        }
        answer.sort(Comparator.naturalOrder());
        int count = 0;
        int moveCount = 0;
        for (int i = n-1; i >= 0 ; i--) {
            if (!Objects.equals(list.get(i), answer.get(i+moveCount))) {
                count++;
                moveCount++;
            }
        }
        System.out.print(count);
    }
}

