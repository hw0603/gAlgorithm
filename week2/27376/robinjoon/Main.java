import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.function.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int n = Integer.parseInt(s.split(" ")[0]);
        int k = Integer.parseInt(s.split(" ")[1]);
        List<Light> lights = IntStream.range(0,k)
                .mapToObj(i -> {
                    try {
                        return new Light(br.readLine());
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                })
                .sorted(Comparator.comparingInt(a -> a.startPoint))
                .collect(Collectors.toList());
        long time = 0;
        long nowPoint = 0;
        for(int i = 0 ; i< k; i++) {
            Light light = lights.get(i);
            time += (light.startPoint - nowPoint);
            long waitTime = light.waitTime(time);
            time += waitTime;
            nowPoint = light.startPoint;
        }
        if(nowPoint < n) {
            time = time + (n - nowPoint);
        }
        System.out.println(time);
    }
}
class Light{
    int startPoint;
    int period;
    int startTime;
    public Light(String input) {
        String[] s = input.split(" ");
        this.startPoint = Integer.parseInt(s[0]);
        this.period = Integer.parseInt(s[1]);
        this.startTime = Integer.parseInt(s[2]);
    }

    long waitTime(long arriveTime) {
        if(arriveTime < startTime) {
            return startTime - arriveTime;
        }
        if(arriveTime == startTime) {
            return 0;
        }
        long x = (arriveTime - startTime)/period;
        if(x % 2 == 0) {
            return 0;
        }
        long periodX = period * x;
        return period - ((arriveTime - startTime) - periodX);
    }
}