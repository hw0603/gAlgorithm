# Info
[28017 게임을 클리어하자](https://www.acmicpc.net/problem/28017)

## 💡 풀이 방법 요약

min[i][j] => i번재 게임에서 j 번 무기 골랐을 때 최소값

min[n][j] => value[i][j] + min(min[n-1][ !j])

min[2][1] = > value[2][1] + min{min[1][0], min[1][2], ...}

## 👀 실패 이유

## 🙂 마무리

