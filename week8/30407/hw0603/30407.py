import sys

N = int(sys.stdin.readline().strip())
H, D, K = map(int, sys.stdin.readline().strip().split())
R = [int(sys.stdin.readline().strip()) for _ in range(N)]

maxHealth = 0

def search(roundIdx=0, dist=D, health=H, surprised=False):
    global maxHealth

    if (roundIdx == N):
        # Leaf 노드 도착 시 최댓값 업데이트 후 종료
        maxHealth = max(maxHealth, health)
        return
    
    punchPower = 0 if surprised else R[roundIdx]
    surprised = None if surprised else surprised  # 한 번 사용한 경우 더 이상 '깜짝 놀라게 하기'를 사용할 수 없도록 마킹

    # 웅크리기: 데미지 절반 감소
    damage = max(0, (punchPower-dist) // 2)
    search(roundIdx+1, dist, health-damage, surprised)
    
    # 네발로 걷기: K만큼 멀리 이동
    newDist = dist+K
    damage = max(0, punchPower-newDist)
    search(roundIdx+1, newDist, health-damage, surprised)
    
    # 깜짝 놀라게 하기: 다음 라운드의 공격 무시
    if (surprised is not None):  # 이전에 사용한 적이 없을 때만 사용 가능!
        damage = max(0, punchPower-dist)
        search(roundIdx+1, dist, health-damage, 1)

search(0, D, H, False)

print(-1 if maxHealth <= 0 else maxHealth)
