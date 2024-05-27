from collections import defaultdict
from itertools import product
import sys

S = int(sys.stdin.readline().strip())
S, r = divmod(S, 4763)
if (r):  # 4763 으로 안 나눠지면 가능한 경우가 없음
    sys.exit(print(0))

data = defaultdict(list)
for keDiff, mrDiff in product(range(201), range(201)):
    scores = (keDiff*i + mrDiff*j for i, j in product((508, 108), (212, 305)))
    for score in scores:
        data[score].append((keDiff, mrDiff))

"""
국어-영어, 수학-탐구 의 차가 0일 경우에는 
원래 508과 212를 곱하는 경우는 존재해서는 안 되지만
편의상 그냥 range(201)로 다 계산했으니까 중복이 발생할 수 있음
-> set 으로 중복 제거
"""
result = sorted(set(data[S]))
print(len(result))
answer = (f"{keDiff} {mrDiff}" for keDiff, mrDiff in result)
print(*answer, sep='\n')
