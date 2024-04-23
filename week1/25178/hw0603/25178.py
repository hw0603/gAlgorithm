from collections import Counter
from collections import deque
import sys

N = int(sys.stdin.readline())
str1 = sys.stdin.readline().strip()
str2 = sys.stdin.readline().strip()
vowels = {'a', 'e', 'i', 'o', 'u'}

isAnagramable = Counter(str1) == Counter(str2)
isPrefixPostfixMatched = str1[0] == str2[0] and str1[-1] == str2[-1]

# 선행 조건 두 개 만족 못 하면 조기 종료
if not (isAnagramable and isPrefixPostfixMatched):
    sys.exit(print("NO"))


q1 = deque(str1)
q2 = deque(str2)

while (q1 and q2):
    while (q1 and q2 and q1[0] == q2[0]):
        q1.popleft()
        q2.popleft()
    
    while (q1 and q1[0] in vowels):
        q1.popleft()
    while (q2 and q2[0] in vowels):
        q2.popleft()
    
    if (q1 and q2 and q1[0] != q2[0]):
        sys.exit(print("NO"))

print("YES")
