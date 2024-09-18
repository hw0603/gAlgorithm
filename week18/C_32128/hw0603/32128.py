import sys

N, M, K = map(int, sys.stdin.readline().split())
S = [[None] + list(map(int, sys.stdin.readline().split())) for _ in range(M)]
operation = [list(map(int, sys.stdin.readline().split())) for _ in range(K)]
cards = [None] + list(range(1, N+1))


# 테크닉 하나 받아서 순열 사이클 분할
def decomposite(Si, N):
    visited = set()
    cycles = []
    
    for i in range(1, N+1):
        if (i in visited):
            continue
        cycle = []
        cur = i
        while (cur not in visited):
            visited.add(cur)
            cycle.append(cur)
            cur = Si[cur]
        cycles.append(cycle)
    
    return cycles

def doShuffle(cards, applyCnt, cycles):
    new_cards = cards[:]
    
    for cycle in cycles:
        cycleSize = len(cycle)
        effectiveApplyCnt = applyCnt % cycleSize
        for i in range(cycleSize):
            new_cards[cycle[(i+effectiveApplyCnt) % cycleSize]] = cards[cycle[i]]
    
    return new_cards


permutationCycles = [decomposite(Si, N) for Si in S]  # 각 셔플 기술에 사이클 분할 적용
for Xi, Yi in operation:
    Xi -= 1
    decomposed = permutationCycles[Xi]
    cards = doShuffle(cards, Yi, decomposed)

print(*cards[1:], sep=' ')
