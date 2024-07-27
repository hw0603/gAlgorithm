import sys

n = int(input())

result = 1

skip = sys.maxsize + 1

increase = ['+', '*']

def cal(prev, order):
    symbol, amount = order[0], int(order[1])
    if symbol == '+':
        return prev + amount
    elif symbol == '*':
        return prev * amount
    elif symbol == '-':
        return prev - amount
    else:
        return prev // amount

for _ in range(n):
    orders = list(sys.stdin.readline().strip().split())
    if result <= 0 and skip <= 0:
        continue
    if orders[0][0] in increase and orders[1][0] in increase:
        if result > 0:
            result = max(cal(result, orders[0]), cal(result, orders[1]))
        if skip != sys.maxsize + 1:
            skip = max(cal(skip, orders[0]), cal(skip, orders[1]))
    elif orders[0][0] in increase and orders[1][0] not in increase:
        if result > 0:
            result = cal(result, orders[0])
        if skip != sys.maxsize + 1:
            skip = cal(skip, orders[0])
    elif orders[0][0] not in increase and orders[1][0] in increase:
        if result > 0:
            result = cal(result, orders[1])
        if skip != sys.maxsize + 1:
            skip = cal(skip, orders[1])
    else:
        if skip != sys.maxsize + 1:
            alreadySkip = max(cal(skip, orders[0]), cal(skip, orders[1]))
            skip = max(alreadySkip, result)
        else:
            skip = result
        if result > 0:
            result = max(cal(result, orders[0]), cal(result, orders[1]))


result = max(result, skip) if skip != sys.maxsize + 1 else result

print(result if result > 0 else "ddong game")