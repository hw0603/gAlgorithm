## 27376 - 참살이길

단순 구현 문제다. 정답이 int를 벗어난다. 코테에서는 무조건 long으로 쓰고 보자.

startTime = 신호등이 처음 초록불이 되는 시점

period = 신호등이 초록불이나 빨간 불이 지속되는 시간

startPoint = 신호등의 위치

신호등 위치에 도착한 시점을 arriveTime 이라 하면, arriveTime이 startTime 이하일 경우 그 차이만큼 기다려야 한다.

그 외의 경우 계산이 필요하다.

arriveTime - startTime = 신호등의 가동 시간

x = (arriveTime - startTime)/period = 신호등이 주기가 바뀐 횟수

신호등이 주기가 바뀐 횟수가 짝수라면 지금이 초록불이기 때문에 기다리지 않는다.

홀수라면 

periodX = period * x = 신호등이 지금 신호가 되기 전까지 지난 시간

passTime = (arriveTime - startTime) - periodX = 지금 신호가 되고나서 지난 시간

period - passTime = 기다려야 하는 시간

으로 기다려야 하는 시간을 계산할 수 있다.





