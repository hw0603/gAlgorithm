import java.util.*;
import java.util.function.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<String,Boolean> hackingMap = new HashMap<>();
        int n = sc.nextInt();
        int p = sc.nextInt();
        int winPoint = sc.nextInt();
        int losePoint = sc.nextInt();
        int targetPoint = sc.nextInt();
        
        while(p-- > 0) {
            String name = sc.next();
            String b = sc.next();
            if(b.equals("L")) {
                hackingMap.put(name, false);
            }else{
                hackingMap.put(name, true);
            }
        }
        int point = 0;
        while(n-- > 0) {
            String name = sc.next();
            boolean isWin = hackingMap.getOrDefault(name, false);
            if(isWin) {
                point += winPoint;
            }else{
                point = point - losePoint;
                if(point < 0) {
                    point = 0;
                }
            }
            if(point >= targetPoint) break;
        }
        if(point < targetPoint) {
            System.out.print("I AM IRONMAN!!");
        }else {
            System.out.print("I AM NOT IRONMAN!!");
        }
    }
}