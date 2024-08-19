import sys
from itertools import accumulate

[sys.stdin.readline() for _ in range(2)]  # 앞 2줄 입력 버림
print(*accumulate(sorted(map(int, sys.stdin.readline().split()), reverse=True)), sep='\n')
