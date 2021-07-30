from collections import deque
from sys import stdin
input = stdin.readline


def dfs(a, b):
    # 모든 경기 끝
    if a > 4:
        return sum(board) == 0
    # 한팀 경기 끝
    if b > 5:
        return dfs(a + 1, a + 2)
    
    # win, tie, lose
    for i in range(3):
        if board[a*3 + i] and board[b*3 + 2 - i]:
            board[a*3 + i] -= 1
            board[b*3 + 2 - i] -= 1

            if (dfs(a, b + 1)):
                return 1
            
            board[a*3 + i] += 1
            board[b*3 + 2 - i] += 1

    return 0

for _ in range(4):
    board = list(map(int, input().split()))
    print(dfs(0, 1))
