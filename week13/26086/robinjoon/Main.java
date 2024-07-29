import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String[] split = s.split(" ");
        int n = Integer.parseInt(split[0]);
        int q = Integer.parseInt(split[1]);
        int k = Integer.parseInt(split[2]);
        Deque<Integer> deque = new LinkedList<>();
        boolean isBack = false;
        List<Input> inputs = new ArrayList<>();
        int lastOp1 = -1;
        for (int i = 0; i < q; i++) {
            String line = br.readLine();
            split = line.split(" ");
            int op = Integer.parseInt(split[0]);
            if (op == 0) {
                inputs.add(new Input(op, Integer.parseInt(split[1])));
            }else {
                inputs.add(new Input(op, -1));
            }
            if (op == 1) {
                lastOp1 = i;
            }
        }
        for (int i = 0; i < inputs.size(); i++) {
            Input input = inputs.get(i);
            int op = input.op;
            int value = input.value;
            if (op == 0 && isBack) {
                deque.addLast(value);
                continue;
            }
            if (op == 0) {
                deque.addFirst(value);
            }
            if (op == 1 && i != lastOp1) {
                continue;
            }
            if (op == 1) { // 정렬
                List<Integer> list = new ArrayList<>(deque.size());
                while (!deque.isEmpty()) {
                    list.add(deque.removeFirst());
                }
                list.sort(Comparator.naturalOrder());
                if (isBack) {
                    for (Integer integer : list) {
                        deque.addFirst(integer);
                    }
                    continue;
                }
                for (Integer integer : list) {
                    deque.addLast(integer);
                }
                continue;
            }
            if (op == 2) {
                isBack = !isBack;
            }
        }
        if (isBack) {
            for (int i = 0; i < k - 1; i++) {
                deque.removeLast();
            }
            System.out.println(deque.removeLast());
            return;
        }
        for (int i = 0; i < k - 1; i++) {
            deque.removeFirst();
        }
        System.out.println(deque.removeFirst());
    }
    static class Input {
        int op;
        int value;

        public Input(int op, int value) {
            this.op = op;
            this.value = value;
        }
    }
}
