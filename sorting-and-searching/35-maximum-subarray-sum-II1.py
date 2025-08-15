# GPT code - short and good
from heapq import heappop, heappush


INF = 10 ** 20

# take input
n, a, b = map(int, input().split())
nums = [int(x) for x in input().split()]

# build prefix sums array
prefix_sums = [0]
for num in nums:
    prefix_sums.append(prefix_sums[-1] + num)

heap = []
ans = -INF

for right in range(1, n + 1):
    left = right - a
    if left >= 0:
        heappush(heap, (prefix_sums[left], left))
    while heap and heap[0][1] < right - b:
        heappop(heap)
    if heap:
        ans = max(ans, prefix_sums[right] - heap[0][0])

print(ans)
