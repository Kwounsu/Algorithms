import sys
input = sys.stdin.readline


def dfs(now):
    if visited[now]:
        return False
    visited[now] = 1
    for rdown in graph[now]:  # 현재 대각선에서 연결 가능한 대각선에 대해
        if linked[rdown] == -1 or dfs(linked[rdown]):  # 비어있거나 새로운 탐색이 가능할 경우
            linked[rdown] = now
            return True
    return False


N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

DIAG = 2 * N - 1  # 대각선 수
graph = [[] for _ in range(DIAG)]  # i번 대각선에서 연결 가능한 우하향 대각선 번호
for i in range(DIAG):  # 좌하향 대각선을 기준으로 놓을수 있는 칸을 탐색
    for x in range(N):
        y = i - x
        if y < 0 or y >= N:
            continue
        if board[x][y] == 0:
            continue
        graph[i].append(x - y + N - 1)

linked = [-1] * DIAG  # 우하향 대각선 i와 연결된 좌하향 대각선 번호

for i in range(DIAG):
    visited = [0] * DIAG
    dfs(i)

answer = 0

for i in range(DIAG):
    if linked[i] != -1:
        answer += 1

print(answer)


"""
import sys
input = sys.stdin.readline

def bishop(level, count, ver):
    if level >= n*2-1:
        answer[ver] = max(answer[ver], count)
        return
    i, j, flag = level, 0, 0
    if level >= n:
        i, j = n-1, level-n+1
    while i >= 0 and j<n:
        idx = n + i - j
        if board[i][j] == 1 and visited[idx] == 0:
            visited[idx] = 1
            flag = 1
            bishop(level + 2, count + 1, ver)
            visited[idx] = 0
        i, j = i - 1, j + 1
    if flag == 0:
        bishop(level + 2, count, ver)

        
n = int(sys.stdin.readline())
board = [list(map(int, input().split())) for _ in range(n)]

visited = [0] * n * 2
answer = [0, 0]

bishop(0, 0, 0)
bishop(1, 0, 1)

print(sum(answer))
"""
