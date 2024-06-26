# Info
[23088 Aging](https://www.acmicpc.net/problem/23088)

## 💡 풀이 방법 요약
포인트: `우선 순위`는 상대적인 값이므로 현재 대기하고 있는 모든 프로세스에 대해 `aging`을 적용하는 대신, 새로 들어온 프로세스에 대해 각각의 요청 시간(`t`)이 클수록 우선 순위를 감소시켜 주어도 동일한 효과를 낼 수 있다.

현재 `time` 이하에 요청된 프로세스들을 모두 `q` 에서 `pq`로 이동시켜 주는 함수 `handle()`을 정의한다. 이때 `heapq`를 활용할 것이므로 원소를 `(-p, b, pid)` 로 저장한다.

`time`의 초깃값을 `q`의 첫 프로세스 요청 시각으로 정의한 후, `pq`가 빌 때 까지 루핑하며 프로세스들을 하나씩 실행시킨다. 각 프로세스의 실행이 완료된 이후에는 실행 시간 `b`를 `time` 에 누적하여 현재 시간을 관리해 준다.  
**만약 프로세스 실행 완료 후 time을 증가시켰는데, `q`에 프로세스가 남아 있는 상태에서 `pq`로 이동하지 못한다면 `time`을 현재 `q`의 첫 프로세스 요청 시각으로 증가시켜 줘야 한다!**

## 👀 실패 이유
`handle()` 한 번 호출 후에도 `q`에 있는 프로세스가 `pq`로 넘어오지 못 하는 경우를 놓쳤었다.
```text
반례:

5
0 1000 2
3 1 4
3 2 3
3 5 3
9 11 2

Ans: 1 4 3 5 2
```

## 🙂 마무리
코드가...너무..더럽네요..
