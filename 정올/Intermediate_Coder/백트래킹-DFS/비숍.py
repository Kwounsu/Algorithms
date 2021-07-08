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
