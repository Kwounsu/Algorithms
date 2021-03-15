def find(v):
    if v == group[v]: 
        return v
    # path compression
    group[v] = find(group, group[v])
    return group[v]

def union(u, v):
    u,v = find(group, u),find(group, v)
    if u == v:
        return True
    # union by rank
    if rank[u] < rank[v]:
        swap(u, v)
    group[v] = u
    if rank[u] == rank[v]:
        rank[u] += 1

def init():
    group, rank = [], []
    for i in range(n):
        group.append(i)
        rank.append(1)
