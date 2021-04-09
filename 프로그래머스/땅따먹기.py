def solution(land):
    dp = [land[0]] + [[0] * 4 for _ in range(len(land) - 1)]
    
    for i in range(1, len(land)):
        for j in range(4):
            dp[i][j] = land[i][j] + max(dp[i - 1][:j] + dp[i - 1][j + 1:])
    
    return max(dp[-1])
