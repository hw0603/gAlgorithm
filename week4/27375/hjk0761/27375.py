import sys
n, k = map(int, input().split())
classes = []
for i in range(n):
    day, start, end = map(int, sys.stdin.readline().strip().split())
    if day != 5:
        classes.append([day, start, end])

n = len(classes)
count = 0
total = 0

classes.sort(key=lambda x:(x[0], x[1]))


def possibleTime(temp, day, s, e):
    for index in temp:
        e_day, e_s, e_e  = classes[index]
        if e_day == day and ((s >= e_s and s <= e_e) or (e >= e_s and e <= e_e)):
            return False
    return True

def possible(temp, day, s, e):
    if (total + e - s + 1 <= k and possibleTime(temp, day, s, e)):
        return True
    return False

def tracking(temp, index):
    global total, count
    if total == k:
        count += 1
        return
    for i in range(index + 1, n):
        day, s, e = classes[i]
        if possible(temp, day, s, e):
            temp.append(i)
            total += (e - s + 1)
            tracking(temp, i)
            total -= (e - s + 1)
            temp.remove(i)

tracking([], -1)

print(count)