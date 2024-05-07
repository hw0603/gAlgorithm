점화식

1. dp[i] = Math.max(dp[i - 1], now - min);
2. min = Math.min(now, min), max = Math.max(now, max) 업데이트
