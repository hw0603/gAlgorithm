1. 최대값  
2. 0부터 n개를 더한 dp[0] 구함
   a. k가 1이면 바로 리턴
3. next, previous 인덱스 구함(원형)
   a. next = (i + k - 1) % n;
   b. previous = (i - 1) % n;
4. dp[i - 1]과 슬라이딩 적용한 값 중 최대값 저장
