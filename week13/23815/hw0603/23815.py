import sys

N = int(sys.stdin.readline())

def apply(cur: int, op: str, var: int):
    match(op):
        case '+':
            return cur + var
        case '-':
            return cur - var
        case '*':
            return cur * var
        case '/':
            return cur // var

noSkip, skip = 1, -sys.maxsize
for _ in range(N):
    a, b = sys.stdin.readline().strip().split()
    c = max(apply(noSkip, a[0], int(a[1])), apply(noSkip, b[0], int(b[1]))) if noSkip > 0 else c
    d = max(apply(skip, a[0], int(a[1])), apply(skip, b[0], int(b[1])))
    
    skip = max(noSkip, d)  # 이번턴에 스킵한걸로 치기 vs 이전에 스킵한 상태에서 이어나가기
    noSkip = c
    if (max(noSkip, skip) <= 0):
        sys.exit(print("ddong game"))

print(max(noSkip, skip))
