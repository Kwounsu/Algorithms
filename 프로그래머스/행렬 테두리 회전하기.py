def solution(rows, columns, queries):
    answer = []
    board = [[i * columns + j for j in range(1, columns + 1)] for i in range(rows)]

    for a, b, c, d in queries:
        r1, c1, r2, c2 = a - 1, b - 1, c - 1, d - 1

        temp = board[r1][c2]
        min_value = temp

        # Top Row
        min_value = min(min(board[r1][c1:c2]), min_value)
        board[r1][c1 + 1:c2 + 1] = board[r1][c1:c2]

        # Right Column
        for i in range(r2 - 1, r1 - 1, -1):
            min_value = min(board[i][c2], min_value)
            board[i + 1][c2] = board[i][c2]

        # Bottom Row
        min_value = min(min(board[r2][c1 + 1:c2 + 1]), min_value)
        board[r2][c1:c2] = board[r2][c1 + 1:c2 + 1]

        # Left Column
        for i in range(r1, r2):
            min_value = min(board[i + 1][c1], min_value)
            board[i][c1] = board[i + 1][c1]

        board[r1 + 1][c2] = temp

        answer.append(min_value)

    return answer



def solution(rows, columns, queries):
    answer = []
    board = [[i * columns + j for j in range(1, columns + 1)] for i in range(rows)]

    for a, b, c, d in queries:
        stack = []
        r1, c1, r2, c2 = a - 1, b - 1, c - 1, d - 1

        # Top Row
        for i in range(c1, c2 + 1):
            stack.append(board[r1][i])
            if len(stack) != 1:
                board[r1][i] = stack[-2]

        # Right Column
        for j in range(r1 + 1, r2 + 1):
            stack.append(board[j][c2])
            board[j][c2] = stack[-2]

        # Bottom Row
        for k in range(c2 - 1, c1 - 1, -1):
            stack.append(board[r2][k])
            board[r2][k] = stack[-2]

        # Left Column
        for l in range(r2 - 1, r1 - 1, -1):
            stack.append(board[l][c1])
            board[l][c1] = stack[-2]

        answer.append(min(stack))

    return answer
