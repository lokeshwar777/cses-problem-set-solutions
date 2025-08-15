""" 777 """


def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    index_map = [n] * (n + 1)
    for index, value in enumerate(arr):
        index_map[value] = index
    rounds = 0
    for cur_num in range(1, n + 1):
        prev_num_index, cur_num_index = index_map[cur_num - 1], index_map[cur_num]
        rounds += prev_num_index > cur_num_index
        # print(prev_num_index, cur_num_index)
    return rounds


T = 1
# T = int(input())
for _ in range(T):
    res = solve()
    print(res)
    # print("YES" if res else "NO")

"""
- if the previous number occurs before the current number then both of them can be taken in a single round
- for this to happen for each num the index of previous num should be less than the index of current num, 
    formally -> prev_num_index < cur_num_index
    then both of them belong to the same round
"""
