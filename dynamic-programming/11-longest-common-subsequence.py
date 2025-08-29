""" 777 """

n1, n2 = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

# recursive (Runtime error)
'''
dp = [[-1]*(n2 + 1) for _ in range(n1 + 1)]
def top_down(i1, i2):
    if i1 == n1 or i2 == n2:
        return 0
    if dp[i1][i2] == -1:
        dp[i1][i2] = (
            (1 + top_down(i1 + 1, i2 + 1)) if a[i1] == b[i2]
            else max(top_down(i1 + 1, i2), top_down(i1, i2 + 1))
        )
    return dp[i1][i2]
top_down(0, 0)
'''

# iterative
dp = [[0]*(n2 + 1) for _ in range(n1 + 1)]
for i in range(n1 - 1, -1, -1):
    for j in range(n2 - 1, -1, -1):
        dp[i][j] = (1 + dp[i + 1][j + 1]) if a[i] == b[j] else max(dp[i + 1][j], dp[i][j + 1])


def print_lcs():
    lcs_length = dp[0][0]
    lcs = []
    i = j = 0
    while i < n1 and j < n2:
        if a[i] == b[j]:
            lcs.append(a[i])
            i += 1
            j += 1
        # better to use top_down(i + 1, j), top_down(i, j + 1) for recursive
        elif dp[i+1][j] > dp[i][j+1]:
            i += 1
        else:
            j += 1
    # print(f"LCSubsequence is {lcs} and its length is {lcs_length}")
    print(lcs_length)
    print(*lcs)


print_lcs()
