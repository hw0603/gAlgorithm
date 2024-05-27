# Info
[30459 현수막 걸기](https://www.acmicpc.net/problem/30459)

## 💡 풀이 방법 요약
1. 모든 현수막의 너비를 구하고 각각에 대해 이진탐색
2. 너비가 r보다 작을 경우의 최대값을 구함

## 👀 실패 이유
```
(height * b[mid]) / (double) 2 <= r
```
일때 double로 안해줘서 틀림 ㅠ

## 🙂 마무리

