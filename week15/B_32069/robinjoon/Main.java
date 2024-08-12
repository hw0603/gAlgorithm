package week15.B_32069.robinjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();
        String[] split = input.split(" ");

        long l = Long.parseLong(split[0]);
        int n = Integer.parseInt(split[1]);
        int k = Integer.parseInt(split[2]);

        input = br.readLine();
        split = input.split(" ");
        List<Long> lights = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            lights.add(Long.parseLong(split[i]));
        }

        StringBuilder sb = new StringBuilder();
        List<Set<Long>> answers = new ArrayList<>();
        int size = 0;
        int level = 0;
        Set<Long> visited = new HashSet<>();
        while (size <= k) {
            Set<Long> positions = find(level,lights, visited, l, k);
            if (positions.isEmpty())break;
            size+=positions.size();
            level++;
            answers.add(positions);
        }
        int nowLevel = 0;
        all: for (Set<Long> answer : answers) {
            for (Long aLong : answer) {
                k--;
                sb.append(nowLevel).append("\n");
                if (k == 0) break all;
            }
            nowLevel++;
        }
        System.out.print(sb);
    }

    private static Set<Long> find(int level, List<Long> lights, Set<Long> visited, long l, int k) {
        Set<Long> answer = new HashSet<>();
        for (Long light : lights) {
            if (light + level <=l && !visited.contains(light+level)) {
                visited.add(light+level);
                answer.add(light+level);
            }
            if (light-level>=0 && !visited.contains(light-level)) {
                visited.add(light-level);
                answer.add(light-level);
            }
            if (visited.size() > k) {
                break;
            }
        }
        return answer;
    }
}

