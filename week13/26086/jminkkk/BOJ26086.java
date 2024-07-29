import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;

public class BOJ26086 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int q = Integer.parseInt(str[1]);
        int k = Integer.parseInt(str[2]);

        boolean isFirst = true; // 뒤집을 것 인지
        LinkedList<Integer> for1 = new LinkedList<>();
        LinkedList<Integer> ll = new LinkedList<>();

        boolean for1IsFirst = true;
        int sortIndex = -1;
        for (int i = 0; i < q; i++) {
            str = br.readLine().split(" ");
            if (str[0].equals("0")) {
                int p = Integer.parseInt(str[1]);
                if (isFirst) {
                    ll.addFirst(p);
                } else {
                    ll.addLast(p);
                }
                if (sortIndex != -1) {
                    sortIndex++;
                }
            } else if (str[0].equals("1")) {
                for1.addAll(ll);
                ll = new LinkedList<>();
                for1IsFirst = isFirst;
                sortIndex = 0;
            } else {
                isFirst = !isFirst;
            }
        }

        if (ll.size() == 1) {
            System.out.println(ll.getFirst());
        }

        if (for1IsFirst) {
            Collections.sort(for1);
        } else {
            for1.sort(Collections.reverseOrder());
        }

        if (isFirst) {
            ll.addAll(ll.size() - sortIndex, for1); // 제일 앞에
        } else {
            ll.addAll(sortIndex, for1);
        }

        System.out.println(ll);
        int answer = 0;
        for (int i = 0; i < k; i++) {
            if (isFirst) {
                answer = ll.removeFirst();
            } else {
                answer = ll.removeLast();
            }
        }
        System.out.println(answer);
    }
}
//[40, 60, 10, 20, 30, 50, 70, 90, 80, 100]
