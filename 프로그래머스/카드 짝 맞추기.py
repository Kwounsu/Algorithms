from collections import deque


def solution(board, r, turn_count):
    def move(board_, row, col, d_row, d_col):
        n_row, n_col = row + d_row, col + d_col
        if 0 <= n_row < 4 and 0 <= n_col < 4:
            if board_[4 * n_row + n_col] == '0':
                return move(board_, n_row, n_col, d_row, d_col)
            else:
                return n_row, n_col
        return row, col

    board_linear = "".join([str(board[i][j]) for i in range(4) for j in range(4)])

    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    q = deque([(r, turn_count, board_linear, 0, -1)])
    visit = set()

    while q:
        cur_row, cur_col, board_linear, turn_count, enter_loc = q.popleft()

        if (cur_row, cur_col, board_linear, enter_loc) not in visit:
            visit.add((cur_row, cur_col, board_linear, enter_loc))

            if board_linear.count('0') == 16:
                return turn_count

            # 한칸 이동
            for dr, dc in directions:
                new_row, new_col = cur_row + dr, cur_col + dc
                if 0 <= new_row < 4 and 0 <= new_col < 4:
                    q.append((new_row, new_col, board_linear, turn_count + 1, enter_loc))

            # ctrl 이동
            for dr, dc in directions:
                new_row, new_col = move(board_linear, cur_row, cur_col, dr, dc)
                if new_row != cur_row or new_col != cur_col:
                    q.append((new_row, new_col, board_linear, turn_count + 1, enter_loc))

            # enter
            idx = 4 * cur_row + cur_col
            if board_linear[idx] != '0':
                if enter_loc == -1:
                    q.append((cur_row, cur_col, board_linear, turn_count + 1, idx))
                else:
                    if enter_loc != idx and board_linear[enter_loc] == board_linear[idx]:
                        board_linear = board_linear.replace(board_linear[enter_loc], "0")
                        q.append((cur_row, cur_col, board_linear, turn_count + 1, -1))
