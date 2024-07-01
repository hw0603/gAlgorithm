from functools import lru_cache
from itertools import chain
import sys

sys.setrecursionlimit(2*10**9)
DIVISOR = 1_000_000_007

N, M = map(int, sys.stdin.readline().strip().split())

def aboveFrom(target: int):
    return range(target+N, 27)

def belowFrom(target: int):
    return range(1, target-N+1)

# target 문자 이후에 사용할 수 있는 문자들
def calcCandidate(target: int):
    return set(chain(belowFrom(target), aboveFrom(target)))  # N == 0 일 때 target이 두 번 들어감 -> 중복제거

data = {k: tuple(calcCandidate(k)) for k in range(1, 27) if len(tuple(calcCandidate(k))) > 0}

# calculate(마지막 글자, 남은 글자 수) -> 가능한 경우의 수
@lru_cache
def calculate(lastChar: int, neededLength: int):
    if (neededLength == 1):
        return len(data[lastChar])
    
    count = 0
    for nextChar in data[lastChar]:
        count += calculate(nextChar, neededLength-1)
    
    return count % DIVISOR

print(sum(calculate(ch, M-1) for ch in data.keys()) % DIVISOR)
