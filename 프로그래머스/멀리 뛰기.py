def solution(n):
    dp = [0, 1]
    for i in range(2, n + 2):
        dp.append((dp[i - 2] + dp[i - 1]) % 1234567)
    return dp[-1]
