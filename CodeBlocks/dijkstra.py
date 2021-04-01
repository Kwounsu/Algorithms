def dijkstra(times: List[List[int]], N: int, K: int) -> int:
    # Create graph
    graph = collections.defaultdict(list)
    for u, v, w in times:
        graph[u].append((v,w))
    
    # Queue: [(distance, vertex)]
    Q = [(0, K)]
    
    dist = collections.defaultdict(int)
    
    # Append shortest path into queue
    while Q:
        time, node = heapq.heappop(Q)
        if node not in dist:
            dist[node] = time
            for v, w in graph[node]:
                alt = time + w
                heapq.heappush(Q, (alt, v))
    
    # Determine every node has shortest path
    if len(dist) == N:
        return max(dist.values())
    return -1
