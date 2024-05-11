import sys

n, p = map(int, sys.stdin.readline().strip().split())
w, l, g = map(int, sys.stdin.readline().strip().split())

win = set()
lose = set()

for _ in range(p):
    name, case = sys.stdin.readline().strip().split()
    if case == "W":
        win.add(name)
    else:
        lose.add(name)

score = 0
iron = True

for _ in range(n):
    player = sys.stdin.readline().strip()
    if player in win:
        score += w
    else:
        score = max(0, score - l)
    if score >= g:
        iron = False
        break

if iron:
    print("I AM IRONMAN!!")
else:
    print("I AM NOT IRONMAN!!")