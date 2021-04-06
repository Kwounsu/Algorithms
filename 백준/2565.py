import sys
input = sys.stdin.readline

N = int(input())
a = [(list(map(int,input().split()))) for _ in range(N)]
a.sort()
dp = [0] * N

if N <= 1:
    print(0)
else:
    for i in range(N):
        for j in range(i):
            if dp[i] < dp[j] and a[i][1] > a[j][1]:
                dp[i] = dp[j]
        dp[i] += 1

print(N - max(dp))
