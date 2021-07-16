import sys
from collections import deque
input = sys.stdin.readline

 
def bfs(y, x, d):
    q = deque()
    visitied = [[[0 for _ in range(4)] for _ in range(M)] for _ in range(N)]
    q.append((y, x, d))
    visitied[y][x][d] = 1
 
    delta = ((0,1),(0,-1),(1,0),(-1,0))
    
    while q:
        cr, cc, cd = q.popleft()
 
        if cr == er-1 and cc == ec-1 and cd == ed-1:
            return visitied[cr][cc][cd] - 1
 
        for k in range(1, 4):
            ny = cr + delta[cd][0] * k
            nx = cc + delta[cd][1] * k
            if 0 <= ny < N and 0 <= nx < M and board[ny][nx] == 0:
                if visitied[ny][nx][cd] == 0:
                    visitied[ny][nx][cd] = visitied[cr][cc][cd] + 1
                    q.append((ny, nx, cd))
            else:
                break
 
        for d in range(4):
            if d == cd:
                continue
            if visitied[cr][cc][d] == 0:
                if d in direction[cd]:
                    visitied[cr][cc][d] = visitied[cr][cc][cd] + 1
                else:
                    visitied[cr][cc][d] = visitied[cr][cc][cd] + 2
                q.append((cr, cc, d))

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

sy, sx, sd = map(int, input().split())
er, ec, ed = map(int, input().split())

direction = [[0, 3, 2], [1, 2, 3], [2, 0, 1], [3, 1, 0]]
answer = bfs(sy-1, sx-1, sd-1)

print(answer)
