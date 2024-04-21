import java.util.*;
import java.util.stream.Collectors;

public class P25178{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String str1 = sc.next();
        String str2 = sc.next();
        String function = function(str1, str2, n);
        System.out.println(function);
    }
    private static String function(String str1, String str2, int n) {
        if(str1.charAt(0) != str2.charAt(0)) {
            return "NO";
        }
        if(str1.charAt(n-1) != str2.charAt(n-1)) {
            return "NO";
        }
        String replacedStr1 = str1.replaceAll("a", "").replaceAll("e", "").replaceAll("i", "").replaceAll("o", "")
                .replaceAll("u", "");
        String replacedStr2 = str2.replaceAll("a", "").replaceAll("e", "").replaceAll("i", "").replaceAll("o", "")
                .replaceAll("u", "");
        if (!replacedStr1.equals(replacedStr2)) {
            return "NO";
        }
        Map<String, Integer> stringIntegerMap1 = Arrays.stream(str1.split(""))
                .collect(Collectors.groupingBy(s -> s, Collectors.summingInt(value -> 1)));
        Map<String, Integer> stringIntegerMap2 = Arrays.stream(str2.split(""))
                .collect(Collectors.groupingBy(s -> s, Collectors.summingInt(value -> 1)));
        Set<String> keySet1 = stringIntegerMap1.keySet();
        Set<String> keySet2 = stringIntegerMap2.keySet();
        if (keySet1.containsAll(keySet2) && keySet1.size() == keySet2.size()) {
            for (String s : keySet1) {
                int count1 = stringIntegerMap1.get(s);
                int count2 = stringIntegerMap2.get(s);
                if (count1 != count2) {
                    return "NO";
                }
            }
            return "YES";
        } else{
            return "NO";
        }
    }
}
