"""
1. 마지막 계단 전의 계단을 밟은 경우.
2. 마지막 계단 전의 계단을 밟지 않은 경우.

1. dp[n] = dp[n-3] + step[n-1] + step[n]
2. dp[n] = dp[n-2] + step[n]
"""

n=int(input())
step=[int(input()) for _ in range(n)]

dp = [step[0]]
dp.append(step[0] + step[1])
dp.append(max(step[0], step[1]) + step[2])

for i in range(3,n):
    dp.append(max(dp[i-3] + step[i-1], dp[i-2]) + step[i])

print(dp[-1])
