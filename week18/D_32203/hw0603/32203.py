import sys

N, M = map(int, sys.stdin.readline().strip().split())
parent = list(range(N+1))
c = [None] + list(map(int, sys.stdin.readline().strip().split()))
people = [None] + [(1, 0) if c[i] % 2 else (0, 1) for i in range(1, N+1)]  # 각 집합안에 남자/여자 수

def union(n1, n2) -> int:
    result = 0

    n1p, n2p = find(n1), find(n2)  # 각자 부모 찾고
    result += people[n1p][0] * people[n2p][1]  # n1그룹 남자 x n2그룹 여자 매칭
    result += people[n1p][1] * people[n2p][0]  # n1그룹 여자 x n2그룹 남자 매칭
    
    # 병합
    ch, pa = max(n1p, n2p), min(n1p, n2p)
    parent[ch] = find(pa)  # 부모 찾아서 바로밑에 갖다 붙임
    people[pa] = (people[pa][0]+people[ch][0], people[pa][1]+people[ch][1])  # 부모는 자식정보를 포함

    return result

def find(node):
    if (parent[node] != node):
        parent[node] = find(parent[node])
    return parent[node]

ans = 0  # 남녀 쌍 개수
for _ in range(M):
    a, b = map(int, sys.stdin.readline().strip().split())
    if (find(a) != find(b)):
        ans += union(a, b)
    print(ans)
