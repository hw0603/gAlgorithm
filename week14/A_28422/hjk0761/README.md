# Info
[XOR 카드 게임](https://boj.kr/28422)

## 💡 풀이 방법 요약

DP 입니다.

점화식만 잘 세우면 풀 수 있습니다.

두 칸 전까지의 계산 결과에 전 칸과 지금 칸을 XOR 한 결과와,

세 칸 전까지의 계산 결과에 이전 두 칸과 지금 칸을 XOR 한 결과 중 큰 값을 저장하면 됩니다.

마지막 한 칸이 남은 경우 0점이 되는 건 마지막 칸이 두 칸 전과 세 칸 전까지의 결과만 가지므로 자연스럽게 처리됩니다.

단, 첫 네 칸의 경우만 잘 처리해주면 됩니다.

## 👀 실패 이유

조건 하나를 빼먹었습니다.

`n = 4`일 떄 `dp[1] + (deck[2] ^ deck[3] ^ deck[4]) 가 불가능한데, 이를 고려하지 않아서 한 번 틀렸습니다.
 
## 🙂 마무리

이진수에서 1 개수 세는 걸 `n &= (n-1)` 로 할 수 있습니다.

문제 풀고 나서 생각이 나 고치진 않았습니다. 알아두면 좋을 듯 합니당.