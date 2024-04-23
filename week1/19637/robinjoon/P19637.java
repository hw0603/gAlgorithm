import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class P19637 {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String s = bufferedReader.readLine();
        String[] split = s.split(" ");
        int n = Integer.parseInt(split[0]);
        int m = Integer.parseInt(split[1]);

        List<String> names = new ArrayList<>();
        List<Integer> limits = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String input = bufferedReader.readLine();
            String[] split1 = input.split(" ");
            names.add(split1[0]);
            limits.add(Integer.parseInt(split1[1]));
        }
        List<String> results = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int point = Integer.parseInt(bufferedReader.readLine());
            int bs = bs(limits, point);
            results.add(names.get(bs));
        }
        String collect = results.stream().collect(Collectors.joining("\n"));
        System.out.println(collect);
    }
    private static int bs(List<Integer> list, int value) {
        int start = 0;
        int end = list.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (list.get(mid) < value) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end + 1;
    }
}
