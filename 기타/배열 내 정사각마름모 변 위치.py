def solution(maps, p, r):
    answer = 0

    N = len(maps)
    hp = p // 2  # half power

    mid_right = r // 2
    mid_left = mid_right - 1
    left, right = mid_left - 1, mid_right + 1

    d1, d2 = set(), set()
    for i in range(1, (r - 2) // 2):
        x, y = i, r - 1 - i
        d1.update(((left, x), (left, y), (right, x), (right, y)))
        left -= 1
        right += 1

    for i in range(r):
        for j in range(r):
            if mid_left <= i <= mid_right or mid_left <= j <= mid_right:
                d2.add((i, j))
                if i == 0 or i == r - 1 or j == 0 or j == r - 1:
                    d1.add((i, j))
    d2 = d2 - d1

    start_i, end_i = (2 - r) // 2, N - (r // 2)
    for r in range(start_i, end_i):
        for c in range(start_i, end_i):
            kill = 0
            for dr, dc in d1:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < N and maps[nr][nc] <= hp:
                    kill += 1
            for dr, dc in d2:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < N and maps[nr][nc] <= p:
                    kill += 1
            answer = max(answer, kill)

    return answer
