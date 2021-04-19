import heapq


def solution(n, works):
    q = []
    for work in works:
        heapq.heappush(q, -work)
    while n:
        heapq.heappush(q, heapq.heappop(q) + 1)
        n -= 1
    answer = 0
    for i in q:
        if i < 0 :
            answer += i**2
    return answer
