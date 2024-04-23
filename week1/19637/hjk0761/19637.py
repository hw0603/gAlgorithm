import sys

n, m = map(int, input().split())
titles = []
threshold_exist = set()
for _ in range(n):
    title, threshold = sys.stdin.readline().strip().split()
    threshold = int(threshold)
    if threshold not in threshold_exist:
        titles.append([threshold, title])
        threshold_exist.add(threshold)

def findTitle(power, head, tail):
    print("power: " + str(power))
    print("head: " + str(head))
    print("tail: " + str(tail))
    if head <= tail:
        return titles[head][1]
    
    index = (head + tail) // 2
    if titles[index][0] < power:
        return findTitle(power, head, index + 1)
    elif titles[index][0] >= power:
        return findTitle(power, index, tail)

for _ in range(m):
    power = int(sys.stdin.readline().strip())
    newTitle = findTitle(power, len(titles)-1, 0)
    print(newTitle)