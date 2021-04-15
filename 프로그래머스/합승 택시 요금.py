# BFS

from collections import defaultdict, deque


def solution(n, s, a, b, fares):
    def bfs(start):
        q = deque([start])
        while q:
            x = q.popleft()
            for y, c in graph[x]:
                if dp[start][y] > dp[start][x] + c:
                    dp[start][y] = dp[start][x] + c
                    q.append(y)

    graph = defaultdict(list)
    for x, y, c in fares:
        graph[x].append([y, c])
        graph[y].append([x, c])

    dp = [[float('inf')] * (n + 1) for _ in range(n + 1)]
    dp[s][s] = 0

    for i in range(1, n + 1):
        dp[i][i] = 0
        bfs(i)

    answer = float('inf')
    for i in range(1, n + 1):
        answer = min(answer, dp[s][i] + dp[i][a] + dp[i][b])
    return answer
  
# DP
  
import heapq


def solution(n, s, a, b, fares):
    dp = [[float('inf')] * n for _ in range(n)]
    for i in range(n):
        dp[i][i] = 0

    for x, y, c in fares:
        dp[x - 1][y - 1], dp[y - 1][x - 1] = c, c

    for i in range(n):
        for j in range(n):
            for k in range(n):
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k])

    answer = []
    for i in range(n):
        heapq.heappush(answer, dp[s - 1][i] + dp[i][a - 1] + dp[i][b - 1])
    return heapq.heappop(answer)
