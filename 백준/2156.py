import sys
input = sys.stdin.readline


N = int(input())
wines = [0] + [int(input()) for _ in range(N)]

if N == 0:
    print(0)
elif N <= 2:
    print(sum(wines))
else:
    dp = [
        0,
        wines[1],
        wines[1] + wines[2]
    ]
    
    for i in range(3, N + 1):
        dp.append(
            max(
                dp[i - 3] + wines[i - 1] + wines[i], 
                dp[i - 2] + wines[i], 
                dp[i - 1]
            ))
    
    print(dp.pop())
