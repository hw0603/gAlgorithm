package week16.C_30108.robinjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = getInt(br);
        int[] parents = getIntArray(br);
        int[] values = getIntArray(br);
        Map<Integer,List<Integer>> parentMap = new HashMap<>();
        for (int i = 1; i <= n ; i++) {
            parentMap.put(i, new ArrayList<>());
        }

        for (int i = 0; i < parents.length; i++) {
            parentMap.get(parents[i]).add(i + 2);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> -Integer.compare(values[o1-1],values[o2-1]));
        pq.add(1);
        long sum = 0;
        StringBuilder sb = new StringBuilder();
        while (!pq.isEmpty()) {
            Integer poll = pq.poll();
            sum += (long)(values[poll-1]);
            sb.append(sum).append("\n");
            // 방금 뺀 애의 자식 노드 전부 큐에 넣기
            pq.addAll(parentMap.get(poll));
        }
        System.out.print(sb);
    }

    private static long[] getLongArray(BufferedReader br) throws IOException {
        String[] split = br.readLine().split(" ");
        long[] result = new long[split.length];
        for (int i = 0; i < split.length; i++) {
            result[i] = Integer.parseInt(split[i]);
        }
        return result;
    }

    private static int getInt(BufferedReader br) throws IOException {
        return Integer.parseInt(br.readLine());
    }

    private static int[] getIntArray(BufferedReader br) throws IOException {
        String[] split = br.readLine().split(" ");
        int[] result = new int[split.length];
        for (int i = 0; i < split.length; i++) {
            result[i] = Integer.parseInt(split[i]);
        }
        return result;
    }
}

