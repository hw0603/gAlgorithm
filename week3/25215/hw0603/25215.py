from itertools import groupby
import sys

string = sys.stdin.readline().strip()
consecutive_upper_lower_case = [len(list(group)) for isLower, group in groupby(string, key=str.islower)]

# [소, 대, ..., 소, 대] 로 인덱스 맞춰줌
# 대문자로 시작하는 경우 문자열 맨 앞에 소문자가 0개 있는 것으로 봄
if (string[0].isupper()):
    consecutive_upper_lower_case = [0] + consecutive_upper_lower_case

result = 0
isCapsLockOn = False
for idx, count in enumerate(consecutive_upper_lower_case):
    isUpperCase = bool(idx % 2)  # 인덱스가 홀수면 현재 문자는 대문자
    if (isUpperCase ^ isCapsLockOn):  # 대소문자 상태가 안 맞으면
        result += 1  # SHIFT, CAPSLOCK 중 하나는 무조건 눌러야 함
        if (count > 1):  # 연속된 문자가 2개 이상 나올 경우
            isCapsLockOn ^= True  # 캡스락 Toggle

print(result + len(string))
print(result)
