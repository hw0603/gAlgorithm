# Info
[Link](https://boj.kr/31778)
## 💡 풀이 방법 요약

1. P와 C의 인덱스를 가지고 있는 각 리스트 생성
2. K만큼 가장 뒤의 P를 최대한 앞에 있는 C와 바꾸어 옮겨야 함
3. 그 후 각 C에 대해 C의 인덱스보다 작은 인덱스인 P의 갯수(pCount)를 찾아야함
   + p의 갯수는 자기 인덱스 - i + k (k 더해주는 이유 -> p랑 바꾼 c를 cList에서 안빼고 pList에 더 해서)
4. 한 C에 대해 PPC가 가능한 경우의 수는 (pCount)C2 조합임 (= pCount * (pCount-1) / 2)

## 👀 실패 이유

1. sum이 int 범위를 초과할 수 있다
2. k가 p의 보다 클 수 있다
   + k = Math.min(k, pList.size())로 바꿔버리기

## 🙂 마무리
