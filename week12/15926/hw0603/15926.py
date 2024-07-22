import sys

N = int(sys.stdin.readline())
arr = list(sys.stdin.readline().strip())

stack = [-1]
result = 0

for i in range(N):
    if (arr[i] == '('):
        stack.append(i)
    else:
        stack.pop()
        if (stack):
            currentPairLenght = i - stack[-1]
            result = max(result, currentPairLenght)
        else:
            stack.append(i)

print(result)
