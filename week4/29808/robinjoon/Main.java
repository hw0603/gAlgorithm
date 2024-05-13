import java.util.*;
import java.awt.Point;
import java.util.stream.*;
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int sn = sc.nextInt();
        if(sn % 4763 !=0) {
            System.out.print(0);
            return;
        }
        int number = sn / 4763;
        List<Point> list = new ArrayList<>();
        if(number % 212 == 0) {
            list.add(new Point(0,number / 212));
        }
        if(number % 305 == 0) {
            list.add(new Point(0,number / 305));
        }
        for(int a = 1; a <= number; a++) {
            int b = number - a;
            if(a % 508 == 0) {
                if(b % 212 == 0) {
                    list.add(new Point(a/508,b/212));
                }
                if(b % 305 == 0) {
                    list.add(new Point(a/508,b / 305));
                } 
            }
            if(a % 108 == 0) {
                if(b % 212 == 0) {
                    list.add(new Point(a/108,b/212));
                }
                if(b % 305 == 0) {
                    list.add(new Point(a/108,b / 305));
                } 
            }
        }
        list = list.stream().filter(p -> p.x >=0 && p.x <=200 && p.y>=0 && p.y <=200)
        .sorted((Point o1,Point o2) -> {
            int c = Integer.compare(o1.x,o2.x);
            if(c == 0) {
                return Integer.compare(o1.y,o2.y);
            }
            return c;
        })
        .distinct().collect(Collectors.toList());
        System.out.println(list.size());
        for(Point p : list) {
            System.out.println(p.x +" " + p.y);
        }
    }
}
