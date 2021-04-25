from collections import deque


def make_block_fit(b):
    min_row = min_col = float('inf')
    for r, c in b:
        min_row = min(min_row, r)
        min_col = min(min_col, c)

    new_block = []
    for idx in range(len(b)):
        new_block.append((b[idx][0] - min_row, b[idx][1] - min_col))
    return sorted(new_block)


def rotate(b):
    ns = []
    for i in range(len(b)):
        ns.append((b[i][1], -b[i][0]))
    return make_block_fit(ns)


def rotate_match(s, b):
    if s == b:
        return 1
    for _ in range(3):
        b = rotate(b)
        if s == b:
            return len(s)
    return 0


def solution(game_board, puzzle):
    answer = 0
    delta = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    N = len(game_board)

    def bfs_move(s, board, x, y):
        q = deque([s])
        visit = []

        while q:
            r, c = q.popleft()
            visit.append((r, c))
            board[r][c] = y

            for dr, dc in delta:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < N and board[nr][nc] == x:
                    q.append((nr, nc))

        return make_block_fit(visit)

    # find all spots and blocks to match
    spots, blocks = [], []
    for i in range(N):
        for j in range(N):
            if game_board[i][j] == 0:
                spots.append(bfs_move((i, j), game_board, 0, 1))
            if puzzle[i][j] == 1:
                blocks.append(bfs_move((i, j), puzzle, 1, 0))

    # match
    spots.sort(key=len)
    blocks.sort(key=len)
    for spot in spots:
        for block in blocks:
            if len(spot) < len(block):
                break
            if len(spot) == len(block):
                answer += rotate_match(spot, block)

    return answer


x_board = [[1, 0, 0, 1, 1],
           [1, 1, 0, 0, 1],
           [0, 1, 0, 1, 1],
           [0, 1, 1, 1, 0],
           [0, 0, 1, 0, 0]]

y_board = [[0, 0, 0, 1, 0],
           [0, 0, 1, 1, 1],
           [0, 0, 1, 0, 0],
           [1, 0, 0, 0, 0],
           [1, 1, 0, 0, 0]]

print(solution(x_board, y_board))
