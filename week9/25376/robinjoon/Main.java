import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Main {
    static int count = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Wrapper time = new Wrapper();
        PriorityQueue<Process> pq = new PriorityQueue<>((o1, o2) -> {
            int priorityCompare = Integer.compare((time.time - o2.t) + o2.p, (time.time - o1.t) + o1.p);
            if (priorityCompare == 0) {
                int timeCompare = Integer.compare(o1.b, o2.b);
                if (timeCompare == 0) {
                    return Integer.compare(o1.number, o2.number);
                }
                return timeCompare;
            }
            return priorityCompare;
        });
        List<Process> processes = new ArrayList<>(n);
        int index = 0;
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line);
            processes.add(new Process(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())));
        }
        Process nowRun;
        List<Integer> list = new ArrayList<>();
        while (list.size() < n) {
            // 실행중인게 없음
            while (index < n && processes.get(index).t <= time.time) {
                pq.add(processes.get(index));
                index++;
            }
            nowRun = pq.poll();
            if (nowRun!=null) {
                list.add(nowRun.number);
                time.time += nowRun.b;
                continue;
            }
            time.time++;
        }
        String collect = list.stream().map(String::valueOf).collect(Collectors.joining(" "));
        System.out.println(collect);
    }
    static class Wrapper{
        int time;
    }
    static class Process{
        int number;
        int t;
        int p;
        int b;

        public Process(int t, int p, int b) {
            this.number = ++count;
            this.t = t;
            this.p = p;
            this.b = b;
        }
    }
}
/*
6
0 1 10
1 2 1000
2 1 3
2 3 1
2 2 2
100 100 3
 */
