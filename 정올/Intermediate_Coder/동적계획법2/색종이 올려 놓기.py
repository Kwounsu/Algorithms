def is_okay(i, j):
    if paper[j][0] >= paper[i][0] and paper[j][1] >= paper[i][1]:
        return True
    if paper[j][0] >= paper[i][1] and paper[j][1] >= paper[i][0]:
        return True
    return False


n = int(input())
paper = sorted([list(map(int, input().split())) for _ in range(n)],
                key=lambda x:x[0]*x[1], reverse=True)

dp = [1] * n
for i in range(1, n):
    for j in range(i):
        if is_okay(i ,j):
            dp[i] = max(dp[i], dp[j] + 1)
            
print(max(dp))
