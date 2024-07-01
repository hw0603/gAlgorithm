package org.example.p30407;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int h = sc.nextInt();
        int d = sc.nextInt();
        int k = sc.nextInt();
        int[] ps = new int[n];
        for (int i = 0; i < n; i++) {
            ps[i] = sc.nextInt();
        }
        Set<Integer> answers = new HashSet<>(n);
        // 스킵 스킬을 고려하는 걸 n 만큼 하면 되네? 1번째에 스킵한 경우, 2번째에 스킵한 경우 ...
        List<int[]> allCase = allCase(n);
        for (int[] eachCase : allCase) {
            int nh = h;
            int nd = d;
            boolean nextSkip = false;
            for (int i = 0; i < eachCase.length; i++) {
                int p = ps[i];
                if (nextSkip) {
                    nd += k;
                    nextSkip = false;
                    continue;
                }
                if (eachCase[i] == 0) {
                    int damage = Math.max((p - nd) / 2, 0);
                    nh -= damage;
                } else if (eachCase[i] == 1) {
                    nd += k;
                    int damage = Math.max((p - nd), 0);
                    nh -= damage;
                } else {
                    int damage = Math.max(p - nd, 0);
                    nh -= damage;
                    nextSkip = true;
                }
            }
            answers.add(nh);
        }
        int asInt = answers.stream().mapToInt(Integer::intValue).max().getAsInt();
        if (asInt <= 0) {
            System.out.println(-1);
            return;
        }
        System.out.println(asInt);
    }

    private static List<int[]> allCase(int n) {
        List<int[]> result = new ArrayList<>();
        allCaseHelper(new int[0], n, result);
        result = result.stream().flatMap(s -> {
            Set<int[]> hashSet = new HashSet<>();
            for (int i = 0; i < s.length; i++) {
                int[] arr = new int[s.length];
                System.arraycopy(s, 0, arr, 0, s.length);
                arr[i] = 2;
                hashSet.add(arr);
            }
            hashSet.add(s);
            return hashSet.stream();
        }).collect(Collectors.toList());
        return result;
    }
    private static void allCaseHelper(int[] current, int n, List<int[]> result) {
        if (n == 0) {
            result.add(current);
        } else {
            int[] next1 = new int[current.length + 1];
            System.arraycopy(current, 0, next1, 0, current.length);
            next1[current.length] = 0;
            int[] next2 = new int[current.length + 1];
            System.arraycopy(current, 0, next2, 0, current.length);
            next2[current.length] = 1;
            allCaseHelper(next1, n - 1, result);
            allCaseHelper(next2, n - 1, result);
        }
    }
}
