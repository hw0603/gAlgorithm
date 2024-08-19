package week16.A_3061.robinjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = getInt(br);
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            int n = getInt(br);
            int[] target = getIntArray(br);
            int i = bubble_sort(target, n);
            sb.append(i).append("\n");
        }
        System.out.println(sb);
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

    private static int bubble_sort(int[] a, int size) {
        int swapCount = 0;
        for(int i = 1; i < size; i++) {
            for(int j = 0; j < size - i; j++) {
                if(a[j] > a [j + 1]) {
                    swap(a, j, j + 1);
                    swapCount++;
                }
            }
        }
        return swapCount;
    }

    private static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
