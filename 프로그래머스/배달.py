from collections import defaultdict, deque


def solution(N, road, K):
    # Create graph of road info
    graph = defaultdict(list)
    for a, b, c in road:
        graph[a].append((b, c))
        graph[b].append((a, c))

    # distances list saves distance data and work as visit list in bfs/dfs
    distances = [float('inf') for _ in range(N + 1)]
    distances[1] = 0

    q = deque([1])
    while q:
        cur = q.popleft()
        for destination, cost in graph[cur]:
            if distances[destination] > distances[cur] + cost:
                q.append(destination)
                distances[destination] = distances[cur] + cost

    # Count towns possible to deliver food
    possible = 0
    for i in distances:
        if i <= K:
            possible += 1
            
    return possible
