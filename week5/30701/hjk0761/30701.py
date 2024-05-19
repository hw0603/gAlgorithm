import sys
n, d = map(int, input().split())

monster = []
equipment = []

for _ in range(n):
    index, power = map(int, sys.stdin.readline().strip().split())
    if index == 1:
        monster.append(power)
    else:
        equipment.append(power)

monster.sort()
equipment.sort()

index_m, max_m = 0, len(monster)
index_e, max_e = 0, len(equipment)



while True:
    if index_m == max_m:
        print(n)
        break
    if monster[index_m] < d:
        d += monster[index_m]
        index_m += 1
    elif index_e < max_e:
        d *= equipment[index_e]
        index_e += 1
    else:
        print(index_e + index_m)
        break