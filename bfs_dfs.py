from collections import deque

def bfs(root,graph):
    visit = {}
    q = deque([root])
    
    while q:
        node = q.popleft()  # 큐로 먼저 넣은 것 먼저 검색하면 BFS
        if node not in visit:
            visit[node] = True
            q.append(graph[node])
            
    return visit

def dfs(root,graph):
    visit = {}
    stack = deque([root])
    
    while stack:
        node = stack.pop()   # 스택으로 나중에 넣은 것 먼저 검색하면 DFS
        if node not in visit:
            visit[node] = True
            q.append(graph[node])
            
    return visit
