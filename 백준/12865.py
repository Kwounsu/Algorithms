import sys
r = sys.stdin.readline

# 타뷸레이션 (memory: 222372kb, time: 7112ms)

N, C = map(int, r().split())
a = [list(map(int, r().split())) for _ in range(N)]  # Weight and Value

dp = [[a[0][1] if a[0][0] <= c else 0 for c in range(C + 1)]]

for i in range(1, N):
    dp.append([])
    for c in range(C + 1):
        if a[i][0] <= c:
            dp[i].append(
                max(
                    dp[i - 1][c],
                    a[i][1] + dp[i - 1][c - a[i][0]]
                ))
        else:
            dp[i].append(dp[i - 1][c])

print(dp[N - 1][C])


# 재귀, 메모이제이션 (memory: 199248kb, time: 2824ms)

N, K = map(int, r().split())
W = [0]
V = [0]
for i in range(N):
    w, v = map(int, r().split())
    W.append(w)
    V.append(v)

dp = [dict() for _ in range(N + 1)]

def pack(i, w):
    if i == 0 or w <= 0:
        return 0
    
    if w not in dp[i]:
        if w >= W[i]:
            dp[i][w] = max(pack(i - 1, w), pack(i - 1, w - W[i]) + V[i])
        else:
            dp[i][w] = pack(i - 1, w)
            
    return dp[i][w]
    
print(pack(N, K))
