import java.util.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        
        int n = sc.nextInt();
        
        List<Integer> list = new ArrayList<>(n);
        for(int i = 0; i< n ; i++) {
            list.add(sc.nextInt());
        }
        Collections.sort(list, Comparator.reverseOrder());
        int index = 0;
        int[][] array = new int[r][c];
        int count = 0;
        try{
            for(int i = r-1; i >=0 ; i--) {
                for(int j = c-1; j>=0 ;j--) {
                    int now = list.get(index++);
                    while(i < r-1 && array[i+1][j] == now) {
                        now = list.get(index++);
                    }
                    array[i][j] = now;
                    count++;
                }
            }
        }catch(Exception e) {
            
        }finally{
            System.out.print(count);
        }
    }
}
