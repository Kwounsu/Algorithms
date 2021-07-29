from collections import deque
import sys
input = sys.stdin.readline


def dq(r, c, size):
    cur = s.popleft()
    if cur != 'X':
        for i in range(r, r+size):
            for j in range(c, c+size):
                board[i][j] = cur
    else:
        half = size//2
        dq(r, c, half)
        dq(r, c+half, half)
        dq(r+half, c, half)
        dq(r+half, c+half, half)

n = int(input())
print(n)
s = deque(input().strip())

r, c, size = 0, 0, n
board = [[None] * n for _ in range(n)]

dq(0, 0, n)
for row in board:
    print(*row)
