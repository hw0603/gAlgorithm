import sys

n, m = map(int, sys.stdin.readline().strip().split())

youtube = [[] for _ in range(n)]

def timeCal(start, end):
    s_h, s_m = map(int, start.split(":"))
    e_h, e_m = map(int, end.split(":"))
    return (60 * e_h + e_m) - (60 * s_h + s_m)

names = set()

youbube = [[] for _ in range(n)]
for i in range(n):
    name, day, start, end = sys.stdin.readline().strip().split()
    names.add(name)
    youtube[i] = [name, int(day), start, end]
youtube.sort(key=lambda x:x[1])
youtube.append(["test", m+7, "00:00", "00:00"])

count = dict()
time = dict()
weekName = set()
week = 1

for i in range(n+1):
    name, day, start, end = youtube[i]
    if day > week * 7 and day <= (week + 1) * 7:
        possibleNames = set()
        for tempName in weekName:
            if count[tempName] >= 5 and time[tempName] >= 3600:
                possibleNames.add(tempName)
        names = names & possibleNames
        weekName = set()
        week += 1
        count = dict()
        time = dict()
    elif day > (week + 1) * 7:
        names = set()
        break
    if name in names:
        weekName.add(name)
        if name not in count.keys():
            count[name] = 1
        else:
            count[name] += 1
        s_time = timeCal(start, end)
        if name not in time.keys():
            time[name] = s_time
        else:
            time[name] += s_time

names = list(names)
names.sort()

if len(names) == 0:
    print(-1)
else:
    for name in names:
        print(name)