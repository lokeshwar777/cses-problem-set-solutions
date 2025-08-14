""" 777 """


def lsb(x): return x & -x


class FenwickTree:  # 1-based
    def __init__(self, size):
        self.TREE_SIZE = size + 1
        self.tree = [0] * self.TREE_SIZE

    def update(self, index, change):  # change/diff prev value vs current
        while index < self.TREE_SIZE:
            self.tree[index] += change
            index += lsb(index)

    def query(self, index):
        result = 0
        while index > 0:
            result += self.tree[index]
            index -= lsb(index)
        return result


def solve():
    N, Q = map(int, input().split())
    arr = list(map(int, input().split()))
    FT = FenwickTree(N)
    for index, value in enumerate(arr):
        FT.update(index + 1, value)  # 1-based
    queries = []
    for _ in range(Q):
        ty, a, b = map(int, input().split())
        if ty == 1:
            FT.update(a, b - arr[a - 1])
            arr[a - 1] = b
        else:
            total = FT.query(b)
            not_needed = FT.query(a - 1)
            queries.append(total - not_needed)

    for q in queries:
        print(q)


T = 1
# T = int(input())
for _ in range(T):
    solve()

# Fenwick Tree
"""
i   binary   last set bit   group covers
1   0001     1              [1]
2   0010     2              [1,2]
3   0011     1              [3]
4   0100     4              [1,2,3,4]
5   0101     1              [5]
6   0110     2              [5,6]
7   0111     1              [7]
8   1000     8              [1,2,3,4,5,6,7,8]
 
update - left to right / top to bottom <-
query - right to left / bottom to top -> 
"""
