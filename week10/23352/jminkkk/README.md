# Info
[방탈출](https://www.acmicpc.net/problem/23352)

## 💡 풀이 방법 요약
1. 0이 아닌 좌표들에 대해 2개 고르기
2. 고른 2개의 좌표들의 최단 경로 찾기
3. 최단 경로의 길이와 두 좌표의 합 구하기
4. 경로의 길이가 max인 합들 중 최대 구하기  

진짜 문제점 -> 좌표들의 최단 경로 어케 찾누?

## 👀 실패 이유

## 🙂 마무리


                            System.out.println("arr[i][j]  = " + arr[i][j]);
                            System.out.println("i  = " + i + " j  = " + j);
                            System.out.println("arr[k][h]  = " + arr[k][h]);
                            System.out.println("k  = " + k + " h  = " + h);
                            maxDist = Math.max(maxDist, calDis(i, j, k, h));
                            maxSum = Math.max(maxSum, arr[i][j] + arr[k][h]);
                            System.out.println("maxDist = " + maxDist);
                            System.out.println("maxSum = " + maxDist);
