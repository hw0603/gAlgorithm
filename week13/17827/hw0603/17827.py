import sys

N, M, V = map(int, sys.stdin.readline().strip().split())
arr = list(map(int, sys.stdin.readline().strip().split()))
convert = lambda q: q if q < N else (tail := V-1) + (q-tail) % (N-tail)
query = (convert(int(sys.stdin.readline())) for _ in range(M))

print(*(arr[q] for q in query), sep='\n')
