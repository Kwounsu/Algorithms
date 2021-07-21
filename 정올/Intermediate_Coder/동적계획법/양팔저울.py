n = int(input())
weights = list(map(int, input().split()))
g = int(input())
marbles = list(map(int, input().split()))

dp = [[0 for _ in range(40001)] for _ in range(40001)]
dp[0][0] = 1

sum_ = 0
for i in range(1, N+1):
    sum_ += weights[i]
    for j in range(sum_+1):
        if dp[i-1][j] == 1:
            dp[i][j] = 1  # 현재 추 미사용
            dp[i][j + weights[i]] = 1  # 한쪽에 모든 추
            dp[i][abs(j - weights[i])] = 1  # 추 양쪽 분산

for marble in marbles:
    print('Y' if dp[n][marble] else 'N')
