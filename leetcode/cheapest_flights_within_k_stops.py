def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, des: int, K: int) -> int:
    # Create graph
    graph = collections.defaultdict(list)
    for u, v, w in times:
        graph[u].append((v,w))
    
    # Queue: [(price, vertex, stops_left)]
    Q = [(0, src, K)]
    
    # determine cheapest flights based on min queue
    while Q:
        price, node, k = heapq.heappop(Q)
        if node == dst:
            return price
        if k >= 0:
            for v, w in graph[node]:
                alt = price + w
                heapq.heappush(Q, (alt, v, k - 1))
    return -1
