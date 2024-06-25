from collections import deque
import heapq
import sys

N = int(sys.stdin.readline())
arr = enumerate(tuple(map(int,sys.stdin.readline().strip().split())) for _ in range(N))

q = deque(arr)
pq = []
time = q[0][1][0]

# 현재 time 이전에 요청된 프로세스들을 다 우선순위 큐로 넣음
def handle():
    while (q and q[0][1][0] <= time):
        item = q.popleft()
        heapq.heappush(pq, (-(item[1][1]-item[1][0]), item[1][2], item[0]+1))  # (-p, b, pid)


handle()
order = []
while (pq):
    launched = heapq.heappop(pq)
    # print(launched)
    order.append(launched[-1])
    time += launched[1]
    handle()
    # handle 했는데 q에 있는 애들이 pq로 못 넘어오면..
    # q의 첫 프로세스가 요청된 시간으로 time을 증가시켜 줘야 함
    if (q and not pq):
        time = q[0][1][0]
        handle()

print(*order)

# for idx, (t, p, b) in enumerate(arr):  # 요청시점, 우선순위, 실행시간
#     pid = idx+1
#     print(pid, t,p,b)
#     # (-p, b, pid) 가 우선순위가 됨.. 근데 -(p-t) 가 돼야 하겠네