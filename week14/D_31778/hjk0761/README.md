# Info
[PPC 만들기](https://boj.kr/31778)

## 💡 풀이 방법 요약

최대한 P를 왼쪽으로, C를 오른쪽으로 몰아야 PPC 문자열이 최대가 됩니다.

그래서 앞에서부터 C를, 뒤에서부터 P를 찾아 최대 k 번 만큼 바꾸는 작업을 순회합니다.

이후 C마다 해당 C보다 왼쪽에 있는 P의 갯수를 세주면 만들 수 있는 PPC 문자열의 개수를 알 수 있습니다.

모든 C 마다 P의 개수를 세는건 최대 O(n^2)가 될 수 있으므로, P의 개수에 대한 누적합을 구하고, 오른쪽부터 C를 찾아 해당 위치의 누적합 값을 통해 계산했습니다.

참고로 모든 C에 대해, 왼쪽에 있는 P의 개수를 i라고 한다면, 만들 수 있는 PPC 문자열의 개수는 `(i-1) * i // 2` 입니다.

## 👀 실패 이유

## 🙂 마무리
