s = int(input())

def find(dest, div1, div2):
    temp = []
    for i in range(dest//div1):
        if (dest - (div1 * i)) % div2 == 0:
            test1, test2 = i, (dest - (div1 * i)) // div2
            if test1 >= 0 and test1 <= 200 and test2 >= 0 and test2 <= 200:
                temp.append([test1, test2])
    return temp

answer = []

if s % 4763 != 0:
    print(0)
elif s == 0:
    print(1)
    zero = 0
    print(zero, zero)
else:
    s = s // 4763
    answer.extend(find(s, 508, 212))
    answer.extend(find(s, 508, 305))
    answer.extend(find(s, 108, 212))
    answer.extend(find(s, 108, 305))
    if len(answer) == 0:
        print(0)
    else:
        answer.sort(key=lambda x: (x[0], x[1]))
        print(len(answer))
        for moongwa, eegwa in answer:
            print(moongwa, eegwa)