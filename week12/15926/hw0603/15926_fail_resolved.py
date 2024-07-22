import sys

N = int(sys.stdin.readline())
arr = list(sys.stdin.readline().strip())

stack = []

ans = 0
buffer = []

for i in range(len(arr)):
    if (arr[i] == '('):
        stack.append(i)
    else:
        if (stack):
            top = stack.pop()
            currentPairLenght = i-top+1
            if (buffer and top == buffer[-1][-1]):
                currentPairLenght += buffer[-1][0]
                buffer.pop()  # 이거 안 해서 틀렸었음
            ans = max(ans, currentPairLenght)

            if (i+1 < len(arr) and arr[i+1] == '('):  # 정상 종료 이후 '(' 이 오는 경우에만 이어갈 가능성이 있음
                buffer.append((currentPairLenght, i+1))  # i+1이 pop 되면 keep 가능
        else:
            buffer.clear()

print(ans)
