from itertools import starmap, pairwise
import sys

N = int(sys.stdin.readline())
coords = sorted(tuple(map(int, sys.stdin.readline().strip().split())) for _ in range(N))  # (W, H)

initCoords, *remainCoords = coords
stack = [initCoords]

for coord in remainCoords:
    while (stack):
        top = stack[-1]
        if (top[1] < coord[1]):
            stack.pop()
        else:
            break
    stack.append(coord)

# stack에 x가 증가할수록 y가 감소하도록 저장되어 있음
# -> 겹치는 x만큼을 제외해 주고 현재 y값을 곱해주면 추가되는 넓이
calcAddedSize = lambda prev, cur: (cur[0] - prev[0]) * cur[1]
result = (stack[0][0] * stack[0][1]) + sum(starmap(calcAddedSize, pairwise(stack)))
print(result)
