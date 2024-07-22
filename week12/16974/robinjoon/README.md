# Info
[Link](https://boj.kr/16974)
## 💡 풀이 방법 요약
레벨-1 버거는 'BPPPB', 레벨-2 버거는 'BBPPPBPBPPPBB'

```
i != 0
dp[n][i] ~ dp[n][i-1] = 0;  // 1 <= i <= n-1

dp[n][i] = dp[n-1][i-1]; //  n <= i <= dp[n-1].length + 1

dp[n][i] = dp[n][i-1] + 1; // i = dp[n-1].length + 2

dp[n][i] = dp[n-1][i-1] + dp[n-1][i-(dp[n-1].length + 2)] ; // dp[n-1].length + 3 <= i <= dp[n-1].length + 2 + dp[n-1].length

dp[n][i] = dp[n][i-1]; // i =  dp[n-1].length + 3 + dp[n-1].length
```

길이가 존나 긴게 문제! => 길이를 짧게 할 수 있으면 되는데..

결국 필요한 것은 이전 단계의 모든 값이 아니라 이전 단계 특정 값! 그 특정 인덱스만 빠르게 알아낼 수 있다면?

n 레벨의 길이 = 3 + 2 *(n-1 레벨의 길이)

```
dp(n,x) :

	if x ==1 : return 0;
	if x < (n-1 레벨 길이) + 1 : return dp(n-1,x-1);
	if x == (n-1 레벨 길이) + 2 : return dp(n-1, (n-1 레벨 길이)) + 1;
	if x < (n-1 레벨 길이) + 2 + (n-1 레벨 길이) : dp(n-1, (n-1 레벨 길이)) + 1 + dp(n-1, x - ((n-1 레벨 길이) + 2 ));
	return dp(n-1,  (n-1 레벨 길이)) * 2 + 1;
```

위 코드 역시 깊이가 깊어지면 스택이 터질 수 있으므로 메모리제이션을 적용해야 함.

```
dp[1][1] = 0
dp[1][2] = 1
dp[1][3] = 2
dp[1][4] = 3
dp[1][5] = 3

dp[2][1] = 0
dp[2][2] = dp[1][1]
dp[2][3] = dp[1][2]
```
## 👀 실패 이유

## 🙂 마무리
