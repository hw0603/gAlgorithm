import heapq

n = int(input())

if (n-1)%4 in [0, 3]:
    print(n)
else:
    print(n-1)


q = [-1*(i+1) for i in range(n-1)]
heapq.heapify(q)

while len(q) > 1:
    a = heapq.heappop(q) * -1
    b = heapq.heappop(q) * -1
    print(a, b)
    heapq.heappush(q, b - a)

if len(q) == 1:
    print(n, heapq.heappop(q) * -1)