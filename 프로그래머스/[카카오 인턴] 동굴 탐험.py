from collections import deque


def solution(n, path, order):
    queue = deque()
    visit, can_go = [False] * n, [False] * n
    visit[0], can_go[0] = True, True
    must, must2 = {}, {}

    for a, b in order:
        must[b] = a
        must2[a] = b

    graph = [[] for _ in range(n)]
    for a, b in path:
        graph[a].append(b)
        graph[b].append(a)

    if 0 not in must:
        queue.extend(graph[0])

    while queue:
        node = queue.popleft()
        can_go[node] = True

        if node not in must:  # 선행지점 없을 경우
            visit[node] = True
            for i in graph[node]:
                if not visit[i]:
                    queue.append(i)
            if node in must2 and can_go[must2[node]]:
                queue.append(must2[node])
        elif visit[must.get(node)]:  # 선행지점을 방문하였을 경우
            visit[node] = True
            for i in graph[node]:
                if not visit[i]:
                    queue.append(i)

    if sum(visit) == n:
        return True
    return False
