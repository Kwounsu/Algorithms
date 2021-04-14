from collections import defaultdict


def solution(tickets):
    routes = []

    def dfs(route, used_ticket):
        if len(route) == len(tickets) + 1:
            routes.append(route)
            return

        for nex, ticket_num in graph[route[-1]]:
            if ticket_num not in used_ticket:
                dfs(route + [nex], used_ticket + [ticket_num])
    
    graph = defaultdict(list)
    for i, ticket in enumerate(tickets):
        graph[ticket[0]].append((ticket[1], i))

    dfs(['ICN'], [])
    
    return sorted(routes)[0]
