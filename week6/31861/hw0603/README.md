# Info
[31861 비밀번호 만들기](https://www.acmicpc.net/problem/31861)

## 💡 풀이 방법 요약
먼저 입력값을 전처리하여 각 문자 이후에 올 수 있는 문자들을 딕셔너리 형태로 구축한다.

이후 `현재 문자열의 마지막 글자`와 `남은 글자 수` 를 전달받아, 가능한 경우의 수를 반환하는 재귀함수를 선언한다. (종료조건: 남은 글자 수가 1일 때 `return len(data[lastChar])`)

그냥 두면 BF랑 다름없으니 재귀함수에 `@lru_cache` 데코레이터를 붙여 캐싱을 활용할 수 있도록 한다.

첫 글자로 가능한 문자들에 대해 모두 재귀호출하여 결과를 합산하면 정답.

## 👀 실패 이유
- 캐싱 안해서 시간초과 남
- `N==0` 인 경우 `calcCandidate()` 결과에 `target`이 중복으로 들어있는데, 중복 제거 놓침


## 🙂 마무리
`sys.setrecursionlimit()`은 한 재귀호출의 깊이를 설정하는 것이 아니라, 시스템 전역의 stack depth를 설정하는 함수였다(...) 실제로 poorly-named 되었다고 한다;

덕분에 같은 로직이라도, 재귀호출 내에 패킹/언패킹 연산이 들어가거나 for-loop를 컴프리핸션으로 바꾼 경우 재귀호출 깊이는 같지만 시스템 스택 깊이가 더 깊어져 `RecursionError`가 발생했다.

`@lru_cache`를 사용해도 유사한 이유로 시스템 스택 깊이가 늘어나서 `N=0, M=500` 이상이 될 경우 재귀호출 예외가 발생하는 것을 확인했다(그런데 통과는 된다ㅋㅋ).  
`recursionlimit`을 더 늘리려고 해도 약 `2*10**9` 이상으로 더 늘리는 것이 불가능했다.
```text
OverflowError: Python int too large to convert to C int
```

아래와 같이 별도의 딕셔너리로 캐시를 구현해 줄 경우 재귀호출 예외 없이 잘 동작한다.
```python
cache = {}
def calculate(lastChar: int, neededLength: int):
    ...
    count = 0
    for nextChar in data[lastChar]:
        if (f"{nextChar} {neededLength-1}" not in cache):
            cache[f"{nextChar} {neededLength-1}"] = calculate(nextChar, neededLength-1)
        count += cache[f"{nextChar} {neededLength-1}"]
    
    return count % DIVISOR
```