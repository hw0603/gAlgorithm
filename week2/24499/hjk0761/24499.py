n, k = map(int, input().split())
pie = list(map(int, input().split()))

circular_pie = pie + pie[:-2]

prefix_sum = [0] * len(circular_pie)
prefix_sum[0] = circular_pie[0]

for i in range(1, len(circular_pie)):
    prefix_sum[i] = prefix_sum[i-1] + circular_pie[i]

_max = -1

for i in range(len(prefix_sum) - k):
    _max = max(_max, prefix_sum[i + k] - prefix_sum[i])

if n == 1:
    print(pie[0])
else:
    print(_max)