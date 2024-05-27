# Info
[31861 비밀번호 만들기](https://www.acmicpc.net/problem/31861)

## 💡 풀이 방법 요약

## 👀 실패 이유
+ 메모리 초과ㅠ
   1. A부터 Z까지 순회하며 재귀 사용
      + i + n부터 25
      + 0부터 i - n
      + |(i -1) - i| >= N
   2. depth가 m이 된다면 Set에 넣고 count를 구함

String 만드는 거 말고 visited 배열을 써서 뭔가 해결하고 싶은데 어케 해야함
## 🙂 마무리

