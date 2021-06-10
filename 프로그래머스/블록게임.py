import numpy as np

delta = {
    1: ((0, 0), (1, 0), (1, 1), (1, 2)),
    2: ((0, 0), (1, 0), (1, -1), (1, -2)),
    3: ((0, 0), (1, 0), (2, 0), (2, -1)),
    4: ((0, 0), (1, 0), (2, 0), (2, 1)),
    5: ((0, 0), (1, 0), (1, -1), (1, 1))
}
top = {
    1: ((1, 1), (1, 2)),
    2: ((1, -1), (1, -2)),
    3: ((2, -1), (1, -1)),
    4: ((2, 1), (1, 1)),
    5: ((1, -1), (1, 1))
}

def solution(board):
    answer = 0
    N = len(board)
    checked_num = set()
    potential_remove = set()
    
    def block_check(r, c):
        num = board[r][c]
        for d in delta:
            flag = True
            for dr, dc in delta[d]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < N and board[nr][nc] == num:
                    pass
                else:
                    flag = False
                    break
            if flag:
                return d
        return 0
    
    def top_check(r, c, block_type):
        zero = 0
        for dr, dc in top[block_type]:
            nr, nc = r + dr, c + dc
            zero += upside_nonzero(nr, nc)
        return zero
    
    def upside_nonzero(r, c):
        count = 0
        for row in range(r - 1, -1, -1):
            if board[row][c] > 0:
                count += 1
        return count
    
    def remove(r, c, block_type):
        for dr, dc in delta[block_type]:
            nr, nc = r + dr, c + dc
            board[nr][nc] = 0
            
    def try_remove(i, j, block_type):
        zero = top_check(i, j, block_type)
        if zero == 0:
            remove(i, j, block_type)
            nonlocal answer
            answer += 1
            return True
        else:
            potential_remove.add((i, j, block_type))
            return False
    
    for i in range(N):
        for j in range(N):
            if board[i][j] > 0 and board[i][j] not in checked_num:
                block_type = block_check(i, j)
                if block_type > 0:
                    checked_num.add(board[i][j])
                    if try_remove(i, j, block_type):
                        deleted = []
                        for r, c, bt in potential_remove:
                            if try_remove(r, c, bt):
                                deleted.append((r, c, bt))
                        for r, c, bt in deleted:
                            potential_remove.remove((r, c, bt))
                    
    return answer
