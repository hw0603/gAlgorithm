import sys

T = int(sys.stdin.readline())

calc = lambda length: length * (length+1) // 2

# right가 2 이상일 때만 호출해야 함
isZigZag = lambda right: (arr[right] - arr[right-1]) * (arr[right-1] - arr[right-2]) < 0

def solve(n: int, arr: list) -> int:
    left, right = 0, 0  # [left, right)

    count = 0
    while (right < n):
        # 맞닿으면 right 전진
        if (left == right):
            right += 1
            continue
        
        # 두 포인터가 한 칸 차이날 때 -> 두 값이 같지 않으면 무조건 페어 하나 성립
        if (right - left == 1):
            if (arr[left] == arr[right]):
                left += 1
            right += 1
            continue
        
        # 일반적인 경우
        if (isZigZag(right)):
            right += 1
        else:
            count += calc(right-left-1)  # 현재 부분의 페어 개수 누적
            left = right-1  # left 포인터 당겨줌
    
    # 탈출한 경우 right == n일 것
    count += calc(n-left-1)
    return count

for _ in range(T):
    n = int(sys.stdin.readline().strip())
    arr = list(map(int, sys.stdin.readline().strip().split()))
    print(solve(n, arr))
