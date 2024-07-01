import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		
		List<Integer> times = new ArrayList<>();
		for (int i=0; i<n;i++ ){
		    int t = sc.nextInt();
		    if(t<=m){
    		    times.add(t);
		    }
		} 
		times.sort(Comparator.naturalOrder());
		int[] dp = new int[times.size()]; // i개를 보는 최소 시간
		for(int i =0 ;i<times.size();i++) {
		    if(i<k) {
		        dp[i] = times.get(i);
		    }else{
		        dp[i] = dp[i-k]+times.get(i);
		    }
		}
		int i = 0;
		for(;i<dp.length;i++){
		    if(dp[i]>m){
		        break;
		    }
		}
		System.out.println(i);
	}
}
