## Info
[27376 참살이길](https://www.acmicpc.net/problem/27376)

## 💡 풀이 방법 요약
각 신호등 별 주기가 존재하고, 시작 시간이 있다는 점에서 나머지 연산을 활용해야 함을 캐치할 수 있다.  
  
```
예시)
3초 간격, 1초 후에 시작되는 신호등인데 14초 시점의 상태
-> (14-1) // 3 = 4...1
-> (15-1) // 3 = 4...2
-> (1 -1) // 3 = 0...0

[1~4): 초록불
[4~7): 빨간불
[7~10): 초록불
[10~13): 빨간불
[13~16): 초록불
```
```
일반화)
t초 간격, s초 후에 시작되는 신호등이 있을 때, T초 후 상태를 구하려면
-> (T - s) // t = Q...r 일 때,
Q가 짝수라면 이미 초록불인 상태이고,
Q가 홀수라면 현재는 빨간불이지만 (t-r)초 후에 초록불로 바뀐다는 의미
```

위 규칙에 따라 특정 시점 `T` 에서 해당 신호등에서 대기해야 하는 시간을 계산하는 함수 `calcOverhead(trafficLight, T)` 를 작성할 수 있다.  
  
이후 좌표값이 작은 신호등부터 순회하며 각 신호등에 도착하는 시점별로 대기해야 하는 시간을 누적해 가면 모든 신호등에서 걸리는 총 대기시간을 구할 수 있고, 이와 참살이길의 길이(`N`)를 더해 주면 최종적으로 완주하는 데 걸리는 시간을 구할 수 있다.

## 🙂 마무리
None