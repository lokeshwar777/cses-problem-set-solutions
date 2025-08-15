""" 777 """
from heapq import heappop, heappush
INF = 10 ** 20

# take input
n, min_length, max_length = map(int, input().split())
nums = [int(x) for x in input().split()]

# build prefix sums array
prefix_sums = []
prefix_sum = 0
for num in nums:
    prefix_sum += num
    prefix_sums.append(prefix_sum)
# print(prefix_sums)

heap = [(0, -1)]
max_subarray_sum = -INF

for right in range(n):
    left = right - min_length
    if left >= 0:
        heappush(heap, (prefix_sums[left], left))
    min_required_index = right - max_length
    while heap and heap[0][1] < min_required_index:
        heappop(heap)
    if right >= min_length - 1:
        right_prefix_sum = prefix_sums[right]
        left_prefix_sum = heap[0][0] if heap else 0
        cur_max_subarray_sum = right_prefix_sum - left_prefix_sum
        max_subarray_sum = max(max_subarray_sum, cur_max_subarray_sum)
        # print(right, left_prefix_sum, right_prefix_sum, cur_max_subarray_sum, heap)

print(max_subarray_sum)
