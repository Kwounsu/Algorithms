import sys
input = sys.stdin.readline


def dq(r, c, size, hr, hc):
    if size == 1: return

    # tile 숫자(종류) 판별
    tile, half = 1, size // 2
    mr, mc = r + half - 1, c + half - 1
    if hr > mr: tile += 2
    if hc > mc: tile += 1

    for i, j in [(0,0), (0,1), (1,0), (1,1)]:
        nr, nc = r + half * i, c + half * j
        if 2 * i + j + 1 == tile:
            dq(nr, nc, half, hr, hc)
        else:
            board[mr + i][mc + j] = tile
            dq(nr, nc, half, mr + i, mc + j)
   

n = int(input())
hr, hc = map(int, input().split())

board = [[0] * n for _ in range(n)]

dq(0, 0, n, hr, hc)
for row in board:
    print(*row)
