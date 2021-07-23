def is_okay(i, j):
    if (line[i][0] > line[j][0] and line[i][1] > line[j][1]) \
    or (line[i][0] < line[j][0] and line[i][1] < line[j][1]):
        return True
    return False

    
n = int(input())
line = sorted([list(map(int, input().split())) for _ in range(n)])

dp = [1] * n
for i in range(1, n):
    for j in range(i):
        if is_okay(i, j):
            dp[i] = max(dp[i], dp[j] + 1)

print(n - max(dp))
