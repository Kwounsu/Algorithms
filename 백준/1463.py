N = int(input())
dp = [0] * (N + 1)

for i in range(2, N + 1):
    dp[i] = dp[i - 1] + 1
    if i % 3 == 0 and dp[i] > dp[i // 3] + 1:
        dp[i] = dp[i // 3] + 1
    if i % 2 == 0 and dp[i] > dp[i // 2] + 1:
        dp[i] = dp[i // 2] + 1

print(dp[N])

#-----------------------------------------------------------------

n = int(input())
d = [0] * (n + 1)

for i in range(2, n + 1):
    d[i] = min(d[i - 1],
               d[i // 3] if i % 3 == 0 else float('inf'),
               d[i // 2] if i % 2 == 0 else float('inf')) + 1

print(d[n])
