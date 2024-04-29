## Info
[29721 변형 체스 놀이 : 다바바(Dabbaba)](https://www.acmicpc.net/problem/29721)

## 💡 풀이 방법 요약
1. 다바바를 포인트로 List에 저장
2. 해당 다바바에 대한 이동가능한 포인트들을 Set에 저장

   2-1. 각 다바바에 대한 포인트 Set을 합침
3. 만약 Set에 다바바가 있다면 이동 불가하므로 제거
4. Set 사이즈 출력

## 🙂 마무리
시간초과가 계속났는데 아래처럼 변경하니까 됨
`canMovePoint.removeIf(points::contains);` -> `points.forEach(canMovePoint::remove);`
1. `canMovePoint.removeIf(points::contains);`는 n^2
2. `points.forEach(canMovePoint::remove);` n이라 그런듯

시간복잡도 생각하는 연습을 해야겠다ㅠ
