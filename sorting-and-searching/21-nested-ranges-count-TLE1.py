# TLE -> max_N can be 1e9, sol: coordinate compression

""" 777 """

# i=index, B=tree, d=delta, N=TREE_SIZE, B1=difference_array, B2=correction_array
# l=left, r=right,
# _u=point_update, _q=query, update=range_update, query=range_query, p_sum=prefix_sum


class FenwickTree:
    def __init__(self, N):
        self.N = N + 2
        self.B1 = [0] * self.N
        self.B2 = [0] * self.N

    def _q(self, B, i):
        s = 0
        while i > 0:
            s += B[i]
            i -= i & -i
        return s

    def _u(self, B, i, d):
        while i < self.N:
            B[i] += d
            i += i & -i

    def update(self, l, r, d):
        self._u(self.B1, l, d)
        self._u(self.B1, r + 1, -d)
        self._u(self.B2, l, -d * (l - 1))
        self._u(self.B2, r + 1, d * r)

    def p_sum(self, i):
        return self._q(self.B1, i) * i + self._q(self.B2, i)

    def query(self, l, r):
        return self.p_sum(r) - self.p_sum(l - 1)


N = int(input())
max_N = 1
events = []
for index in range(N):
    start, end = map(int, input().split())
    events.append((start, end, index))
    max_N = max(max_N, end)

# sort (end, -start) - all intervals before current interval end before current interval
# in case if two intervals end at a same time then the one which starts late comes first
events.sort(key=lambda x: (x[1], -x[0]))

# contains - other ranges it contains
# how many other intervals does the current interval contain inside it
contains = [0] * N
FT1 = FenwickTree(max_N)
for i in range(N):
    start, end, index = events[i]
    res = FT1.query(start, end)
    FT1.update(start, start, 1)
    contains[index] = res

# contained - other ranges contain it
# how many intervals have contained the current interval inside them
contained = [0] * N
FT2 = FenwickTree(max_N)
for i in range(N - 1, -1, -1):
    start, end, index = events[i]
    res = FT2.query(1, start)
    FT2.update(start, start, 1)
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
