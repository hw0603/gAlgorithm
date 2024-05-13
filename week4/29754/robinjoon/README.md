#
 Info
[29754 세상에는 많은...](https://www.acmicpc.net/problem/29754)

## 💡 풀이 방법 요약
두개의 Map을 만들고 모두 순회하며 검사하면 됨. Stream 장인이 된거같음...

Map<String, Map<Integer, Long>> map; // 누가 몇번째 주에 몇분 방송을 했는지 저장

Map<String, Map<Integer, Integer>> map2 // 누가 몇번째 주에 몇번 방송을 했는지 저장

## 👀 실패 이유

매 주 모두 조건을 만족해야 했음. 만약, 어느 한 주에 방송을 아예 하지 않았다면, 그 주는 데이터가 없어서 아예 조건 검사가 수행되지 않았음.

따라서, 매 주의 데이터가 존재하는지 확인한뒤 그렇지 않으면 제외하는 로직을 추가함.

``` Java
if(weekHourMap.keySet().size() < m/7) {
    print = false;
}
```

## 🙂 마무리

