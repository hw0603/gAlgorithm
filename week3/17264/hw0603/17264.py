import sys

N, P = map(int, sys.stdin.readline().split())
W, L, G = map(int, sys.stdin.readline().split())
hackedData = (sys.stdin.readline().strip().split() for _ in range(P))
data = {pName for pName, isWin in hackedData if isWin == "W"}

score = 0
for _ in range(N):
    playerName = sys.stdin.readline().strip()
    score += (W if playerName in data else -L)
    score = max(score, 0)
    if (score >= G):
        break

print(f"I AM{' NOT ' if score >= G else ' '}IRONMAN!!")
