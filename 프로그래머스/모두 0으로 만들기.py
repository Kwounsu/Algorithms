import sys
sys.setrecursionlimit(300000)


def solution(a, edges):
    def dfs(x):
        cur = a[x]
        visit[x] = 1

        for next_node in graph[x]:
            if visit[next_node] == 0:
                cur += dfs(next_node)

        answer[0] += abs(cur)
        return cur

    if sum(a):
        return -1

    answer = [0]
    N = len(a)
    visit = [0] * N
    
    graph = [[] for _ in range(N)]
    for s, e in edges:
        graph[s].append(e)
        graph[e].append(s)

    dfs(1)
    return answer[0]
