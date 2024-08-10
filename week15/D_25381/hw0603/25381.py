import sys

S = list(map(ord, (sys.stdin.readline().strip())))

def count(left: int, right: int) -> int:
    cnt, lCnt = 0, 0
    for ch in S:
        if (ch == left):
            lCnt += 1
        elif (ch == right and lCnt > 0):
            lCnt -= 1
            cnt += 1
    return cnt

print(min(count(65, 66) + count(66, 67), S.count(66)))
