# Info
[Link](https://boj.kr/28422)
## 💡 풀이 방법 요약

오랜만에 쉬운 DP 문제라서 더 어려웠다.

dp[n] = n장 뽑았을 때 최대 점수

```Java
for (int i = 5; i<=n; i++) {
    if (i - 2 >= 0) { // 두장 뽑는 경우
        dp[i] = Math.max(dp[i-2] + calculateScore(arr[i],arr[i-1]), dp[i]);
    }
    if (i - 3 >= 0) { // 세장 뽑는 경우
        dp[i] = Math.max(dp[i-3] + calculateScore(arr[i]^arr[i-1],arr[i-2]), dp[i]);
    }
}
```

## 👀 실패 이유

dp[2], dp[3], dp[4] 를 미리 결정해 둬야 하는지 찾는데 오래 걸렸다.

## 🙂 마무리
