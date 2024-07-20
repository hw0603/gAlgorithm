import sys

n = int(input())

brackets = list(sys.stdin.readline().strip())

stack = [0]

result = 0

for bracket in brackets:
    if bracket == '(':
        stack.append(0)
    else:
        if len(stack) == 1:
            stack = [0]
        else:
            temp = stack.pop() + 1
            stack[-1] += temp
            result = max(result, stack[-1])

print(result*2)