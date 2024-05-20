from collections import defaultdict
import sys

N = int(sys.stdin.readline().strip())
arr = list(map(int, sys.stdin.readline().strip().split()))

def minusFruit(fruitCnt: defaultdict, fruit: int):
    if (fruit not in fruitCnt):
        raise KeyError
    if (fruitCnt[fruit]) == 1:
        del fruitCnt[fruit]
    else:
        fruitCnt[fruit] -= 1

def addFruit(fruitCnt: defaultdict, fruit: int):
    fruitCnt[fruit] += 1

def abletoProceed(fruitCnt: defaultdict, fruit: int):
    addFruit(fruitCnt, fruit)
    if (len(fruitCnt) <= 2):
        return True
    else:
        minusFruit(fruitCnt, fruit)
        return False


left, right = 0, 0
fruitCnt = defaultdict(int)
totalFruit = 0
maxTotalFruit = 0
while (right < N):
    if (abletoProceed(fruitCnt, arr[right])):
        right += 1
        totalFruit += 1
    else:
        minusFruit(fruitCnt, arr[left])
        left += 1
        totalFruit -= 1
    
    maxTotalFruit = max(maxTotalFruit, totalFruit)

print(maxTotalFruit)
