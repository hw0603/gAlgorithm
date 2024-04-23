## Info
[29721 변형 체스 놀이 : 다바바(Dabbaba)](https://www.acmicpc.net/problem/29721)

## 💡 풀이 방법 요약

1. 들어온 x, y 값을 set에 넣는다
2. 해당 말이 이동할 수 있는 칸들을 순회하며 이미 set에 존재하거나 보드 바깥이면 continue
3. 아닐 경우 cnt를 1 증가시키고 해당 좌표를 set에 추가한다

- 1번 과정을 수행할 때 이미 set에 있다면 cnt를 1 감소한다

시간복잡도는 O(nlogn)


## 🙂 마무리
