import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long d = sc.nextInt();

        List<Long> m = new ArrayList<>(n); // 몹
        List<Long> w = new ArrayList<>(n); // 무기

        for (long i = 0; i < n; i++) {
            long type = sc.nextInt();
            long value = sc.nextInt();
            if (type == 1) {
                m.add(value);
            }else{
                w.add(value);
            }
        }
        Collections.sort(m);
        Collections.sort(w);
        long count = w.size();
        int wStart = 0;
        for (int i = 0; i < m.size(); i++) {
            long mm = m.get(i);
            if(d > mm) {
                count ++;
                d = d + mm;
            }else {
                for (int j = wStart; j < w.size(); j++) {
                    long ww = w.get(j);
                    if(d * ww > mm) {
                        count++;
                        d = d * ww + mm;
                        wStart = j + 1;
                        break;
                    }else {
                        d = d * ww;
                    }
                }
            }
        }
        System.out.println(count);
    }
}
