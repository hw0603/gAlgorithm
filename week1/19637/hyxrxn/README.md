## Info
[19637 IF문 좀 대신 써줘](https://www.acmicpc.net/problem/19637)

## 💡 풀이 방법 요약
1. 칭호와 전투력 상한값을 갖는 pair를 vector에 저장한다.
2. 캐릭터의 전투력 별로 다음 과정의 이분 탐색을 수행한다.
    - low, high, middle은 모두 vector의 순서이다.
3. middle 번째 vector의 전투력 상한값과 캐릭터의 전투력을 비교한다.
4. 캐릭터의 전투력이 작거나 같다면 high를 middle로 변경하고 answer에 high를 저장한다.
    - 칭호가 여러 개인 경우 가장 먼저 입력된 칭호를 출력해야 하기 때문에 같은 경우라면 high를 변경해야 한다.
5. 아니라면 low를 middle + 1로 변경하고 answer에 low를 저장한다.
6. low와 high가 같아질 때까지 반복하고 answer를 출력한다.

## 👀 실패 이유
1. 이중 for문 돌며 일일히 찾아서 출력해서 총 n^2의 시간 복잡도 발생 (시간 초과)
2. cin, cout 사용 시 버퍼 및 동기화 문제 (시간 초과)
    - `ios::sync_with_stdio(false)`를 사용해 C++ 표준 스트림과 C 표준 스트림의 동기화 비활성화
    - `cin.tie(nullptr)`를 사용해 입력 요청 전에 자동으로 출력 버퍼를 비우는 작업 비활성화
    - `cout.tie(nullptr)`를 사용해 어떤 스트림도 cout에 연결되지 않도록 설정
3. endl 사용 시 버퍼 flush 문제 (시간 초과)
    - endl은 새 줄 문자를 출력하고, 추가로 출력 버퍼를 비우기 때문에 endl 대신 \n 사용

## 🙂 마무리
