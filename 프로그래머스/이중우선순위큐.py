import heapq as hq


def solution(operations):
    q = []
    for o in operations:
        r, n = o.split()
        if r == 'I':
            hq.heappush(q, int(n))
        elif len(q) > 0:
            if n == '1':
                q.remove(max(q))
                hq.heapify(q)
            else:
                hq.heappop(q)
    if len(q) > 0:
        return [max(q), hq.heappop(q)]
    return [0, 0]
