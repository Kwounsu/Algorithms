import sys
from collections import deque
input = sys.stdin.readline


def bfs():
    while queue:
        cr, cc, move = queue.popleft()
        for dr, dc in d:
            nr = cr + dr
            nc = cc + dc
            if 0 < nr <= N and 0 < nc <= M and not visited[nr][nc]:
                if nr == S and nc == K: 
                    return move + 1
                visited[nr][nc] = 1
                queue.append((nr, nc, move + 1))
    return move
 
    
N, M = map(int, input().split())
R, C, S, K = map(int, input().split())  # 말(R, C), 졸(S, K)

visited = [[False] * (M+1) for _ in range(N+1)]
d = [(1, 2), (2, 1), (-1, -2), (-2, -1), (1, -2), (-2, 1), (2, -1), (-1, 2)]

queue = deque([(R, C, 0)])
visited[R][C] = 1

print(bfs())
