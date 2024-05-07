## Info
[과자 나눠주기](https://www.acmicpc.net/problem/16401)

## 💡 풀이 방법 요약

parametric search 문제입니다.<br>
성공함수를 구현합니다: 들어온 막대의 길이만큼 모든 과자들을 나누면 총 몇개인지<br>
    이 갯수가 n 이상이면 true 반환<br>
lower_bound를 구합니다.<br>

bound 구할 때 무한루프를 조심해야 한다.<br>
mid = (st + en) / 2<br>
mid = (st + en + 1) / 2<br>
둘 중에 어떤 건지,<br>
en = mid - 1, st = mid<br>
en = mid, st = mid + 1<br>
둘 중에 어떤 건지<br>
를 잘 사용하자(이거 조건 케이스 알아봤었는데 다 까먹음 걍 이거저거 해보고 되는거로 하는게 나을듯)

## 🙂 마무리
이번엔 제가 재즈처럼 페드로에게 티어를 스포했습니다
