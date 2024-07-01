# Info
[31784 포닉스의 문단속](https://www.acmicpc.net/problem/31784)

## 💡 풀이 방법 요약
앞에서부터 조사해서 이미 A인 애들 제외하고
A로 만들 수 있을 경우에 A로 만듦

이후 돌려야 할 횟수가 남으면 뒤에서부터 돌림

## 👀 실패 이유
```python
moveCnt = initialK - K
a = K % moveCnt if moveCnt else K

arr[-1] += min(K % 26, a % 26)
```
잘못 생각해서 위와 같이 풀었다.  
앞에서 모든 문자를 A로 만들 때 움직인 횟수만큼 다시 한 바퀴를 돌았을 때, 맨 뒷자리를 덜 움직일 수 있는 경우가 있을까봐 `min`으로 계산했는데, 애초에 `moveCnt` 만큼 다시 움직인다고 제자리로 돌아오는 것이 아니므로 `K % moveCnt`는 틀린 식이었다.

## 🙂 마무리
None
