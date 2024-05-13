import java.util.*;
import java.util.stream.*;
import java.time.*;
import java.time.temporal.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<Tv> tvs = new ArrayList<>(n);
        for(int i = 0;i<n;i++){
            String name = sc.next();
            int day = sc.nextInt();
            LocalTime start = LocalTime.parse(sc.next()+":00");
            LocalTime end = LocalTime.parse(sc.next()+":00");
            Duration d = Duration.between(start,end);
            long min = d.getSeconds() / 60;
            Tv tv = new Tv(name, min, (day-1) / 7 + 1);
            tvs.add(tv);
        }
        int printCount = 0;
        Map<String, Map<Integer, Long>> map = tvs.stream()
                .collect(Collectors.groupingBy(tv -> tv.name,
                        Collectors.groupingBy(t -> t.week, Collectors.summingLong(value -> value.min))));
        Map<String, Map<Integer, Integer>> map2 = tvs.stream()
                .collect(Collectors.groupingBy(tv -> tv.name,
                        Collectors.groupingBy(t -> t.week, Collectors.summingInt(value -> 1))));
        for(String name : map.keySet().stream().sorted().collect(Collectors.toList())) {
            var weekHourMap = map.get(name);
            var weekCountMap = map2.get(name);
            boolean print = true;
            
            for(int week: weekHourMap.keySet()) {
                long hour = weekHourMap.get(week);
                int count = weekCountMap.get(week);
                if(hour < 3600L || count < 5) {
                    print = false;
                    break;
                }
            }
            if(weekHourMap.keySet().size() < m/7) {
                print = false;
            }
            if(print) {
                System.out.println(name);
                printCount ++;
            }
        }
        if(printCount == 0) {
            System.out.println(-1);
        }
    }

    static class Tv {
        String name;
        long min;
        int week;
        public Tv(String n, long m,int w) {
            name = n;
            min = m;
            week = w;
        }
    }
}
