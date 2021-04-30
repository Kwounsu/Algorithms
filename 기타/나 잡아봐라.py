from collections import deque


def solution(C, B):
    LIMIT = 2000001

    visit = [[0] * 2 for _ in range(LIMIT + 1)]
    visit[B][0] = 1
    q = deque([[B, 0]])

    time = 0
    while True:
        C += time
        if C > LIMIT:
            return -1
        if visit[C][time % 2] != 0:
            return time

        N = len(q)
        for i in range(N):
            cur, t = q.popleft()
            new_time = (t + 1) % 2

            new = cur - 1
            if new >= 0 and visit[new][new_time] == 0:
                visit[new][new_time] = 1
                q.append([new, new_time])

            new = cur + 1
            if new <= LIMIT and visit[new][new_time] == 0:
                visit[new][new_time] = 1
                q.append([new, new_time])

            new = cur * 2
            if new <= LIMIT and visit[new][new_time] == 0:
                visit[new][new_time] = 1
                q.append([new, new_time])

        time += 1


print(solution(11, 2))
