# Info
[제기차기](https://www.acmicpc.net/problem/23830)

## 💡 풀이 방법 요약
1. 학생들의 점수를 입력받는다.
2. k값을 변경하며 가능 여부를 확인한다.
    - lower는 1, upper는 100001로 설정한다.
3. 가능하다면 upper를 middle - 1로 변경하고, middle을 answer에 저장한다.
4. 불가능하다면 lower를 middle + 1로 변경한다.
5. answer가 초기값이라면 -1을 출력한 후 종료한다.
6. 아니라면 answer를 출력한 후 종료한다.

## 👀 실패 이유
1. sum은 long long으로 설정하고 s를 바꾸는 것을 잊어 오류 발생
2. upper를 100000으로 설정해 100000점인 학생들이 추가 점수를 얻지 못함
3. lower를 0으로 설정해 문제의 양수 조건을 만족하지 못함

## 🙂 마무리
