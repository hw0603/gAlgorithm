# Info
[30701 돌아온 똥게임](https://www.acmicpc.net/problem/30701)

## 💡 풀이 방법 요약
깰 수 있는 만큼 몹 스테이지를 깨고, 안깨지는 상황에선 무기를 약한 무기에서부터 하나씩 얻어보면서 깨지는지 확인하고 깨지면 깨면 됨.

단, 결국 모든 무기는 깰 수 있으므로, 몹 스테이지를 깰때만 카운트를 증가시키고, 무기 개수만큼 더해주면 됨
## 👀 실패 이유
0으로 시작해서 그런 듯?
``` JAVA
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
        long count = 0;
        int wStart = 0;
        for (int i = 0; i < m.size(); i++) {
            long mm = m.get(i);
            if(d > mm) {
                count ++;
                d = d + mm;
            }else {
                for (int j = wStart; j < w.size(); j++) {
                    long ww = w.get(j);
                    count ++;
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
        if (m.size() == 0 && count == 0) {
            System.out.println(w.size());
            return;
        }
        System.out.println(count);
    }
}

```
## 🙂 마무리

