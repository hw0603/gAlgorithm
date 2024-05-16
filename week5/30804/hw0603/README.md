# Info
[30804 과일 탕후루](https://www.acmicpc.net/problem/30804)

## 💡 풀이 방법 요약
투 포인터를 활용하여 풀이한다.

두 개의 포인터 내의 구간을 탕후루 내에서 선택된 과일로 생각하고, 현재 구간의 각 과일별 개수를 딕셔너리로 유지한다.

딕셔너리를 조사하여 다음 과일이 범위에 들어와도 구간의 총 과일 수가 2개를 초과하지 않으면 right 포인터를 전진(오른쪽 과일 추가) 하고, 아니라면 left 포인터를 전진(왼쪽 과일 삭제)한다.

탐색하면서 구간별 과일의 최대 개수를 유지해 주다가, 루프 종료 후 출력하면 정답.

## 🙂 마무리
투포인터는 역시 `[left, right)`