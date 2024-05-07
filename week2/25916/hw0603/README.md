## Info
[25916 싫은데요](https://www.acmicpc.net/problem/25916)

## 💡 풀이 방법 요약
기본 투포인터 문제  
구간합의 upper bound가 지정되어 있고(`M`), 해당 상한선을 넘지 않는 최대의 구간합을 투포인터를 활용하여 구하면 된다.  
  
처음에는 누적합을 구해 두고 계산했었는데, 어차피 투포인터를 활용할 것이라 굳이 누적합을 활용하지 않아도 됐다.

## 🙂 마무리
쉬운 문제였는데 투포인터 루핑 조건을 잘못 잡아서 몇 시간동안 삽질을 했다.  
문제가 됐던 부분은 `while (left <= right < N)` 과 같이 `left` 포인터가 `right` 포인터를 역전할 수 없도록 설정했던 부분이였다.  
중간에 분명 역전됐다가 다시 돌아오는 부분이 존재했고, 내 코드는 그럴 때 그냥 루프를 탈출해 버려서 문제가 됐던 것. 루핑 조건 조심합시다...^^  
```python
# Fail
import sys

N, M = map(int, sys.stdin.readline().split())
data = list(map(int, sys.stdin.readline().split()))

left, right = 0, 0  # [left, right)
partSum = 0
result = 0
while (left <= right < N):
    # 하나 더 더할 수 있으면 오른쪽 포인터 옮기고 더함
    if (partSum + data[right] <= M):
        partSum += data[right]
        right += 1
        
    # 더할 수 없으면 왼쪽 포인터 옮겨서 부분합 감소
    else:
        partSum -= data[left]
        left += 1
    # left, right가 같은 위치 -> 현재 인덱스 값 하나만으로 M보다 크다는 뜻
    # -> 왼쪽 오른쪽 포인터 둘 다 1씩 증가시킴
    if (left == right):
        # left += 1
        partSum += data[right]
        right += 1

    if (partSum <= M):
        result = max(result, partSum)

print(result)
```

개인적인 풀이법이긴 한데, 투포인터 구간을 `[left, rigth)` 처럼 `right` 포인터는 열린구간으로 생각하는 것이 편한 것 같다.  
파이썬에서 `arr[left:right]` 과 같은 리스트 슬라이싱 연산이 위와 같이 동작하기도 하고, 보통 개구간으로 두게 되면 포인터 전진 시 구간에 들어오게 될 원소에 접근할 때 포인터값에 1을 더해서 접근해야 해서(`arr[right+1]`) 귀찮아진다.  
  
루핑 전 `partSum, left, right` 를 모두 `0`으로 초기화할 수 있어 직관적이고, `left` 와 `right` 모두 '값 누적 -> 포인터 전진' 으로 순서를 맞출 수 있는 것은 덤.  
`left == right` 일 때 구간합이 `0`으로 항상 맞춰지므로 디버깅하기도 편하다!
