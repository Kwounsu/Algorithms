from collections import deque
import sys

input = sys.stdin.readline


def solution(N, K):
    if N == K:
        return 0

    LIMIT = 100001

    visit = [-1] * LIMIT
    visit[N] = 0

    q = deque([[N, 0]])
    while q:
        cur, time = q.popleft()
        new_time = time + 1

        if visit[K] != -1:
            return visit[K]

        new_loc = cur - 1
        if new_loc >= 0 and visit[new_loc] == -1:
            visit[new_loc] = new_time
            q.append([new_loc, new_time])

        new_loc = cur * 2
        if new_loc < LIMIT and visit[new_loc] == -1:
            visit[new_loc] = new_time
            q.append([new_loc, new_time])

        new_loc = cur + 1
        if new_loc < LIMIT and visit[new_loc] == -1:
            visit[new_loc] = new_time
            q.append([new_loc, new_time])


N, K = map(int, input().split())
print(solution(N, K))
