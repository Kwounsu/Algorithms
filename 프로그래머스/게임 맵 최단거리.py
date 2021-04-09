from collections import deque


def solution(maps):
    n, m = len(maps), len(maps[0])

    dp = [[-1] * m for _ in range(n)]
    dp[0][0] = 1

    directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]

    q = deque([[0, 0]])
    while q:
        r, c = q.popleft()

        for d in range(4):
            r_, c_ = r + directions[d][0], c + directions[d][1]

            if 0 <= r_ < n and 0 <= c_ < m and maps[r_][c_] == 1 and dp[r_][c_] == -1:
                dp[r_][c_] = dp[r][c] + 1
                q.append([r_, c_])

    return dp[-1][-1]
