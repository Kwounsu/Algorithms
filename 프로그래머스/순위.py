from collections import defaultdict


def solution(n, results):
    win, lose = defaultdict(set), defaultdict(set)
    for winner, loser in results:
        win[winner].add(loser)
        lose[loser].add(winner)

    def dfs(stack, graph):
        visit = []
        while stack:
            cur = stack.pop()
            if cur not in visit:
                visit.append(cur)
                for node in graph[cur]:
                    stack.append(node)
        return visit

    win_count, lose_count = [], []
    for i in range(1, n + 1):
        win_count.append(len(dfs([i], win)))
        lose_count.append(len(dfs([i], lose)))

    return list(map(sum, zip(win_count, lose_count))).count(n + 1)
