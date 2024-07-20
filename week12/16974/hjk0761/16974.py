n, x = map(int, input().split())

patty = 0
# layer = 2 ** (n+2) - 3
# patty = 2 ** (n+1) - 1
left, right = 1, 2 ** (n+2) - 3

for i in range(n, 0, -1):
    mid = (left + right) // 2
    if x == mid:
        patty += 2 ** i
        break
    elif x == left:
        break
    elif x == right:
        patty += 2 ** (i+1) - 1
        break
    elif x < mid:
        if  i != 1:
            left += 1
            right = mid - 1
        else:
            patty += 1
            break
    else:
        if i != 1:
            patty += 2 ** i
            right -= 1
            left = mid + 1
        else:
            patty += 3

print(patty)