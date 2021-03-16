def union(group,u,v):
    if group[u] == group[v]:
        return
    target = group[v]
    for i in range(len(group)):
        if group[i] == target:
            group[i] = group[u]
