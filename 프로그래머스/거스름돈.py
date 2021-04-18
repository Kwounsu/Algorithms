def solution(n, money):
    arr = [1] + [0] * n
    
    for m in money:
        for i in range(m, n + 1):
            arr[i] += arr[i - m]
            
    return arr[-1]


# def solution(n, money):
#     dp = [[0] * (n + 1) for _ in range(len(money))]
#     for i in range(0, n + 1, money[0]):
#         dp[0][i] = 1
    
#     for i in range(1, len(money)):
#         for j in range(n + 1):
#             if j < money[i]:
#                 dp[i][j] = dp[i - 1][j]
#             else:
#                 dp[i][j] = dp[i - 1][j] + dp[i][j - money[i]]
    
#     return dp[-1][-1]
