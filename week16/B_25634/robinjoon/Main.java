package week16.B_25634.robinjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = getInt(br);
        int[] arr = getIntArray(br);
        int[] states = getIntArray(br);
        int deafult = 0;

        for (int i = 1; i <= n; i++) {
            deafult += arr[i];
            if (states[i]==0){
                deafult -= arr[i];
            }
        }
        int[] toggle = new int[n+1];
        for (int i = 1; i <= n ; i++) {
            if (states[i] == 1) toggle[i] = -arr[i];
            else toggle[i] = arr[i];
        }
        int max = 0;
        int sum = 0;
        for (int i = 1; i <= n ; i++) {
            sum = sum + toggle[i];
            max = Math.max(max, sum);
            if (sum < 0) sum = 0;
        }

        if (Arrays.stream(states).skip(1).allMatch(value -> value == 1)) {
            System.out.println(deafult - Arrays.stream(arr).skip(1).min().getAsInt());
            return;
        }
        System.out.println(deafult + max);
    }

    private static int getInt(BufferedReader br) throws IOException {
        return Integer.parseInt(br.readLine());
    }

    private static int[] getIntArray(BufferedReader br) throws IOException {
        String[] split = br.readLine().split(" ");
        int[] result = new int[split.length + 1];
        for (int i = 1; i <= split.length; i++) {
            result[i] = Integer.parseInt(split[i-1]);
        }
        return result;
    }
}

