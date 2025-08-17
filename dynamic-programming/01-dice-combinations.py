""" 777 """
MOD = 10 ** 9 + 7
N = int(input())

dp = [0] * (N + 1)
dp[0] = 1

for i in range(1, N + 1):
    for j in range(max(0, i - 6), i):
        dp[i] += dp[j]
        if dp[i] >= MOD:
            dp[i] -= MOD

print(dp[N])
