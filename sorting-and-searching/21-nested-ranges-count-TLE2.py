""" 777 """


class FenwickTree:  # 1-based
    def __init__(self, size):
        self.TREE_SIZE = size + 1
        self.tree = [0] * self.TREE_SIZE

    def update(self, index, delta):  # delta/diff prev value vs current
        while index < self.TREE_SIZE:
            self.tree[index] += delta
            index += index & -index

    def query(self, index):
        result = 0
        while index > 0:
            result += self.tree[index]
            index -= index & -index
        return result


def get_compressed(unique_elements):
    """ coordinate compression """
    return {original: compressed for compressed,
            original in enumerate(sorted(unique_elements), start=1)}


N = int(input())
unique_elements = set()
events = []
for index in range(N):
    start, end = map(int, input().split())
    unique_elements.update((start, end))
    events.append((start, end, index))

# sort (end, -start) - all intervals before current interval end before current interval
# in case if two intervals end at a same time then the one which starts late comes first
events.sort(key=lambda x: (x[1], -x[0]))

compressed = get_compressed(unique_elements)
max_N = len(compressed)

# contains - other ranges it contains
# how many other intervals does the current interval contain inside it
contains = [0] * N
FT1 = FenwickTree(max_N)
for i in range(N):
    start, end, index = events[i]
    res = FT1.query(compressed[end]) - FT1.query(compressed[start] - 1)
    FT1.update(compressed[start], 1)
    contains[index] = res

# contained - other ranges contain it
# how many intervals have contained the current interval inside them
contained = [0] * N
FT2 = FenwickTree(max_N)
for i in range(N - 1, -1, -1):
    start, end, index = events[i]
    res = FT2.query(compressed[start])
    FT2.update(compressed[start], 1)
    contained[index] = res

print(*contains)
print(*contained)

"""
sort events by (end, -start)
 
contains - how many do you have
    - mark all the start points in the fenwick tree while traversing
    - before mark fire a query to know how many intervals have started in the range (start, end)
 
contained - how many you are part of
    - mark all the start points in the fenwick tree while traversing
    - before mark fire a query to know how many intervals have started in the range (1, start)
"""
